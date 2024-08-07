/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkCastToConcrete.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:36:32 $
  Version:   $Revision: 1.29 $


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
// .NAME vtkCastToConcrete - works around type-checking limitations
// .SECTION Description
// vtkCastToConcrete is a filter that works around type-checking limitations
// in the filter classes. Some filters generate abstract types on output, 
// and cannot be connected to the input of filters requiring a concrete
// input type. For example, vtkElevationFilter generates vtkDataSet for output,
// and cannot be connected to vtkDecimate, because vtkDecimate requires 
// vtkPolyData as input. This is true even though (in this example) the input 
// to vtkElevationFilter is of type vtkPolyData, and you know the output of 
// vtkElevationFilter is the same type as its input.
//
// vtkCastToConcrete performs run-time checking to insure that output type
// is of the right type. An error message will result if you try to cast
// an input type improperly. Otherwise, the filter performs the appropriate
// cast and returns the data.

// .SECTION Caveats
// You must specify the input before you can get the output. Otherwise an
// error results.

// .SECTION See Also
// vtkDataSetToDataSetFilter vtkPointSetToPointSetFilter

#ifndef __vtkCastToConcrete_h
#define __vtkCastToConcrete_h

#include "vtkDataSetToDataSetFilter.h"

class VTK_FILTERING_EXPORT vtkCastToConcrete : public vtkDataSetToDataSetFilter
{

public:
  static vtkCastToConcrete *New();
  vtkTypeMacro(vtkCastToConcrete,vtkDataSetToDataSetFilter);

protected:
  vtkCastToConcrete() {};
  ~vtkCastToConcrete() {};

  void Execute(); //insures compatibility; satisfies abstract api in vtkFilter
  void ExecuteInformation();
private:
  vtkCastToConcrete(const vtkCastToConcrete&);  // Not implemented.
  void operator=(const vtkCastToConcrete&);  // Not implemented.
};

#endif
