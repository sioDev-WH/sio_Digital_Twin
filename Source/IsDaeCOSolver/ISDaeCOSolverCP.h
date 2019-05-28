#ifndef _ISDAECOSOLVERCP_H_
#define _ISDAECOSOLVERCP_H_



template <class T>
class CProxy_IIsDaeSolverEvents : public IConnectionPointImpl<T, &DIID__IIsDaeSolverEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:

  void Fire_BeforeRParEvent(double Time, long iGlobalId, double Value)
  {
		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[0] = Time;
    pvars[1] = iGlobalId;
    pvars[2] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

  void Fire_BeforeIParEvent(double Time, long iGlobalId, long Value)
  {
		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[0] = Time;
    pvars[1] = iGlobalId;
    pvars[2] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


  void Fire_BeforeStateEvent(double Time, BSTR EvId, long iEvEqn)
  {
		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[0] = Time;
    pvars[1] = EvId;
    pvars[2] = iEvEqn;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


  void Fire_AfterRParEvent(double Time, long iGlobalId, double Value)
  {
		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[0] = Time;
    pvars[1] = iGlobalId;
    pvars[2] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

  void Fire_AfterIParEvent(double Time, long iGlobalId, long Value)
  {
		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[0] = Time;
    pvars[1] = iGlobalId;
    pvars[2] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


  void Fire_AfterStateEvent(double Time, BSTR EvId, long iEvEqn)
  {
		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[0] = Time;
    pvars[1] = EvId;
    pvars[2] = iEvEqn;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


};
#endif