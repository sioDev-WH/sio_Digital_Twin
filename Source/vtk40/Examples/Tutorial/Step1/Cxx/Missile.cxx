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
	strcpy(FileName, "E:\\DistComponents\\AvionicsLib\\3DModels\\81Missile.3DS");
	importer->SetFileName(FileName);
	importer->Read();

	vtkRenderer *mRen= importer->GetRenderer();
	vtkRenderWindow *mRenWin = vtkRenderWindow::New();
	mRenWin->AddRenderer( mRen );
    mRenWin->SetSize( 500, 500 );
	mRenWin->SetPosition(1000,500);
	float a[3];
	
	a[0] = 0.2;
	a[1] = 0.2;
	a[2] = 0.4;
	for (i = 0; i < 200; ++i) mRen->GetActiveCamera()->Roll(-0.4);
	for (i = 0; i < 100; ++i)
    {
    // render the image
		
	// mRen->GetActiveCamera()->Elevation(0.2);
    // rotate the active camera by one degree
     // mRen->GetActiveCamera()->Azimuth( .2 );
	 mRen->GetActiveCamera()->Roll(0.5); // theta = 60 deg after 10 seconds
	 // mRen->GetActiveCamera()->Yaw(.1);
		a[0] += 0.001;
		a[1] -= 0.005;
		a[2] += 0.003;
		mRen->SetBackground( a[0], a[1], a[2] );
		mRenWin->Render();
    }
	importer->Delete();
	mRenWin->Delete();
	return 0;
}



