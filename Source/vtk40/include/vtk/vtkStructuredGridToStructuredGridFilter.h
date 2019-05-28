/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkStructuredGridToStructuredGridFilter.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:36:38 $
  Version:   $Revision: 1.26 $


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
// .NAME vtkStructuredGridToStructuredGridFilter - abstract filter class
// .SECTION Description
// vtkStructuredPointsToStructuredPointsFilter is an abstract filter class 
// whose subclasses take on input a structured grid  and generate a
// structured grid on output.

// .SECTION See Also
// vtkExtractGrid

#ifndef __vtkStructuredGridToStructuredGridFilter_h
#define __vtkStructuredGridToStructuredGridFilter_h

#include "vtkStructuredGridSource.h"

class VTK_FILTERING_EXPORT vtkStructuredGridToStructuredGridFilter : public vtkStructuredGridSource
{
public:
  vtkTypeMacro(vtkStructuredGridToStructuredGridFilter,vtkStructuredGridSource);

  // Description:
  // Set / get the input Grid or filter.
  void SetInput(vtkStructuredGrid *input);
  vtkStructuredGrid *GetInput();

protected:
  vtkStructuredGridToStructuredGridFilter() {this->NumberOfRequiredInputs = 1;};
  ~vtkStructuredGridToStructuredGridFilter() {};
private:
  vtkStructuredGridToStructuredGridFilter(const vtkStructuredGridToStructuredGridFilter&);  // Not implemented.
  void operator=(const vtkStructuredGridToStructuredGridFilter&);  // Not implemented.
};

#endif

