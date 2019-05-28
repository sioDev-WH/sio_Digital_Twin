//{{SCG_IMPLEMENTATION(LookupTable.cpp) [0]

//{{SCG_INCLUDE  

// Cg_Add
#include "StdAfx.h" 
                   


                  
#include "LookupTable.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

LookupTable::LookupTable(){

}

LookupTable::~LookupTable(){

}

void LookupTable::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  m_nRows = 0;     
  m_nCols = 0;     
  m_x = NULL;     
  m_y = NULL;     
  m_Table = NULL;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void LookupTable::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long i;

  if (m_x) delete[] m_x;
  if (m_y) delete[] m_y;
  
  if (m_Table)
  {
    for (i = 0; i < m_nRows; i++) if (m_Table[i]) delete m_Table[i];
    delete[] m_Table;
  }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void LookupTable::interpolate_1D(const double x, double *z)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  long ix;
  double lambda;
  double D;
  double* Table1D;

  Table1D = m_Table[0];
  locate(x,m_nRows, m_x, &ix);
  *z=0;
  
  D=0;

  if(ix>m_nRows-2){
    ix=m_nRows-2;
    lambda = 1.0;
  }
  else if(ix<0){
    ix=0;
    lambda = 0.0;
  }
  else{
    D = m_x[ix+1]-m_x[ix]; 
    lambda = (x-m_x[ix])/D;  // if D==0 then error in table 
  }
  *z =(1-lambda)*Table1D[ix]+lambda*Table1D[ix+1];
  

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void LookupTable::interpolate_2D(const double x, const double y, double *z)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  long ix,iy;
  double lambdax, lambday,z1,z2;
  double D;

  locate(x,m_nRows, m_x, &ix);
  locate(y,m_nCols, m_y, &iy);

  if(ix>m_nRows-2){
    ix=m_nRows-2;
    lambdax = 1.0;
  }
  else if(ix<0){
    ix=0;
    lambdax = 0.0;
  }
  else{
    D = m_x[ix+1]-m_x[ix]; 
    lambdax = (x-m_x[ix])/D;  // if D==0 then error in table
  }

  if(iy>m_nCols-2){
    iy=m_nCols-2;
    lambday = 1.0;
  }
  else if(iy<0){
    iy=0;
    lambday = 0.0;
  }
  else{
    D = m_y[iy+1]-m_y[iy]; 
    lambday = (y-m_y[iy])/D;  // if D==0 then error in table
  }

  z1 =(1-lambdax)*m_Table[ix][iy]+lambdax*m_Table[ix+1][iy];
  z2 =(1-lambdax)*m_Table[ix][iy+1]+lambdax*m_Table[ix+1][iy+1];

  *z =(1-lambday)*z1+lambday*z2;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void LookupTable::locate(const double x, const long nData, const double* Data, long *i)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
	unsigned long upper,index,lower;
	int ascending;

	lower=-1;
	upper=nData;
	ascending=(Data[nData-1] > Data[0]);
	while (upper-lower > 1) {
		index=(upper+lower) >> 1;
    if (x >= Data[index] == ascending)
			lower=index;
		else
			upper=index;
	}
	*i=lower;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void LookupTable::init_1D(const int nRows, const double* x, const double* Table)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int i;
m_nRows = nRows;
m_nCols = 1;
m_x = new double[nRows];
m_y = 0;
m_Table = (double**) new double* [1];
m_Table[0] = (double*) new double[nRows];

for(i=0;i<nRows;i++){
  m_x[i] = x[i];
  m_Table[0][i] = Table[i];
}

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void LookupTable::init_2D(const int nRows, const int nCols, const double* x, const double* y, const double** Table)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int i,j;

m_nRows = nRows;
m_nCols = nCols;
m_x = new double[nRows];
m_y = new double[nCols];
m_Table = (double**) new double* [nRows];
for(i=0;i<nRows;i++)
   m_Table[i] = (double*) new double[nCols];

for(i=0;i<nRows;i++){
  m_x[i] = x[i];
  for(j=0;j<nCols;j++){
    m_y[j] = y[j];
    m_Table[i][j] = Table[i][j];
  }
}

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









