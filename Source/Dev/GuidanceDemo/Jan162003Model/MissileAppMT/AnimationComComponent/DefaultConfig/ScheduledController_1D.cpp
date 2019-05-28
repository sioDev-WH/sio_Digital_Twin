/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: ScheduledController_1D
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "ScheduledController_1D.h"
#include "ScheduledController_1D_Coeff.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_ScheduledController_1D_ScheduledController_1D_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// ScheduledController_1D.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class ScheduledController_1D 



ScheduledController_1D::ScheduledController_1D(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(ScheduledController_1D, ScheduledController_1D(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_ScheduledController_1D_SERIALIZE);
    setThread(p_thread, FALSE);
    initRelations();
    //#[ operation ScheduledController_1D() 
    init();
    //#]
}

ScheduledController_1D::~ScheduledController_1D() {
    NOTIFY_DESTRUCTOR(~ScheduledController_1D, TRUE);
    //#[ operation ~ScheduledController_1D() 
    //#]
    cleanUpRelations();
}

void ScheduledController_1D::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void ScheduledController_1D::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    Coeff->update(v);
    update();
    broadcast();
    
    //#]
}

void ScheduledController_1D::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_init_SERIALIZE);
    //#[ operation init() 
    	long i;
    	int nx;     
    	int nu;
    	int ny; 
    
    	
    	Coeff = new ScheduledController_1D_Coeff();
    	nx = Coeff->getNx();
    	nu = Coeff->nu;
    	ny = Coeff->ny; 
    	
    	x = new double[nx];
    	u = new double[nu];
    	y = new double[ny];
    	
    	x_old = new double[nx];
    
    
    	
    	for (i = 0; i < nx; i++) x_old[i] = Coeff->getX0()[i];
    	for (i = 0; i < ny; i++) y[i] = 0.0;
    
    	
    //#]
}

void ScheduledController_1D::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void ScheduledController_1D::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_update_SERIALIZE);
    //#[ operation update() 
    int i,j;
    double *A,*B,*C,*D;
    int nx = Coeff->getNx();
    int nu = Coeff->nu;
    int ny = Coeff->ny;
      
     
      A = Coeff->A;
      B = Coeff->B;
      C = Coeff->C;
      D = Coeff->D;
    
    for(i=0;i<nx;i++){
    	  x[i] = 0.0;
    	  for(j=0;j<nx;j++)
    		  x[i] += A[i*nx+j]*x_old[j];
    	  for(j=0;j<nu;j++)
    		  x[i] += B[i*nu+j]*u[j];
      }
      for(i=0;i<ny;i++){
        y[i] = 0.0; 
        for(j=0;j<nx;j++) y[i] += C[i*nx+j]*x[i];
        for(j=0;j<nu;j++) y[i] += D[i*nu+j]*u[j]; 
      }
      
      for(i=0;i<nx;i++) x_old[i] = x[i];
    //#]
}

double ScheduledController_1D::getPeriod() const {
    return period;
}

void ScheduledController_1D::setPeriod(double  p_period) {
    period = p_period;
}

double* ScheduledController_1D::getU() const {
    return u;
}

void ScheduledController_1D::setU(double*  p_u) {
    u = p_u;
}

double* ScheduledController_1D::getU_old() const {
    return u_old;
}

void ScheduledController_1D::setU_old(double*  p_u_old) {
    u_old = p_u_old;
}

double ScheduledController_1D::getV() const {
    return v;
}

void ScheduledController_1D::setV(double  p_v) {
    v = p_v;
}

double* ScheduledController_1D::getX() const {
    return x;
}

void ScheduledController_1D::setX(double*  p_x) {
    x = p_x;
}

double* ScheduledController_1D::getX_old() const {
    return x_old;
}

void ScheduledController_1D::setX_old(double*  p_x_old) {
    x_old = p_x_old;
}

double* ScheduledController_1D::getY() const {
    return y;
}

void ScheduledController_1D::setY(double*  p_y) {
    y = p_y;
}

ScheduledController_1D_Coeff* ScheduledController_1D::getCoeff() const {
    return Coeff;
}

ScheduledController_1D_Coeff* ScheduledController_1D::newCoeff() {
    Coeff = new ScheduledController_1D_Coeff;
    NOTIFY_RELATION_ITEM_ADDED("Coeff", Coeff, TRUE, TRUE);
    return Coeff;
}

void ScheduledController_1D::deleteCoeff() {
    NOTIFY_RELATION_ITEM_REMOVED("Coeff", Coeff);
    delete Coeff;
}

void ScheduledController_1D::initRelations() {
    Coeff = newCoeff();
}

void ScheduledController_1D::cleanUpRelations() {
    {
        deleteCoeff();
        Coeff = NULL;
    }
}

OMBoolean ScheduledController_1D::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedScheduledController_1D::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("u", x2String(myReal->u));
    aomsAttributes->addAttribute("x", x2String(myReal->x));
    aomsAttributes->addAttribute("u_old", x2String(myReal->u_old));
    aomsAttributes->addAttribute("x_old", x2String(myReal->x_old));
    aomsAttributes->addAttribute("y", x2String(myReal->y));
    aomsAttributes->addAttribute("v", x2String(myReal->v));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

void OMAnimatedScheduledController_1D::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Coeff", TRUE, TRUE);
    if(myReal->Coeff)
        aomsRelations->ADD_ITEM(myReal->Coeff);
}

IMPLEMENT_REACTIVE_META(ScheduledController_1D, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedScheduledController_1D)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D.cpp
*********************************************************************/

