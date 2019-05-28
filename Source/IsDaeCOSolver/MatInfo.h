/*
Matrix types:

Sparse Vector: List of nonzero elements with their index locations. It assumes no particular ordering of 
elements. 

COOR Matrix: Coordinate Storage Matrix. List of nonzero elements with their respective row and column 
indices. This is the most general sparse matrix format, but it is not very space or computationally 
efficient. It assumes no ordering of nonzero matrix values. 

CRS Matrix : Compressed Row Storage Matrix. Subsequent nonzeros of the matrix rows are stored in 
contiguous memory locations and an additional integer arrays specifies where each row begins. It 
assumes no ordering among nonzero values within each row, but rows are stored in consecutive order. 

CCS Matrix: Compressed Column Storage (also commonly known as the Harwell­Boeing sparse matrix for­ 
mat [4]). This is a variant of CRS storage where columns, rather rows, are stored contiguously. Note 
that the CCS ordering of A is the same as the CRS of A T . 

CDS Matrix: Compressed Diagonal Storage. Designed primarily for matrices with relatively constant band­ 
width, the sub and super­diagonals are stored in contiguous memory locations. 

JDS Matrix: Jagged Diagonal Storage. Also know as ITPACK storage. More space efficient than CDS matrices 
at the cost of a gather/scatter operation. 

BCRS Matrix: Block Compressed Row Storage. Useful when the sparse matrix is comprised of square dense 
blocks of nonzeros in some regular pattern. The savings in storage and reduced indirect addressing 
over CRS can be significant for matrices with large block sizes. 

SKS Matrix: Skyline Storage. Also for variable band or profile matrices. Mainly used in direct solvers, but 
can also be used for handling the diagonal blocks in block matrix factorizations. 

Symmetric, Hermitian  In such cases only an upper (or lower) triangular portion of the matrix is stored. 


*/


/*
FULL      { nRows, nCols, val[row][col]}
SPARSE    { indCol, valCol, ispRow, cnzRow }
  indCol - index of non-zero columns             (length = # non-zero columns) 
  valCol - value of each column entry            (length = # non-zero columns)
  ispRow - index of row starting point in iCol   (length = nRow)
  cnzRow - count of non-zero columns in each row (length = nRow [redundant])
U_TRIANGULAR (upper triangular - all values below the main diagonal are 0)
L_TRIANGULAR (lower triangular - all values above the main diagonal are 0)
DIAGONAL     (symmetric matrix where all values off main diagonal are 0)
TRIDIAGONAL  (3 non-zero diagonals only)  length = 3*n
BANDED       (lowerBandwidth lower diagonals, upperBandwidth upper diagonals) (lb + ub + 1)*n
HESSENBURG
*/

#ifndef _MAT_INFO_H_
#define _MAT_INFO_H_

#include "OnDaeCOSolverExport.h"


typedef enum MatForm {FULL, SPARSE, U_TRIANGULAR, L_TRIANGULAR, DIAGONAL, TRIDIAGONAL, BANDED, HESSENBURG} MatFORM;


// Note:: add symmetric flag
class ONDAECOSOLVER_API MatInfo
{	// useful for Iteration, Jacobians and Mass matrices

public:
	MatInfo();
	MatInfo(long n, long m, bool bNumeric,double*  vec);
	~MatInfo();

  MatInfo& operator=(const MatInfo& other);

  void Init();
  void SetCompactSize(long nEqns, long nColIndices);
  void SetActiveCompactSize(MatInfo& other, long* activeRows, long nActiveRows);

  // bool update(double** structureData, double t, double*  y, double* ydot);
	void decompose();
	void multiplyVec(double* x, double* &b); 
	void SolveEquation(double* b);
  bool GetValue(long iRow, long iCol, double& val);
	bool SetValue(long iRow, long iCol, double val);

  void spMatrixDestroy();
  void spMatrixInit();

  // serialization
  void Save(FILE* fs);
  bool Load(FILE* fs);

public:
	bool	m_updateRequired;
	bool  m_dataUpToDate;
	bool	m_decompositionRequired;
	MatForm	m_form;
	long	m_nRows;
	long	m_nCols;
	long	m_lowerBandwidth;	// if not banded, lower=number of rows
	long	m_upperBandwidth;	// if not banded, upper=number of columns
	double** 	m_data;
	double**	m_L; 
	long*		m_index; 
	double		m_sign;  

  // sparse structure support
  long m_nColIndices;
  long m_dColIndices;  // dimension used when allocating vectors of length m_nColIndices
  long* m_ColIndices;
  long* m_cNZCols;
  long* m_spRowPage;
  long* m_compact_data;
  double* m_compact_value;
  bool* m_bValueSet;

  // sparse solver support
  char* m_spMatrix;
  int* m_spRowIndex;
  int* m_spColIndex;
  bool m_bFullDecompositionRequired; // on startup and event initialization

  // Added for efficient passing of matrix information via SafeArrays
  SAFEARRAY* m_psa_data;  // SA of SAs wrapping m_data
  VARIANT* m_pv_data;     // array of SAs (data pointer from m_psa_data)
  SAFEARRAY* m_psa_L;     // SA of SAs wrapping m_L
  VARIANT* m_pv_L;        // array of SAs (data pointer from m_psa_L)
};

#endif // _MAT_INFO_H_