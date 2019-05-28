/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkWeightedTransformFilter.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:37:27 $
  Version:   $Revision: 1.5 $
  Thanks:    Michael Halle, Brigham and Women's Hospital


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
// .NAME vtkWeightedTransformFilter -- transform based on per-point or per-cell weighting functions.
// .SECTION Description

// vtkWeightedTransformFilter is a filter that can be used to "skin"
// structures and to create new and complex shapes.  Unlike a
// traditional transform filter (which has one transform for a data
// set) or an assembly (which has one transform per part or group of
// parts), a weighted transform produces the weighted sum of
// transforms on a per-point or per-cell basis.
//
// Each point or cell in the filter's input has an attached DataArray
// that contains tuples of weighting functions, one per point or cell.
// The filter also has a set of fixed transforms.  When the filter
// executes, each input point/cell is transformed by each of the
// transforms.  These results are weighted by the point/cell's
// weighting factors to produce final output data.
//
// Linear transforms are performance-optimized.  Using arbitrary
// transforms will work, but performance may suffer.
//
// As an example of the utility of weighted transforms, here's how
// this filter can be used for "skinning."  Skinning is the process of
// putting a mesh cover over an underlying structure, like skin over
// bone.  Joints are difficult to skin because deformation is hard to
// do.  Visualize skin over an elbow joint.  Part of the skin moves
// with one bone, part of the skin moves with the other bone, and the
// skin in the middle moves a little with each.
//
// Weighted filtering can be used for a simple and efficient kind of
// skinning.  Begin with a cylindrical mesh.  Create a FloatArray with
// two components per tuple, and one tuple for each point in the mesh.
// Assign transform weights that linear interpolate the distance along
// the cylinder (one component is the distance along the cylinder, the
// other is one minus that distance).  Set the filter up to use two
// transforms, the two used to transform the two bones.  Now, when the
// transforms change, the mesh will deform so as to, hopefully,
// continue to cover the bones.
//
// vtkWeightedTransformFilter is also useful for creating "strange and
// complex" shapes using pinching, bending, and blending.
//
// .SECTION Caveats
// Weighted combination of normals and vectors are probably not appropriate
// in many cases.  Surface normals are treated somewhat specially, but
// in many cases you may need to regenerate the surface normals.
//
// Cell data can only be transformed if all transforms are linear.
//
//
// .SECTION See Also
// vtkAbstractTransform vtkLinearTransform vtkTransformPolyDataFilter vtkActor

#ifndef __vtkWeightedTransformFilter_h
#define __vtkWeightedTransformFilter_h

#include "vtkPointSetToPointSetFilter.h"
#include "vtkAbstractTransform.h"

class VTK_HYBRID_EXPORT vtkWeightedTransformFilter : public vtkPointSetToPointSetFilter
{
public:
  static vtkWeightedTransformFilter *New();
  vtkTypeMacro(vtkWeightedTransformFilter,vtkPointSetToPointSetFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Return the MTime also considering the filter's transforms.
  unsigned long GetMTime();

  // Description:
  // WeightArray is the string name of the DataArray in the input's
  // FieldData that holds the weighting coefficients for each point.
  // The filter will first look for the array in the input's PointData
  // FieldData.  If the array isn't there, the filter looks in the
  // input's FieldData.  The WeightArray can have tuples of any length,
  // but must have a tuple for every point in the input data set.
  // This array transforms points, normals, and vectors.
  vtkSetStringMacro(WeightArray);
  vtkGetStringMacro(WeightArray);

  // Description:
  // The CellDataWeightArray is analogous to the WeightArray, except
  // for CellData.  The array is searched for first in the CellData 
  // FieldData, then in the input's FieldData.  The data array must have
  // a tuple for each cell.  This array is used to transform only normals
  // and vectors.
  vtkSetStringMacro(CellDataWeightArray);
  vtkGetStringMacro(CellDataWeightArray);

  // Description:
  // Set or Get one of the filter's transforms. The transform number must
  // be less than the number of transforms allocated for the object.  Setting
  // a transform slot to NULL is equivalent to assigning an overriding weight
  // of zero to that filter slot.
  virtual void SetTransform(vtkAbstractTransform *transform, int num);
  virtual vtkAbstractTransform *GetTransform(int num);

  // Description:
  // Set the number of transforms for the filter.  References to non-existent
  // filter numbers in the data array is equivalent to a weight of zero
  // (i.e., no contribution of that filter or weight).
  virtual void SetNumberOfTransforms(int num);
  vtkGetMacro(NumberOfTransforms, int);

  // Description:
  // If AddInputValues is true, the output values of this filter will be
  // offset from the input values.  The effect is exactly equivalent to
  // having an identity transform of weight 1 added into each output point.
  vtkBooleanMacro(AddInputValues, int);
  vtkSetMacro(AddInputValues, int);
  vtkGetMacro(AddInputValues, int);

protected:
  vtkAbstractTransform **Transforms;
  int NumberOfTransforms;
  int AddInputValues;

  char *CellDataWeightArray;
  char *WeightArray;

  vtkWeightedTransformFilter();
  ~vtkWeightedTransformFilter();

  void Execute();
private:
  vtkWeightedTransformFilter(const vtkWeightedTransformFilter&);  // Not implemented.
  void operator=(const vtkWeightedTransformFilter&);  // Not implemented.
};

#endif

