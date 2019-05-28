#ifndef _trimEqnInfo_h_
#define _trimEqnInfo_h_

struct trimEqnInfo
{
  long trim_nEqns;
  long trim_nColIndices;
  SAFEARRAY* psa_cNZCols;
  SAFEARRAY* psa_spRowPage;
  SAFEARRAY* psa_ColIndices;
  long* cNZCols;
  long* spRowPage;
  long* ColIndices;
  bool bAccessData;

  trimEqnInfo()
  {
    trim_nEqns = 0;
    trim_nColIndices = 0;
    psa_cNZCols = NULL;
    psa_spRowPage = NULL;
    psa_ColIndices = NULL;
    cNZCols = NULL;
    spRowPage = NULL;
    ColIndices = NULL;
    bAccessData = false;
  }

  trimEqnInfo(long nEqns, long nColIndices)
  {
    init(nEqns, nColIndices);
  }

  void init(long nEqns, long nColIndices)
  {
    trim_nEqns = nEqns;
    trim_nColIndices = nColIndices;
    psa_cNZCols = SafeArrayCreateVector(VT_I4, 0, nEqns);
    psa_spRowPage = SafeArrayCreateVector(VT_I4, 0, nEqns);
    psa_ColIndices = SafeArrayCreateVector(VT_I4, 0, nColIndices);
    cNZCols = NULL;
    spRowPage = NULL;
    ColIndices = NULL;
    bAccessData = false;
    AccessData();
  }

  ~trimEqnInfo()
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

#endif // _trimEqnInfo_h_