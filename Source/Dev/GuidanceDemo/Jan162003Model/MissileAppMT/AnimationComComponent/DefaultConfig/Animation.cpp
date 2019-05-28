/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Animation
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Animation.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Animation.h"
#include <stdafx.h>

//## package DisplayPkg 


//#[ ignore 
#define DisplayPkg_Animation_Animation_SERIALIZE OM_NO_OP


#define DisplayPkg_Animation_clean_SERIALIZE OM_NO_OP


#define DisplayPkg_Animation_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define DisplayPkg_Animation_init_SERIALIZE OM_NO_OP


#define DisplayPkg_Animation_set_dishAngle_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define DisplayPkg_Animation_set_guidanceMode_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define DisplayPkg_Animation_set_missile_attitude_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));
//#]

//----------------------------------------------------------------------------
// Animation.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(DisplayPkg)
//## class Animation 



Animation::Animation() {
    NOTIFY_CONSTRUCTOR(Animation, Animation(), 0, DisplayPkg_Animation_Animation_SERIALIZE);
    //#[ operation Animation() 
    init();
    //#]
}

Animation::~Animation() {
    NOTIFY_DESTRUCTOR(~Animation, TRUE);
    //#[ operation ~Animation() 
    clean();
    //#]
}

void Animation::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, DisplayPkg_Animation_clean_SERIALIZE);
    //#[ operation clean() 
    	if(radarDish) radarDish->Delete();
        if(radarMapper) radarMapper->Delete();
        if(radarActor) radarActor->Delete();
        if(radarRenderer) radarRenderer->Delete();
        if(radarWindow) radarWindow->Delete();
    	if(missile_importer) missile_importer->Delete();
    	if(target_importer) target_importer->Delete();
    	if(missile_renWindow) missile_renWindow->Delete();  
    	if(target_renWindow) target_renWindow->Delete();
    //#]
}

void Animation::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, DisplayPkg_Animation_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    	 double old_DishAngle=0; 
    	 double old_attitude=0;
    	 double dish_attitude;
    	 
    	 old_DishAngle = dishAngle;
    	 old_attitude = missile_attitude;
    	 
    	 receive(); 
    	 dish_attitude =(dishAngle-old_DishAngle) + (missile_attitude - old_attitude);
    	 missile_renderer->GetActiveCamera()->Roll(missile_attitude*2);
    	 missile_renWindow->Render();
    	 if(guidanceMode>=1){
    	 	radarRenderer->GetActiveCamera()->Roll((dish_attitude)*30);
    	 	radarWindow->Render();
    	}
    	 if(guidanceMode>1){
    	 	target_renderer->GetActiveCamera()->Zoom(1.05);
    	 	target_renWindow->Render(); 
    	 }
    	 
    	         
    //#]
}

void Animation::init() {
    NOTIFY_OPERATION(init, init(), 0, DisplayPkg_Animation_init_SERIALIZE);
    //#[ operation init() 
    	char FileName[120];
    	int i;
    	char *ONIROOTvar;
    
        
        radarDish = vtkConeSource::New();
      	radarDish->SetHeight( 0.6 );
      	radarDish->SetRadius( 0.3 );
      	radarDish->SetResolution( 20 );
      	radarMapper = vtkPolyDataMapper::New();
      	radarMapper->SetInput( radarDish->GetOutput() );
      	radarActor = vtkActor::New();
      	radarActor->SetMapper( radarMapper );
      	radarRenderer= vtkRenderer::New();
        radarRenderer->AddActor( radarActor );
        radarRenderer->SetBackground( 0.4, 0.1, 0.1 );
        radarWindow = vtkRenderWindow::New();
        radarWindow->AddRenderer( radarRenderer );
        radarWindow->SetSize( 200, 200 );
        radarWindow->SetPosition( 200, 200 );
        for (i = 0; i < 200; ++i) radarRenderer->GetActiveCamera()->Roll(.45);
        
        ONIROOTvar = getenv( "ONIROOT" );
    
    	missile_importer = vtk3DSImporter::New(); 
    	strcpy(FileName, ONIROOTvar);
    	strcat(FileName, "\\bin\\81Missile.3DS");
    	missile_importer->SetFileName(FileName);
    	missile_importer->Read();
        missile_renderer= missile_importer->GetRenderer();
        
        target_importer = vtk3DSImporter::New(); 
        strcpy(FileName, ONIROOTvar);
    	strcat(FileName, "\\bin\\80jet.3DS");
    	target_importer->SetFileName(FileName);
    	target_importer->Read();
    
    	missile_renderer = missile_importer->GetRenderer();
        target_renderer  = target_importer->GetRenderer();
        
    	missile_renWindow = vtkRenderWindow::New();
    	missile_renWindow->AddRenderer( missile_renderer );
        missile_renWindow->SetSize( 400, 400 ); 
        missile_renWindow->SetPosition( 0, 400 );
        missile_renderer->SetBackground( .25, .15, .45 );
        for (i = 0; i < 200; ++i) missile_renderer->GetActiveCamera()->Roll(-0.4);
        
        target_renWindow = vtkRenderWindow::New();
    	target_renWindow->AddRenderer( target_renderer );
        target_renWindow->SetSize( 400, 400 );
        target_renWindow->SetPosition( 400, 0 ); 
        target_renderer->SetBackground( .15, .45, .15 );
        
        for (i = 0; i < 200; ++i) target_renderer->GetActiveCamera()->Roll(-0.4);
        target_renderer->GetActiveCamera()->Zoom(0.2);
        // target_renWindow->Render();
    //#]
}

void Animation::set_dishAngle(const double  t, double *val) {
    NOTIFY_OPERATION(set_dishAngle, set_dishAngle(const double,double *), 2, DisplayPkg_Animation_set_dishAngle_SERIALIZE);
    //#[ operation set_dishAngle(const double,double *) 
    
    dishAngle  = *val; // *d2r if *val in degree for display
    //#]
}

void Animation::set_guidanceMode(const double  t, long *  val) {
    NOTIFY_OPERATION(set_guidanceMode, set_guidanceMode(const double,long *), 2, DisplayPkg_Animation_set_guidanceMode_SERIALIZE);
    //#[ operation set_guidanceMode(const double,long *) 
    
    guidanceMode  = *val; // *d2r if *val in degree for display
    //#]
}

void Animation::set_missile_attitude(const double  t, double *val) {
    NOTIFY_OPERATION(set_missile_attitude, set_missile_attitude(const double,double *), 2, DisplayPkg_Animation_set_missile_attitude_SERIALIZE);
    //#[ operation set_missile_attitude(const double,double *) 
    
    missile_attitude  = *val; // *d2r if *val in degree for display
    //#]
}

double Animation::getDishAngle() const {
    return dishAngle;
}

void Animation::setDishAngle(double  p_dishAngle) {
    dishAngle = p_dishAngle;
}

int Animation::getGuidanceMode() const {
    return guidanceMode;
}

void Animation::setGuidanceMode(int  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

double Animation::getMissile_attitude() const {
    return missile_attitude;
}

void Animation::setMissile_attitude(double  p_missile_attitude) {
    missile_attitude = p_missile_attitude;
}

vtk3DSImporter * Animation::getMissile_importer() const {
    return missile_importer;
}

void Animation::setMissile_importer(vtk3DSImporter *p_missile_importer) {
    missile_importer = p_missile_importer;
}

vtkRenderWindow * Animation::getMissile_renWindow() const {
    return missile_renWindow;
}

void Animation::setMissile_renWindow(vtkRenderWindow *p_missile_renWindow) {
    missile_renWindow = p_missile_renWindow;
}

vtkRenderer * Animation::getMissile_renderer() const {
    return missile_renderer;
}

void Animation::setMissile_renderer(vtkRenderer *p_missile_renderer) {
    missile_renderer = p_missile_renderer;
}

vtkActor * Animation::getRadarActor() const {
    return radarActor;
}

void Animation::setRadarActor(vtkActor *p_radarActor) {
    radarActor = p_radarActor;
}

vtkConeSource * Animation::getRadarDish() const {
    return radarDish;
}

void Animation::setRadarDish(vtkConeSource *p_radarDish) {
    radarDish = p_radarDish;
}

vtkPolyDataMapper * Animation::getRadarMapper() const {
    return radarMapper;
}

void Animation::setRadarMapper(vtkPolyDataMapper *p_radarMapper) {
    radarMapper = p_radarMapper;
}

vtkRenderer * Animation::getRadarRenderer() const {
    return radarRenderer;
}

void Animation::setRadarRenderer(vtkRenderer *p_radarRenderer) {
    radarRenderer = p_radarRenderer;
}

vtkRenderWindow * Animation::getRadarWindow() const {
    return radarWindow;
}

void Animation::setRadarWindow(vtkRenderWindow *p_radarWindow) {
    radarWindow = p_radarWindow;
}

vtk3DSImporter * Animation::getTarget_importer() const {
    return target_importer;
}

void Animation::setTarget_importer(vtk3DSImporter *p_target_importer) {
    target_importer = p_target_importer;
}

vtkRenderWindow * Animation::getTarget_renWindow() const {
    return target_renWindow;
}

void Animation::setTarget_renWindow(vtkRenderWindow *p_target_renWindow) {
    target_renWindow = p_target_renWindow;
}

vtkRenderer * Animation::getTarget_renderer() const {
    return target_renderer;
}

void Animation::setTarget_renderer(vtkRenderer *p_target_renderer) {
    target_renderer = p_target_renderer;
}



#ifdef _OMINSTRUMENT


void OMAnimatedAnimation::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("missile_importer", x2String(myReal->missile_importer));
    aomsAttributes->addAttribute("missile_renderer", x2String(myReal->missile_renderer));
    aomsAttributes->addAttribute("missile_renWindow", x2String(myReal->missile_renWindow));
    aomsAttributes->addAttribute("missile_attitude", x2String(myReal->missile_attitude));
    aomsAttributes->addAttribute("guidanceMode", x2String(myReal->guidanceMode));
    aomsAttributes->addAttribute("target_importer", x2String(myReal->target_importer));
    aomsAttributes->addAttribute("target_renderer", x2String(myReal->target_renderer));
    aomsAttributes->addAttribute("target_renWindow", x2String(myReal->target_renWindow));
    aomsAttributes->addAttribute("radarDish", x2String(myReal->radarDish));
    aomsAttributes->addAttribute("radarMapper", x2String(myReal->radarMapper));
    aomsAttributes->addAttribute("radarActor", x2String(myReal->radarActor));
    aomsAttributes->addAttribute("radarRenderer", x2String(myReal->radarRenderer));
    aomsAttributes->addAttribute("radarWindow", x2String(myReal->radarWindow));
    aomsAttributes->addAttribute("dishAngle", x2String(myReal->dishAngle));
}

IMPLEMENT_META(Animation, DisplayPkg, FALSE, OMAnimatedAnimation)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Animation.cpp
*********************************************************************/

