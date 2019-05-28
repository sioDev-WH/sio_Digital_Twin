#ifndef _VAR_INFO_H_
#define _VAR_INFO_H_


class VarInfo
{

public:
  VarInfo(long nVars);
  void Init(long nVars);
  void CommonConstruction(long nVars);

  bool Load(FILE* fs);
  void Save(FILE* fs);

	~VarInfo();

public:
	long m_varSize;
	double* m_var_init;
	double* m_varVal;
	double* m_varDeltaVal;
	double* m_varLastVal;
	double* m_varDot_init;
	double* m_varDotVal;
	double* m_varDeltaDotVal;
	double* m_varLastDotVal;
	double* m_residualVal;

  // SafeArray wrappers of the above
	SAFEARRAY* m_psa_var_init;
	SAFEARRAY* m_psa_varVal;
	SAFEARRAY* m_psa_varDeltaVal;
	SAFEARRAY* m_psa_varLastVal;
	SAFEARRAY* m_psa_varDot_init;
	SAFEARRAY* m_psa_varDotVal;
	SAFEARRAY* m_psa_varDeltaDotVal;
	SAFEARRAY* m_psa_varLastDotVal;
	SAFEARRAY* m_psa_residualVal;

	bool	m_valInvalid; // Set to false before calling a function that 
                      // evaluates of any the members to adapt step size
};

#endif // _VAR_INFO_H_