
#ifndef _STEP_SIZE_INFO_H_
#define _STEP_SIZE_INFO_H_


class StepSizeInfo 

{ // can be instantiated for calc and/or graphics

public:
	StepSizeInfo();
  ~StepSizeInfo();

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
  bool	m_adaptive;
  double	m_initVal;
  double	m_lastVal;
  double  m_maxVal;
  double	m_min_Val;
  double	m_curVal;
  double	m_predictedVal;
  double  m_LUVal;
  double	m_minChangeFactor;
  double	m_maxChangeFactor;
  double  m_eventChangeFactor;        // factor used for m_maxEventStepperCalls steps after events
  long    m_eventStepCount;           // count of stepper calls when last event was processed
  long    m_maxEventStepCount;        // number of stepper calls m_eventChangeFactor is active after an event 
  bool    m_eventChangeFactorApplied; // flag indicating that the eventChangeFactor has been applied at least once
  double	m_rigidChangeFactor;
  double	m_alignmentFactor;					// omega  = 0.05e0; (used in control module)
  double	m_updateFormulaCoeff;				// zeta in error
  double	m_updateFormulaMinExponent;			// pmin in error
};

#endif // _STEP_SIZE_INFO_H_