/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Animation
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Animation.cpp
*********************************************************************/

#include "Animation.h"
#include <stdafx.h>

//## package DisplayPkg 

//----------------------------------------------------------------------------
// Animation.cpp                                                                  
//----------------------------------------------------------------------------
//## class Animation 



Animation::Animation() {
    //#[ operation Animation() 
    init();
    //#]
}

Animation::~Animation() {
    //#[ operation ~Animation() 
    clean();
    //#]
}

void Animation::clean() {
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

void Animation::handle_tick() {
    //#[ operation handle_tick() 
    	 double old_DishAngle=0; 
    	 double old_attitude=0;
    	 double dish_attitude;
    	 double Ts;
    	 
    	 Ts = period/1000;
    	 
    	 old_DishAngle = dishAngle;
    	 old_attitude = missile_attitude;
    	 
    	 receive(); 
    	 dish_attitude =(dishAngle-old_DishAngle) + (missile_attitude - old_attitude);
    	 missile_renderer->GetActiveCamera()->Roll((missile_attitude- old_attitude)*57.295779513082320876798154814105);
    	 missile_renWindow->MakeCurrent();
    	 missile_renWindow->Render();
    	 if(guidanceMode>=1){
    	 	radarRenderer->GetActiveCamera()->Roll((dish_attitude)*57.295779513082320876798154814105);
    		radarWindow->Render();
    	}
    	 if(guidanceMode>1){
    	 	// target_renderer->GetActiveCamera()->Zoom(1.05); // initZoomOutScale*scale_ft2image*init_Range/(init_Range-Range)
    	 	target_renderer->GetActiveCamera()->Zoom(1.05);  // init_Range is calculated at initial call to handle_tick()
    	 	target_renWindow->Render();						   // initZoomOutScale 
    	 }
    	 
    	         
    //#]
}

void Animation::init() {
    //#[ operation init() 
    	char FileName[120];
    	char *ONIROOTvar;
    
        dishAngle =0.0;
    	missile_attitude=0.0;
    
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
        // for (i = 0; i < 200; ++i) radarRenderer->GetActiveCamera()->Roll(.45);
    	radarRenderer->GetActiveCamera()->Roll(180);
        
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
    	missile_renderer->GetActiveCamera()->Roll(-90);
        
        target_renWindow = vtkRenderWindow::New();
    	target_renWindow->AddRenderer( target_renderer );
        target_renWindow->SetSize( 400, 400 );
        target_renWindow->SetPosition( 400, 200 ); 
        target_renderer->SetBackground( .15, .45, .15 );
        
        // for (i = 0; i < 200; ++i) target_renderer->GetActiveCamera()->Roll(-0.4);
    	target_renderer->GetActiveCamera()->Roll(-90);
        target_renderer->GetActiveCamera()->Zoom(0.2);
        
    //#]
}

void Animation::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
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

long Animation::getPeriod() const {
    return period;
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



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Animation.cpp
*********************************************************************/

