/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkCellData.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:36:03 $
  Version:   $Revision: 1.16 $


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
// .NAME vtkCellData - represent and manipulate cell attribute data
// .SECTION Description
// vtkCellData is a class that is used to represent and manipulate
// cell attribute data (e.g., scalars, vectors, normals, texture 
// coordinates, etc.) Special methods are provided to work with filter
// objects, such as passing data through filter, copying data from one 
// cell to another, and interpolating data given cell interpolation weights.

#ifndef __vtkCellData_h
#define __vtkCellData_h

#include "vtkDataSetAttributes.h"

class VTK_COMMON_EXPORT vtkCellData : public vtkDataSetAttributes
{
public:
  static vtkCellData *New();

  vtkTypeMacro(vtkCellData,vtkDataSetAttributes);
  void PrintSelf(ostream& os, vtkIndent indent);

protected:
  vtkCellData() {}; //make sure constructor and desctructor are protected
  ~vtkCellData() {};
  
private:
  vtkCellData(const vtkCellData&);  // Not implemented.
  void operator=(const vtkCellData&);  // Not implemented.
};

#endif


