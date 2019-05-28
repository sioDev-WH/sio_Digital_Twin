/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkMatrixToHomogeneousTransform.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:36:17 $
  Version:   $Revision: 1.5 $


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

// .NAME vtkMatrixToHomogeneousTransform - convert a matrix to a transform
// .SECTION Description
// This is a very simple class which allows a vtkMatrix4x4 to be used in
// place of a vtkHomogeneousTransform or vtkAbstractTransform.  For example,
// if you use it as a proxy between a matrix and vtkTransformPolyDataFilter
// then any modifications to the matrix will automatically be reflected in
// the output of the filter.
// .SECTION See Also
// vtkPerspectiveTransform vtkMatrix4x4 vtkMatrixToLinearTransform  

#ifndef __vtkMatrixToHomogeneousTransform_h
#define __vtkMatrixToHomogeneousTransform_h

#include "vtkHomogeneousTransform.h"
#include "vtkMatrix4x4.h"

class VTK_COMMON_EXPORT vtkMatrixToHomogeneousTransform : 
  public vtkHomogeneousTransform
{
 public:
  static vtkMatrixToHomogeneousTransform *New();
  vtkTypeMacro(vtkMatrixToHomogeneousTransform,vtkHomogeneousTransform);
  void PrintSelf (ostream& os, vtkIndent indent);

  // Set the input matrix.  Any modifications to the matrix will be
  // reflected in the transformation.
  vtkSetObjectMacro(Input,vtkMatrix4x4);
  vtkGetObjectMacro(Input,vtkMatrix4x4);

  // Description:
  // The input matrix is left as-is, but the transformation matrix
  // is inverted.
  void Inverse();

  // Description:
  // Get the MTime: this is the bit of magic that makes everything work.
  unsigned long GetMTime();

  // Description:
  // Make a new transform of the same type.
  vtkAbstractTransform *MakeTransform();

  // Description:
  // This method is deprecated.
  void SetMatrix(vtkMatrix4x4 *matrix) {
    this->SetInput(matrix);
    vtkWarningMacro("SetMatrix: deprecated, use SetInput() instead"); }

protected:
  vtkMatrixToHomogeneousTransform();
  ~vtkMatrixToHomogeneousTransform();

  void InternalUpdate();
  void InternalDeepCopy(vtkAbstractTransform *transform);

  int InverseFlag;
  vtkMatrix4x4 *Input;
private:
  vtkMatrixToHomogeneousTransform(const vtkMatrixToHomogeneousTransform&);  // Not implemented.
  void operator=(const vtkMatrixToHomogeneousTransform&);  // Not implemented.
};

#endif