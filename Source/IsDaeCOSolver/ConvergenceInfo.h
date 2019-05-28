#ifndef _CONVERGENCE_INFO_H_
#define _CONVERGENCE_INFO_H_

class ConverganceInfo{

public:
	ConverganceInfo();
  ~ConverganceInfo();

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
	bool m_ready;
	// bool m_diver;
	bool m_slow; 
	bool m_solved; 
	bool m_exact;
	double	m_curVal;
	double	m_curRate;	// Rate of convergence (alpha)
	double	m_initialRate;	// Initial Rate of convergence (alpha1)
	double m_rateFactor;  // xi     = 1.2e0;
	double m_desiredRate; // alphaRef desired rate of convergance (control module)
    double m_updateThresholdRate; // alphaJac = 0.1e0; threshold used to detect need to update Jacobian
    double m_decompositionThresholdRate; //alphaLU  = 0.2e0; // threshold used to detect need to decomp iteration matrix
	bool	m_growing;
	bool	m_diverged;
	bool	m_converged;
	unsigned long 	m_newtonIterationIndex;
	unsigned long 	m_newtonIterationMaxIndex;
	double m_tau;
	double m_kappa; 
	double m_gamma; 
	double m_theta;
	double m_gfac;  
	double m_uround;
};

#endif // _CONVERGENCE_INFO_H_