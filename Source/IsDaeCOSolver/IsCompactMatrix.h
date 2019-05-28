
class CIsCompactMatrix // equation association list structure
{
public:
  long m_nRows;
  long* m_nCols;
  long** m_iColIndices;
  double** m_vals;

  CIsCompactMatrix();
  ~CIsCompactMatrix();
  void Destroy();
  void SetRowCount(long nRows);
  void InitRow( long iRow, long count, ... );
  void InitCompact(long nRows, long* inzCol, long* ispRow, long* cnzCol);
};
