#ifndef _trimInfo_h_
#define _trimInfo_h_

struct addEquationInfo
{
  long nEqns;
  long* EqnIndices;
  long nColIndices;
  long* ColIndices;
  long* cNZCols;
  long* spRowPage;

  addEquationInfo()
  {
    nEqns = 0;
    EqnIndices = NULL;
    nColIndices = 0;
    ColIndices = NULL;
    cNZCols = NULL;
    spRowPage = NULL;
  }

  ~addEquationInfo()
  {
    clean();
  }

  void init(long nEquations, long nColumnIndices)
  {
    clean();

    nEqns = nEquations;
    EqnIndices = new long [nEqns];
    nColIndices = nColumnIndices;
    ColIndices = new long[nColIndices];
    cNZCols = new long[nEqns];
    spRowPage = new long[nEqns];
  }

  void clean()
  {
    if (EqnIndices) delete[] EqnIndices;
    if (ColIndices) delete[] ColIndices;
    if (cNZCols) delete[] cNZCols;
    if (spRowPage) delete[] spRowPage;
  }
};


struct trimEquationInfo
{
  long nEqns;
  long nColIndices;
  SAFEARRAY* psa_cNZCols;
  SAFEARRAY* psa_spRowPage;
  SAFEARRAY* psa_ColIndices;
  long* cNZCols;
  long* spRowPage;
  long* ColIndices;
  bool bAccessData;

  trimEquationInfo()
  {
    nEqns = 0;
    nColIndices = 0;
    psa_cNZCols = NULL;
    psa_spRowPage = NULL;
    psa_ColIndices = NULL;
    cNZCols = NULL;
    spRowPage = NULL;
    ColIndices = NULL;
    bAccessData = false;
  }

  trimEquationInfo(long nEquations, long nColumnIndices)
  {
    init(nEquations, nColumnIndices);
  }

  void init(long nEquations, long nColumnIndices)
  {
    nEqns = nEquations;
    nColIndices = nColumnIndices;
    psa_cNZCols = SafeArrayCreateVector(VT_I4, 0, nEqns);
    psa_spRowPage = SafeArrayCreateVector(VT_I4, 0, nEqns);
    psa_ColIndices = SafeArrayCreateVector(VT_I4, 0, nColIndices);
    cNZCols = NULL;
    spRowPage = NULL;
    ColIndices = NULL;
    bAccessData = false;
    AccessData();
  }

  ~trimEquationInfo()
  {
    UnaccessData();
    if (psa_cNZCols) SafeArrayDestroy(psa_cNZCols);
    if (psa_spRowPage) SafeArrayDestroy(psa_spRowPage);
    if (psa_ColIndices) SafeArrayDestroy(psa_ColIndices);
  }

  void AccessData()
  {
    if (!bAccessData)
    {
      if (psa_cNZCols) SafeArrayAccessData(psa_cNZCols, (void HUGEP* FAR*)& cNZCols);
      if (psa_spRowPage) SafeArrayAccessData(psa_spRowPage, (void HUGEP* FAR*)& spRowPage);
      if (psa_ColIndices) SafeArrayAccessData(psa_ColIndices, (void HUGEP* FAR*)& ColIndices);
      bAccessData = true;
    }
  }

  void UnaccessData()
  {
    if (bAccessData)
    {
      if (psa_cNZCols) SafeArrayUnaccessData(psa_cNZCols);
      if (psa_spRowPage) SafeArrayUnaccessData(psa_spRowPage);
      if (psa_ColIndices) SafeArrayUnaccessData(psa_ColIndices);
      bAccessData = false;
    }
  }

};


struct trimConstraintInfo
{
  // trim constraint variables
  long nVars;
  SAFEARRAY* psa_VarIds;
  SAFEARRAY* psa_VarVals;
  long* VarIds;
  double* VarVals;
  bool bAccessData;

  trimConstraintInfo()
  {
    nVars = 0;
    psa_VarIds = NULL;
    psa_VarVals = NULL;
    VarIds = NULL;
    VarVals = NULL;
    bAccessData = false;
  }

  trimConstraintInfo(long nVariables)
  {
    init(nVariables);
  }

  void init(long nVariables)
  {
    nVars = nVariables;
    psa_VarIds = SafeArrayCreateVector(VT_I4, 0, nVars);
    psa_VarVals = SafeArrayCreateVector(VT_R8, 0, nVars);
    VarIds = NULL;
    VarVals = NULL;
    bAccessData = false;
    AccessData();
  }

  ~trimConstraintInfo()
  {
    UnaccessData();
    if (psa_VarIds) SafeArrayDestroy(psa_VarIds);
    if (psa_VarVals) SafeArrayDestroy(psa_VarVals);
  }

  void AccessData()
  {
    if (!bAccessData)
    {
      if (psa_VarIds) SafeArrayAccessData(psa_VarIds, (void HUGEP* FAR*)& VarIds);
      if (psa_VarVals) SafeArrayAccessData(psa_VarVals, (void HUGEP* FAR*)& VarVals);
      bAccessData = true;
    }
  }

  void UnaccessData()
  {
    if (bAccessData)
    {
      if (psa_VarIds) SafeArrayUnaccessData(psa_VarIds);
      if (psa_VarVals) SafeArrayUnaccessData(psa_VarVals);
      bAccessData = false;
    }
  }

};

#endif // _trimInfo_h_