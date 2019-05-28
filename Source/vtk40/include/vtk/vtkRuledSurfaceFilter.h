/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkRuledSurfaceFilter.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:37:14 $
  Version:   $Revision: 1.7 $


Copyright (c) 1993-2001 Ken Martin, Will Schroeder, Bill Lorensen 
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither name of Ken Martin, Will Schroeder, or Bill Lorensen nor the names
   of any contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
// .NAME vtkRuledSurfaceFilter - generates a surface from a set of lines
// .SECTION Description
// vtkRuledSurfaceFilter is a filter that generates a surface from a set of
// lines. The lines are assumed to be "parallel" in the sense that they do
// not intersect and remain somewhat close to one another. A surface is
// generated by connecting the points defining each pair of lines with
// straight lines. This creates a strip for each pair of lines (i.e., a
// triangulation is created from two generating lines). The filter can handle
// an arbitrary number of lines, with lines i and i+1 assumed connected.
// Note that there are several different approaches for creating the ruled
// surface, the method for creating the surface can either use the input
// points or resample from the polylines (using a user-specified resolution).
//
// This filter offers some other important features. A DistanceFactor ivar is
// used to decide when two lines are too far apart to connect. (The factor is
// a multiple of the distance between the first two points of the two lines
// defining the strip.) If the distance between the two generating lines
// becomes too great, then the surface is not generated in that
// region. (Note: if the lines separate and then merge, then a hole can be
// generated in the surface.) In addition, the Offset and OnRation ivars can
// be used to create nifty striped surfaces. Closed surfaces (e.g., tubes) can
// be created by setting the CloseSurface ivar. (The surface can be closed
// in the other direction by repeating the first and last point in the
// polylines defining the surface.)
//
// An important use of this filter is to combine it with vtkStreamLine to
// generate stream surfaces. It can also be used to create surfaces from
// contours.

// .SECTION Caveats
// The number of lines must be greater than two if a surface is to be
// generated.  sides (i.e., a ribbon), use vtkRibbonFilter.

// .SECTION See Also
// vtkRibbonFilter vtkStreamLine

#ifndef __vtkRuledSurfaceFilter_h
#define __vtkRuledSurfaceFilter_h

#include "vtkPolyDataToPolyDataFilter.h"

#define VTK_RULED_MODE_RESAMPLE 0
#define VTK_RULED_MODE_POINT_WALK 1

class VTK_GRAPHICS_EXPORT vtkRuledSurfaceFilter : public vtkPolyDataToPolyDataFilter
{
public:
  vtkTypeMacro(vtkRuledSurfaceFilter,vtkPolyDataToPolyDataFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct object with OnRatio=1, Offset=0. DistanceFactor=3.0,
  // CloseSurface off, and PassLines off.
  static vtkRuledSurfaceFilter *New();

  // Description:
  // Set/Get the factor that controls tearing of the surface.
  vtkSetClampMacro(DistanceFactor,float,1.0,VTK_LARGE_FLOAT);
  vtkGetMacro(DistanceFactor,float);

  // Description:
  // Control the striping of the ruled surface. If OnRatio is greater 
  // than 1, then every nth strip is turned on, beginning with the Offset
  // strip.
  vtkSetClampMacro(OnRatio,int,1,VTK_LARGE_INTEGER);
  vtkGetMacro(OnRatio,int);

  // Description:
  // Control the striping of the ruled surface. The offset sets the
  // first stripe that is visible. Offset is generally used with
  // OnRatio to create nifty striping effects.
  vtkSetClampMacro(Offset,int,0,VTK_LARGE_INTEGER);
  vtkGetMacro(Offset,int);

  // Description:
  // Indicate whether the surface is to be closed. If this boolean is
  // on, then the first and last polyline are used to generate a stripe
  // that closes the surface. (Note: to close the surface in the other
  // direction, repeat the first point in the polyline as the last
  // point in the polyline.)
  vtkSetMacro(CloseSurface,int);
  vtkGetMacro(CloseSurface,int);
  vtkBooleanMacro(CloseSurface,int);

  // Description:
  // Set the mode by which to create the ruled surface. (Dramatically
  // different results are possible depending on the chosen mode.) The
  // resample mode evenly resamples the polylines (based on length) and 
  // generates triangle strips. The
  vtkSetClampMacro(RuledMode,int,
                   VTK_RULED_MODE_RESAMPLE,VTK_RULED_MODE_POINT_WALK);
  vtkGetMacro(RuledMode,int);
  void SetRuledModeToResample()
    {this->SetRuledMode(VTK_RULED_MODE_RESAMPLE);}
  void SetRuledModeToPointWalk()
    {this->SetRuledMode(VTK_RULED_MODE_POINT_WALK);}
  const char *GetRuledModeAsString();

  // Description:
  // If the ruled surface generation mode is RESAMPLE, then these parameters
  // are used to determine the resample rate. Resolution[0] defines the
  // resolution in the direction of the polylines; Resolution[1] defines
  // the resolution across the polylines (i.e., direction orthogonal to
  // Resolution[0]).
  vtkSetVector2Macro(Resolution, int);
  vtkGetVectorMacro(Resolution, int, 2);

  // Description:
  // Indicate whether the generating lines are to be passed to the output.
  // By defualt lines are not passed to the output.
  vtkSetMacro(PassLines,int);
  vtkGetMacro(PassLines,int);
  vtkBooleanMacro(PassLines,int);

protected:
  vtkRuledSurfaceFilter();
  ~vtkRuledSurfaceFilter();

  // Usual data generation method
  void Execute();

  float DistanceFactor;
  int   OnRatio;
  int   Offset;
  int   CloseSurface;
  int   RuledMode;
  int   Resolution[2];
  int   PassLines;
  
private:
  vtkIdList *Ids;
  float     Weights[4];

  void  Resample(vtkPolyData *output, vtkPoints *inPts, vtkPoints *newPts, 
                 int npts, vtkIdType *pts, int npts2, vtkIdType *pts2);
  void  PointWalk(vtkPolyData *output, vtkPoints *inPts, 
                  int npts, vtkIdType *pts, int npts2, vtkIdType *pts2);
  
private:
  vtkRuledSurfaceFilter(const vtkRuledSurfaceFilter&);  // Not implemented.
  void operator=(const vtkRuledSurfaceFilter&);  // Not implemented.
};

#endif

