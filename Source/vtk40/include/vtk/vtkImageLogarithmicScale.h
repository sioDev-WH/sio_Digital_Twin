/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageLogarithmicScale.h,v $
  Language:  C++
  Date:      $Date: 2001/11/13 14:32:37 $
  Version:   $Revision: 1.20 $
  Thanks:    Thanks to C. Charles Law who developed this class.

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
// .NAME vtkImageLogarithmicScale - Passes each pixel through log function.
// .SECTION Description
// vtkImageLogarithmicScale passes each pixel through the function
// c*log(1+x).  It also handles negative values with the function
// -c*log(1-x).



#ifndef __vtkImageLogarithmicScale_h
#define __vtkImageLogarithmicScale_h


#include "vtkImageToImageFilter.h"

class VTK_IMAGING_EXPORT vtkImageLogarithmicScale : public vtkImageToImageFilter
{
public:
  static vtkImageLogarithmicScale *New();
  vtkTypeMacro(vtkImageLogarithmicScale,vtkImageToImageFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/Get the scale factor for the logarithmic function.
  vtkSetMacro(Constant,float);
  vtkGetMacro(Constant,float);
  
protected:
  vtkImageLogarithmicScale();
  ~vtkImageLogarithmicScale() {};

  float Constant;
  
  void ThreadedExecute(vtkImageData *inData, vtkImageData *outData,
                       int outExt[6], int id);
private:
  vtkImageLogarithmicScale(const vtkImageLogarithmicScale&);  // Not implemented.
  void operator=(const vtkImageLogarithmicScale&);  // Not implemented.
};

#endif


