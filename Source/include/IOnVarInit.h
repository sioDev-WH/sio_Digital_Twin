// IOnVarInit.h

#ifndef _IONVARINIT_H_
#define _IONVARINIT_H_

#include "OnUMLEsoExports.h"
#include "OnStlVecBase.h"



// PDE
#include "DistributionDomain.h"
#include "DistributedVar.h"
#include "FDistributedVar.h"
#include "OnAD.h"
#include "OnUMLEsoExports.h"

// VarEx defines the extended forms of a distributed variable
struct ONUML_API VarEx
{
  double der;
  double old;
  double der_old;
  Fdouble ad;
  Fdouble der_ad;
};

// VarExV defines the extended forms of a distributed variable (for vector variables)
struct ONUML_API VarExV
{
  VarEx* pVar;
  long nVar;

  VarExV() : pVar(NULL), nVar(0) { }
  ~VarExV();
  void init(double* v, long len);
  void clean(); 
  VarEx& operator [] (long idx);
};

struct ONUML_API VarCont
{
  double** vars;
  double** derVars;
  double** oldVars;
  double** derOldVars;
  Fdouble** FVars;
  Fdouble** derFVars;
  _TCHAR** Names; 
  long nVars;
  long dVars;
  long nADVars;
  long dADVars;

  VarCont();
  ~VarCont();
  void clean();

};


// DistributedVarEx defines the extended forms of a distributed variable
struct ONUML_API DistributedVarEx
{
  DistributedVar der;
  DistributedVar old;
  DistributedVar der_old;
  FDistributedVar ad;
  FDistributedVar der_ad;

  void init(DistributedVar& src);
  void setParent(DistributedVarEx& src);
};

struct ONUML_API DistributedVarExV
{
  DistributedVarEx* pVar;
  long nVar;

  DistributedVarExV();
  ~DistributedVarExV();
  void init(DistributedVar*& src, long len);
  void clean(); 
  void setParent(DistributedVarExV& src);
  DistributedVarEx& operator [] (long idx);
};

// end PDE

#define DIRECT_OFFSET 1000000

#ifndef _UMLDaeEsoBase_Macros_
#define _UMLDaeEsoBase_Macros_

#define RETURN_VARIABLE_VALUE(VARNAME, TIME_STAMP, P_VAL) \
  static long idx = -1; \
  HRESULT hr = E_FAIL; \
  if (m_pOnModel) \
  { \
    hr = S_OK; \
    if (idx < 0) hr = m_pOnModel->GetVariableId(VARNAME, &idx); \
    if (idx >= 0 && SUCCEEDED(hr)) hr = m_pOnModel->GetVariable(idx - DIRECT_OFFSET, TIME_STAMP, P_VAL); \
  } \
  return hr;

#define GET_VARIABLE_VALUE(VARNAME, TIME_STAMP, P_VAL) \
  if (m_pOnModel) \
  { \
    static long idx = -1; \
    if (idx < 0) m_pOnModel->GetVariableId(VARNAME, &idx); \
    if (idx >= 0) m_pOnModel->GetVariable(idx - DIRECT_OFFSET, TIME_STAMP, P_VAL); \
  }

#define RETURN_VARIABLE_DER_VALUE(VARNAME, TIME_STAMP, P_VAL) \
  HRESULT hr = E_FAIL; \
  if (m_pOnModel) \
  { \
    static long idx = -1; \
    hr = S_OK; \
    if (idx < 0) hr = m_pOnModel->GetVariableId(VARNAME, &idx); \
    if (idx >= 0 && SUCCEEDED(hr)) hr = m_pOnModel->GetDerivative(idx - DIRECT_OFFSET, TIME_STAMP, P_VAL); \
  } \
  return hr;

#define GET_VARIABLE_DER_VALUE(VARNAME, TIME_STAMP, P_VAL) \
  if (m_pOnModel) \
  { \
    static long der_idx = -1; \
    if (der_idx < 0) m_pOnModel->GetVariableId(VARNAME, &der_idx); \
    if (der_idx >= 0) m_pOnModel->GetDerivative(der_idx - DIRECT_OFFSET, TIME_STAMP, P_VAL); \
  }

#define POST_RPAR(RPARNAME, TIME_STAMP, VAL) \
  static long idx = -1; \
  HRESULT hr = E_FAIL; \
  if (m_pOnModel) \
  { \
    hr = S_OK; \
    if (idx < 0) hr = m_pOnModel->GetRealParId(RPARNAME, &idx); \
    if (idx >= 0 && SUCCEEDED(hr)) hr = PostRealParameter(TIME_STAMP, idx, VAL); \
  } \
  return hr;
 

#define POST_IPAR(IPARNAME, TIME_STAMP, VAL) \
  static long idx = -1; \
  HRESULT hr = E_FAIL; \
  if (m_pOnModel) \
  { \
    hr = S_OK; \
    if (idx < 0) hr = m_pOnModel->GetIntParId(IPARNAME, &idx); \
    if (idx >= 0 && SUCCEEDED(hr)) hr = PostIntegerParameter(TIME_STAMP, idx, VAL); \
  } \
  return hr;

#ifdef _STL_UML_MACROS

// macro for referencing state transition pre_condition of variables
#define pre(ITEM) ITEM.old 
#define PRE(ITEM) ITEM.old 

#define old(ITEM) ITEM.old 
#define OLD(ITEM) ITEM.old 

// macro for derivative of variables
#define der(ITEM) ITEM.der 
#define DER(ITEM) ITEM.der 

// macro for Fdouble version of variables
#define ad(ITEM) ITEM.ad
#define AD(ITEM) ITEM.ad

// macro for DER(AD(ITEM)) version of variables
#define der_ad(ITEM) ITEM.der_ad
#define DER_AD(ITEM) ITEM.der_ad

// macro for DER(OLD(ITEM)) version of variables
#define der_old(ITEM) ITEM.der_old
#define DER_OLD(ITEM) ITEM.der_old

// support scalar macros using macros with s_ prefix

// macro for referencing state transition pre_condition of variables
#define s_pre(ITEM) _##ITEM.old 
#define S_PRE(ITEM) _##ITEM.old 

#define s_old(ITEM) _##ITEM.old 
#define S_OLD(ITEM) _##ITEM.old 

// macro for derivative of variables
#define s_der(ITEM) _##ITEM.der 
#define S_DER(ITEM) _##ITEM.der 

// macro for Fdouble version of variables
#define s_ad(ITEM) _##ITEM.ad
#define S_AD(ITEM) _##ITEM.ad

// macro for DER(AD(ITEM) version of variables
#define s_der_ad(ITEM) _##ITEM.der_ad
#define S_DER_AD(ITEM) _##ITEM.der_ad

// macro for DER(OLD(ITEM) version of variables
#define s_der_old(ITEM) _##ITEM.der_old
#define S_DER_OLD(ITEM) _##ITEM.der_old


#endif // _STL_UML_MACROS


#ifdef _VAREX_UML_MACROS

// macro for referencing state transition pre_condition of variables
#define pre(ITEM) _##ITEM.old 
#define PRE(ITEM) _##ITEM.old 

#define old(ITEM) _##ITEM.old 
#define OLD(ITEM) _##ITEM.old 

// macro for derivative of variables
#define der(ITEM) _##ITEM.der 
#define DER(ITEM) _##ITEM.der 

// macro for Fdouble version of variables
#define ad(ITEM) _##ITEM.ad
#define AD(ITEM) _##ITEM.ad

// macro for DER(AD(ITEM) version of variables
#define der_ad(ITEM) _##ITEM.der_ad
#define DER_AD(ITEM) _##ITEM.der_ad

// macro for DER(OLD(ITEM) version of variables
#define der_old(ITEM) _##ITEM.der_old
#define DER_OLD(ITEM) _##ITEM.der_old

#endif // _VAREX_UML_MACROS



#ifndef _VAREX_UML_MACROS
#ifndef _STL_UML_MACROS

// macro for referencing state transition pre_condition of variables
#define pre(ITEM) old_##ITEM 
#define PRE(ITEM) old_##ITEM 

#define old(ITEM) old_##ITEM 
#define OLD(ITEM) old_##ITEM 

// macro for derivative of variables
#define der(ITEM) der_##ITEM 
#define DER(ITEM) der_##ITEM 

// macro for Fdouble version of variables
#define ad(ITEM) ad_##ITEM
#define AD(ITEM) ad_##ITEM

#endif // _STL_UML_MACROS
#endif // _VAREX_UML_MACROS
  
#endif // _UMLDaeEsoBase_Macros_


class Fdouble;

class ONUML_API IOnVarInit
{

public:
  virtual HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly) = 0;
	virtual HRESULT InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars) = 0;
	virtual HRESULT InitLocalIPars(const _TCHAR* prefix, long*** pars, _TCHAR*** Names, long* nPars, long* dPars) = 0;

protected:

// Initialization macros

//--------------------------------------------
// variables
//   scalar

#if defined(_STL_UML_MACROS) || defined(_VAREX_UML_MACROS)

#define ADD_LOCAL_SVAR(VAR) AddLocalVar( &VAR, &_##VAR, _T(#VAR), prefix, varC, bADOnly);
//   vector
#define ADD_LOCAL_VVAR(VEC, SIZE) AddLocalVar( VEC, _##VEC, SIZE, _T(#VEC), prefix, varC, bADOnly);

//   matrix
#define ADD_LOCAL_MVAR(MAT, SIZE1, SIZE2) AddLocalVar( MAT, der_##MAT, old_##MAT, der_old_##MAT, ad_##MAT, der_ad_##MAT, SIZE1, SIZE2, _T(#MAT), \
  prefix, varC, bADOnly);
//   complex type
#define ADD_LOCAL_CVAR(CVAR) AddLocalVar( CVAR, _T(#CVAR), \
  prefix, varC, bADOnly);

#define ADD_LOCAL_DIST_SVAR(VAR) AddLocalVar( &VAR, &_##VAR, _T(#VAR), \
  prefix, varC, bADOnly);

#define ADD_LOCAL_STLVAR(VAR) AddLocalVar( &VAR, _T(#VAR), prefix, varC, bADOnly);

#else

#define ADD_LOCAL_SVAR(VAR) AddLocalVar( &VAR, &der_##VAR, &old_##VAR, &der_old_##VAR, &ad_##VAR, &der_ad_##VAR, _T(#VAR), \
  prefix, varC, bADOnly);
//   vector
#define ADD_LOCAL_VVAR(VEC, SIZE) AddLocalVar( VEC, der_##VEC, old_##VEC, der_old_##VEC, ad_##VEC, der_ad_##VEC, SIZE, _T(#VEC), \
  prefix, varC, bADOnly);
//   matrix
#define ADD_LOCAL_MVAR(MAT, SIZE1, SIZE2) AddLocalVar( MAT, der_##MAT, old_##MAT, der_old_##MAT, ad_##MAT, der_ad_##MAT, SIZE1, SIZE2, _T(#MAT), \
  prefix, varC, bADOnly);
//   complex type
#define ADD_LOCAL_CVAR(CVAR) AddLocalVar( CVAR, _T(#CVAR), \
  prefix, varC, bADOnly);

#define ADD_LOCAL_DIST_SVAR(VAR) AddLocalVar( &VAR, &_##VAR, _T(#VAR), \
  prefix, varC, bADOnly);

#endif // _VAREX_UML_MACROS || _STL_UML_MACROS

//--------------------------------------------
// real paramters:
//   scalar
#define ADD_LOCAL_SRPAR(RPAR) AddLocalRPar( &RPAR, _T(#RPAR), \
  prefix, pars, Names, nPars, dPars );
//   vector
#define ADD_LOCAL_VRPAR(VEC, SIZE) AddLocalRPar( VEC, SIZE, _T(#VEC), \
  prefix, pars, Names, nPars, dPars );
//   matrix
#define ADD_LOCAL_MRPAR(MAT, SIZE1, SIZE2) AddLocalRPar( MAT, SIZE1, SIZE2, _T(#MAT), \
  prefix, pars, Names, nPars, dPars );
//   complex type
#define ADD_LOCAL_CRPAR(CRPAR) AddLocalRPar( &CRPAR, _T(#CRPAR), \
  prefix, pars, Names, nPars, dPars );

//--------------------------------------------
// integer parameters
//   scalar
#define ADD_LOCAL_SIPAR(IPAR) AddLocalIPar( &IPAR, _T(#IPAR), \
  prefix, pars, Names, nPars, dPars );
//   vector
#define ADD_LOCAL_VIPAR(VEC, SIZE) AddLocalIPar( VEC, SIZE, _T(#VEC), \
  prefix, pars, Names, nPars, dPars );
//   matrix
#define ADD_LOCAL_MIPAR(MAT, SIZE1, SIZE2) AddLocalIPar( MAT, SIZE1, SIZE2, _T(#MAT), \
  prefix, pars, Names, nPars, dPars );
//   complex type
#define ADD_LOCAL_CIPAR(CIPAR) AddLocalIPar( &CIPAR, _T(#CIPAR), \
  prefix, pars, Names, nPars, dPars );

//===================================================================
// helper functions

// variables

void AddLocalVar(
  double* V, double* derV, double* oldV, double* derOldV, Fdouble* FV, Fdouble* derFV, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// vector
void AddLocalVar(double* V, double* derV, double* oldV, double* derOldV, Fdouble* FV, Fdouble* derFV, long Size, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// full matrix
void AddLocalVar(double** V, double** derV, double** oldV, double** derOldV, Fdouble** FV, Fdouble** derFV, long nRows, long nCols, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// sparse matrix mat[r][c]
void AddLocalVar(double** V, double** derV, double** oldV, double** derOldV, Fdouble** FV, Fdouble** derFV, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// sparse matrix mat[nColIndices]
void AddLocalVar(double* V, double* derV, double* oldV, double* derOldV, Fdouble* FV, Fdouble* derFV, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);


// interface IOnVarInit (member user-defined class)
void AddLocalVar(IOnVarInit* pVar, _TCHAR* Name,
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);


// PDE begin

// scalar : variable additions using VarEx and VarCont (simplification to implementation classes)
void AddLocalVar(double* V, VarEx* varEx, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// vector : variable additions using VarEx and VarCont (simplification to implementation classes)
void AddLocalVar(double* V, VarExV* varEx, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

void AddLocalVar(OnStlVec<double>* var, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// DistributedVar scalar : variable additions using DistributedVarEx and VarCont (simplification to implementation classes)
void AddLocalVar(DistributedVar* V, DistributedVarEx* varEx, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// DistributedVar vector : variable additions using DistributedVarEx and VarCont (simplification to implementation classes)
void AddLocalVar(DistributedVar** V, DistributedVarExV* varEx, _TCHAR* Name, 
  const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

// PDE end


// real parameters


// scalar
void AddLocalRPar(
  double* V, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// vector
void AddLocalRPar(double* V, long Size, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// full matrix
void AddLocalRPar(double** V, long nRows, long nCols, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// sparse matrix mat[r][c]
void AddLocalRPar(double** V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// sparse matrix mat[nColIndices]
void AddLocalRPar(double* V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
void AddLocalRPar(IOnVarInit* pRPar, _TCHAR* Name,
  const _TCHAR* prefix, double*** RPars, _TCHAR*** Names, 
  long* nPars, long* dPars);


// integer parameters


// scalar
void AddLocalIPar(
  long* V, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// vector
void AddLocalIPar(long* V, long Size, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// full matrix
void AddLocalIPar(long** V, long nRows, long nCols, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// sparse matrix mat[r][c]
void AddLocalIPar(long** V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
// sparse matrix mat[nColIndices]
void AddLocalIPar(long* V, long nRows, long* sizeCols, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nPars, long* dPars);
void AddLocalIPar(IOnVarInit* pIPar, _TCHAR* Name,
  const _TCHAR* prefix, long*** IPars, _TCHAR*** Names, 
  long* nPars, long* dPars);


protected:
  void SizeVars(
    long Size, 
    VarCont* varC,
    const bool bADOnly);

  void SizeRPars(long Size, double*** pars, _TCHAR*** Names, long* nPars, long* dPars);
  void SizeIPars(long Size, long*** pars, _TCHAR*** Names, long* nPars, long* dPars);


};

#endif // _IONVARINIT_H_