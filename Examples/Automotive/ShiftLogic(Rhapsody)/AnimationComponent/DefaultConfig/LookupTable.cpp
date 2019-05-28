/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: LookupTable
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\LookupTable.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "LookupTable.h"
#include "math.h"

//## package StandardModels 


//#[ ignore 
#define StandardModels_LookupTable_LookupTable_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_clean_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_init_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_init_1D_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_init_2D_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_interpolate_1D_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_interpolate_2D_SERIALIZE OM_NO_OP


#define StandardModels_LookupTable_locate_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// LookupTable.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(StandardModels)
//## class LookupTable 



LookupTable::LookupTable() {
    NOTIFY_CONSTRUCTOR(LookupTable, LookupTable(), 0, StandardModels_LookupTable_LookupTable_SERIALIZE);
    //#[ operation LookupTable() 
    //#]
}

LookupTable::~LookupTable() {
    NOTIFY_DESTRUCTOR(~LookupTable, TRUE);
    //#[ operation ~LookupTable() 
    //#]
}

void LookupTable::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, StandardModels_LookupTable_clean_SERIALIZE);
    //#[ operation clean() 
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
    //#]
}

void LookupTable::init() {
    NOTIFY_OPERATION(init, init(), 0, StandardModels_LookupTable_init_SERIALIZE);
    //#[ operation init() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
      m_nRows = 0;     
      m_nCols = 0;     
      m_x = NULL;     
      m_y = NULL;     
      m_Table = NULL;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

void LookupTable::init_1D(const int nRows, const double * x, const double * Table) {
    NOTIFY_OPERATION(init_1D, init_1D(const int ,const double * ,const double * ), 0, StandardModels_LookupTable_init_1D_SERIALIZE);
    //#[ operation init_1D(const int ,const double * ,const double * ) 
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
    //#]
}

void LookupTable::init_2D(const int nRows, const int nCols, const double * x, const double * y, const double * * Table) {
    NOTIFY_OPERATION(init_2D, init_2D(const int ,const int ,const double * ,const double * ,const double * * ), 0, StandardModels_LookupTable_init_2D_SERIALIZE);
    //#[ operation init_2D(const int ,const int ,const double * ,const double * ,const double * * ) 
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
    //#]
}

void LookupTable::interpolate_1D(const double x, double * z) {
    NOTIFY_OPERATION(interpolate_1D, interpolate_1D(const double ,double * ), 0, StandardModels_LookupTable_interpolate_1D_SERIALIZE);
    //#[ operation interpolate_1D(const double ,double * ) 
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
    //#]
}

void LookupTable::interpolate_2D(const double x, const double y, double * z) {
    NOTIFY_OPERATION(interpolate_2D, interpolate_2D(const double ,const double ,double * ), 0, StandardModels_LookupTable_interpolate_2D_SERIALIZE);
    //#[ operation interpolate_2D(const double ,const double ,double * ) 
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
    //#]
}

void LookupTable::locate(const double x, const long nData, const double * Data, long * i) {
    NOTIFY_OPERATION(locate, locate(const double ,const long ,const double * ,long * ), 0, StandardModels_LookupTable_locate_SERIALIZE);
    //#[ operation locate(const double ,const long ,const double * ,long * ) 
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
    //#]
}

double * *  LookupTable::getM_Table() const {
    return m_Table;
}

void LookupTable::setM_Table(double * * p_m_Table) {
    m_Table = p_m_Table;
}

long LookupTable::getM_nCols() const {
    return m_nCols;
}

void LookupTable::setM_nCols(long  p_m_nCols) {
    m_nCols = p_m_nCols;
}

long LookupTable::getM_nRows() const {
    return m_nRows;
}

void LookupTable::setM_nRows(long  p_m_nRows) {
    m_nRows = p_m_nRows;
}

double *  LookupTable::getM_x() const {
    return m_x;
}

void LookupTable::setM_x(double * p_m_x) {
    m_x = p_m_x;
}

double *  LookupTable::getM_y() const {
    return m_y;
}

void LookupTable::setM_y(double * p_m_y) {
    m_y = p_m_y;
}



#ifdef _OMINSTRUMENT


void OMAnimatedLookupTable::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(LookupTable, StandardModels, FALSE, OMAnimatedLookupTable)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\LookupTable.cpp
*********************************************************************/

