// OnModelExec.cpp : Implementation of CISDaeCOSolverApp and DLL registration.

#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "OnModelExec.h"
#include <math.h>

#include "OnDaeCOSolverMacros.h"
#include "ModelNavMaps.h"
#include "IndexInfo.h"
#include "MatInfo.h"
#include "VarInfo.h"
#include "VirtualTimeInfo.h"
#include "ToleranceInfo.h"
#include "ConvergenceInfo.h"
#include "StepSizeInfo.h"
#include "ReportInfo.h"
#include "StateInfo.h"
#include "TransitionInfo.h"
#include "BandedInfo.h"
#include "triangularization.h"
#include "ConsistentInitialization.h"
#include "IsStepper.h"
#include "CommonTools.h"
#include "IsDaeEso.h"
#include "IsDaeEsoCImpl.h"

#include "IsCINlaEso.h"
#include "IsNlaSolver.h"
#include "MSS.h"
#include "trimEqnInfo.h"

struct _Collection;
#include "OnInitialization.h"

#include <fstream.h>
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

const long FIXED_ASSIGNMENT = 1000000000;


/////////////////////////////////////////////////////////////////////////////
//

COnModelExec::COnModelExec()
{
  init();
}

void COnModelExec::init()
{
  long i;

  m_M = NULL;      // model
  m_pIIsDaeEso = NULL;
  m_pStepper = new CIsStepper();

  m_nAugmentedEqns = 0;
  m_nAugmentedVars = 0; 
  m_assignedEqn = NULL;
  m_VAL = NULL;
  
  // event queue
  m_nEvents = 0;
  m_dEvents = 50;
  m_Events = NULL;
  m_Events = new event_item*[m_dEvents];
  for (i = 0; i < m_dEvents; i++) m_Events[i] = NULL;

  m_bEventPostedWithoutReset = false;
  m_bEventProcessed = false;

  m_pCINlaEso = NULL;  
  m_bRetryInitialization = false;

#if 0
  hr = CoCreateInstance(CLSID_OnScriptParser, NULL, CLSCTX_INPROC_SERVER, IID__OnScriptParser, (void**) &m_pScriptParser);
  _ASSERTE(hr == S_OK);
#endif

}

COnModelExec::~COnModelExec()
{
  clean();
}

void COnModelExec::Destroy()
{
  clean();
}

void COnModelExec::clean()
{
  long i;

  if (m_pIIsDaeEso) 
  {
    m_pIIsDaeEso->Release();
    m_pIIsDaeEso = NULL;
    m_M = NULL;
  }

  m_nAugmentedEqns = 0;
  m_nAugmentedVars = 0; 
  DESTROY_VECTOR(m_assignedEqn)
  DESTROY_VECTOR(m_VAL)

  DESTROY_MEMBER(m_pStepper) 

  // queues
  for (i = 0; i < m_nEvents; i++) DESTROY_MEMBER(m_Events[i])
  DESTROY_VECTOR(m_Events)

  RELEASE_MEMBER(m_pCINlaEso)
  DESTROY_MEMBER(m_pScriptParser)
}

STDMETHODIMP COnModelExec::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOnModelExec,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COnModelExec::OnTransition(double event_time, long iEventEqn, BSTR EventId, long iNewState, IIsDaeEso* pEso)
{
  HRESULT hr;
  long i, j;
  long iVar;
  long* oldEqns = NULL;
  long nOldEqns = 0;
  long* newEqns = NULL;
  long nNewEqns = 0;
  bool bReset = false;

  CIsDaeEsoBase* pEventEso = NULL;
  DWORD dwEso = NULL;
  pEso->GetCPPPtr(&dwEso);
  pEventEso = reinterpret_cast<CIsDaeEsoBase*> (dwEso);

  m_M->m_report->m_nStateEvents++;
  pEventEso->EventInitialization(
    event_time,
    iEventEqn,
    EventId,
    iNewState,
    oldEqns,
    nOldEqns,
    newEqns,
    nNewEqns);
  
  hr = ConsistentInitialization(m_nAugmentedEqns, m_nAugmentedVars, m_assignedEqn, m_VAL, m_M, m_pCINlaEso, pEventEso, iEventEqn, oldEqns, nOldEqns, newEqns, nNewEqns);
  m_pStepper->OnEvent(true);

  if (FAILED(hr)) goto clean_up;

  m_M->initializeConstantJacobians();
  m_M->initDirectEqnMap();

  // initialize the m_K vector based on new m_y values
  for (i = 0; i < m_M->m_nStages; i++)
  {
    for (j = 0; j < m_M->m_nActiveVars; j++)
    {
      iVar = m_M->m_ActiveVars[j];
      m_M->m_K[i]->m_varVal[j] = m_M->m_y->m_varVal[iVar];
      m_M->m_K[i]->m_varDotVal[j] = m_M->m_y->m_varDotVal[iVar];
      
      // attempting to update the last vals as well to eliminate the step size hiccup after initialization
      m_M->m_K[i]->m_varLastVal[j] = m_M->m_y->m_varVal[iVar];
      m_M->m_K[i]->m_varLastDotVal[j] = m_M->m_y->m_varDotVal[iVar];
 
    }
  }

  if (m_pCINlaEso)
  {
    m_pCINlaEso->Release();
    m_pCINlaEso = NULL;
  }

  // fire the after event notification
  
  DispatchProxy::Fire_AfterStateEvent(m_M->m_time->m_curVal, EventId, iEventEqn);
  VTableProxy::Fire_AfterStateEvent(m_M->m_time->m_curVal, EventId, iEventEqn);
 
clean_up:
  DESTROY_VECTOR(oldEqns)
  DESTROY_VECTOR(newEqns)

  // flag jacobian for update
  m_M->m_Jac->m_updateRequired = true;

  return hr;
}

static int __cdecl EventCompare(const void * pElem1, const void * pElem2)
{
  event_item* u1 = ((event_item*)*(void **)pElem1);
  event_item* u2 = ((event_item*)*(void **)pElem2);

  if (u1->event_time == u2->event_time)
    return 0;
  else if (u1->event_time > u2->event_time)
    return 1;
  else
    return -1;
}


void COnModelExec::InternalEventDetection()
{
  if ( m_M->iEventDetection(m_Events, m_nEvents, m_dEvents) )
    OrderEventQueue();
}

void COnModelExec::OrderEventQueue()
{
  long i, j;
  state_event_item* e1;
  state_event_item* e2;

  if (m_nEvents > 1)
  {
    // remove duplicate entries
    for (i = 0; i < m_nEvents-1; i++)
    {
      if (m_Events[i]->type == state_event)
      {
        e1 = static_cast<state_event_item*> (m_Events[i]);
        for (j = i+1; j < m_nEvents; j++)
        {
          if (m_Events[j]->type == state_event)
          {
            e2 = static_cast<state_event_item*> (m_Events[j]);
            if ( (e1->pEventEso == e2->pEventEso) && (e1->iEventEqn == e2->iEventEqn))
            {
              // remove e1 as it is older and likely less accurate entry
              ATLTRACE(L"\nflushing event in OrderEventQueue(): ptr: %d, type: %d, time: %f", e1, e1->type, e1->event_time);
              delete e1;
              compress_ptr_array(i, m_nEvents, m_Events);
              // break out of the for (j...) loop and reset i to i-1 if i > 0 because
              // the above queue compression dropped the next queue entry into the i'th slot
              if (i > 0) i--;
              break;
            }
          }
        }
      }
    }

    // order entries
    qsort(m_Events, m_nEvents, sizeof *(m_Events), EventCompare);
  }

}

STDMETHODIMP COnModelExec::PostRPar(double t, long iGlobalId, double val)
{

#if 0
  ATLTRACE("\n post rpar event: %f, %d, %f", t, iGlobalId, val);
#endif

  
  rpar_event_item* event = new rpar_event_item();
  event->event_time = t;
  event->bExternal = true;
  event->iGlobalId = iGlobalId;
  event->value = val;
  m_Events[m_nEvents++] = event;
  OrderEventQueue();

  return S_OK;
}

STDMETHODIMP COnModelExec::PostIPar(double t, long iGlobalId, long val)
{
  rpar_event_item* event = new rpar_event_item();
  event->event_time = t;
  event->bExternal = true;
  event->iGlobalId = iGlobalId;
  event->value = val;
  m_Events[m_nEvents++] = event;
  OrderEventQueue();

	return S_OK;
}

STDMETHODIMP COnModelExec::PostStateEvent(double EventTime, BSTR EventId, long iEventEqn, IIsDaeEso* pIIsDaeEso)
{
  CIsDaeEsoBase* pEventEso = NULL;
  DWORD dwEso = NULL;
  pIIsDaeEso->GetCPPPtr(&dwEso);
  pEventEso = reinterpret_cast<CIsDaeEsoBase*> (dwEso);
  return iPostStateEvent(EventTime, EventId, iEventEqn, pEventEso, true);
}

HRESULT COnModelExec::iPostStateEvent(double EventTime, BSTR EventId, long iEventEqn, CIsDaeEsoBase* pEventEso, bool bExternal)
{
  state_event_item* event = new state_event_item();

#if 1
  ATLTRACE("\n post state event: %f, %S, %d", EventTime, EventId, iEventEqn);
#endif

  event->event_time = EventTime;
  event->bExternal = bExternal;
  event->EventId = ::SysAllocString(EventId);
  event->iEventEqn = iEventEqn;
  event->pEventEso = pEventEso;
  m_Events[m_nEvents++] = event;
  OrderEventQueue();

  return S_OK;
}

STDMETHODIMP COnModelExec::SetModel(IIsDaeEso *pModel)
{
  HRESULT hr = S_OK;

  if (m_pIIsDaeEso) m_pIIsDaeEso->Release();
  m_pIIsDaeEso = pModel;

  DESTROY_VECTOR(m_assignedEqn)
  DESTROY_VECTOR(m_VAL)

  if (pModel != NULL)
  {
    m_pIIsDaeEso->AddRef();

    pModel->SetModelExec( static_cast<IOnModelExec*> (this) );
    DWORD pIsEsoImpl = NULL;
    hr = pModel->GetCPPPtr(&pIsEsoImpl);
    if (SUCCEEDED(hr))
    {
      m_M = m_pStepper->m_M = reinterpret_cast<CIsDaeEsoBase*> (pIsEsoImpl);
      m_M->m_bGlobalNode = true;

      if (!m_M->m_bEsoInitialized)
      {
        hr = m_M->iInitialize();
        if (SUCCEEDED(hr))
        {
          m_M->iInitializeMasterNodes();
          hr = m_M->initFlatModel();
          if (SUCCEEDED(hr))
          {
            m_M->iCompleteMasterNodeInit();
            m_M->initializeConstantJacobians(); 
            hr = ConsistentInitialization(m_nAugmentedEqns, m_nAugmentedVars, m_assignedEqn, m_VAL, m_M, m_pCINlaEso);
            m_M->initDirectEqnMap();
            if (SUCCEEDED(hr))
            {
              m_pStepper->OnEvent(true);
            }
          }
        }
      }
    }
  }

  return hr;
}

STDMETHODIMP COnModelExec::get_MaxStepSize(double *pVal)
{
	m_pStepper->GetMaxStepSize(pVal);
	return S_OK;
}

STDMETHODIMP COnModelExec::put_MaxStepSize(double newVal)
{
	m_pStepper->SetMaxStepSize(newVal);
  return S_OK;
}

STDMETHODIMP COnModelExec::Step(double external_time)
{
  HRESULT hr = S_OK;
  bool bContinue = true;

  while (bContinue && SUCCEEDED(hr))
  {
    hr = processEventQueue(external_time);
    if (SUCCEEDED(hr))
    {
      bContinue = m_M->m_time->m_reverse ? m_M->m_time->m_curVal > external_time : m_M->m_time->m_curVal < external_time;
      if (bContinue)
      {
        // try to step
        hr = m_pStepper->Step();
        if (FAILED(hr))
        {
          // generate failure report
          generateStepFailureReport();

          // if an event was posted without reset, force a reset before retrying the step
          m_M->m_report->m_idid = 1;
          hr = S_OK;
          if (m_bEventPostedWithoutReset)
            hr = ForceReset();
          
          // retry once again before giving up
          if (SUCCEEDED(hr))
            hr = m_pStepper->Step();
        }
        

        if (SUCCEEDED(hr))
        {
          // validate the event queue if events were left on the queue after previous event processing
          // May 24, 2002 removed this event queue validation because now flushing internal events from the queue
          // after processing events
          if (m_bEventProcessed) ValidateEventQueue();
          InternalEventDetection();

        }
      }
    }
  }

  m_bEventPostedWithoutReset = false;


  return hr;
}

void COnModelExec::generateStepFailureReport()
{
  printEqnAndVarValues();
}

void COnModelExec::ValidateEventQueue()
{

#if 0 // TODO: testing to see if this validation is the cause for lost events

  // purge the event queue of state events if the state condition is not longer valid.  
  event_item* event;
  state_event_item* se;
  long i, j;
  VARIANT_BOOL bStateEvent;

  const double time_offset = 1.0e-6;

  for (i = 0; i < m_nEvents; i++)
  {
    event = m_Events[i];
    // only look at the event if its values can be interpolated
    if ( (m_M->m_time->m_lastVal <= event->event_time) && (m_M->m_time->m_curVal >= (event->event_time + time_offset)) )
    {
      if (event->type == state_event)
      {
        bStateEvent = VARIANT_FALSE;
        se = static_cast<state_event_item*> (event);
        se->pEventEso->EvalStateCondition(
          se->event_time + time_offset,          // event time (offset to put g* positive if close to zero)
          -1,                                    // g* index (set invalid to stop automatic validation)
          se->iTransition,                       // transition index
          &bStateEvent);                         // state event return flag

        if (bStateEvent == VARIANT_FALSE)
        {
#if 1
          ATLTRACE("\n purged event: time, Id, iEqn, iTransition");
          ATLTRACE("\n %f %S %d, %d", se->event_time, se->EventId, se->iEventEqn, se->iTransition);
#endif
          // remove event from the queue
          delete event;
          for (j = i; j < m_nEvents-1; j++) m_Events[j] = m_Events[j+1];
          m_nEvents--;
          m_Events[m_nEvents] = NULL;
        }
      }
    }
  }

#endif

  if (m_nEvents == 0) m_bEventProcessed = false;

}


HRESULT COnModelExec::processEventQueue(double external_time)
{
  HRESULT hr = S_OK;
  event_item* event = NULL;
  double delta_t;
  bool deltat_gt_zero = true;
  long i;
  state_event_item* se = NULL;
  rpar_event_item* re = NULL;
  ipar_event_item* ie = NULL;

  // TODO: the following is a magic number and should be treated in a more generic way
  // The number is used for two purposes; a) events seperated by less than this time will be processed together, and
  // b) current time is offset by this value when evaluating state conditions to remove the noise from the 
  //    g* results which are very close to zero.

  const double min_delta_event_time = 1.0e-6;

  if (m_nEvents > 0)
  {
    // TODO: there is a pathological case where processing one event invalidates the state conditions for 
    //       another event already on the queue.  Before each event is processed, the state conditions should
    //       be reevaluated
    // read first item off the event queue
    event = m_Events[0];


    // event processing conditions:
    // 1) Event time must be between last step and current step
    // 2) External time is the time the external system is requesting the stepper to step to or past.
    //    The new external time target must be beyond the event time
    if (
        !( 
            (event->event_time >= m_M->m_time->m_lastVal) && 
            (event->event_time <= m_M->m_time->m_curVal)  &&
            (  
              (event->event_time <= external_time && !m_M->m_time->m_reverse) || 
              (event->event_time >= external_time && m_M->m_time->m_reverse)
            )
         )
       )
      return S_OK;

process_event:

#if 1 // print Eso name and equation name to output window for event
    long idx;
    CIsDaeEsoCImpl* pModel = NULL;
    BSTR* pEqnNames = NULL;
    CComBSTR prefix;
    long count = 0;


    if (event->type == state_event)
    {
      se = static_cast<state_event_item*> (event);
      idx = se->iEventEqn;
      if (idx >= 0)
      {
        pModel = static_cast<CIsDaeEsoCImpl*> (m_M);

        ATLTRACE("\nevent_time: %e", event->event_time);
        pModel->iGetEqnNames(pEqnNames, prefix, count);
        if (pEqnNames)
        {
          if (pEqnNames[idx]) ATLTRACE("\n%S", pEqnNames[idx]);

          for (i = 0; i < count; i++)
            if (pEqnNames[i]) ::SysFreeString(pEqnNames[i]);

          delete [] pEqnNames;
        }
      }
    }

#endif

    // no need to reinitialize all variables if delta t from last initialization is effectively zero
    if (deltat_gt_zero && event->event_time != m_M->m_time->m_curVal)
    {
      double* y = new double[m_M->m_nActiveVars];
      double* ydot = new double[m_M->m_nActiveVars];
      m_M->iDerivInterpolateAll(event->event_time, y, ydot);
    
      for (i = 0; i < m_M->m_nActiveVars; i++)
      {
        m_M->SetVariable(i, y[i]);
        m_M->SetDerivative(i, ydot[i]);
      }

      m_M->SetTime(event->event_time);
      DESTROY_VECTOR(y)
      DESTROY_VECTOR(ydot)
    }
    
    if (event->type == rpar_event)
    { 
      m_M->m_report->m_nParameterEvents++; 
      re = static_cast<rpar_event_item*> (event);

      // fire the before event notification
      DispatchProxy::Fire_BeforeRParEvent(event->event_time, re->iGlobalId, re->value);
      VTableProxy::Fire_BeforeRParEvent(event->event_time, re->iGlobalId, re->value);
      
      m_M->SetRealPar(re->iGlobalId, re->value);
      // only force reset if parameter change is > 100.0 times the absolute tolerance
      if (fabs(re->value - m_M->m_realParameters[re->iGlobalId]) > 100.0 * m_M->m_tolerance->m_atol[0])
        hr = ForceReset();
      else
        m_bEventPostedWithoutReset = true;  // note the fact that force reset was not used so it will be tried later if necessary
    }
    else if (event->type == ipar_event)
    {
      m_M->m_report->m_nParameterEvents++; 
      ie = static_cast<ipar_event_item*> (event);

      // fire the before event notification
      DispatchProxy::Fire_BeforeIParEvent(event->event_time, ie->iGlobalId, ie->value);
      VTableProxy::Fire_BeforeIParEvent(event->event_time, ie->iGlobalId, ie->value);
      
      m_M->SetIntPar(ie->iGlobalId, ie->value);
      if (abs(ie->value - m_M->m_integerParameters[ie->iGlobalId]) > 100.0 * m_M->m_tolerance->m_atol[0])
        hr = ForceReset();
      else
        m_bEventPostedWithoutReset = true;
    }
    else if (event->type == state_event)
    {
      se = static_cast<state_event_item*> (event);

      // fire the before event notification
      DispatchProxy::Fire_BeforeStateEvent(event->event_time, se->EventId, se->iEventEqn);
      VTableProxy::Fire_BeforeStateEvent(event->event_time, se->EventId, se->iEventEqn);

      hr = se->pEventEso->TriggerEvent(se->event_time, se->EventId, se->iEventEqn);
    }

    // roll the event queue down one
    ATLTRACE(L"\ndeleting event in processEventQueue(): ptr: %d, type: %d, time: %f", event, event->type, event->event_time);
    for (i = 1; i < m_nEvents; i++) m_Events[i-1] = m_Events[i];
    delete event;
    m_nEvents--;
    m_Events[m_nEvents] = NULL;
  }

  if (m_nEvents > 0)
  {
    // more events are on the queue, set the event processed flag so events remaining on the queue will be validated
    // until the queue is emptied.
    m_bEventProcessed = true;

    // process events that have essentially the same time stamp
    event = m_Events[0];
    delta_t = event->event_time - m_M->m_time->m_curVal;
    if (delta_t < min_delta_event_time)
    {
      // There are several reasons why delta_t might be very small; a) events are physically related and are occurring
      // at essentially the same time (two clutches in parallel will lock at the same time), b) the nudge in the Nla reset
      // pushed time up to or past the time of another event in the queue, or c) the events just happen to coincide with
      // each other for no obvious reason.

      deltat_gt_zero = false;
      event->event_time = m_M->m_time->m_curVal;
      goto process_event;
    }
  }

  // flush internal events from the event queue
  if (m_nEvents > 0)
  {
    long iCur = 0;
    for (i = 0; i < m_nEvents; i++)
    {
      if (!m_Events[i]->bExternal || m_Events[i]->event_time < m_M->m_time->m_lastVal)
      {
        ATLTRACE(L"\nflushing event in processEventQueue(): ptr: %d, type: %d, time: %f", m_Events[i], m_Events[i]->type, m_Events[i]->event_time);
        delete m_Events[i];
      }
      else
        m_Events[iCur++] = m_Events[i];
    }

    for (i = iCur; i < m_nEvents; i++) m_Events[i] = NULL;
    m_nEvents = iCur;
  }

  if (m_nEvents == 0) m_bEventProcessed = false;
  return hr;
}


STDMETHODIMP COnModelExec::ForceReset()
{
  HRESULT hr = S_OK;
  long i, j;
  long iVar;

  if (!m_pCINlaEso)
  {
    hr = ConsistentInitialization(m_nAugmentedEqns, m_nAugmentedVars, m_assignedEqn, m_VAL, m_M, m_pCINlaEso);
  }
  else
  {
    hr = m_pCINlaEso->Solve();
  }
  m_pStepper->OnEvent(false);

  if (SUCCEEDED(hr))
  {
    // initialize the m_K vector based on new m_y values
    for (i = 0; i < m_M->m_nStages; i++)
    {
      for (j = 0; j < m_M->m_nActiveVars; j++)
      {
        iVar = m_M->m_ActiveVars[j];
        m_M->m_K[i]->m_varVal[j] = m_M->m_y->m_varVal[iVar];
        m_M->m_K[i]->m_varDotVal[j] = m_M->m_y->m_varDotVal[iVar];
        m_M->m_K[i]->m_varLastVal[j] = m_M->m_y->m_varVal[iVar];
        m_M->m_K[i]->m_varLastDotVal[j] = m_M->m_y->m_varDotVal[iVar];
      }
    }
  }

  return hr;
}


STDMETHODIMP COnModelExec::Save(BSTR filename)
{
  const long m_classId = 1016;
  const long m_schema = 1;

  long i;
  FILE* fs;
  USES_CONVERSION;
  short bm_assignedEqn = (m_assignedEqn != NULL);
  short bm_VAL = (m_VAL != NULL);

  fs = fopen(W2CA(filename), "wb");
  if (!fs)
    return ERROR_FILE_NOT_FOUND;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  m_pStepper->Save(fs);
  
  WRITE_SCALAR( bm_assignedEqn )
  if (m_assignedEqn)
  {
    WRITE_SCALAR( m_nAugmentedVars )
    WRITE_VECTOR( m_assignedEqn, long, m_nAugmentedVars )
  }

  WRITE_SCALAR( bm_VAL )
  if (m_VAL)
  {
    WRITE_SCALAR( m_nAugmentedVars )
    WRITE_VECTOR( m_VAL, long, m_nAugmentedVars )
  }

  WRITE_SCALAR( m_nEvents )
  for (i = 0; i < m_nEvents; i++)
  {
    WRITE_SCALAR( m_Events[i]->type )
    m_Events[i]->Save(fs);
  }

  WRITE_SCALAR( m_bEventPostedWithoutReset )
  WRITE_SCALAR( m_bEventProcessed )

  fclose( fs );

  return S_OK;
}

STDMETHODIMP COnModelExec::Load(BSTR filename)
{
  const long m_classId = 1016;
  const long m_schema = 1;

  HRESULT hr = E_FAIL;
  long classId;
  long schema;
  long i;
	FILE* fs;
  USES_CONVERSION;
  short bm_assignedEqn;
  short bm_VAL;
  long size;
  event_type type;
  state_event_item* se;
  rpar_event_item* re;
  ipar_event_item* ie;

  fs = fopen(W2CA(filename), "rb");
  if (!fs) 
    return ERROR_FILE_NOT_FOUND;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  if (m_pStepper->Load(fs) )
  {

    READ_SCALAR( bm_assignedEqn )
    if (bm_assignedEqn)
    {
      READ_SCALAR( size )
      if (size != m_nAugmentedVars) { _ASSERTE(0); return false; }

      if (!m_assignedEqn) 
        m_assignedEqn = new long[m_nAugmentedVars];

      READ_VECTOR( m_assignedEqn, long, m_nAugmentedVars )
    }

    READ_SCALAR( bm_VAL )
    if (bm_VAL)
    {
      READ_SCALAR( size )
      if (size != m_nAugmentedVars) { _ASSERTE(0); return false; }

      if (!m_VAL)
        m_VAL = new long[m_nAugmentedVars];

      READ_VECTOR( m_VAL, long, m_nAugmentedVars )
    }

    // wipe out event queue
    for (i = 0; i < m_nEvents; i++)
    {
      delete m_Events[i];
      m_Events[i] = NULL;
    }
    m_nEvents = 0;

    READ_SCALAR( m_nEvents )
    for (i = 0; i < m_nEvents; i++)
    {
      READ_SCALAR( type )
      if (type == state_event)
      {
        m_Events[i] = se = new state_event_item();
        se->Load(fs, m_M->m_fm->EsoList, m_M->m_fm->EsoCount);
      }
      else if (type == rpar_event)
      {
        m_Events[i] = re = new rpar_event_item();
        re->Load(fs, m_M->m_fm->EsoList, m_M->m_fm->EsoCount);
      }
      else if (type == ipar_event)
      {
        m_Events[i] = ie = new ipar_event_item();
        ie->Load(fs, m_M->m_fm->EsoList, m_M->m_fm->EsoCount);
      }
    }

    READ_SCALAR( m_bEventPostedWithoutReset )
    READ_SCALAR( m_bEventProcessed )    

    fclose( fs );

    // release the cached CINlaEso
    if (m_pCINlaEso)
    {
      m_pCINlaEso->Release();
      m_pCINlaEso = NULL;
    }
    
    hr = S_OK;
  }

  return hr;
}


void COnModelExec::performOutputAssignment(
  long nEqns,
  long nVars,
  long nAugmentedVars,
  long* cNZCols, 
  long* spRowPage, 
  long* ColIndices,
  long* VAL,
  long*& assignedEqn, 
  long*& itAssignedEqn,
  long*& itVAL)
{
  long i;

  DESTROY_VECTOR(assignedEqn)
  assignedEqn = new long[nAugmentedVars];
  itAssignedEqn = new long[nAugmentedVars];
  itVAL = new long[nAugmentedVars];
  TransposeVector(VAL, nAugmentedVars, itVAL, nAugmentedVars);
  for (i = 0; i < nAugmentedVars; i++) 
  {
    assignedEqn[i] = -1;
    if (VAL[i] >= 0) assignedEqn[i] = FIXED_ASSIGNMENT;
  }
  assignVariables(nEqns, nAugmentedVars, cNZCols, spRowPage, ColIndices, assignedEqn);
  for (i = 0; i < nAugmentedVars; i++) if (assignedEqn[i] == FIXED_ASSIGNMENT) assignedEqn[i] = -1;
  TransposeVector(assignedEqn, nAugmentedVars, itAssignedEqn, nAugmentedVars);  
}


void COnModelExec::printEqnStructure(
  CIsDaeEsoCImpl* pCImpl,
  long nEqns,
  long nVars,
  long nAugmentedVars,
  long* VAL,
  long* itVAL,
  long* EqnOrder,
  long* VarOrder,
  long* assignedEqn, 
  long* itAssignedEqn,
  bool bShowAssignment)
{
  USES_CONVERSION;
  SAFEARRAY* psaEqnNames = NULL;
  BSTR* pEqnNames = NULL;
  SAFEARRAY* psaVarNames = NULL;
  BSTR* pVarNames = NULL;
  ofstream fs;
  
  long i, j, iEqn, iVar;

  pCImpl->GetEqnNames( &psaEqnNames);
  SafeArrayAccessData(psaEqnNames, (void HUGEP* FAR*)& pEqnNames);
  pCImpl->GetVarNames( &psaVarNames);
  SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& pVarNames);

  fs.open("Equation_Structure.txt");

  fs << "\n\n\nEquation List";
  for (i = 0; i < nEqns; i++)
  {
    iEqn = EqnOrder[i];
    fs << "\n" << i << "\t" << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );
    if (bShowAssignment)
    {
      if (itAssignedEqn[i] >= 0)
      {
        if (itAssignedEqn[i] >= nVars)
        {
          iVar = VarOrder[itVAL[itAssignedEqn[i]]];
          fs << "\tVar: " << iVar << "\tDER(" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" ) << ")";
        }
        else
        {
          iVar = VarOrder[itAssignedEqn[i]];
          fs << "\tVar: " << iVar << "\t" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" );
        }
      }
      else
      {
        fs << "\tVar: ***** No Assignment *****"; 
      }
    }
  }
  
  fs << "\n\n\nVariable List";
  for (i = 0; i < nAugmentedVars; i++)
  {
    if (i >= nVars)
    {
      iVar = VarOrder[itVAL[i]];
      fs << "\n" << i << "\t" << iVar << "\tDER(" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" ) << ")";
    }
    else
    {
      iVar = VarOrder[i];
      fs << "\n" << i << "\t" << iVar << "\t" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" );
    }

    if (bShowAssignment)
    {
      if (assignedEqn[i] >= 0)
      {
        iEqn = EqnOrder[assignedEqn[i]];
        fs << "\tEqn: " << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );  
      }
      else
      {
        if (VAL[i] >= 0)
        {
          fs << "\tEqn: ***** X Variable *****";
        }
        else
        {
          fs << "\tEqn: ***** No Assignment *****";
        }
      }
    }
  }

  fs << "\n\n\nJacobian Matrix";
  long spVar;
  for (i = 0; i < pCImpl->m_nActiveEqns; i++)
  {
    iEqn = pCImpl->m_ActiveEqns[i];
    spVar = pCImpl->m_JacStruct->m_spRowPage[iEqn];  
    fs << "\n" << i << "\t" << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );
    for (j = 0; j < pCImpl->m_JacStruct->m_cNZCols[iEqn]; j++)
    {
      iVar = pCImpl->m_JacStruct->m_ColIndices[spVar+j];
      fs << "\t" << iVar << "\t" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" );
    }
  }

  fs << "\n\n\nMass Matrix";
  for (i = 0; i < pCImpl->m_nActiveEqns; i++)
  {
    iEqn = pCImpl->m_ActiveEqns[i];
    if (pCImpl->m_MassStruct->m_cNZCols[iEqn] > 0)
    {
      spVar = pCImpl->m_MassStruct->m_spRowPage[iEqn];  
      fs << "\n" << i << "\t" << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );
      for (j = 0; j < pCImpl->m_MassStruct->m_cNZCols[iEqn]; j++)
      {
        iVar = pCImpl->m_MassStruct->m_ColIndices[spVar+j];
        fs << "\t" << iVar << "\tDER(" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" ) << ")"; 
      }
    }
  }

  fs.close();
  SafeArrayUnaccessData(psaEqnNames);
  SafeArrayDestroy(psaEqnNames);
  SafeArrayUnaccessData(psaVarNames);
  SafeArrayDestroy(psaVarNames);
}


void COnModelExec::printEqnAndVarValues()
{
  USES_CONVERSION;
  SAFEARRAY* psaEqnNames = NULL;
  BSTR* pEqnNames = NULL;
  SAFEARRAY* psaVarNames = NULL;
  BSTR* pVarNames = NULL;
  ofstream fs;
  double* res = NULL;

  CIsDaeEsoCImpl* pCImpl = static_cast<CIsDaeEsoCImpl*> (m_M);
  long i, j, iEqn, iVar;

  res = new double[m_M->m_nEqns];
  pCImpl->GetEqnNames( &psaEqnNames);
  SafeArrayAccessData(psaEqnNames, (void HUGEP* FAR*)& pEqnNames);
  pCImpl->GetVarNames( &psaVarNames);
  SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& pVarNames);

  fs.open("Equation_And_Variable_Values.txt");

  m_M->iDirectGetAllResiduals(
    m_M->m_time->m_curVal,
    m_M->m_y->m_varVal,
    m_M->m_y->m_varDotVal,
    res,
    m_M->m_y->m_valInvalid,
    m_M->m_realParameters,
    m_M->m_integerParameters);

  fs << "\n\n\nEquation List";
  for (i = 0; i < m_M->m_nActiveEqns; i++)
  {
    iEqn = m_M->m_ActiveEqns[i];
    fs << "\n" << i << "\t" << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );
    fs << " res: " << res[i];
  }
  
  fs << "\n\n\nVariable List";
  for (i = 0; i < m_M->m_nActiveVars; i++)
  {
    iVar = m_M->m_ActiveVars[i];
    
    fs << "\n" << i << "\t" << iVar << "\t" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" );
    fs << " VAL: " << m_M->m_y->m_varVal[i];
    fs << " DER: " << m_M->m_y->m_varDotVal[i];
  }

  fs << "\n\n\nJacobian Matrix";
  long spVar;
  for (i = 0; i < pCImpl->m_nActiveEqns; i++)
  {
    iEqn = pCImpl->m_ActiveEqns[i];
    spVar = pCImpl->m_JacStruct->m_spRowPage[iEqn];  
    fs << "\n" << i << "\t" << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );
    for (j = 0; j < pCImpl->m_JacStruct->m_cNZCols[iEqn]; j++)
    {
      iVar = pCImpl->m_JacStruct->m_ColIndices[spVar+j];
      fs << "\t" << iVar << "\t" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" );
    }
  }

  fs << "\n\n\nMass Matrix";
  for (i = 0; i < pCImpl->m_nActiveEqns; i++)
  {
    iEqn = pCImpl->m_ActiveEqns[i];
    if (pCImpl->m_MassStruct->m_cNZCols[iEqn] > 0)
    {
      spVar = pCImpl->m_MassStruct->m_spRowPage[iEqn];  
      fs << "\n" << i << "\t" << iEqn << "\t" << ( pEqnNames[iEqn] ? W2CA(pEqnNames[iEqn]) : "(null)" );
      for (j = 0; j < pCImpl->m_MassStruct->m_cNZCols[iEqn]; j++)
      {
        iVar = pCImpl->m_MassStruct->m_ColIndices[spVar+j];
        fs << "\t" << iVar << "\tDER(" << ( pVarNames[iVar] ? W2CA(pVarNames[iVar]) : "(null)" ) << ")"; 
      }
    }
  }

  DESTROY_VECTOR(res)
  fs.close();
  SafeArrayUnaccessData(psaEqnNames);
  SafeArrayDestroy(psaEqnNames);
  SafeArrayUnaccessData(psaVarNames);
  SafeArrayDestroy(psaVarNames);
}










  // example:

  // g, L are fixed parameters
  // f0 : 0 = -xd + w
  // f1 : 0 = yd + z
  // f2 : 0 = wd + t*x
  // f3 : 0 = zd + t*y - g
  // f4 : 0 = x^2 + y^2 - L^2

  // from MSS
  // f5 : df4/dt = df4/dx * xd + df4/dy * yd
  // f6 : df0/dt = df0/dw * wd + df0/dxd * xdd
  // f7 : df1/dt = df1/dz * zd + df1/dyd * ydd
  // f8 : df5/dt = d2f4/dt = df5/dx * xd + df5/dy * yd + df5/dxd * xdd + df5/dyd * ydd

  // VAL - how variables and their derivatives are associated
  //       0, 1, 2, 3,  4,  5,  6,  7, 8,   9,  10
  // VAL { x, y, w, z, xd, yd, wd, zd, t, xdd, ydd } 
  // ==> { 4, 5, 6, 7,  9, 10, -1, -1,-1,  -1,  -1 }
  
  // EAL - how equations and their derivatives are associated
  //          0,  1,  2,  3,  4,   5,   6,   7,   8
  //  eqns { f0, f1, f2, f3, f4, f4d, f1d, f2d, f5d }  (f5d == f4dd)
  //       {   6, 7, -1, -1,  5, 8,    -1,   -1, -1 }

  // calculate derivatives of functions as follows:
  //   dfi/dt -> look in edge list for variable dependencies on equation i

  //   chain rule:   dfi/dt = dfi/dj * dj/dt for each equation to variable edge
  
  //     get dfi/dj from jacobian if i < in_nEqns && j < in_nVars, 
  //         otherwise calculate numerically by perturbing j
  
  //     get dfi/d2j from mass if i < in_nEqns && j < in_nVars,
  //         otherwise calculate numerically by perturbing dj

  //     get dj/dt by getting derivative of j from VAL


  // edgeList - how variables map to equations
  //     { x, y, w, z,xd,yd,wd,zd, t,x2,y2 } 
  // eqns  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10
  //    0        1     1 
  //    1           1     1
  //    2  1                 1     1
  //    3     1                 1  1
  //    4  1  1

  //    5  1  1        1  1
  //    6        1     1     1        1
  //    7           1     1     1        1
  //    8  1  1        1  1           1  1

  // NOTE:  if time is used in any equation, add v(n+1) = t where vd(n+1) = 1


// assumption:  The source ESO y, ydot values have already been written into
//              the pDaeEso by the caller in the case of the event transition.
//              This code is intended to polish the 'initial guess' for consistency
HRESULT COnModelExec::ConsistentInitialization(
  long& nAugmentedEqns,
  long& nAugmentedVars,
  long*& assignedEqn,
  long*& VAL,
  CIsDaeEsoBase* pDaeEso,             // pointer to differential algebraic model
  CComObject<CIsCINlaEso>*& pNlaEso,  // pointer to consistent initialization Nla Eso
  CIsDaeEsoBase* pTransitionEso,      // pointer to transition EsoX
  long iEventEqn,                     // index of g*() (event initialization only)
  long* oldEqns,                      // indices of equations from source state
  long nOldEqns,                      // number of equations in source state
  long* newEqns,                      // indices of equations in target state
  long nNewEqns)                      // number of equations in target state
{

  long i, j, k;
  FlatModel* fm = pDaeEso->m_fm;
  HRESULT hr = S_OK;

  // the following variables are prefixed with in_ because effectively, they are inputs
  // to the consistent initialization.
  long in_nEqns = 0;                       // number of actual equations
  long in_nVars = 0;                       // number of actual variables
  long in_nAugmentedVars = 0;              // number of augmented vars (2 * nDiff + nAlg)
  long* in_VAL = NULL;                     // Variable association list x -> x_dot
  long in_edgeList_nColIndices = 0;        // number of column indices
  long* in_edgeList_cNZCols = NULL;        // number of NZ in each column in edge list
  long* in_edgeList_spRowPage = NULL;      // index of row pages
  long* in_edgeList_ColIndices = NULL;     // edge list [iCol][0 -> cNZCols-1]
  ModelEqnMap* EqnMap = NULL;              // model to equation map
  long* itVAL = NULL;                      // transpose of VAL
  long* itEAL = NULL;                      // transpose of EAL

  // MSS
  //long* assignedEqn = NULL;              // output assignment (now a parameter)
  long* itAssignedEqn = NULL;              // transpose of output assignment
  //long* VAL = NULL;                      // Variable association list (x -> xdot) (now a parameter)
  long* EAL = NULL;        
  short* differentialIndex = NULL;
  long* EqnOrder = NULL;
  long* VarOrder = NULL;                   // variable order in DAE model (-1 where variable not part of model)
  long* itVarOrder = NULL;
  long nDiscEqns = 0;
  long* DiscEqns = NULL;
  long* DiscVars = NULL;
  long edgeList_nColIndices = 0;
  long* edgeList_spRowPage = NULL;
  long* edgeList_cNZCols = NULL;
  long* edgeList_ColIndices = NULL;
  long max_var_index;

  // block triangularization
  long* tr_ColIndices = NULL;
  long* tr_columnPageNumber = NULL;
  long* tr_cNZCols = NULL;         
  long  tr_cBlocks;
  long* tr_blockSizes = NULL;     
  long* tr_orderMap = NULL;
  long* tr_columnOrder = NULL;
  long* tr_rowOrder = NULL;


  // temporary vectors for reallocation
  long* t_VarOrder = NULL;
  long* t_EqnOrder = NULL;

  // z variable calculations
  long* iEqns = NULL;
  double* residuals = NULL;

  // reinitialization triggering events
  double* last_x = NULL;
  double* last_xdot = NULL;
  state_event_item* se = NULL;
  event_item** events = NULL;
  long event_count = 0;
  long event_dim = 0;
  
  long eqnSource[6];
  for (i = 0; i < 6; i++) eqnSource[i] = -1;

  addEquationInfo addEqnInfo;
  trimEquationInfo trimEqnInfo;
  trimConstraintInfo trimConInfo;

  // debugging vector
  long* temp = NULL;

  bool bRunMSS = false;





_retry_initialization:

  bRunMSS = (assignedEqn == NULL || pDaeEso->m_index->m_isHighIndex) ? true : false;

#if 1
  double startTime = ((double)clock() / CLOCKS_PER_SEC);
  double endTime = startTime;
#endif

  CComObject<CIsNlaSolver>* pNlaSolver = NULL;

  if (pNlaEso)
  {
    pNlaEso->Release();
    pNlaEso = NULL;
  }

  // remove old F(), G() and add new F()
  if (pTransitionEso)
  {
    replaceEquations(assignedEqn, fm, oldEqns, nOldEqns, newEqns, nNewEqns);
    pDaeEso->RefreshEqnMap(*fm);
  }

  // get structure from global Eso model
  hr = pDaeEso->iGetNlaStruct(
    in_nEqns, in_nVars, in_nAugmentedVars, in_VAL, EqnOrder, VarOrder,
    in_edgeList_nColIndices, in_edgeList_cNZCols, in_edgeList_spRowPage, in_edgeList_ColIndices);

  eqnSource[0] = in_nEqns;

  nAugmentedEqns = in_nEqns;
  nAugmentedVars = in_nAugmentedVars;

  bool bShowAssignment = in_nEqns != in_nVars;

  // Ensure that the number of equation equals the number of variables.  If not, do an output assignment to
  // aid the user in finding his errors, and return on error.
  if (bShowAssignment)
  {
    performOutputAssignment(
      in_nEqns, in_nVars, in_nAugmentedVars,
      in_edgeList_cNZCols, in_edgeList_spRowPage, in_edgeList_ColIndices, in_VAL, 
      assignedEqn, itAssignedEqn, itVAL);
    
    hr = E_FAIL;
  }

#if 1
  if (itVAL == NULL)
  {
    itVAL = new long[in_nAugmentedVars];
    TransposeVector(in_VAL, in_nAugmentedVars, itVAL, in_nAugmentedVars);
  }
  
  CIsDaeEsoCImpl* pCImpl = static_cast<CIsDaeEsoCImpl*> (pDaeEso);

  printEqnStructure(
    pCImpl,
    in_nEqns,
    in_nVars,
    in_nAugmentedVars,
    in_VAL,
    itVAL,
    EqnOrder,
    VarOrder,
    assignedEqn, 
    itAssignedEqn,
    bShowAssignment);

#endif

  if (FAILED(hr)) goto clean_up;
  
  // calculate variable index, augmented equations, and validate problem structure 
  if (bRunMSS)
  {
    // not reusing VAL or assignedEqn if running MSS again.  Starting from scratch.  In the future
    // we may look for more efficiency.
    DESTROY_VECTOR(VAL);
    DESTROY_VECTOR(assignedEqn);
    long iRet = iCalculateMSS(nAugmentedVars, nAugmentedEqns, in_VAL, in_edgeList_cNZCols, in_edgeList_ColIndices,
      VAL, EAL, edgeList_nColIndices, edgeList_spRowPage, edgeList_cNZCols, edgeList_ColIndices, 
      assignedEqn, differentialIndex);

    if (iRet ==  iMSS_MaxCalls)
    {
      hr = E_FAIL;
      printVec("assignedEqn",assignedEqn, in_nEqns);
    }
  }
  else
  {
    hr = S_OK;
    edgeList_nColIndices = in_edgeList_nColIndices;
    edgeList_spRowPage = in_edgeList_spRowPage;
    edgeList_cNZCols = in_edgeList_cNZCols;
    edgeList_ColIndices = in_edgeList_ColIndices;
  }

  eqnSource[1] = nAugmentedEqns;

  if (FAILED(hr)) 
  {
#if 0 
    reportInitializationEqnInfo(
      true,
      InitStage_Init,
      pDaeEso,
      in_nEqns,
      in_nVars,
      in_edgeList_spRowPage,
      in_edgeList_cNZCols,
      in_edgeList_nColIndices,
      in_edgeList_ColIndices,
      EqnOrder, 
      VarOrder, 
      in_VAL,
      NULL,
      assignedEqn);
#endif
    goto clean_up;
  }

  TransposeVector(VAL, nAugmentedVars, itVAL, nAugmentedVars);
  
  if (bRunMSS)
    TransposeVector(EAL, nAugmentedEqns, itEAL, nAugmentedEqns);

  if (nAugmentedVars != in_nAugmentedVars || nAugmentedEqns != in_nEqns)
  {
    // re-allocate the VarOrder and EqnOrder vectors at the nAugmentedVars size
    t_VarOrder = new long[nAugmentedVars];
    t_EqnOrder = new long[nAugmentedVars];

    for (i = 0; i < nAugmentedVars; i++) 
    {
      if (i < in_nEqns)
        t_EqnOrder[i] = EqnOrder[i];
      else if (i < nAugmentedEqns)
        t_EqnOrder[i] = fm->nEqns + i - in_nEqns;
      else
        t_EqnOrder[i] = -1;
    }
    DESTROY_VECTOR(EqnOrder)
    EqnOrder = t_EqnOrder;

    max_var_index = 0;
    for (i = 0; i < in_nAugmentedVars; i++) max_var_index = IMAX(max_var_index, VarOrder[i]);

    for (i = 0; i < nAugmentedVars; i++)
    {
      if (i < in_nAugmentedVars)
        t_VarOrder[i] = VarOrder[i];
      else
        t_VarOrder[i] = max_var_index + i + 1 - in_nAugmentedVars;
    }
    DESTROY_VECTOR(VarOrder)
    VarOrder = t_VarOrder;
  }

  // calculate the maximum variable index
  max_var_index = 0;
  for (i = 0; i < nAugmentedVars; i++) max_var_index = IMAX(max_var_index, VarOrder[i]);

  if (bRunMSS)
  {
    // size the EqnMap if necessary
    fm->nAugmentedEqns = nAugmentedEqns;
    fm->nMSSEqns = nAugmentedEqns - in_nEqns;
    if (fm->EqnMapSize < (fm->nEqns + fm->nMSSEqns))
    {
      size_ptr_array(50, fm->EqnMapSize, fm->EqnMapDim, fm->EqnMap, fm->nEqns + fm->nMSSEqns - fm->EqnMapSize);
      for (i = fm->nEqns; i < (fm->nEqns + fm->nMSSEqns); i++) 
      {
        if (!fm->EqnMap[i]) 
        {
          fm->EqnMap[i] = new ModelEqnMap(); 
          fm->EqnMapSize++;
        }
      }
    }
  }
  
  if (bRunMSS)
  {
    // initialize the augmented equations
    j = in_nEqns;
    for (i = fm->nEqns; i < (fm->nEqns + fm->nMSSEqns); i++)
    {
      fm->EqnMap[i]->bAugmented = true;
      fm->EqnMap[i]->iEqn = j++;
    }
  }

  if (bRunMSS)
  {

    // initialize the augmented variables
    fm->nAugmentedVars = nAugmentedVars;
    fm->nMSSVars = nAugmentedVars - in_nAugmentedVars;
    j = in_nVars;

    if (max_var_index > fm->nVars)
      size_ptr_array(50, fm->VarMapSize, fm->VarMapDim, fm->VarMap, max_var_index - fm->nVars + 1);

    for (i = fm->nVars; i <= max_var_index; i++)
    {
      if (!fm->VarMap[i]) 
      {
        fm->VarMap[i] = new ModelVarMap();
        fm->VarMapSize++;
      }
      fm->VarMap[i]->bAugmented = true;
      fm->VarMap[i]->iVar = j++;
    }
  }

  if (bRunMSS)
  {
    // initialize the EAL index on the equations that have MSS added derivatives
    for (i = 0; i < nAugmentedEqns; i++)
    {
      if (i < in_nEqns)
      {
        if (EAL[i] >= 0)
          fm->EqnMap[EqnOrder[i]]->iEAL = EqnOrder[EAL[i]];
      }
    
      if (itEAL[i] >= 0)
        fm->EqnMap[EqnOrder[i]]->itEAL = EqnOrder[itEAL[i]];
    }
  }

  if (bRunMSS)
  {
    // initialize the VAL index on the variables that have xdot and xdotdot
    for (i = 0; i < nAugmentedVars; i++)
    {
      if (VAL[i] >= 0) fm->VarMap[VarOrder[i]]->iVAL = VarOrder[VAL[i]];
      if (itVAL[i] >= 0) fm->VarMap[VarOrder[i]]->itVAL = VarOrder[itVAL[i]];
    }
  }

  if (bRunMSS)
  {
    // evaluate the differential order of each variable using itVAL
    for (i = 0; i < nAugmentedVars; i++)
    {
      k = 0;
      j = itVAL[i];
      if (j >= 0 && j < nAugmentedVars) 
      { 
        do 
        { 
          j = itVAL[j]; 
          k++;
        } while (j >= 0); 
      }

      fm->VarMap[VarOrder[i]]->iDiffOrder = k;
    }
  }

  if (bRunMSS)
  {
    // update the differential index of the variables in the Eso
    for (i = 0; i < pDaeEso->m_nVars; i++) pDaeEso->m_index->m_daeIndex[i] = 1;

    pDaeEso->m_index->m_isHighIndex = false;
    for (i = 0; i < in_nVars; i++)
    {
      pDaeEso->m_index->m_daeIndex[VarOrder[i]] = differentialIndex[i] <= 0 ? 1 : differentialIndex[i];
      if (pDaeEso->m_index->m_daeIndex[i] > 1) 
        pDaeEso->m_index->m_isHighIndex = true;
    }
  }

#if 0
  printVec("MSS EAL", EAL, nAugmentedEqns);
  printVec("MSS assignedEqn", assignedEqn, nAugmentedVars);
  temp = new long[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) { temp[i] = (long) pDaeEso->m_index->m_daeIndex[i]; }
  printVec("diff index", (long*) temp, nAugmentedVars);
  DESTROY_VECTOR(temp);
  printVec("VarOrder", VarOrder, nAugmentedVars);
  printVec("EqnOrder", EqnOrder, nAugmentedEqns);
  printVec("MSS VAL", VAL, nAugmentedVars);
  printMat2(nAugmentedEqns, nAugmentedVars, edgeList_cNZCols, edgeList_ColIndices);
#endif

  if (pTransitionEso)
  {
    addTransitionEquations(fm, iEventEqn, oldEqns, nOldEqns, addEqnInfo);
    pDaeEso->RefreshEqnMap(*fm);
  }

  // get the transpose of the VarOrder vector so compressed equation indices can be determined from 
  // actual equation indices
  TransposeVector(VarOrder, nAugmentedVars, itVarOrder, max_var_index+1);

#if 0
  printVec("itVarOrder",itVarOrder, max_var_index+1);
#endif

  eqnSource[2] = eqnSource[1] + addEqnInfo.nEqns;

  if (addEqnInfo.nEqns > 0)
  {
    // determine the number of non-zero elements to add
    for (i = 0; i < addEqnInfo.nEqns; i++)
      addEqnInfo.nColIndices += pDaeEso->m_JacStruct->m_cNZCols[addEqnInfo.EqnIndices[i]] + pDaeEso->m_MassStruct->m_cNZCols[addEqnInfo.EqnIndices[i]];

    // dimension add vectors
    addEqnInfo.ColIndices = new long[addEqnInfo.nColIndices];
    addEqnInfo.cNZCols = new long[addEqnInfo.nEqns];
    addEqnInfo.spRowPage = new long[addEqnInfo.nEqns];
    addEqnInfo.nColIndices = 0;

    for (i = 0; i < addEqnInfo.nEqns; i++)
    {
      addEqnInfo.spRowPage[i] = addEqnInfo.nColIndices;
      addEqnInfo.cNZCols[i] = 0;
      k = pDaeEso->m_JacStruct->m_spRowPage[addEqnInfo.EqnIndices[i]];
      for (j = 0; j < pDaeEso->m_JacStruct->m_cNZCols[addEqnInfo.EqnIndices[i]]; j++)
      {
        if (itVarOrder[pDaeEso->m_JacStruct->m_ColIndices[k]] >= 0)
        {
          addEqnInfo.ColIndices[addEqnInfo.nColIndices++] = itVarOrder[pDaeEso->m_JacStruct->m_ColIndices[k]];
          addEqnInfo.cNZCols[i]++;
        }
        k++;
      }

      k = pDaeEso->m_MassStruct->m_spRowPage[addEqnInfo.EqnIndices[i]];
      for (j = 0; j < pDaeEso->m_MassStruct->m_cNZCols[addEqnInfo.EqnIndices[i]]; j++)
      {
        if (itVarOrder[pDaeEso->m_MassStruct->m_ColIndices[k]] >= 0)
        {
          if (VAL[itVarOrder[pDaeEso->m_MassStruct->m_ColIndices[k]]] >= 0)
          {
            addEqnInfo.ColIndices[addEqnInfo.nColIndices++] = VAL[itVarOrder[pDaeEso->m_MassStruct->m_ColIndices[k]]];
            addEqnInfo.cNZCols[i]++;
          }
        }
        k++;
      }
    }
  }

  // initialize other variables
  tr_ColIndices = new long[
    edgeList_nColIndices + 
    addEqnInfo.nColIndices + 
    edgeList_nColIndices 
    /* 
      edgeList_nColIndices is a guess because the following are still unknown:
        trimEqnInfo.nColIndices 
        trimConInfo.nVars
        trimConInfo.nDerVars
    */];
  tr_columnPageNumber = new long[
    nAugmentedEqns + 
    addEqnInfo.nEqns + 
    nAugmentedEqns
    /*
      nAugmentedEqns is a guess because the following are still unknown:
        trimEqnInfo.nEqns
        trimConInfo.nVars 
        trimConInfo.nDerVars
    */
    ];
  tr_cNZCols = new long[
    nAugmentedEqns + 
    addEqnInfo.nEqns + 
    nAugmentedEqns
    /*
      nAugmentedEqns is a guess because the following are still unknown:
        trimEqnInfo.nEqns
        trimConInfo.nVars 
        trimConInfo.nDerVars
    */
    ];
  tr_columnOrder = new long[nAugmentedVars];
  tr_rowOrder = new long[nAugmentedVars];
  tr_blockSizes = new long[nAugmentedVars];
  tr_cBlocks = 0;
  tr_orderMap = new long[nAugmentedVars];

  for (i = 0; i < edgeList_nColIndices; i++)
    tr_ColIndices[i] = edgeList_ColIndices[i];

  for (i = 0; i < nAugmentedVars; i++)
  {
    tr_columnOrder[i] = i;
    tr_rowOrder[i] = i;
  }

  if (!triangularizeMatrix(
        pDaeEso, VAL, EAL, eqnSource, pDaeEso->m_index->m_isHighIndex, nAugmentedEqns, nAugmentedVars, 
        edgeList_nColIndices, edgeList_ColIndices, edgeList_spRowPage, edgeList_cNZCols,
        tr_ColIndices, tr_columnPageNumber, tr_cNZCols, 
        assignedEqn, tr_columnOrder, tr_rowOrder, 
        tr_cBlocks, tr_blockSizes, tr_orderMap, fm->VarMap, EqnOrder, VarOrder, 
        addEqnInfo, trimEqnInfo, trimConInfo) )
  {  
    hr = E_FAIL;
    goto clean_up;
  }


#if 0
  printMat2(nAugmentedEqns, nAugmentedVars, tr_cNZCols, tr_ColIndices);
  printVec("tr_columnOrder", tr_columnOrder, nAugmentedVars);
  printVec("tr_rowOrder", tr_rowOrder, nAugmentedEqns);
  printVec("assignedEqn", assignedEqn, nAugmentedVars); 
#endif

  if (SUCCEEDED( CComObject<CIsCINlaEso>::CreateInstance(&pNlaEso) ))
  {
    pNlaEso->AddRef();

    pNlaEso->SetCIData(
      in_nVars, in_nEqns,
      nAugmentedVars, nAugmentedEqns,
      VarOrder, EqnOrder, VAL, itVAL,
      pDaeEso, pTransitionEso, iEventEqn);

    pNlaEso->SetTriangularizationData(
      tr_columnPageNumber, tr_cNZCols, tr_ColIndices,
      assignedEqn, tr_columnOrder, tr_rowOrder, 
      tr_cBlocks, tr_blockSizes, tr_orderMap);

    if (SUCCEEDED( CComObject<CIsNlaSolver>::CreateInstance(&pNlaSolver) ))
    {
      pNlaSolver->SetEso(static_cast<IIsNlaEso*> (pNlaEso) );
      pNlaEso->SetNlaSolver(static_cast<IIsNlaSolver*> (pNlaSolver));
    }
  }

  if (pNlaEso)
  {
    // cache the values before the reinitialization
    last_x = new double[pDaeEso->m_nActiveVars];
    last_xdot = new double[pDaeEso->m_nActiveVars];
    for (i = 0; i < pDaeEso->m_nActiveVars; i++)
    {
      last_x[i] = pDaeEso->m_y->m_varVal[i];
      last_xdot[i] = pDaeEso->m_y->m_varDotVal[i];
    }
    
    // invoke the NlaSolver to reinitialize the model
    hr = pNlaEso->Solve();

    // determine if any events were triggered by the reinitialization
    // TODO: determine the best place to call iCIEventDetection().  
    // It might make more sense to call it as each block is processed
    pDaeEso->iCIEventDetection(events, event_count, event_dim, last_x, last_xdot, pDaeEso->m_y->m_varVal, pDaeEso->m_y->m_varDotVal);
    // process the list of events detected
    for (i = 0; i < event_count; i++)
    {
      se = static_cast<state_event_item*> (events[i]);
      se->pEventEso->TriggerEvent(se->event_time, se->EventId, se->iEventEqn);
      delete se;
    }

  }

#if 0
  printVec("blockSizes", tr_blockSizes, tr_cBlocks);
#endif

  // remove g*() and R(), and add new state F() and G() equations
  if (pTransitionEso)
  {
    replaceTransitionEquations(fm, oldEqns, nOldEqns, newEqns, nNewEqns);
    pDaeEso->RefreshEqnMap(*fm);
  }

#if 0
  for (i = 0; i < pDaeEso->m_nActiveEqns; i++) ATLTRACE("\n%d\t%d",i,pDaeEso->m_ActiveEqns[i]);
#endif

  // update discontinuity variables
  double z;
  long iDiscVar, iActiveVar;
  long iActiveEqn, iMapEqn;
  long cEqns;
  bool validVal;

  iEqns = new long[pDaeEso->m_nActiveEqns];
  residuals = new double[pDaeEso->m_nActiveEqns];
  cEqns = 0;

  for (iActiveEqn = 0; iActiveEqn < pDaeEso->m_nActiveEqns; iActiveEqn++)
  {
    iMapEqn = pDaeEso->m_ActiveEqns[iActiveEqn];
    if (pDaeEso->m_EqnMap[iMapEqn].bDiscontinuous) iEqns[cEqns++] = iActiveEqn;
  }

  if (cEqns > 0)
  {
    pDaeEso->iGetResiduals(
      iEqns,
      cEqns, 
      pDaeEso->m_time->m_curVal,
      pDaeEso->m_y->m_varVal,
      pDaeEso->m_y->m_varDotVal,
      residuals,
      validVal,
      pDaeEso->m_realParameters,
      pDaeEso->m_integerParameters);
    
    for (i = 0; i < cEqns; i++)
    {
      iMapEqn = pDaeEso->m_ActiveEqns[iEqns[i]];
      iDiscVar = pDaeEso->m_EqnMap[iMapEqn].iDiscVar;
      iActiveVar = pDaeEso->m_itActiveVars[iDiscVar];
      z = pDaeEso->m_y->m_varVal[iDiscVar];
      pDaeEso->SetVariable(iActiveVar, z - residuals[i]);
      pDaeEso->SetLastVariable(iActiveVar, z - residuals[i]);
    }
  }

#if 1
  endTime = ((double)clock() / CLOCKS_PER_SEC);
  ATLTRACE("\ndt\t%f\ttime\t%f\tsimtime\t%f", endTime - startTime, endTime, pDaeEso->m_time->m_curVal);
#endif

clean_up:

  DESTROY_VECTOR(iEqns)
  DESTROY_VECTOR(residuals)

  DESTROY_VECTOR(in_VAL)
  DESTROY_VECTOR(in_edgeList_cNZCols)
  DESTROY_VECTOR(in_edgeList_spRowPage)
  DESTROY_VECTOR(in_edgeList_ColIndices)
  DESTROY_VECTOR(EqnMap)

  //DESTROY_VECTOR(assignedEqn)
  DESTROY_VECTOR(itAssignedEqn)
  //DESTROY_VECTOR(VAL)
  DESTROY_VECTOR(itVAL)
  DESTROY_VECTOR(itEAL)
  DESTROY_VECTOR(EAL)
  DESTROY_VECTOR(differentialIndex)
  DESTROY_VECTOR(EqnOrder)
  DESTROY_VECTOR(VarOrder)
  DESTROY_VECTOR(itVarOrder)
  DESTROY_VECTOR(DiscEqns)
  DESTROY_VECTOR(DiscVars)

  if (bRunMSS)
  {
    DESTROY_VECTOR(edgeList_spRowPage)
    DESTROY_VECTOR(edgeList_cNZCols)
    DESTROY_VECTOR(edgeList_ColIndices)
  }

  DESTROY_VECTOR(tr_ColIndices)
  DESTROY_VECTOR(tr_columnPageNumber)
  DESTROY_VECTOR(tr_cNZCols)
  DESTROY_VECTOR(tr_blockSizes)
  DESTROY_VECTOR(tr_orderMap)
  DESTROY_VECTOR(tr_columnOrder)
  DESTROY_VECTOR(tr_rowOrder)

  DESTROY_VECTOR(last_x)
  DESTROY_VECTOR(last_xdot)
  DESTROY_VECTOR(events)

  if (FAILED(hr) && m_bRetryInitialization)
    goto _retry_initialization;

  return hr;
}

STDMETHODIMP COnModelExec::get_RetryInitialization(VARIANT_BOOL* bVal)
{
  *bVal = m_bRetryInitialization ? VARIANT_TRUE : VARIANT_FALSE;
  return S_OK;
}

STDMETHODIMP COnModelExec::put_RetryInitialization(VARIANT_BOOL bVal)
{
  m_bRetryInitialization = (bVal == VARIANT_TRUE);
  return S_OK;
}


void COnModelExec::reportInitializationEqnInfo(
  bool bFault,
  InitStage stage,
  CIsDaeEsoBase* pDaeEso,
  long nEqns,
  long nVars,
  long* spRowPage, 
  long* cNZCols,
  long nColIndices,
  long* ColIndices,
  long* EqnOrder, 
  long* VarOrder, 
  long* VAL,
  long* EAL,
  long* AssignedEqn)
{
  SAFEARRAY* psaSpRowPage = NULL;
  SAFEARRAY* psaEqnNames = NULL;
  SAFEARRAY* psaVarNames = NULL;
  SAFEARRAY* psaCNZCols = NULL;
  SAFEARRAY* psaColIndices = NULL;
  SAFEARRAY* psaEqnOrder = NULL;
  SAFEARRAY* psaVarOrder = NULL;
  SAFEARRAY* psaVAL = NULL;
  SAFEARRAY* psaEAL = NULL;
  SAFEARRAY* psaAssignedEqn = NULL;
  SAFEARRAY* psaResVals = NULL;
  long i;

  long* t_spRowPage = NULL;
  long* t_cNZCols = NULL;
  long* t_colIndices = NULL;
  long* t_EqnOrder = NULL;
  long* t_VarOrder = NULL;
  long* t_VAL = NULL;
  long* t_EAL = NULL;
  long* t_AssignedEqn = NULL;
  double* t_ResVals = NULL;

  CIsDaeEsoCImpl* pCImpl = static_cast<CIsDaeEsoCImpl*> (pDaeEso);
  pCImpl->GetEqnNames( &psaEqnNames);
  pCImpl->GetVarNames( &psaVarNames);
  
  psaSpRowPage = SafeArrayCreateVector(VT_I4, 0, nEqns);
  psaCNZCols = SafeArrayCreateVector(VT_I4, 0, nEqns);
  psaColIndices = SafeArrayCreateVector(VT_I4, 0, nColIndices);
  psaEqnOrder = SafeArrayCreateVector(VT_I4, 0, pDaeEso->m_nEqns);
  psaVarOrder = SafeArrayCreateVector(VT_I4, 0, pDaeEso->m_nVars);
  psaVAL = SafeArrayCreateVector(VT_I4, 0, nVars);
  psaEAL = SafeArrayCreateVector(VT_I4, 0, nEqns);
  psaAssignedEqn = SafeArrayCreateVector(VT_I4, 0, nVars);
  psaResVals = SafeArrayCreateVector(VT_R8, 0, nVars);

  SafeArrayAccessData(psaSpRowPage, (void HUGEP* FAR*)& t_spRowPage);
  SafeArrayAccessData(psaCNZCols, (void HUGEP* FAR*)& t_cNZCols);
  SafeArrayAccessData(psaColIndices, (void HUGEP* FAR*)& t_colIndices);
  SafeArrayAccessData(psaEqnOrder, (void HUGEP* FAR*)& t_EqnOrder);
  SafeArrayAccessData(psaVarOrder, (void HUGEP* FAR*)& t_VarOrder);
  SafeArrayAccessData(psaVAL, (void HUGEP* FAR*)& t_VAL);
  SafeArrayAccessData(psaEAL, (void HUGEP* FAR*)& t_EAL);
  SafeArrayAccessData(psaAssignedEqn, (void HUGEP* FAR*)& t_AssignedEqn);
  SafeArrayAccessData(psaResVals, (void HUGEP* FAR*)& t_ResVals);

  for (i = 0; i < nEqns; i++)
  {
    t_spRowPage[i] = spRowPage[i];
    t_cNZCols[i] = cNZCols[i];
  }

  if (EAL)
  {
    for (i = 0; i < nEqns; i++) t_EAL[i] = EAL[i];
  }

  for (i = 0; i < pDaeEso->m_nEqns; i++) t_EqnOrder[i] = EqnOrder[i];
  for (i = 0; i < pDaeEso->m_nVars; i++) t_VarOrder[i] = VarOrder[i];


  for (i = 0; i < nVars; i++)
  {
    t_VAL[i] = VAL[i];
    t_AssignedEqn[i] = AssignedEqn[i];
  }

  for (i = 0; i < nColIndices; i++)
  {
    t_colIndices[i] = ColIndices[i];
  }

  bool validVal = true;
  pDaeEso->iGetAllResiduals(
    pDaeEso->m_time->m_curVal,
    pDaeEso->m_y->m_varVal,
    pDaeEso->m_y->m_varDotVal,
    t_ResVals,
    validVal,
    pDaeEso->m_realParameters,
    pDaeEso->m_integerParameters);
  
  SafeArrayUnaccessData(psaSpRowPage);
  SafeArrayUnaccessData(psaCNZCols);
  SafeArrayUnaccessData(psaColIndices);
  SafeArrayUnaccessData(psaEqnOrder);
  SafeArrayUnaccessData(psaVarOrder);
  SafeArrayUnaccessData(psaVAL);
  SafeArrayUnaccessData(psaEAL);
  SafeArrayUnaccessData(psaAssignedEqn);
  SafeArrayUnaccessData(psaResVals);

  DispatchProxy::Fire_InitializationInfo(
    bFault,
    stage,
    pDaeEso->m_nEqns,
    pDaeEso->m_nVars,
    pDaeEso->m_nActiveEqns,
    pDaeEso->m_nActiveVars, 
    nEqns,
    nVars,
    psaEqnNames, 
    psaVarNames, 
    nColIndices,
    psaCNZCols,
    psaSpRowPage,
    psaColIndices,
    psaEqnOrder, 
    psaVarOrder, 
    psaVAL,
    psaEAL,
    psaAssignedEqn,
    pDaeEso->m_y->m_psa_varVal,
    pDaeEso->m_y->m_psa_varDotVal,
    psaResVals);

  VTableProxy::Fire_InitializationInfo(
    bFault,
    stage,
    pDaeEso->m_nEqns,
    pDaeEso->m_nVars,
    pDaeEso->m_nActiveEqns,
    pDaeEso->m_nActiveVars, 
    nEqns,
    nVars,
    psaEqnNames, 
    psaVarNames, 
    nColIndices,
    psaCNZCols,
    psaSpRowPage,
    psaColIndices,
    psaEqnOrder, 
    psaVarOrder, 
    psaVAL,
    psaEAL,
    psaAssignedEqn,
    pDaeEso->m_y->m_psa_varVal,
    pDaeEso->m_y->m_psa_varDotVal,
    psaResVals);

  // local cleanup
  SafeArrayDestroy(psaEqnNames);
  SafeArrayDestroy(psaVarNames);

  SafeArrayDestroy(psaSpRowPage);
  SafeArrayDestroy(psaCNZCols);
  SafeArrayDestroy(psaColIndices);
  SafeArrayDestroy(psaEqnOrder);
  SafeArrayDestroy(psaVarOrder);
  SafeArrayDestroy(psaVAL);
  SafeArrayDestroy(psaEAL);
  SafeArrayDestroy(psaAssignedEqn);
  SafeArrayDestroy(psaResVals);
}

void COnModelExec::replaceEquations(long* assignedEqn, FlatModel* fm, long* oldEqns, long nOldEqns, long* newEqns, long nNewEqns)
{
  long i, j;

  // disable old G() and F() equations
  // g*() and R() will be added in addTransitionEquations()
  for (i = 0; i < nOldEqns; i++) 
  {
    fm->EqnMap[oldEqns[i]]->bActive = false;
    // update the output assignment by removing references to the old equations
    if (assignedEqn)
    {
      for (j = 0; j < fm->nVars; j++)
      {
        if (oldEqns[i] == assignedEqn[j])
        {
          assignedEqn[j] = -1;
          break;
        }
      }
    }
  }

  // enable F() of new state
  for (i = 0; i < nNewEqns; i++)
  {
    if (fm->EqnMap[newEqns[i]]->bDiscontinuous || fm->EqnMap[newEqns[i]]->bReset)  
      fm->EqnMap[newEqns[i]]->bActive = false;
    else
      fm->EqnMap[newEqns[i]]->bActive = true;
  }
}

void COnModelExec::addTransitionEquations(FlatModel* fm, long iEventEqn, long* oldEqns, long nOldEqns, addEquationInfo& addEqnInfo)
{
  long i, j;
  bool bFound;

  addEqnInfo.nEqns = 0;
  if (!addEqnInfo.EqnIndices) addEqnInfo.EqnIndices = new long[nOldEqns];

  // enable g*() and R() 
  for (i = 0; i < nOldEqns; i++)
  {
    if (fm->EqnMap[oldEqns[i]]->bReset || oldEqns[i] == iEventEqn)
    {
      if (!fm->EqnMap[oldEqns[i]]->bUndefined)
      {
        bFound = false;
        for (j = 0; j < addEqnInfo.nEqns; j++) 
        { 
          if (addEqnInfo.EqnIndices[j] == oldEqns[i]) 
          {
            bFound = true;
            break;
          }
        }
      
        if (!bFound)
        {
          addEqnInfo.EqnIndices[addEqnInfo.nEqns++] = oldEqns[i];
          fm->EqnMap[oldEqns[i]]->bActive = true;
        }
      }
    }
  }
}

void COnModelExec::replaceTransitionEquations(FlatModel* fm, long* oldEqns, long nOldEqns, long* newEqns, long nNewEqns)
{
  long i;

  // disable g*() and R() of transition Eso
  for (i = 0; i < nOldEqns; i++)
  {
    if (fm->EqnMap[oldEqns[i]]->bDiscontinuous || fm->EqnMap[oldEqns[i]]->bReset)
      fm->EqnMap[oldEqns[i]]->bActive = false;
  }

  // enable G() of newEsos
  for (i = 0; i < nNewEqns; i++)
  {
    if (fm->EqnMap[newEqns[i]]->bDiscontinuous) fm->EqnMap[newEqns[i]]->bActive = true;
  }
}

void COnModelExec::ResizeCompactStructure(
  long nOldEqns, 
  long nOldColIndices, 
  long nNewEqns, 
  long nNewColIndices,
  long*& ColIndices, 
  long*& cNZCols, 
  long*& spRowPage)
{
  // copy the vectors created for MSS and resize the edgeList
  long i;
  long* t_spRowPage = new long[nNewEqns];
  long* t_cNZCols = new long[nNewEqns];
  long* t_ColIndices = new long[nNewColIndices];

  for (i = nOldEqns; i < nNewEqns; i++)
  {
    t_spRowPage[i] = 0;
    t_cNZCols[i] = 0;
  }

  for (i = 0; i < nOldEqns; i++)
  {
    t_spRowPage[i] = spRowPage[i];
    t_cNZCols[i] = cNZCols[i];
  }

  for (i = 0; i < nOldColIndices; i++)
    t_ColIndices[i] = ColIndices[i];

  for (i = nOldColIndices; i < nNewColIndices; i++)
    t_ColIndices[i] = -1;

  spRowPage = t_spRowPage;
  cNZCols = t_cNZCols;
  ColIndices = t_ColIndices;
}

#if 0
bool COnModelExec::initEqns(long nDaeEsoEqns, long nDaeEsoVars, long nDaeEsoAugmentedVars, 
  long nAugmentedEqns, long nAugmentedVars, long* DaeEsoVarOrder,
  long* VAL, long* EAL, 
  long edgeList_nColIndices, long* edgeList_spRowPage, long* edgeList_cNZCols, long* edgeList_ColIndices, 
  EqnStruct*& EqnStructs, long& nEqnStructs)
{

  long i, j, k;
  long iEqn, iVar, nEqnVars;
  long iSourceEqn;
  long* itVAL = NULL;         // transpose of VAL
  long* itEAL = NULL;         // transpose of EAL
  long* VarDiffOrder = NULL;  // derivative order
  long* EqnDiffOrder = NULL;  // equation order
  EqnStruct* pEqn;
  EqnVarStruct* pVar;
  long max_VAL = nAugmentedVars;
  long max_EAL = nAugmentedVars;
  for (i = 0; i < nAugmentedVars; i++) max_VAL = IMAX(VAL[i], max_VAL);
  TransposeVector(VAL, nAugmentedVars, itVAL, max_VAL);
  for (i = 0; i < nAugmentedEqns; i++) max_EAL = IMAX(EAL[i], max_EAL);
  TransposeVector(EAL, nAugmentedEqns, itEAL, max_EAL);
  DiffOrder(itVAL, nAugmentedVars, VarDiffOrder);
  DiffOrder(itEAL, nAugmentedEqns, EqnDiffOrder);

#if 0
  printVec("itVAL",itVAL, nAugmentedVars);
  printVec("itEAL",itEAL, nAugmentedEqns);
  printVec("VarDiffOrder",VarDiffOrder, nAugmentedVars);
  printVec("EqnDiffOrder",EqnDiffOrder, nAugmentedEqns);
#endif

  // calculate derivatives of source function as follows:
  //   dfi/dt -> look in edge list for variable dependencies on equation i

  //   chain rule:   dfi/dt = dfi/dj * dj/dt for each equation to variable edge
  
  //     get dfi/dj from jacobian if i < in_nEqns && j < in_nVars, 
  //         otherwise calculate numerically by perturbing j with h*jd
  
  //     get dfi/d2j from mass if i < in_nEqns && j < in_nVars,
  //         otherwise calculate numerically by perturbing jd with h*jdd

  //     get dj/dt by getting derivative of j from VAL

  nEqnStructs = nAugmentedEqns - nDaeEsoEqns;
  EqnStructs = new EqnStruct[nEqnStructs];
  for (i = 0; i < nEqnStructs; i++)
  {
    iEqn = i + nDaeEsoEqns;
    iSourceEqn = itEAL[iEqn];
    nEqnVars = edgeList_cNZCols[iSourceEqn];
    EqnStructs[i].Init(nEqnVars);
    pEqn = &EqnStructs[i];
    pEqn->iEqn = iEqn;
    pEqn->iSourceEqn = iSourceEqn;
    pEqn->diffOrder = EqnDiffOrder[iEqn];

#if 0
    sprintf(buffer, "\n\nf%d = df%d/dt = ",iEqn, iSourceEqn); ATLTRACE(buffer);
#endif

    // for each variable association, dfi/dt += dfi/dj * dj/dt where i = iSourceEqn
    // var index        iVar (from edge list)
    // dfi/dj type:     dfi_dj_type { jacobian = 0, mass = 1, numeric = 2 } 
    // dfi/dj index:    dfi_dj_index { ij = var_index, im = itVAL[var_index], in = VAL[var_index] }
    // dj/dt var index: dj_dt_index

    for (j = 0; j < nEqnVars; j++)
    {
      k = edgeList_spRowPage[iSourceEqn] + j;
      iVar = edgeList_ColIndices[k];
      pVar = pEqn->EqnVars[j];
      pVar->iNlaEsoVar = iVar;
      pVar->diffOrder = VarDiffOrder[iVar];
      // DaeEsoVarOrder vector only goes up to nDaeEsoAugmentedVars in length
      if (pVar->diffOrder == 0)
      {
        pVar->dfi_dj_source = JAC_SOURCE_JACOBIAN;
        if (iVar < nDaeEsoAugmentedVars) 
          pVar->iDaeEsoVar = DaeEsoVarOrder[iVar];
      }
      else if (pVar->diffOrder == 1)
      {
        pVar->dfi_dj_source = JAC_SOURCE_MASS;
        if (itVAL[iVar] >= 0 && itVAL[iVar] < nDaeEsoAugmentedVars) 
          pVar->iDaeEsoVar = DaeEsoVarOrder[itVAL[iVar]];
      }
      pVar->dj_dt_iNlaEsoVar = VAL[iVar];
      if (iSourceEqn >= nDaeEsoEqns || pVar->iDaeEsoVar < 0 || pVar->diffOrder > 1)
        pVar->dfi_dj_source = JAC_SOURCE_NUMERIC;

#if 0
      sprintf(buffer, "df%d/d%d (%s[%d]) * d%d/dt ([%d])",
        iSourceEqn, 
        pVar->iNlaEsoVar, 
        (pVar->dfi_dj_source == JAC_SOURCE_JACOBIAN) ? "j" : ((pVar->dfi_dj_source == JAC_SOURCE_MASS) ? "m" : "n"),
        pVar->iDaeEsoVar, 
        pVar->iNlaEsoVar, 
        pVar->dj_dt_iNlaEsoVar);
      ATLTRACE(buffer);
      if (j<(nEqnVars-1)) { sprintf(buffer, " + "); ATLTRACE(buffer); }
#endif
    }
  }

  return true;
}
#endif


////////////////////////////////////////////////////////////////////
// DiffOrder
//
// calculates the differential order of variables or equations from
// the transpose of an VAL or EAL
//
// itAL - transpose of an equation or variable association list
// diffOrder - allocated automatically if NULL
//
void COnModelExec::DiffOrder(long* itAL, long size, long*& diffOrder)
{
  long i, j;

  if (diffOrder == NULL) diffOrder = new long[size];
  for (i = 0; i < size; i++)
  {
    diffOrder[i] = 0;
    j = itAL[i];
    if (j >= 0 && j < size) 
    { 
      do 
      { 
        j = itAL[j]; 
        diffOrder[i]++; 
      } while (j >= 0); 
    }
  }
}











/*****************************************************************
*
*  triangularizeMatrix function
*
*****************************************************************/

/////////////////////////////////////////////////////////////////
// triangularizeMatrix
//
// - all vectors allocated by calling program
// - input matrix does not have to be square, but nVars must be >= nEqns
// - input matrix must be in [nEqns][nVars] format
//
/////////////////////////////////////////////////////////////////
bool COnModelExec::triangularizeMatrix(
  CIsDaeEsoBase* pDaeEso,
  long* VAL,
  long* EAL,
  long* eqnSource,
  bool bHighIndex,
  long& nEqns,                  // [in]       (scalar)
  long& nVars,                  // [in]       (scalar)
  long nColumnIndices,          // [in]       (scalar)
  long* in_columnIndices,       // [in]       [nColumnIndices]
  long* in_columnPageNumber,    // [in]       [nEqns]
  long* in_cRowNZ,              // [in]       [nEqns]
  long* out_columnIndices,      // [in, out]  [nColumnIndices]
  long* out_columnPageNumber,   // [in, out]  [nEqns]
  long* out_cRowNZ,             // [in, out]  [nEqns]
  long* assignedEqn,            // [in, out]  [nVars]
  long* columnOrder,            // [in, out]  [nVars] (initial order defined)
  long* rowOrder,               // [in, out]  [nVars] (initial order defined)
  long& out_cBlocks,            // [in, out]  (scalar)
  long* out_blockSizes,         // [in, out]  [vVar]
  long* out_orderMap,
  ModelVarMap** VarMap,
  long* EqnOrder,
  long* VarOrder,
  addEquationInfo& addEqnInfo, 
  trimEquationInfo& trimEqnInfo, 
  trimConstraintInfo& trimConInfo)
{
  bool bReturn;
  long i, j, k, m;

  long* orderMap = NULL;              // local order map (tarjan return reversed order)
  long* blockSizes = NULL;            // local blockSizes 

  long* Eq2EqColTranspose = NULL;     // Eq2Eq column transpose for problem matrix
  long* CT_columnIndices = NULL;      // problem matrix with Eq2Eq transposed columns

  long nRowIndices;                   // Eq2Eq problem matrix columns Orderped to rows
  long* rowIndices = NULL;            // Eq2Eq problem matrix columns Orderped to rows
	long* rowPageNumber = NULL;         // Eq2Eq problem matrix columns Orderped to rows
	long* cColNZ = NULL;                // Eq2Eq problem matrix columns Orderped to rows

  bool bAllocateSquareMatrix = (nVars > nEqns);
  long* s_columnIndices = NULL;
  long* s_columnPageNumber = NULL;
  long* s_cRowNZ = NULL;
  long s_nColumnIndices;

  long* result_orderMap = NULL;
  long* result_blockSizes = NULL;
  long* result_columnIndices = NULL;
  long* result_columnPageNumber = NULL;
  long* result_cRowNZ = NULL;

#if 0
// print original matrix
  printNote("original matrix\n");
  printMatWithOrder(nEqns, nVars, in_cRowNZ, in_columnIndices, columnOrder, rowOrder);
#endif

// ensure matrix is square
  if (bAllocateSquareMatrix)
  {
    /* 
      trimEqnInfo.nColIndices, trimConInfo.nVars, trimConInfo.nDerVars are still unknown, so
      nColumnIndices is used as a guess.
    */
    s_nColumnIndices = nColumnIndices + nVars - nEqns + addEqnInfo.nColIndices + nColumnIndices;
    s_columnIndices = new long[s_nColumnIndices];
    s_columnPageNumber = new long[nVars];
    s_cRowNZ = new long[nVars];
    
    FillSquareMatrix(bHighIndex, nEqns, nVars, nColumnIndices, 
                     in_columnPageNumber, in_cRowNZ, in_columnIndices,
                     VarMap, VarOrder, assignedEqn,
                     s_columnPageNumber, s_cRowNZ, s_columnIndices, s_nColumnIndices);
  }
  else
  {
    s_nColumnIndices = nColumnIndices;
    s_columnIndices = in_columnIndices;
    s_columnPageNumber = in_columnPageNumber;
    s_cRowNZ = in_cRowNZ;
  }

// fill in remaining columns of rowOrder vector
  for (i = nEqns; i < nVars; i++)
    rowOrder[i] = i;

#if 0
  printVec("assignedEqn", assignedEqn, nVars);
#endif

  // equation assignments to equation indices >= nEqns are continuity assignments
  // continuity assignments must be cleared so they can be reevaluated, particularly for the g* equation
  // NOTE: there is no significant expense incurred in doing this reassignment as most will be picked up
  //       by the continuity equations that have only 1 edge anyways (no brainer assignments).
  for (i = 0; i < nVars; i++)
  {
    if (assignedEqn[i] >= nEqns) 
      assignedEqn[i] = -1;
  }

#if 0
  printMat2(nVars, nVars, s_cRowNZ, s_columnIndices);
  printVec("assignedEqn", assignedEqn, nVars);
#endif

// calculate the assigned variables
  bReturn = assignVariables(nVars, nVars, s_cRowNZ, s_columnPageNumber, s_columnIndices, assignedEqn);
  if (!bReturn)
  {
    // try doing the output assignment from scratch
    for (i = 0; i < nVars; i++) assignedEqn[i] = -1;
    bReturn = assignVariables(nVars, nVars, s_cRowNZ, s_columnPageNumber, s_columnIndices, assignedEqn);
  }

  if (!bReturn)
  {
#if 0
    // first output assignment failed.  Report it to the user
    reportInitializationEqnInfo(
      true,
      InitStage_Reset,
      pDaeEso,
      nEqns,
      nVars,
      in_columnPageNumber,
      in_cRowNZ,
      nColumnIndices,
      in_columnIndices,
      EqnOrder, 
      VarOrder, 
      VAL,
      EAL,
      assignedEqn);
#endif
  }
  else if (addEqnInfo.nEqns == 0)
  {
    // report on equation and variable info in model for first model initialization
#if 0

    reportInitializationEqnInfo(
      false,
      InitStage_Trim,
      pDaeEso,
      nEqns,
      nVars,
      s_columnPageNumber,
      s_cRowNZ,
      s_nColumnIndices,
      s_columnIndices,
      EqnOrder, 
      VarOrder, 
      VAL,
      EAL,
      assignedEqn);

    CComBSTR bstrMsg = L"Define initialization constraints";
    DispatchProxy::Fire_ShowDialog(bstrMsg);
    VTableProxy::Fire_ShowDialog(bstrMsg);

    DispatchProxy::Fire_GetTrimEqns(trimEqnInfo);
    VTableProxy::Fire_GetTrimEqns(trimEqnInfo);

    DispatchProxy::Fire_GetTrimVars(trimConInfo);
    VTableProxy::Fire_GetTrimVars(trimConInfo);

#endif
  }


#if 0
  printVec("assignedEqn", assignedEqn, nVars);
#endif

  if (bReturn && (addEqnInfo.nEqns + trimEqnInfo.nEqns + trimConInfo.nVars) > 0)
  {
    long c;
    long add_nColIndices = addEqnInfo.nColIndices + trimEqnInfo.nColIndices + trimConInfo.nVars;
    long add_nEqns = addEqnInfo.nEqns + trimEqnInfo.nEqns + trimConInfo.nVars;
    long add_nVars = 0;
    long* add_cNZCols = new long[add_nEqns];
    long* add_spRowPage = new long[add_nEqns];
    long* add_ColIndices = new long[add_nColIndices];
    
    // merge the ColIndices
    for (i = 0; i < addEqnInfo.nColIndices; i++) add_ColIndices[i] = addEqnInfo.ColIndices[i];
    c = addEqnInfo.nColIndices;
    for (i = 0; i < trimEqnInfo.nColIndices; i++) add_ColIndices[c + i] = trimEqnInfo.ColIndices[i];
    c += trimEqnInfo.nColIndices;
    for (i = 0; i < trimConInfo.nVars; i++) add_ColIndices[c + i] = trimConInfo.VarIds[i];
    c += trimConInfo.nVars;
    //for (i = 0; i < trimConInfo.nDerVars; i++) add_ColIndices[c + i] = VAL[trimConInfo.DerVarIds[i]];

    // merge the spRowPage and cNZCols
    add_nColIndices = 0;
    for (i = 0; i < addEqnInfo.nEqns; i++) 
    {
      add_cNZCols[i] = addEqnInfo.cNZCols[i];
      add_spRowPage[i] = add_nColIndices;
      add_nColIndices += addEqnInfo.cNZCols[i];
    }
    c = addEqnInfo.nEqns;
    for (i = 0; i < trimEqnInfo.nEqns; i++) 
    {
      add_cNZCols[i+c] = trimEqnInfo.cNZCols[i];
      add_spRowPage[i+c] = add_nColIndices;
      add_nColIndices += trimEqnInfo.cNZCols[i];
    }
    c +=  trimEqnInfo.nEqns;
    for (i = 0; i < trimConInfo.nVars; i++) 
    {
      add_cNZCols[i+c] = 1;
      add_spRowPage[i+c] = add_nColIndices++;
    }
    c +=  trimConInfo.nVars;

    long* tVars = new long[nVars];
    long* add_Vars = new long[add_nColIndices];
    long* it_add_Vars = NULL;
    long* it_add_ColIndices = new long[add_nColIndices];
    long* add_assignedEqn = new long[add_nColIndices];
    long* tColIndices = new long[s_nColumnIndices];
    bool* bRemovedEqns = new bool[nVars];
    long* iReplacedEqns = new long[nVars];
    
    long iVar;
    long iEqn;
    long spRowPage;
    long cNZ;
    long nColIndices;
    long nModelEqnsDiscarded = 0;

    for (i = 0; i < s_nColumnIndices; i++) tColIndices[i] = s_columnIndices[i];
    for (i = 0; i < nVars; i++) bRemovedEqns[i] = false;
    for (i = 0; i < add_nColIndices; i++) add_assignedEqn[i] = -1;
    for (i = 0; i < nVars; i++) tVars[i] = 0;
    for (i = 0; i < add_nColIndices; i++) tVars[add_ColIndices[i]]++;
    for (i = 0; i < nVars; i++) if (tVars[i] > 0) add_Vars[add_nVars++] = i;
    TransposeVector(add_Vars, add_nVars, it_add_Vars, nVars);

    for (i = 0; i < add_nColIndices; i++) it_add_ColIndices[i] = it_add_Vars[add_ColIndices[i]];

    bReturn = assignVariables(add_nEqns, add_nVars, add_cNZCols, add_spRowPage, it_add_ColIndices, add_assignedEqn);

    if (!bReturn)
    {
      // second output assignment failed.  Report it to the user
      reportInitializationEqnInfo(
        true,
        InitStage_Trim,
        pDaeEso,
        add_nEqns,
        nVars,
        add_spRowPage, 
        add_cNZCols,
        add_nColIndices,
        add_ColIndices,
        EqnOrder, 
        VarOrder, 
        VAL,
        EAL,
        add_assignedEqn);
    }

    if (bReturn)
    {
      // merge the two output assignments      
      for (i = 0; i < add_nVars; i++) 
      {
        if (add_assignedEqn[i] >= 0)
        {
          iVar = add_Vars[i];
          iEqn = assignedEqn[iVar];
          if (iEqn < nEqns) nModelEqnsDiscarded++;
          bRemovedEqns[iEqn] = true;
          iReplacedEqns[iEqn] = add_assignedEqn[i];
          EqnOrder[iEqn] = addEqnInfo.EqnIndices[add_assignedEqn[i]];
        }
      }

      nColIndices = 0;
      for (iEqn = 0; iEqn < nVars; iEqn++)
      {
        spRowPage = s_columnPageNumber[iEqn];
        cNZ = s_cRowNZ[iEqn];

        s_columnPageNumber[iEqn] = nColIndices;
        s_cRowNZ[iEqn] = 0;

        if (!bRemovedEqns[iEqn])
        {
          for (j = 0; j < cNZ; j++)
          {
            s_columnIndices[nColIndices++] = tColIndices[spRowPage + j];
            s_cRowNZ[iEqn]++;
          }
        }
        else
        {
          spRowPage = add_spRowPage[iReplacedEqns[iEqn]];
          cNZ = add_cNZCols[iReplacedEqns[iEqn]];

          for (j = 0; j < cNZ; j++)
          {
            s_columnIndices[nColIndices++] = add_ColIndices[spRowPage + j]; 
            s_cRowNZ[iEqn]++;
          }
        }
      }
      
      // bump the number of equations
      nEqns += add_nEqns - nModelEqnsDiscarded;
      s_nColumnIndices = nColIndices;
    }

    DESTROY_VECTOR(add_cNZCols)
    DESTROY_VECTOR(add_spRowPage)
    DESTROY_VECTOR(add_ColIndices)

    DESTROY_VECTOR(tVars)
    DESTROY_VECTOR(add_Vars)
    DESTROY_VECTOR(it_add_Vars)
    DESTROY_VECTOR(it_add_ColIndices)
    DESTROY_VECTOR(add_assignedEqn)
    DESTROY_VECTOR(tColIndices)
    DESTROY_VECTOR(bRemovedEqns)
    DESTROY_VECTOR(iReplacedEqns)
  }

#if 0
  printVec("assignedEqn", assignedEqn, nVars);
  printVec("s_spRowPage", s_columnPageNumber, nVars);
  printVec("s_cNZ", s_cRowNZ, nVars);
  printMat2(nVars, nVars, s_cRowNZ, s_columnIndices);
#endif

  
  if (bReturn)
  {

// allocate vectors to shuffle columns so 1's appear on diagonal
    Eq2EqColTranspose = new long[nVars];
    CT_columnIndices = new long[s_nColumnIndices];
    
// calculate eqn2eqn transpose using assignedEqn results
    for (i = 0; i < nVars; i++) Eq2EqColTranspose[assignedEqn[i]] = i;

#if 0
    printVec("assignedEqn",assignedEqn, nVars);
    printVec("itAssignedEqn", Eq2EqColTranspose, nVars);
#endif

    OrderMatrixColumns(nVars, s_nColumnIndices, Eq2EqColTranspose, s_columnIndices, CT_columnIndices);
    OrderVector(nVars, Eq2EqColTranspose, columnOrder, columnOrder);

#if 0
    printNote("matrix with columns reordered");
    printMat(nVars, nVars, s_cRowNZ, CT_columnIndices);
#endif

// generate row-wise matrix (passed to tarjan)
    nRowIndices = s_nColumnIndices;
    rowIndices = new long[s_nColumnIndices];
	  rowPageNumber = new long[nVars];
	  cColNZ = new long[nVars];

    TransposeMatrix(nVars, nVars, s_nColumnIndices, 
                    s_columnPageNumber, s_cRowNZ, CT_columnIndices, 
                    rowPageNumber, cColNZ, rowIndices);

#if 0
    printNote("matrix transposed in row order");
    printMat(nVars, nVars, cColNZ, rowIndices);
#endif

// call to tarjan
    orderMap = new long[nVars];
    blockSizes = new long[nVars];
    result_orderMap = new long[nVars];
    result_blockSizes = new long[nVars];
	  tarjan(nVars, rowIndices, nRowIndices, rowPageNumber, cColNZ, orderMap, out_cBlocks, blockSizes);

// put blocks in correct order
	  k = nVars-1;
	  for (i = out_cBlocks-1; i >= 0; i--)
	  {
		  result_blockSizes[out_cBlocks-i-1] = blockSizes[i];
		  for (j = 0; j < blockSizes[i]; j++)
		  {
			  result_orderMap[nVars-k-1] = orderMap[k];
			  k--;
		  }
	  }

#if 0
    printNote("*** solution ***");
    printVec("orderMap", result_orderMap, nVars);
#endif

    result_columnIndices = new long[s_nColumnIndices];
    result_columnPageNumber = new long[nVars];
    result_cRowNZ = new long[nVars];
    OrderMatrixColumns(nVars, s_nColumnIndices, result_orderMap, CT_columnIndices, result_columnIndices);
    OrderMatrixRows(nVars, nVars, s_nColumnIndices, result_orderMap, 
                    s_columnPageNumber, s_cRowNZ, result_columnIndices, 
                    result_columnPageNumber, result_cRowNZ, result_columnIndices);

#if 0
    printNote("block triangular matrix");
    printMat(nVars, nVars, result_cRowNZ, result_columnIndices);
#endif

// write out the order map
    long* offset = new long[nVars];
    long iOffset = 0;
    for (i = 0; i < nVars; i++)
    {
      offset[i] = iOffset;
      if (EqnOrder[i] < 0) iOffset++;
    }

    long cOut = 0;
    long cResult = 0;
    long iBlock;
    long iRow;
    for (iBlock = 0; iBlock < out_cBlocks; iBlock++)
    {
      out_blockSizes[iBlock] = 0;
    
      // finish updating the output map for the now square block
      for (j = 0; j < result_blockSizes[iBlock]; j++)
      {
        if (EqnOrder[rowOrder[result_orderMap[cResult]]] >= 0)
        {
          out_blockSizes[iBlock]++;
          iRow = rowOrder[result_orderMap[cResult]];
          out_orderMap[cOut++] = iRow - offset[iRow];
        }
        cResult++;
      }
    }

// order the column and row vectors
    OrderVector(nVars, result_orderMap, columnOrder, columnOrder);
    OrderVector(nVars, result_orderMap, rowOrder, rowOrder);

// write out the result matrix
    k = 0;
    m = 0;
    long iEqn = 0;

    for (i = 0; i < nVars; i++)
    {
      if (EqnOrder[rowOrder[i]] >= 0)
      {
        out_columnPageNumber[iEqn] = m;
        out_cRowNZ[iEqn] = 0;
        for (j = 0; j < result_cRowNZ[i]; j++)
        {
          out_columnIndices[m++] = result_columnIndices[k++]; 
          out_cRowNZ[iEqn]++;
        }
        iEqn++;
      }
      else
      {
        k += result_cRowNZ[i];
      }
    }

// write out the rowOrder vector
    for (i = 0, j = 0; i < nVars; i++)
    {
      iRow = rowOrder[i];
      if (EqnOrder[iRow] >= 0) 
        rowOrder[j++] = iRow - offset[iRow];
    }

    for (i = 0; i < nVars; i++)
    {
      j = assignedEqn[i];
      if (EqnOrder[j] >= 0)
        assignedEqn[i] = j - offset[j];
      else
        assignedEqn[i] = nEqns; 
    }

// write out the equation order vector
    for (i = 0, j = 0; i < nVars; i++)
    {
      if (EqnOrder[i] >= 0)
        EqnOrder[j++] = EqnOrder[i];
    }

    DESTROY_VECTOR(offset)


#if 0
    printNote("block outputs");
    printEqnBlocks(nVars, out_cBlocks, out_blockSizes, out_orderMap);
    printMat2(nEqns, nVars, out_cRowNZ, out_columnIndices);
    printVec("assignedEqn", assignedEqn, nVars);
    //printMatWithOrder(nEqns, nVars, out_cRowNZ, out_columnIndices, columnOrder, rowOrder);
#endif
  }

  // cleanup
  if (orderMap) delete[] orderMap;
  if (blockSizes) delete[] blockSizes;
  if (Eq2EqColTranspose) delete[] Eq2EqColTranspose;
  if (CT_columnIndices) delete[] CT_columnIndices;
  if (rowIndices) delete[] rowIndices;
	if (rowPageNumber) delete[] rowPageNumber;
	if (cColNZ) delete[] cColNZ;
  if (result_orderMap) delete[] result_orderMap;
  if (result_blockSizes) delete[] result_blockSizes;
  if (result_columnIndices) delete[] result_columnIndices;
  if (result_columnPageNumber) delete[] result_columnPageNumber;
  if (result_cRowNZ) delete[] result_cRowNZ;

  if (bAllocateSquareMatrix)
  {
    delete[] s_columnIndices;
    delete[] s_columnPageNumber;
    delete[] s_cRowNZ;
  }

  return bReturn;
}


/////////////////////////////////////////////////////////////////
// FillSquareMatrix
//
// - assume square matrix is already allocated:
//     s_columnIndices[nColumnIndices + (nVar-nEqn)*nVar]
//     s_columnPageNumber[nVar]
//     s_cRowNZ[nVar]
// - pads rectangular matrix with additional filled rows
// 
/////////////////////////////////////////////////////////////////
void COnModelExec::FillSquareMatrix(bool bHighIndex, long nEqns, long nVars, long nColumnIndices,
                      long* in_columnPageNumber, long* in_cRowNZ, long* in_columnIndices, 
                      ModelVarMap** VarMap, long* VarOrder, long* assignedEqn,
                      long* s_columnPageNumber, long* s_cRowNZ, long* s_columnIndices, long& s_nColumnIndices)
{
  long i, iEqn;

  for (i = 0; i < nColumnIndices; i++)
    s_columnIndices[i] = in_columnIndices[i];

  for (i = 0; i < nEqns; i++)
  {
    s_cRowNZ[i] = in_cRowNZ[i];
    s_columnPageNumber[i] = in_columnPageNumber[i];
  }
  
  s_nColumnIndices = nColumnIndices;

  // TODO: get the high index version to work for low index problems.
  // Jan 14, 2002 the follow code works for low index problems

  if (!bHighIndex)
  {
    long iVar;
    iEqn = nEqns;
    for (i = 0; i < nVars; i++)
    {
      iVar = VarOrder[i];
      if (VarMap[iVar]->iVAL >= 0) 
      {
        s_columnPageNumber[iEqn] = s_nColumnIndices;
        s_columnIndices[s_nColumnIndices++] = i;
        s_cRowNZ[iEqn] = 1;
        iEqn++;
      }
    }
  }

  else // bHighIndex
  {

    long* continuityVars = NULL;
    long nContinuityVars = 0;
    GetUnassignedVars(nEqns, nVars, assignedEqn, 
                        nColumnIndices, in_columnPageNumber, in_cRowNZ, in_columnIndices, 
                        VarMap, VarOrder, 
                        continuityVars, nContinuityVars);

    iEqn = nEqns;
    for (i = 0; i < nContinuityVars; i++)
    {
      s_columnPageNumber[iEqn] = s_nColumnIndices;
      s_columnIndices[s_nColumnIndices++] = continuityVars[i];
      s_cRowNZ[iEqn] = 1;
      iEqn++;
    }
  }

}

void COnModelExec::GetUnassignedVars(long nEqns, long nVars, long* assignedEqn, 
                      long nColIndices, long* in_spRowPage, long* in_cRowNZ, long* in_colIndices, 
                      ModelVarMap** VarMap, long* VarOrder, 
                      long*& out_Vars, long& out_nVars)
{
  long i, j;

  /*
  1) Determine which variables are x's
  2) Search the assignments for those variables that are not x's, and note the referenced equations
  3) Determine which equeations were never referenced.
  4) Build an edge list including only those equations found in 3, and only those variables found in 1
  5) Do an output assignment, stopping when all equations are assigned.
  6) Determine which x's didn't get assignments
  */
  long iEqn;
  long iVar;
  long* bx = new long[nVars];
  long* bAssigned = new long[nEqns];
  long nLocalVars = 0;
  long nLocalEqns = 0;

  long nIndices;
  long* spRowPage = NULL;
  long* cRowNZ = NULL;
  long* Indices = NULL;
  long* assigned = NULL;

  // determine which variables are x's
  for (i = 0; i < nVars; i++) bx[i] = -1;
  for (i = 0, iVar = 0; i < nVars; i++) if (VarMap[VarOrder[i]]->iVAL >= 0) bx[i] = nLocalVars++;

  // search the assignments for other variables, and note the referenced equations
  for (i = 0; i < nEqns; i++) bAssigned[i] = false;
  for (i = 0; i < nVars; i++)
  {
    if (bx[i] == -1)
    {
      iEqn = assignedEqn[i];
      if (iEqn >= 0 && iEqn < nEqns) bAssigned[iEqn] = true;
    }
  }

  // determine which equations were never referenced
  for (i = 0; i < nEqns; i++) 
  {
    if (bAssigned[i]) 
      bAssigned[i] = -1;
    else
      bAssigned[i] = nLocalEqns++;
  }

  if (nLocalEqns > 0)
  {
    // build edge list including local eqns and local vars
    nIndices = 0;
    spRowPage = new long[nLocalEqns];
    cRowNZ = new long[nLocalEqns];
    Indices = new long[nLocalEqns * nLocalVars];
    assigned = new long[nLocalVars];

    for (i = 0; i < nLocalVars; i++) assigned[i] = -1;

    for (i = 0; i < nEqns; i++)
    {
      if (bAssigned[i] >= 0)
      {
        iEqn = bAssigned[i];
        cRowNZ[iEqn] = 0;
        spRowPage[iEqn] = nIndices;
        for (j = 0; j < in_cRowNZ[i]; j++)
        {
          iVar = in_colIndices[in_spRowPage[i]+j];
          if (bx[iVar] >= 0)
          {
            Indices[nIndices++] = bx[iVar];
            cRowNZ[iEqn]++;
          }
        }
      }
    }

    // assign the equations to the variables
    assignVariables(nLocalEqns, nLocalVars, cRowNZ, spRowPage, Indices, assigned);
    for (i = 0; i < nLocalVars; i++)
    {
      if (assigned[i] >= 0)
      {
        for (j = 0; j < nVars; j++)
        {
          if (bx[j] == i)
          {
            bx[j] = -1;
            break;
          }
        }
      }
    }
  }

  // determine which x's didn't get assignments
  out_Vars = new long[nLocalVars];
  out_nVars = 0;
  for (i = 0; i < nVars; i++) if (bx[i] >= 0) out_Vars[out_nVars++] = i;

  // cleanup
  if (bx) delete[] bx;
  if (bAssigned) delete[] bAssigned;
  if (spRowPage) delete[] spRowPage;
  if (cRowNZ) delete[] cRowNZ;
  if (Indices) delete[] Indices;
  if (assigned) delete[] assigned;

}

STDMETHODIMP COnModelExec::SetVariables(SAFEARRAY** VarVals)
{
  HRESULT hr = S_OK;
  DispatchProxy::Fire_SetVariables(*VarVals);
  hr = VTableProxy::Fire_SetVariables(*VarVals);
  return hr;
}


STDMETHODIMP COnModelExec::GetResiduals(long nEqns, SAFEARRAY** EqnIds, SAFEARRAY** Residuals)
{
  HRESULT hr = S_OK;
  DispatchProxy::Fire_GetResiduals(nEqns, *EqnIds, *Residuals);
  hr = VTableProxy::Fire_GetResiduals(nEqns, *EqnIds, *Residuals);
  return hr;
}

STDMETHODIMP COnModelExec::HandleInitEvents()
{
#if 0 
  IOnModelExec* pExec = static_cast<IOnModelExec*> (this);
  m_pScriptParser->SetModelExec( &pExec );
#endif
  return S_OK;
}
