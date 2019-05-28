/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Animation
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Animation.h
*********************************************************************/


#ifndef Animation_H 

#define Animation_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "DisplayPkg.h"
#include "vtk3DSImporter.h"
#include "vtkRenderWindow.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "OnModelBase.h"

//## package DisplayPkg 

//----------------------------------------------------------------------------
// Animation.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedAnimation;
#endif // _OMINSTRUMENT


//## class Animation 
class Animation : public COnModelBase {
public :
    //#[ ignore 
    #define d2r 0.017453292519943295769236907684886
    //#]
    
    


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAnimation;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Animation() 
    Animation();
    
    //## operation ~Animation() 
    ~Animation();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();
    
    //## operation set_dishAngle(const double,double *) 
    void set_dishAngle(const double  t, double *val);
    
    //## operation set_guidanceMode(const double,long *) 
    void set_guidanceMode(const double  t, long *  val);
    
    //## operation set_missile_attitude(const double,double *) 
    void set_missile_attitude(const double  t, double *val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getDishAngle() const;
    
    //## auto_generated 
    void setDishAngle(double  p_dishAngle);
    
    //## auto_generated 
    int getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(int  p_guidanceMode);
    
    //## auto_generated 
    double getMissile_attitude() const;
    
    //## auto_generated 
    void setMissile_attitude(double  p_missile_attitude);
    
    //## auto_generated 
    vtk3DSImporter * getMissile_importer() const;
    
    //## auto_generated 
    void setMissile_importer(vtk3DSImporter *p_missile_importer);
    
    //## auto_generated 
    vtkRenderWindow * getMissile_renWindow() const;
    
    //## auto_generated 
    void setMissile_renWindow(vtkRenderWindow *p_missile_renWindow);
    
    //## auto_generated 
    vtkRenderer * getMissile_renderer() const;
    
    //## auto_generated 
    void setMissile_renderer(vtkRenderer *p_missile_renderer);
    
    //## auto_generated 
    vtkActor * getRadarActor() const;
    
    //## auto_generated 
    void setRadarActor(vtkActor *p_radarActor);
    
    //## auto_generated 
    vtkConeSource * getRadarDish() const;
    
    //## auto_generated 
    void setRadarDish(vtkConeSource *p_radarDish);
    
    //## auto_generated 
    vtkPolyDataMapper * getRadarMapper() const;
    
    //## auto_generated 
    void setRadarMapper(vtkPolyDataMapper *p_radarMapper);
    
    //## auto_generated 
    vtkRenderer * getRadarRenderer() const;
    
    //## auto_generated 
    void setRadarRenderer(vtkRenderer *p_radarRenderer);
    
    //## auto_generated 
    vtkRenderWindow * getRadarWindow() const;
    
    //## auto_generated 
    void setRadarWindow(vtkRenderWindow *p_radarWindow);
    
    //## auto_generated 
    vtk3DSImporter * getTarget_importer() const;
    
    //## auto_generated 
    void setTarget_importer(vtk3DSImporter *p_target_importer);
    
    //## auto_generated 
    vtkRenderWindow * getTarget_renWindow() const;
    
    //## auto_generated 
    void setTarget_renWindow(vtkRenderWindow *p_target_renWindow);
    
    //## auto_generated 
    vtkRenderer * getTarget_renderer() const;
    
    //## auto_generated 
    void setTarget_renderer(vtkRenderer *p_target_renderer);


////    Attributes    ////
protected :
    
    double dishAngle;		//## attribute dishAngle 
    
    int guidanceMode;		//## attribute guidanceMode 
    
    double missile_attitude;		//## attribute missile_attitude 
    
    vtk3DSImporter *missile_importer;		//## attribute missile_importer 
    
    vtkRenderWindow *missile_renWindow;		//## attribute missile_renWindow 
    
    vtkRenderer *missile_renderer;		//## attribute missile_renderer 
    
    vtkActor *radarActor;		//## attribute radarActor 
    
    vtkConeSource *radarDish;		//## attribute radarDish 
    
    vtkPolyDataMapper *radarMapper;		//## attribute radarMapper 
    
    vtkRenderer *radarRenderer;		//## attribute radarRenderer 
    
    vtkRenderWindow *radarWindow;		//## attribute radarWindow 
    
    vtk3DSImporter *target_importer;		//## attribute target_importer 
    
    vtkRenderWindow *target_renWindow;		//## attribute target_renWindow 
    
    vtkRenderer *target_renderer;		//## attribute target_renderer 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAnimation : virtual public AOMInstance {

    
    DECLARE_META(Animation, OMAnimatedAnimation)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Animation.h
*********************************************************************/

