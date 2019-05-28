// IOnVarInit.cpp
//=====================================================================

#include "stdafx.h"
#include "IOnVarInit.h"
#include "CommonTools.h"
#include "OnAD.h"
#include "OnUMLEsoMacros.h"


#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

void IOnVarInit::SizeVars(
  long Size, 
  VarCont* varC,
  const bool bADOnly)
{
  long dim;

  if (!bADOnly)
  {
    dim = varC->dVars;
    size_ptr_array(10, varC->nVars, dim, varC->vars, Size);
    dim = varC->dVars;
    size_ptr_array(10, varC->nVars, dim, varC->derVars, Size);
    dim = varC->dVars;
    size_ptr_array(10, varC->nVars, dim, varC->oldVars, Size);
    dim = varC->dVars;
    size_ptr_array(10, varC->nVars, dim, varC->derOldVars, Size);
    dim = varC->dVars;
    size_ptr_array(10, varC->nVars, varC->dVars, varC->Names, Size);
  }
  
  dim = varC->dADVars;
  size_ptr_array(10, varC->nADVars, dim, varC->FVars, Size);
  size_ptr_array(10, varC->nADVars, varC->dADVars, varC->derFVars, Size);
}


void IOnVarInit::SizeRPars(long Size, double*** pars, _TCHAR*** Names, long* nPars, long* dPars)
{
  long dim;

  dim = *dPars;
  size_ptr_array(10, *nPars, dim, *pars, Size);
  size_ptr_array(10, *nPars, *dPars, *Names, Size);
}


void IOnVarInit::SizeIPars(long Size, long*** pars, _TCHAR*** Names, long* nPars, long* dPars)
{
  long dim;

  dim = *dPars;
  size_ptr_array(10, *nPars, dim, *pars, Size);
  size_ptr_array(10, *nPars, *dPars, *Names, Size);
}

// scalar
void IOnVarInit::AddLocalVar(
  double* V, double* derV, double* oldV, double* derOldV, Fdouble* FV, Fdouble* derFV, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  SizeVars(1, varC, bADOnly);

  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;

  if (!bADOnly)
  {
    CComBSTR local_prefix = prefix;
    if (local_prefix.Length() > 0) local_prefix.Append(L".");
    if (Name) local_prefix.Append(Name);

    varC->vars[nVars] = V;
    varC->derVars[nVars] = derV;
    varC->oldVars[nVars] = oldV;
    varC->derOldVars[nVars] = derOldV;
    if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
    varC->Names[nVars] = ::SysAllocString(local_prefix);
    nVars++;
  }
  varC->FVars[nADVars] = FV;
  varC->derFVars[nADVars] = derFV;
  nADVars++;
}

// vector
void IOnVarInit::AddLocalVar(double* V, double* derV, double* oldV, double* derOldV, Fdouble* FV, Fdouble* derFV, long Size, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i;
  CComBSTR locName;
  CComBSTR modName;
  _TCHAR buffer[10];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeVars(Size, varC, bADOnly);

  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  
  for (i = 0; i < Size; i++)
  {
    if (!bADOnly)
    {
      varC->vars[nVars] = &V[i];
      varC->derVars[nVars] = &derV[i];
      varC->oldVars[nVars] = &oldV[i];
      varC->derOldVars[nVars] = &derOldV[i];
      modName = locName;
      _ltot( i, buffer, 10 );
      modName.Append(buffer);
      modName.Append(L"]");
      if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
      varC->Names[nVars] = modName.Detach();
      nVars++;
    }

    varC->FVars[nADVars] = &FV[i];
    varC->derFVars[nADVars] = &derFV[i];
    varC->nADVars++;
  }
}

// scalar : variable additions using VarEx and VarCont (simplification to implementation classes)
void IOnVarInit::AddLocalVar(double* V, VarEx* varEx, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  SizeVars(1, varC, bADOnly);
  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  if (!bADOnly)
  {
    CComBSTR local_prefix = prefix;
    if (local_prefix.Length() > 0) local_prefix.Append(L".");
    if (Name) local_prefix.Append(Name);

    varC->vars[nVars] = V;
    varC->derVars[nVars] = &(varEx->der);
    varC->oldVars[nVars] = &(varEx->old);
    varC->derOldVars[nVars] = &(varEx->der_old);
    if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
    varC->Names[nVars] = ::SysAllocString(local_prefix);
    nVars++;
  }
  varC->FVars[nADVars] = &(varEx->ad);
  varC->derFVars[nADVars] = &(varEx->der_ad);
  nADVars++;
}

void IOnVarInit::AddLocalVar(OnStlVec<double>* var, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i;
  _TCHAR buffer[10];
  long size = var->size();
  SizeVars(size, varC, bADOnly);
  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  if (!bADOnly)
  {
    CComBSTR local_prefix = prefix;
    CComBSTR itemName;
    if (local_prefix.Length() > 0) local_prefix.Append(L".");
    if (Name) local_prefix.Append(Name);

    for (i = 0; i < size; i++)
    {
      varC->vars[nVars] = &(var->_Ptr[i]);
      varC->derVars[nVars] = &(var->der._Ptr[i]);
      varC->oldVars[nVars] = &(var->old._Ptr[i]);
      varC->derOldVars[nVars] = &(var->der_old._Ptr[i]);
      if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
      itemName = local_prefix;
      itemName.Append(L"[");
      _ltot( i, buffer, 10 );
      itemName.Append(buffer);
      itemName.Append(L"]");
      varC->Names[nVars] = ::SysAllocString(itemName);
      nVars++;
    }
  }

  for (i = 0; i < size; i++)
  {
    varC->FVars[nADVars] = &(var->ad._Ptr[i]);
    varC->derFVars[nADVars] = &(var->der_ad._Ptr[i]);
    nADVars++;
  }
}

// vector : variable additions using VarEx and VarCont (simplification to implementation classes)
void IOnVarInit::AddLocalVar(double* V, VarExV* varEx, _TCHAR* Name, const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i;
  CComBSTR locName;
  CComBSTR modName;
  _TCHAR buffer[10];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeVars(varEx->nVar, varC, bADOnly);
  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  VarExV& vEx = *varEx;

  for (i = 0; i < varEx->nVar; i++)
  {
    
    if (!bADOnly)
    {
      varC->vars[nVars] = &V[i];
      varC->derVars[nVars] = &(vEx[i].der);
      varC->oldVars[nVars] = &(vEx[i].old);
      varC->derOldVars[nVars] = &(vEx[i].der_old);
      modName = locName;
      _ltot( i, buffer, 10 );
      modName.Append(buffer);
      modName.Append(L"]");
      if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
      varC->Names[nVars] = modName.Detach();
      nVars++;
    }

    varC->FVars[nADVars] = &(vEx[i].ad);
    varC->derFVars[nADVars] = &(vEx[i].der_ad);
    nADVars++;
  }
}

// DistributedVar scalar : variable additions using DistributedVarEx and VarCont (simplification to implementation classes)
void IOnVarInit::AddLocalVar(DistributedVar* V, DistributedVarEx* varEx, _TCHAR* Name, const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i;
  CComBSTR locName;
  CComBSTR modName;
  _TCHAR buffer[10];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeVars(V->nVal, varC, bADOnly);
  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  
  for (i = 0; i < V->nVal; i++)
  {
    if (!bADOnly)
    {
      varC->vars[nVars] = &(V->pVal[i]);
      varC->derVars[nVars] = &(varEx->der.pVal[i]);
      varC->oldVars[nVars] = &(varEx->old.pVal[i]);
      varC->derOldVars[nVars] = &(varEx->der_old.pVal[i]);
      modName = locName;
      _ltot( i, buffer, 10 );
      modName.Append(buffer);
      modName.Append(L"]");
      if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
      varC->Names[nVars] = modName.Detach();
      nVars++;
    }

    varC->FVars[nADVars] = &(varEx->ad.pVal[i]);
    varC->derFVars[nADVars] = &(varEx->der_ad.pVal[i]);
    nADVars++;
  }
}

// DistributedVar vector : variable additions using DistributedVarEx and VarCont (simplification to implementation classes)
void IOnVarInit::AddLocalVar(DistributedVar** V, DistributedVarExV* varEx, _TCHAR* Name, const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  // TODO: finish this implementation
  _ASSERTE(0);
}





// full matrix
void IOnVarInit::AddLocalVar(double** V, double** derV, double** oldV, double** derOldV, Fdouble** FV, Fdouble** derFV, long nRows, long nCols, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = nRows * nCols;

  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeVars(Size, varC, bADOnly);

  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < nCols; j++)
    {
      if (!bADOnly)
      {
        varC->vars[nVars] = &V[i][j];
        varC->derVars[nVars] = &derV[i][j];
        varC->oldVars[nVars] = &oldV[i][j];
        varC->derOldVars[nVars] = &derOldV[i][j];
        modName2 = modName1;
        _ltot( j, buffer, 10 );
        modName2.Append(buffer);
        modName2.Append(L"]");
        if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
        varC->Names[nVars] = modName2.Detach();
        nVars++;
      }

      varC->FVars[nADVars] = &FV[i][j];
      varC->derFVars[nADVars] = &derFV[i][j];
      nADVars++;
    }
  }
}

// sparse matrix mat[r][c]
void IOnVarInit::AddLocalVar(double** V, double** derV, double** oldV, double** derOldV, Fdouble** FV, Fdouble** derFV, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = 0;

  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  
  for (i = 0; i < nRows; i++) Size += sizeCols[i];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeVars(Size, varC, bADOnly);

  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < sizeCols[i]; j++)
    {
      if (!bADOnly)
      {
        varC->vars[nVars] = &V[i][j];
        varC->derVars[nVars] = &derV[i][j];
        varC->oldVars[nVars] = &oldV[i][j];
        varC->derOldVars[nVars] = &derOldV[i][j];
        modName2 = modName1;
        _ltot( j, buffer, 10 );
        modName2.Append(buffer);
        modName2.Append(L"]");
        if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
        varC->Names[nVars] = modName2.Detach();
        nVars++;
      }

      varC->FVars[nADVars] = &FV[i][j];
      varC->derFVars[nADVars] = &derFV[i][j];
      nADVars++;
    }
  }
}


// sparse matrix mat[nColIndices]
void IOnVarInit::AddLocalVar(double* V, double* derV, double* oldV, double* derOldV, Fdouble* FV, Fdouble* derFV, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = 0;
  long nColIndices;

  long& nVars = varC->nVars;
  long& nADVars = varC->nADVars;
  
  for (i = 0; i < nRows; i++) Size += sizeCols[i];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeVars(Size, varC, bADOnly);

  nColIndices = 0;
  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < sizeCols[i]; j++)
    {
      if (!bADOnly)
      {
        varC->vars[nVars] = &V[nColIndices];
        varC->derVars[nVars] = &derV[nColIndices];
        varC->oldVars[nVars] = &oldV[nColIndices];
        varC->derOldVars[nVars] = &derOldV[nColIndices];
        modName2 = modName1;
        _ltot( j, buffer, 10 );
        modName2.Append(buffer);
        modName2.Append(L"]");
        if (varC->Names[nVars]) ::SysFreeString(varC->Names[nVars]);
        varC->Names[nVars] = modName2.Detach();
        nVars++;
      }
      varC->FVars[nADVars] = &FV[nColIndices];
      varC->derFVars[nADVars] = &derFV[nColIndices];
      nADVars++;

      nColIndices++;
    }
  }
}

void IOnVarInit::AddLocalVar(IOnVarInit* pVar, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  CComBSTR local_prefix = prefix;
  if (local_prefix.Length() > 0) local_prefix.Append(L".");
  if (Name) local_prefix.Append(Name);

  pVar->InitLocalVars(local_prefix, varC, bADOnly);
}



// real parameters


// scalar
void IOnVarInit::AddLocalRPar(
  double* V, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nRPars, long* dRPars)
{
  CComBSTR local_prefix = prefix;
  if (local_prefix.Length() > 0) local_prefix.Append(L".");
  if (Name) local_prefix.Append(Name);

  SizeRPars(1, RPars, Names, nRPars, dRPars);
  (*RPars)[*nRPars] = V;
  if ((*Names)[*nRPars]) ::SysFreeString((*Names)[*nRPars]);
  (*Names)[*nRPars] = ::SysAllocString(local_prefix);
  (*nRPars)++;
}

// vector
void IOnVarInit::AddLocalRPar(double* V, long Size, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nRPars, long* dRPars)
{
  long i;
  CComBSTR locName;
  CComBSTR modName;
  _TCHAR buffer[10];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeRPars(Size, RPars, Names, nRPars, dRPars);
  for (i = 0; i < Size; i++)
  {
    (*RPars)[*nRPars] = &V[i];
    modName = locName;
    _ltot( i, buffer, 10 );
    modName.Append(buffer);
    modName.Append(L"]");
    if ((*Names)[*nRPars]) ::SysFreeString((*Names)[*nRPars]);
    (*Names)[*nRPars] = modName.Detach();
    (*nRPars)++;
  }
}

// full matrix
void IOnVarInit::AddLocalRPar(double** V, long nRows, long nCols, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nRPars, long* dRPars)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = nRows * nCols;

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeRPars(Size, RPars, Names, nRPars, dRPars);

  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < nCols; j++)
    {
      (*RPars)[*nRPars] = &V[i][j];
      modName2 = modName1;
      _ltot( j, buffer, 10 );
      modName2.Append(buffer);
      modName2.Append(L"]");
      if ((*Names)[*nRPars]) ::SysFreeString((*Names)[*nRPars]);
      (*Names)[*nRPars] = modName2.Detach();
      (*nRPars)++;
    }
  }
}

// sparse matrix mat[r][c]
void IOnVarInit::AddLocalRPar(double** V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nRPars, long* dRPars)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = 0;
  
  for (i = 0; i < nRows; i++) Size += sizeCols[i];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeRPars(Size, RPars, Names, nRPars, dRPars);

  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < sizeCols[i]; j++)
    {
      (*RPars)[*nRPars] = &V[i][j];
      modName2 = modName1;
      _ltot( j, buffer, 10 );
      modName2.Append(buffer);
      modName2.Append(L"]");
      if ((*Names)[*nRPars]) ::SysFreeString((*Names)[*nRPars]);
      (*Names)[*nRPars] = modName2.Detach();
      (*nRPars)++;
    }
  }
}


// sparse matrix mat[nColIndices]
void IOnVarInit::AddLocalRPar(double* V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nRPars, long* dRPars)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = 0;
  long nColIndices;
  for (i = 0; i < nRows; i++) Size += sizeCols[i];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeRPars(Size, RPars, Names, nRPars, dRPars);

  nColIndices = 0;
  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < sizeCols[i]; j++)
    {
      (*RPars)[*nRPars] = &V[nColIndices];
      modName2 = modName1;
      _ltot( j, buffer, 10 );
      modName2.Append(buffer);
      modName2.Append(L"]");
      if ((*Names)[*nRPars]) ::SysFreeString((*Names)[*nRPars]);
      (*Names)[*nRPars] = modName2.Detach();
      (*nRPars)++;
      nColIndices++;
    }
  }
}

void IOnVarInit::AddLocalRPar(IOnVarInit* pRPar, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nRPars, long* dRPars)
{
  CComBSTR local_prefix = prefix;
  if (local_prefix.Length() > 0) local_prefix.Append(L".");
  if (Name) local_prefix.Append(Name);
  pRPar->InitLocalRPars(local_prefix, RPars, Names, nRPars, dRPars);
}


// real parameters


// scalar
void IOnVarInit::AddLocalIPar(
  long* V, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nIPars, long* dIPars)
{
  CComBSTR local_prefix = prefix;
  if (local_prefix.Length() > 0) local_prefix.Append(L".");
  if (Name) local_prefix.Append(Name);

  SizeIPars(1, IPars, Names, nIPars, dIPars);
  (*IPars)[*nIPars] = V;
  if ((*Names)[*nIPars]) ::SysFreeString((*Names)[*nIPars]);
  (*Names)[*nIPars] = ::SysAllocString(local_prefix);
  (*nIPars)++;
}

// vector
void IOnVarInit::AddLocalIPar(long* V, long Size, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nIPars, long* dIPars)
{
  long i;
  CComBSTR locName;
  CComBSTR modName;
  _TCHAR buffer[10];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeIPars(Size, IPars, Names, nIPars, dIPars);
  for (i = 0; i < Size; i++)
  {
    (*IPars)[*nIPars] = &V[i];
    modName = locName;
    _ltot( i, buffer, 10 );
    modName.Append(buffer);
    modName.Append(L"]");
    if ((*Names)[*nIPars]) ::SysFreeString((*Names)[*nIPars]);
    (*Names)[*nIPars] = modName.Detach();
    (*nIPars)++;
  }
}

// full matrix
void IOnVarInit::AddLocalIPar(long** V, long nRows, long nCols, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nIPars, long* dIPars)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = nRows * nCols;

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeIPars(Size, IPars, Names, nIPars, dIPars);

  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < nCols; j++)
    {
      (*IPars)[*nIPars] = &V[i][j];
      modName2 = modName1;
      _ltot( j, buffer, 10 );
      modName2.Append(buffer);
      modName2.Append(L"]");
      if ((*Names)[*nIPars]) ::SysFreeString((*Names)[*nIPars]);
      (*Names)[*nIPars] = modName2.Detach();
      (*nIPars)++;
    }
  }
}

// sparse matrix mat[r][c]
void IOnVarInit::AddLocalIPar(long** V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nIPars, long* dIPars)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = 0;
  
  for (i = 0; i < nRows; i++) Size += sizeCols[i];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeIPars(Size, IPars, Names, nIPars, dIPars);

  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < sizeCols[i]; j++)
    {
      (*IPars)[*nIPars] = &V[i][j];
      modName2 = modName1;
      _ltot( j, buffer, 10 );
      modName2.Append(buffer);
      modName2.Append(L"]");
      if ((*Names)[*nIPars]) ::SysFreeString((*Names)[*nIPars]);
      (*Names)[*nIPars] = modName2.Detach();
      (*nIPars)++;
    }
  }
}


// sparse matrix mat[nColIndices]
void IOnVarInit::AddLocalIPar(long* V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nIPars, long* dIPars)
{
  long i, j;
  CComBSTR locName;
  CComBSTR modName1;
  CComBSTR modName2;
  _TCHAR buffer[10];
  long Size = 0;
  long nColIndices;
  for (i = 0; i < nRows; i++) Size += sizeCols[i];

  locName = prefix;
  if (locName.Length() > 0) locName.Append(L".");
  if (Name) locName.Append(Name);
  locName.Append(L"[");

  SizeIPars(Size, IPars, Names, nIPars, dIPars);

  nColIndices = 0;
  for (i = 0; i < nRows; i++)
  {
    modName1 = locName;
    _ltot( i, buffer, 10 );
    modName1.Append(buffer);
    modName1.Append(L"][");
    for (j = 0; j < sizeCols[i]; j++)
    {
      (*IPars)[*nIPars] = &V[nColIndices];
      modName2 = modName1;
      _ltot( j, buffer, 10 );
      modName2.Append(buffer);
      modName2.Append(L"]");
      if ((*Names)[*nIPars]) ::SysFreeString((*Names)[*nIPars]);
      (*Names)[*nIPars] = modName2.Detach();
      (*nIPars)++;
      nColIndices++;
    }
  }
}

void IOnVarInit::AddLocalIPar(IOnVarInit* pIPar, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nIPars, long* dIPars)
{
  CComBSTR local_prefix = prefix;
  if (local_prefix.Length() > 0) local_prefix.Append(L".");
  if (Name) local_prefix.Append(Name);

  pIPar->InitLocalIPars(local_prefix, IPars, Names, nIPars, dIPars);
}



// *********************************************************************************************
// VarExV

  
VarExV::~VarExV()
{
  clean();
}

void VarExV::init(double* v, long len)
{
  clean();
  nVar = len;
  pVar = new VarEx[nVar];
}

void VarExV::clean() 
{ 
  DESTROY_VECTOR(pVar)
}

inline VarEx& VarExV::operator [] (long idx)
{
  return pVar[idx];  
}

// end VarExV
// *********************************************************************************************



// *********************************************************************************************
// VarCont

VarCont::VarCont()
{
  vars = NULL;
  derVars = NULL;
  oldVars = NULL;
  derOldVars = NULL;
  FVars = NULL;
  derFVars = NULL;
  Names = NULL; 
  nVars = 0;
  dVars = 0;
  nADVars = 0;
  dADVars = 0;
}

VarCont::~VarCont()
{
  clean();
}

void VarCont::clean()
{
  DESTROY_VECTOR(vars)
  DESTROY_VECTOR(derVars)
  DESTROY_VECTOR(oldVars)
  DESTROY_VECTOR(derOldVars)
  DESTROY_VECTOR(FVars)
  DESTROY_VECTOR(derFVars)
  DESTROY_BSTR_ARRAY(Names, nVars)
  nVars = 0;
  dVars = 0;
  nADVars = 0;
  dADVars = 0;
}

// end VarCont
// *********************************************************************************************


// *********************************************************************************************
// DistributedVarEx

void DistributedVarEx::init(DistributedVar& src)
{
  der.init(src);
  old.init(src);
  der_old.init(src);
  ad.init(src);
  der_ad.init(src);
}

void DistributedVarEx::setParent(DistributedVarEx& src)
{
  der.pParent = src.der.pParent;
  old.pParent = src.old.pParent;
  der_old.pParent = src.der_old.pParent;
  ad.pParent = src.ad.pParent;
  der_ad.pParent = src.der_ad.pParent;
}

// end DistributedVarEx
// *********************************************************************************************



// *********************************************************************************************
// DistributedVarExV

DistributedVarExV::DistributedVarExV() : pVar(NULL), nVar(0) 
{ 

}

DistributedVarExV::~DistributedVarExV() 
{ 
  clean(); 
}

void DistributedVarExV::init(DistributedVar*& src, long len)
{
  clean();

  nVar = len;
  pVar = new DistributedVarEx[nVar];

  for (long i = 0; i < nVar; i++)
    pVar[i].init(src[i]);
}

void DistributedVarExV::clean() 
{ 
  DESTROY_VECTOR(pVar)
  nVar = 0;
}

void DistributedVarExV::setParent(DistributedVarExV& src)
{
  for (long i = 0; i < nVar; i++)
    pVar[i].setParent(src.pVar[i]);
}

DistributedVarEx& DistributedVarExV::operator [] (long idx)
{
  return pVar[idx];
}

// end DistributedVarExV
// *********************************************************************************************
