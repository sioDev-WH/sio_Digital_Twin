//
// This example creates a polygonal model of a cone, and then rendered it to
// the screen. It willrotate the cone 360 degrees and then exit. The basic
// setup of source -> mapper -> actor -> renderer -> renderwindow is 
// typical of most VTK programs.
//

// first include the required header files for the vtk classes we are using
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"

int main( int argc, char *argv[] )
{
  //
  // Next we create an instance of vtkConeSource and set some of its 
  // properties
  //
  vtkConeSource *cone = vtkConeSource::New();
  cone->SetHeight( 3.0 );
  cone->SetRadius( 1.0 );
  cone->SetResolution( 10 );
  
  //
  // We create an instance of vtkPolyDataMapper to map the polygonal data 
  // into graphics primitives. We connect the output of the cone souece 
  // to the input of this mapper 
  //
  vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
  coneMapper->SetInput( cone->GetOutput() );

  //
  // create an actor to represent the cone. The actor coordinates rendering of
  // the graphics primitives for a mapper. We set this actor's mapper to be
  // coneMapper which we created above.
  //
  vtkActor *coneActor = vtkActor::New();
  coneActor->SetMapper( coneMapper );

  //
  // Create the Renderer and assign actors to it. A renderer is like a
  // viewport. It is part or all of a window on the screen and it is
  // responsible for drawing the actors it has.  We also set the background
  // color here
  //
  vtkRenderer *ren1= vtkRenderer::New();
  ren1->AddActor( coneActor );
  ren1->SetBackground( 0.1, 0.2, 0.4 );

  //
  // Finally we create the render window which will show up on the screen
  // We put our renderer into the render window using AddRenderer. We also
  // set the size to be 300 pixels by 300
  //
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer( ren1 );
  renWin->SetSize( 300, 300 );

  //
  // now we loop over 360 degreeees and render the cone each time
  //
  int i;
  for (i = 0; i < 360; ++i)
    {
    // render the image
    renWin->Render();
    // rotate the active camera by one degree
    ren1->GetActiveCamera()->Azimuth( 1 );
    }
  
  //
  // Free up any objects we created
  //
  cone->Delete();
  coneMapper->Delete();
  coneActor->Delete();
  ren1->Delete();
  renWin->Delete();

  return 0;
}


