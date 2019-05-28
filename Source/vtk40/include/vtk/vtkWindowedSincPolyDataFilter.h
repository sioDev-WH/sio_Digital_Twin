/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkWindowedSincPolyDataFilter.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:37:22 $
  Version:   $Revision: 1.19 $


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
// .NAME vtkWindowedSincPolyDataFilter - adjust point positions using a windowed sinc function interpolation kernel
// .SECTION Description
// vtkWindowedSincPolyDataFiler adjust point coordinate using a windowed
// sinc function interpolation kernel.  The effect is to "relax" the mesh,
// making the cells better shaped and the vertices more evenly distributed.
// Note that this filter operates the lines, polygons, and triangle strips
// composing an instance of vtkPolyData.  Vertex or poly-vertex cells are
// never modified.
//
// The algorithm proceeds as follows. For each vertex v, a topological and
// geometric analysis is performed to determine which vertices are connected
// to v, and which cells are connected to v. Then, a connectivity array is
// constructed for each vertex. (The connectivity array is a list of lists
// of vertices that directly attach to each vertex.) Next, an iteration
// phase begins over all vertices. For each vertex v, the coordinates of v
// are modified using a windowed sinc function interpolation kernel.
// Taubin describes this methodology is the IBM tech report RC-20404
// (#90237, dated 3/12/96) "Optimal Surface Smoothing as Filter Design"
// G. Taubin, T. Zhang and G. Golub. (Zhang and Golub are at Stanford
// University).
//
// This report discusses using standard signal processing low-pass filters
// (in particular windowed sinc functions) to smooth polyhedra. The
// transfer functions of the low-pass filters are approximated by
// Chebyshev polynomials. This facilitates applying the filters in an
// iterative diffusion process (as opposed to a kernel convolution).  The
// more smoothing iterations applied, the higher the degree of polynomial
// approximating the low-pass filter transfer function. Each smoothing
// iteration, therefore, applies the next higher term of the Chebyshev
// filter approximation to the polyhedron. This decoupling of the filter
// into an iteratively applied polynomial is possible since the Chebyshev
// polynomials are orthogonal, i.e. increasing the order of the
// approximation to the filter transfer function does not alter the
// previously calculated coefficients for the low order terms. 
//
// Note: Care must be taken to avoid smoothing with too few iterations.
// A Chebyshev approximation with too few terms is an poor approximation.
// The first few smoothing iterations represent a severe scaling and
// translation of the data.  Subsequent iterations cause the smoothed
// polyhedron to converge to the true location and scale of the object.
// We have attempted to protect against this by automatically adjusting
// the filter, effectively widening the pass band. This adjustment is only
// possible if the number of iterations is greater than 1.  Note that this
// sacrifices some degree of smoothing for model integrity. For those
// interested, the filter is adjusted by searching for a value sigma
// such that the actual pass band is k_pb + sigma and such that the
// filter transfer function evaluates to unity at k_pb, i.e. f(k_pb) = 1
//
// This implementation is currently limited to using an interpolation
// kernel based on Hamming windows.  Other windows (such as Hann, Blackman,
// Kaiser, Lanczos, Gaussian, and exponential windows) could be used
// instead.
//
// There are some special instance variables used to control the execution
// of this filter. (These ivars basically control what vertices can be
// smoothed, and the creation of the connectivity array.) The
// BoundarySmoothing ivar enables/disables the smoothing operation on
// vertices that are on the "boundary" of the mesh. A boundary vertex is one
// that is surrounded by a semi-cycle of polygons (or used by a single
// line).
// 
// Another important ivar is FeatureEdgeSmoothing. If this ivar is
// enabled, then interior vertices are classified as either "simple",
// "interior edge", or "fixed", and smoothed differently. (Interior
// vertices are manifold vertices surrounded by a cycle of polygons; or used
// by two line cells.) The classification is based on the number of feature 
// edges attached to v. A feature edge occurs when the angle between the two
// surface normals of a polygon sharing an edge is greater than the
// FeatureAngle ivar. Then, vertices used by no feature edges are classified
// "simple", vertices used by exactly two feature edges are classified
// "interior edge", and all others are "fixed" vertices.
//
// Once the classification is known, the vertices are smoothed
// differently. Corner (i.e., fixed) vertices are not smoothed at all. 
// Simple vertices are smoothed as before . Interior edge vertices are
// smoothed only along their two connected edges, and only if the angle
// between the edges is less than the EdgeAngle ivar.
//
// The total smoothing can be controlled by using two ivars. The 
// NumberOfIterations determines the maximum number of smoothing passes.
// The NumberOfIterations corresponds to the degree of the polynomial that
// is used to approximate the windowed sinc function. Ten or twenty
// iterations is all the is usually necessary. Contrast this with
// vtkSmoothPolyDataFilter which usually requires 100 to 200 smoothing
// iterations. vtkSmoothPolyDataFilter is also not an approximation to
// an ideal low-pass filter, which can cause the geometry to shrink as the
// amount of smoothing increases.
//
// The second ivar is the specification of the PassBand for the windowed
// sinc filter.  By design, the PassBand is specified as a floating point
// number between 0 and 2.  Lower PassBand values produce more smoothing.
// A good default value for the PassBand is 0.1 (for those interested, the
// PassBand (and frequencies) for PolyData are based on the valence of the
// vertices, this limits all the frequency modes in a polyhedral mesh to
// between 0 and 2.)
//
// There are two instance variables that control the generation of error
// data. If the ivar GenerateErrorScalars is on, then a scalar value indicating
// the distance of each vertex from its original position is computed. If the
// ivar GenerateErrorVectors is on, then a vector representing change in 
// position is computed.
//
// .SECTION Caveats
// The smoothing operation reduces high frequency information in the
// geometry of the mesh. With excessive smoothing important details may be
// lost. Enabling FeatureEdgeSmoothing helps reduce this effect, but cannot
// entirely eliminate it.
//
// .SECTION See Also
// vtkSmoothPolyDataFilter vtkDecimate vtkDecimatePro


#ifndef __vtkWindowedSincPolyDataFilter_h
#define __vtkWindowedSincPolyDataFilter_h


#include "vtkPolyDataToPolyDataFilter.h"

class VTK_GRAPHICS_EXPORT vtkWindowedSincPolyDataFilter : public vtkPolyDataToPolyDataFilter 
{
public:
  vtkTypeMacro(vtkWindowedSincPolyDataFilter,vtkPolyDataToPolyDataFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct object with number of iterations 20; passband .1;
  // feature edge smoothing turned off; feature 
  // angle 45 degrees; edge angle 15 degrees; and boundary smoothing turned 
  // on. Error scalars and vectors are not generated (by default). The 
  // convergence criterion is 0.0 of the bounding box diagonal.
  static vtkWindowedSincPolyDataFilter *New();

  // Description:
  // Specify the number of iterations (or degree of the polynomial
  // approximating the windowed sinc function).
  vtkSetClampMacro(NumberOfIterations,int,0,VTK_LARGE_INTEGER);
  vtkGetMacro(NumberOfIterations,int);

  // Description:
  // Set the passband value for the windowed sinc filter
  vtkSetClampMacro(PassBand,float, 0.0, 2.0);
  vtkGetMacro(PassBand,float);
  
  // Description:
  // Turn on/off smoothing along sharp interior edges.
  vtkSetMacro(FeatureEdgeSmoothing,int);
  vtkGetMacro(FeatureEdgeSmoothing,int);
  vtkBooleanMacro(FeatureEdgeSmoothing,int);

  // Description:
  // Specify the feature angle for sharp edge identification.
  vtkSetClampMacro(FeatureAngle,float,0.0,180.0);
  vtkGetMacro(FeatureAngle,float);

  // Description:
  // Specify the edge angle to control smoothing along edges (either interior
  // or boundary).
  vtkSetClampMacro(EdgeAngle,float,0.0,180.0);
  vtkGetMacro(EdgeAngle,float);

  // Description:
  // Turn on/off the smoothing of vertices on the boundary of the mesh.
  vtkSetMacro(BoundarySmoothing,int);
  vtkGetMacro(BoundarySmoothing,int);
  vtkBooleanMacro(BoundarySmoothing,int);

  // Description:
  // Turn on/off the generation of scalar distance values.
  vtkSetMacro(GenerateErrorScalars,int);
  vtkGetMacro(GenerateErrorScalars,int);
  vtkBooleanMacro(GenerateErrorScalars,int);

  // Description:
  // Turn on/off the generation of error vectors.
  vtkSetMacro(GenerateErrorVectors,int);
  vtkGetMacro(GenerateErrorVectors,int);
  vtkBooleanMacro(GenerateErrorVectors,int);
  
 protected:
  vtkWindowedSincPolyDataFilter();
  ~vtkWindowedSincPolyDataFilter() {};

  void Execute();

  int NumberOfIterations;
  float PassBand;
  int FeatureEdgeSmoothing;
  float FeatureAngle;
  float EdgeAngle;
  int BoundarySmoothing;
  int GenerateErrorScalars;
  int GenerateErrorVectors;
private:
  vtkWindowedSincPolyDataFilter(const vtkWindowedSincPolyDataFilter&);  // Not implemented.
  void operator=(const vtkWindowedSincPolyDataFilter&);  // Not implemented.
};

#endif 