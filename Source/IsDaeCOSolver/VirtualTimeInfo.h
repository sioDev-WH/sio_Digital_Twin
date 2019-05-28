#ifndef _VIRTUAL_TIME_INFO_H_
#define _VIRTUAL_TIME_INFO_H_



class VirtualTimeInfo
{	// can be instantiated for calc and/or graphics

public:
	VirtualTimeInfo(); 
  VirtualTimeInfo(long nSize);
  ~VirtualTimeInfo();

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
	double	m_initVal;
	double	m_curVal;
	double	m_lastVal;
	unsigned long	m_curIteration;
	double	m_endVal;
	double* m_sequence;	// if for graphics then it will include interpolated
	long	m_size;
	double	m_samplingRate;
	unsigned long m_curSampleIndex;	
  bool m_reverse;
};

#endif // _VIRTUAL_TIME_INFO_H_