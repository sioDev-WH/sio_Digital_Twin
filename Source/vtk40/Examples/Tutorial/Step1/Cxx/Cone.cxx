//
// This example creates a polygonal model of a Cube, and then rendered it to
// the screen. It willrotate the Cube 360 degrees and then exit. The basic
// setup of source -> mapper -> actor -> renderer -> renderwindow is 
// typical of most VTK programs.
//

// first include the required header files for the vtk classes we are using
#include "vtkCylinderSource.h"
#include "vtkConeSource.h"
#include "vtk3DSImporter.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"

int main( int argc, char *argv[] )
{

	char FileName[120];
	int i;

	vtk3DSImporter *importer = vtk3DSImporter::New();
	strcpy(FileName, "E:\\DistComponents\\AvionicsLib\\3DModels\\80jet.3DS");
	importer->SetFileName(FileName);
	importer->Read();

	vtkRenderer *mRen= importer->GetRenderer();
	vtkRenderWindow *mRenWin = vtkRenderWindow::New();
	mRenWin->AddRenderer( mRen );
    mRenWin->SetSize( 500, 500 );

	float a[3];
	
	a[0] = 0.2;
	a[1] = 0.2;
	a[2] = 0.4;
	// mRen->SetBackground( a[0], a[1], a[2] );
	for (i = 0; i < 200; ++i) mRen->GetActiveCamera()->Roll(-0.4);
	 for (i = 0; i < 100; ++i)
    {
    // render the image
		
	// mRen->GetActiveCamera()->Elevation(0.2);
    // rotate the active camera by one degree
     // mRen->GetActiveCamera()->Azimuth( .2 );
	 mRen->GetActiveCamera()->Roll(0.5); // theta = 60 deg after 10 seconds
	 mRen->GetActiveCamera()->SetViewAngle(180);
	 // mRen->GetActiveCamera()->Yaw(.1);
		a[0] += 0.001;
		a[1] -= 0.005;
		a[2] += 0.003;
		mRen->SetBackground( a[0], a[1], a[2] );
		mRenWin->Render();
    }
return 0;
  //
  // Next we create an instance of vtkCubeSource and set some of its 
  // properties
  //
  // vtkCubeSource *Cube = vtkCubeSource::New();
	vtkCylinderSource *Cylinder = vtkCylinderSource::New();
  Cylinder->SetHeight( .20 );
  Cylinder->SetRadius( 0.02 );
  // Cylinder->SetBounds(3,4,1,2,10,11);
  Cylinder->SetResolution( 50 );


  vtkConeSource *Cone = vtkConeSource::New();
  Cone->SetHeight( 1.0 );
  Cone->SetRadius( 0.1 );
  // Cone->SetBounds(3,4,1,2,10,11);
  Cone->SetResolution( 50 );
  
  //
  // We create an instance of vtkPolyDataMapper to map the polygonal data 
  // into graphics primitives. We connect the output of the Cube souece 
  // to the input of this mapper 
  //
  vtkPolyDataMapper *CylinderMapper = vtkPolyDataMapper::New();
  CylinderMapper->SetInput( Cylinder->GetOutput() );

  vtkPolyDataMapper *ConeMapper = vtkPolyDataMapper::New();
  ConeMapper->SetInput( Cone->GetOutput() );
  //
  // create an actor to represent the Cube. The actor coordinates rendering of
  // the graphics primitives for a mapper. We set this actor's mapper to be
  // CubeMapper which we created above.
  //
  vtkActor *CylinderActor = vtkActor::New();
  CylinderActor->SetMapper( CylinderMapper );

  vtkActor *ConeActor = vtkActor::New();
  ConeActor->SetMapper( ConeMapper );
  //
  // Create the Renderer and assign actors to it. A renderer is like a
  // viewport. It is part or all of a window on the screen and it is
  // responsible for drawing the actors it has.  We also set the background
  // color here
  //
  vtkRenderer *ren1= vtkRenderer::New();
  ren1->AddActor( CylinderActor );  
  ren1->AddActor( ConeActor );
  ren1->SetBackground( 0.2, 0.2, 0.4 );



  //
  // Finally we create the render window which will show up on the screen
  // We put our renderer into the render window using AddRenderer. We also
  // set the size to be 300 pixels by 300
  //
  
vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer( ren1 );
  renWin->SetSize( 500, 500 );
  //
  // now we loop over 360 degreeees and render the Cube each time
  //


  for (i = 0; i < 360; ++i)
    {
    // render the image
    renWin->Render();
    // rotate the active camera by one degree
    // ren1->GetActiveCamera()->Azimuth( 2 );
	 ren1->GetActiveCamera()->Roll(0.2 );
	// ren1->GetActiveCamera()->Yaw(.1 );
    }
  
  //
  // Free up any objects we created
  //
  Cylinder->Delete();
  CylinderMapper->Delete();
  CylinderActor->Delete();

  Cone->Delete();
  ConeMapper->Delete();
  ConeActor->Delete();

  ren1->Delete();
  renWin->Delete();

  return 0;
}


