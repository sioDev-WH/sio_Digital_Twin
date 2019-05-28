#ifndef _MODEL_NAV_MAPS_H_
#define _MODEL_NAV_MAPS_H_

class CIsDaeEsoBase;
class istream;
class ostream;
struct _iobuf;
typedef struct _iobuf FILE;

typedef enum EqnDiffForm;

class ModelEqnMap
{

public:
  ModelEqnMap();
  ModelEqnMap& operator=(const ModelEqnMap& other);

public:
  long iModel;           // model index in Eso vector
  long iEqn;             // equation index
  long iGlobalEqn;       // equation index in the global Eso
  long iEAL;             // f_dot that calculates the derivative of this f equation
  long itEAL;            // f equation for which this f_dot equation calculates the derivative
  bool bAugmented;       // augmented equation for consistent initialization
  bool bReset;           // reset equation for event initialization
  long iAssignedVar;     // variable assigned to this equation during initialization
  bool bDiscontinuous;   // discontinuous equation included for the purpose of triggering events
  long iDiscVar;         // associated z variable for g() equation
  bool bActive;          // equation currently active
  bool bUndefined;       // equation is masking an unused variable
  EqnDiffForm diff_form; // equation differential form { numeric, automatic, symbolic }
};

class ModelVarMap
{
public:
  ModelVarMap();
  ModelVarMap& operator=(const ModelVarMap& other);

public:
  long iModel;           // model index
  long iMNModel;         // model index of master node (if applicable)
  long iVar;             // variable index for the referenced model index
  long iMNVar;           // variable index for the referenced master node model index
  long iGlobalVar;       // variable index in parent (STN or composite Eso)
  long iVAL;             // index of xdot variable associated with this x variable
  long itVAL;            // index of x variable associated with this xdot variable
  bool bAugmented;       // augmented variable for consistent initialization
  bool bDiscontinuous;   // z variable
  long iDiffOrder;       // differential order of variable 0 - x, 1 - xdot, 2 - xdotdot
  bool bActive;          // variable is active
};


class ModelParMap
{

public:
  ModelParMap();
  ModelParMap& operator=(const ModelParMap& other);

public:
  long iModel;          // model index
  long iPar;            // variable index for the referenced model index
  long iGlobalPar;      // variable index in parent (STN or composite Eso)

};


class FlatModel
{
public:
  FlatModel(long cEqns, long cVars, long cRPars, long cIPars);
  ~FlatModel();

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
  long nEqns;              // n+m equations
  long nMSSEqns;           // number of equations added by MSS
  long nAugmentedEqns;     // n+m+MSS equations
  long nVars;              // n+m
  long nAugmentedVars;     // 2*n+m+MSS variables
  long nMSSVars;           // number of variables added by MSS
  long nRPars;             // number of real parameters
  long nIPars;             // number of integer parameters
  long EsoCount;
  long EsoDim;
  CIsDaeEsoBase** EsoList;
  long EqnMapSize;
  long EqnMapDim;
  ModelEqnMap** EqnMap;
  long* spModelEqn;
  long* cNZModelEqn;
  long VarMapSize;
  long VarMapDim;
  ModelVarMap** VarMap;
  ModelParMap* RParMap;
  ModelParMap* IParMap;
};

#endif // _MODEL_NAV_MAPS_H_