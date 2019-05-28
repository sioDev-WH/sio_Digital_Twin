// IsDaeEso.h : Declaration of the CIsDaeEso

#ifndef __IsDaeEso_H_
#define __IsDaeEso_H_

#include "OnDaeCOSolverExport.h"

// forward declarations
class ModelEqnMap;
class ModelVarMap;
class ModelParMap;
class FlatModel;
class CIsStepper;

class VarInfo;
class	IndexInfo;
class	ToleranceInfo;
class VirtualTimeInfo;
class ConverganceInfo;
class StepSizeInfo;
class ReportInfo;
class StateInfo;
class TransitionInfo;
class MatInfo;
struct event_item;

const long DIRECT_OFFSET = 1000000;


// end forward declarations


class ONDAECOSOLVER_API CIsDaeEsoBase
{

public:
  CIsDaeEsoBase(long nEqns, long nVars, long nRPars, long nIPars);
  virtual ~CIsDaeEsoBase();
  void Destroy();
  void CommonConstruction(long nEqns, long nVars, long nRPars, long nIPars);

  friend class CIsStepper;
public:
  // IIsDaeEso

  // initialization
  STDMETHOD(GetCPPPtr)(DWORD* pDaeEsoBase) { *pDaeEsoBase = reinterpret_cast<DWORD> (this); return S_OK; }
  STDMETHOD(SetModelExec)(IOnModelExec* pModelExec);
  STDMETHOD(SetSize)(long nEqns, long nVars, long nRPars, long nIPars);
  STDMETHOD(SetLocalSize)(long nEqns, long nVars, long nRPars, long nIPars);

  STDMETHOD(InitTime)(double StartTime, VARIANT_BOOL Reverse);
  STDMETHOD(SetTime)(double time);
  HRESULT iDirectSetTime(double time);
  STDMETHOD(SetLastTime)(double time);
  HRESULT iDirectSetLastTime(double time);

  // reporting
  STDMETHOD(GetReportInfo)(
	  long* StepperCalls, long* functionCalls, long* jacobiansCalls, long* DecompCalls,
	  long* Substitutions, long* TotalSteps, long* errorRejectedSteps, long* newtonRejectedSteps,
	  long* growthRejectedSteps, long* funcRejectedSteps, long* nStateEvents, long* nParameterEvents, long* nStepSizeChanges);

  // tolerance
  STDMETHOD(SetRelTolerance)(SAFEARRAY** relTolValue);
  STDMETHOD(GetRelTolerance)(SAFEARRAY** relTolValue);
  STDMETHOD(SetAbsTolerance)(SAFEARRAY** absTolValues);
  STDMETHOD(GetAbsTolerance)(SAFEARRAY** absTolValues);

	// residuals
	STDMETHOD(GetAllResiduals)(SAFEARRAY** residuals,	VARIANT_BOOL* validVal);
	STDMETHOD(GetResiduals)(SAFEARRAY** Indices, SAFEARRAY** residuals,	VARIANT_BOOL* validVal);

	// Jacobian matrix
	STDMETHOD(GetJacobianStruct)(long* nColIndices, SAFEARRAY** ColIndices, SAFEARRAY** cNZCols, SAFEARRAY** CalcMethod);
	STDMETHOD(GetJacobianValues)(SAFEARRAY** Indices, SAFEARRAY** JacVals);
	STDMETHOD(GetAllJacobianValues)(IIsMatrix** ppJacVals);

	// Mass matrix
	STDMETHOD(GetDiffJacobianStruct)(long* nColIndices, SAFEARRAY** ColIndices, SAFEARRAY** cNZCols, SAFEARRAY** CalcMethod);
	STDMETHOD(GetDiffJacobianValues)(SAFEARRAY** Indices, SAFEARRAY** MassVals);
	STDMETHOD(GetAllDiffJacobianValues)(IIsMatrix** ppMassVals);

  // Parameters
	STDMETHOD(GetNumRealPars)(long* nRPars);
	STDMETHOD(GetRealPar)(long index, double* Val);
	STDMETHOD(GetRealParId)(BSTR Name, long* idx);
  STDMETHOD(SetRealPar)(long index, double newVal);
  STDMETHOD(GetNumIntPars)(long* nIPars);
  STDMETHOD(GetIntPar)(long index, long* Val);
  STDMETHOD(GetIntParId)(BSTR Name, long* idx);
  STDMETHOD(SetIntPar)(long index, long newVal);

	// Variables
	STDMETHOD(GetVariables)(SAFEARRAY** Indices, double t, SAFEARRAY** Vals);
	STDMETHOD(GetVariable)(long index, double t, double* val);
  STDMETHOD(GetVariableId)(BSTR Name, long* idx);
	STDMETHOD(SetVariables)(SAFEARRAY** Indices, SAFEARRAY** Vals);
  STDMETHOD(SetVariable)(long index, double val);
  STDMETHOD(SetLastVariable)(long index, double val);
	STDMETHOD(GetAllVariables)(double t, SAFEARRAY** Vals);
	STDMETHOD(SetAllVariables)(SAFEARRAY** Vals);
	STDMETHOD(GetVariablesIndex)(SAFEARRAY** Index);

	// Derivatives
	STDMETHOD(GetDerivatives)(SAFEARRAY** Indices, double t, SAFEARRAY** Vals);
	STDMETHOD(GetDerivative)(long index, double t, double* val);
	STDMETHOD(SetDerivatives)(SAFEARRAY** Indices, SAFEARRAY** Vals);
	STDMETHOD(SetDerivative)(long index, double val);
	STDMETHOD(SetLastDerivative)(long index, double val);
	STDMETHOD(GetAllDerivatives)(double t, SAFEARRAY** Vals);
	STDMETHOD(SetAllDerivatives)(SAFEARRAY** Vals);

	// equation / variable structure
	STDMETHOD(GetNumVars)(long* nVars);
	STDMETHOD(GetNumEqns)(long* nEqns);
  STDMETHOD(GetNumLocalVars)(long* nVars);
  STDMETHOD(GetNumLocalEqns)(long* nVars);

  // model time
	STDMETHOD(GetLastTime)(double* t);
	STDMETHOD(GetTime)(double* t);

// IIsCompDaeEso
  STDMETHOD(AddEso)(IIsDaeEso* pEso);
  STDMETHOD(GetEso)(long index, IIsDaeEso** pEso);
  STDMETHOD(RemoveEso)(long index);
  STDMETHOD(GetNumEso)(long* count);

// IIsDaeEso  
  STDMETHOD(SizeDiscontinuousVars)();
  STDMETHOD(EvalStateCondition)(double EventTime, long iDisEqn, long iTransition, VARIANT_BOOL* bEvent);
  virtual HRESULT iEvalStateCondition(bool* EqnState, double EventTime, long iDisEqn, long iTransition, VARIANT_BOOL* bEvent) { return E_NOTIMPL; }

  STDMETHOD(CIEvalStateCondition)(
    double EventTime, 
    long iDisEqn, 
    long iTransition, 
    VARIANT_BOOL* bEvent,
    double* global_x,
    double* global_xdot);
  
  virtual HRESULT iCIEvalStateCondition(
    bool* EqnState, 
    double EventTime, 
    long iDisEqn, 
    long iTransition, 
    VARIANT_BOOL* bEvent,
    double* global_x,
    double* global_xdot)
    { return E_NOTIMPL; }

  // container methods and properties
  // NOTE: While it may be argued that a model should be isolated from data associated with its
  //       container, in practical terms, it is infinitely easier to manage this data if it is 
  //       stored directly on the Eso for which the map is being applied.  If this info is stored
  //       in lists, it is too easy for the lists to get out of synch when objects are added or removed, 
  //       especially considering how dynamic things can be during state transitions.
  STDMETHOD(get_ContainerIndex)(long* Index) { *Index = m_ContainerIndex; return S_OK; }
  STDMETHOD(put_ContainerIndex)(long Index) { m_ContainerIndex = Index; return S_OK; }
  STDMETHOD(get_VariableMap)(SAFEARRAY** Map);
  STDMETHOD(put_VariableMap)(SAFEARRAY** Map);


  // **********************************************************************
  // Serialization
  // **********************************************************************
  virtual bool Load(FILE* fs);
  virtual void Save(FILE* fs);

  // **********************************************************************
  // Numeric jacobian calculations
  // **********************************************************************
  HRESULT numericJacobian(
    long iEqn,
    long iVar,
    double t, 
    double* y, 
    double* ydot,
    double* rPar, 
    long* iPar,
    double& jacobian);

  HRESULT numericDiffJacobian(
    long iEqn,
    long iVar,
    double t, 
    double* y, 
    double* ydot,
    double* rPar, 
    long* iPar,
    double& jacobian);

  HRESULT numericJacobianStruct(MatInfo& JacStruct, bool bDiffJacobian);

  // **********************************************************************
  // Event detection / initialization
  // **********************************************************************
  virtual bool iEventDetection(
      event_item**& events,
      long& count,
      long& dim);

  bool iCIEventDetection(
      event_item**& events,
      long& count,
      long& dim,
      double* global_last_x,
      double* global_last_xdot,
      double* global_x,
      double* global_xdot);

  virtual HRESULT EventInitialization(
      double event_time, 
      long iEventEqn, 
      BSTR EventId,
      long iNewState,
      long*& oldEqns,
      long& nOldEqns,
      long*& newEqns,
      long& nNewEqns);

  HRESULT OnEventInitEqnMap(CIsDaeEsoBase* pChild);

public:
  // **********************************************************************
  // flat model maintenance
  // **********************************************************************
  HRESULT GetFlatModel(
    FlatModel& fm,
    long* EqnIndices,
    long* VarIndices,
    long* RParIndices,
    long* IParIndices,
    bool bParentIsGlobal);

  virtual HRESULT GetLocalFlatModel(
    FlatModel& fm,
    long* EqnIndices,
    long* VarIndices,
    long* RParIndices,
    long* IParIndices,
    bool bParentIsGlobal);

  virtual HRESULT RefreshEqnMap(FlatModel& fm);
  void initActiveEqns();
  void initDirectEqnMap();
  HRESULT initFlatModel();

  // **********************************************************************
  // Residual calculations
  // **********************************************************************
  HRESULT iGetAllResiduals(
		double t,
		double* y,
		double* ydot,
    double* residuals,
		bool& validVal,
		double* realParameters, 
		long* integerParameters);

  HRESULT iDirectGetAllResiduals(
	  double t,
	  double* y,
	  double* ydot,
    double* residuals,
	  bool& validVal,
	  double* realParameters, 
	  long* integerParameters);

  HRESULT iGetResiduals(
		long* Indices,                // equation indices
    long cIndices,                // count of equation indices
		double t,                     // time
		double* y,                    // y variable values
		double* ydot,                 // dy/dt values
    double* residuals,            // equation residuals
		bool& validVal,               // result validation
		double* realParameters,       // real parameters
		long* integerParameters);     // integer parameters

  // **********************************************************************
  // Jacobian and Mass matrix calculations
  // **********************************************************************
  // jacobian structure
  HRESULT iGetJacobianStruct(MatInfo& JacStruct);
  HRESULT iGetMassStruct(MatInfo& MassStruct);
  
  HRESULT UpdateAllJacobianValues();
  HRESULT UpdateAllDiffJacobianValues();

	// Jacobian matrix
  HRESULT iGetAllJacobianValues(
    MatInfo& JacStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals,
    long*& Indices,
    long& nIndices,
    double* rPar, 
    long* iPar,
    bool bIncludeConst);

  HRESULT iGetAllMassValues(
    MatInfo& MassStruct,
    double t, 
    double* y, 
    double* ydot,
		double* MassVals, 
    long*& Indices,
    long& nIndices,
    double* rPar, 
    long* iPar,
    bool bIncludeConst);

  HRESULT iGetJacobianValues(
    long* indices,
    long cIndices,
    MatInfo& JacStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals, 
    double* rPar, 
    long* iPar,
    bool bIncludeConst = true);

  HRESULT iGetMassValues(
    long* Indices,
    long cIndices,
    MatInfo& MassStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals, 
    double* rPar, 
    long* iPar,
    bool bIncludeConst = true);

  // **********************************************************************
  // interpolation
  // **********************************************************************
  HRESULT InterpolateAll(double t, SAFEARRAY** pVals);
  HRESULT Interpolate(SAFEARRAY** Indices, double t, SAFEARRAY** pVals);
  void iInterpolateAll(double tau, double* u);
  void iInterpolate(long* Indices, long cIndices, double tau, double* u);
  void iDerivInterpolateAll(double tau, double* u, double* udot);
  void iDerivInterpolateAll(double tau, double* udot);
  void iDerivInterpolate(long* Idx, long cIdx, double tau, double* u, double* udot);
  void iDerivInterpolate(long* Idx, long cIdx, double tau, double* udot);

  // **********************************************************************
  // index
  // **********************************************************************
  HRESULT iGetVariablesIndex(short*& differentialIndex);

  // **********************************************************************
  // tolerance
  // **********************************************************************
  void iGetAbsTolerance(long iVar, double& atol);
  void iGetRelTolerance(long iVar, double& rtol);

  // **********************************************************************
  // initialization
  // **********************************************************************
  virtual HRESULT iInitialize();
  void iInitializePageMaps(long& EquationCount, long& VariableCount, long& RParCount, long& IParCount);

  // initialize master nodes
  HRESULT iInitializeMasterNodes();
  void GetNumMasterNodes(long& nNodes);
  void GetMasterNodes(long& nNodes, CIsDaeEsoBase** pNodes);
  void iCompleteMasterNodeInit();
  void LevelInit(const long Level);
  void MergeJacobianStructures(long nNodes, CIsDaeEsoBase** pNodes);
  void MergeMassStructures(long nNodes, CIsDaeEsoBase** pNodes);

	void initializeIndex();
	void initializeVars();
	void initializeJacobians(); 
  void initializeConstantJacobians();
  void initializeEqns();

  HRESULT iGetNlaStruct(
    long& nEqns,
    long& nVars,
    long& nAugmentedVars,
    long*& VAL,
    long*& EqnOrder,
    long*& VarOrder,
    long& edgeList_nColumnIndices,
    long*& edgeList_cRowNZ,
    long*& edgeList_spRowPage,
    long*& edgeList_ColumnIndices);

//*****************************************************************************
// pure virtual functions
//*****************************************************************************

  // the first 5 are pure virtual functions and must be implemented by any derived class
	virtual HRESULT iGetLocalResiduals(
		long* Indices,                // equation indices
    long cIndices,                // count of equation indices
		double t,                     // time
		double* y,                    // y variable values
		double* ydot,                 // dy/dt values
    double* residuals,            // equation residuals
		bool& validVal,               // result validation
		double* realParameters,       // real parameters
		long* integerParameters) = 0; // integer parameters

  // jacobian calculations
  virtual HRESULT iGetLocalJacobianStruct(MatInfo& JacStruct) = 0;
  virtual HRESULT iGetLocalMassStruct(MatInfo& MassStruct) = 0;

  virtual HRESULT iGetLocalJacobianValues(
    long* indices,
    long cIndices,
    MatInfo& JacStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals, 
    double* rPar, 
    long* iPar,
    bool bIncludeConst = true) = 0;

  virtual HRESULT iGetLocalMassValues(
    long* Indices,
    long cIndices,
    MatInfo& MassStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals, 
    double* rPar, 
    long* iPar,
    bool bIncludeConst = true) = 0;

  virtual HRESULT iGetVariableId(BSTR Name, long* idx) = 0;
  virtual HRESULT iGetRealParId(BSTR Name, long* idx) = 0;
  virtual HRESULT iGetIntParId(BSTR Name, long* idx) = 0;

  virtual HRESULT iGetEquationForm(EqnForm*& eqn_form, EqnDiffForm*& eqn_diff_form) = 0;

  //*****************************************************************************
  // Event virtual functions
  //*****************************************************************************
  virtual HRESULT TriggerEvent(double EventTime, BSTR EventId, long iEventEqn) = 0;
  STDMETHOD(PostStateEvent)(double t, BSTR EventId) = 0;
  STDMETHOD(PostTransition)(long iNewState) = 0;
	STDMETHOD(PostRealParameter)(double t, long Id, double newVal);
	STDMETHOD(PostIntegerParameter)(double t, long Id, long newVal);

public:
  CIsDaeEsoBase* m_pParent;
  IOnModelExec* m_pModelExec;

  bool m_bMasterNode;
  bool m_bGlobalNode;

  long m_nEqns;
  long m_nVars;
  long m_nLocalEqns;
  long m_nLocalVars;
  long m_nDiscontinuousEqns;

  long* m_ActiveEqns;
  long* m_itActiveEqns;
  long m_nActiveEqns;

  long* m_ActiveVars;
  long* m_itActiveVars;
  long m_nActiveVars;

  ModelEqnMap* m_EqnMap;
  ModelVarMap* m_VarMap;
  long* m_IParMap;
  long* m_RParMap;

  // variables
	VarInfo* m_y;
	IndexInfo* m_index;
	ToleranceInfo* m_tolerance;

  // jacobians
  bool m_bJacobiansInitialized;
	MatInfo* m_Jac;
	MatInfo* m_Mass;
	MatInfo* m_JacStruct;
	MatInfo* m_MassStruct;	

  // parameters
  long m_nRealParameters;  // count of user defined real parameters
	long m_nIntegerParameters;
  long m_nLocalRPars;
	long m_nLocalIPars;

	double* m_realParameters;
	long*	m_integerParameters;

  // stepper environment variables (only initialized if called directly from the stepper)
	VirtualTimeInfo* m_time;
	ConverganceInfo* m_convergance;
	StepSizeInfo* m_step;
	ReportInfo*	m_report;
  VarInfo** m_K;
	MatInfo** m_iterationMatrix;
	long m_nStages;
  bool m_bEsoInitialized;

  // direct residual calculation support
  long m_Level;                   // level in Eso hierarchy
  CIsDaeEsoBase** m_DirectEsos;   // sorted map of Esos by level   (global Eso only)
  long** m_DirectEqnMap;          // sorted map of active eqns     (global Eso only)
  long** m_DirectResMap;          // map to export direct residuals (global Eso only)
  long** m_DirectDiscVarMap;      // map of discontinuous equation variable mapping (global Eso only)
  long* m_nDirectEqnMap;          // count of active defined eqns  (global Eso only)
  double* m_DirectRes;            // res    (global Eso only)
  long m_nDirectUndefDiscEqns;
  long* m_DirectUndefDiscEqns;
  long* m_DirectUndefDiscVars;

  // container properties (associated with how an Eso is being used in a container.  These are not
  // properties of the Eso itself.
  long m_GlobalIndex;     // index in global Eso
  long m_ContainerIndex;  // index in a container object (graph Eso or STN Eso)
  long* m_VariableMap;    // index of variables in container
  long* m_MNVariableMap;  // index of variables in master node container

  // flat Eso data (only applicable if Eso is the global Eso
  FlatModel* m_fm;

  // From Composite Eso
  CIsDaeEsoBase** m_Esos;       // Esos including this one (m_Esos[0] = this;)
  IIsDaeEso** m_IIsEsos;        // Eso interface pointers (enables Esos to be built using automation)
  long m_nEsos;                 // number of Esos including this one (always >= 1)
  long m_EsoDim;
  long m_IIsEsoDim;

  // variable map
  // The following map information enables subsections of the variable and parameter vectors
  // to be passed to member Esos
  long* m_spEsoEqns;  // start point in eqn vector for each Eso
  long* m_spEsoVars;  // start point in variable vector for each Eso
  long* m_spEsoRPars; // start point in real parameter vector for each Eso
  long* m_spEsoIPars; // start point in integer parameter vector for each Eso

  // STN variables
  long m_nStates;                    // number of local states
  long m_nTransitions;               // number of local transitions
  long m_DefaultState;               // index of default state
  long m_CurrentState;               // index of current state
  StateInfo* m_StateInfo;            // state equation map
  TransitionInfo* m_TransitionInfo;  // transition EventId, SourceState, Equation map

  // event handler
  double m_EventTime;
  BSTR m_EventId;
  long m_EventEqn;

private:
  // variables used for numeric differentiation
  double* nominalVal;
  double* nominalTime;
  double uround;
  double epsilon;

  // cached equation indices for jacobian and mass calculations
  long* JacIndices;
  long nJacIndices;
  long* MassIndices;
  long nMassIndices;


};




typedef enum event_type
{
  state_event,
  rpar_event,
  ipar_event,
};

struct event_item
{
  event_item() { event_time = 0.0; type = state_event; bExternal = false; } 
  virtual ~event_item() { }

  double event_time;
  event_type type;
  bool bExternal;

  virtual void Save(FILE* fs) = 0;
  virtual bool Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos) = 0;
};

struct state_event_item : public event_item
{
  BSTR EventId;
  long iEventEqn;
  long iTransition;
  bool bZeroCrossing;
  CIsDaeEsoBase* pEventEso;

  state_event_item();
  ~state_event_item();
  void Save(FILE* fs);
  bool Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos);

};

struct rpar_event_item : public event_item
{
  long iGlobalId;
  double value;

  rpar_event_item();
  void Save(FILE* fs);
  bool Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos);

};

struct ipar_event_item : public event_item
{
  long iGlobalId;
  long value;

  ipar_event_item();
  void Save(FILE* fs);
  bool Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos);

};





#endif //__IsDaeEso_H_
