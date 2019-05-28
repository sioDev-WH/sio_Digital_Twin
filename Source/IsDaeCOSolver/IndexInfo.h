#ifndef _INDEX_INFO_H_
#define _INDEX_INFO_H_


class IndexInfo {

public:
	IndexInfo();
  ~IndexInfo();

  void Destroy();
  void Init(long nEqns);

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
	bool	m_scalar;	     // index = 1 (ODE or DAE of index 1)
	short* m_daeIndex;   // index of DAE's
	bool	m_isHighIndex; // Comment if problem is high index 
  long m_Size;
};

#endif // _INDEX_INFO_H_