/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageProgressIterator.h,v $
  Language:  C++
  Date:      $Date: 2001/10/26 19:59:17 $
  Version:   $Revision: 1.2 $


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
// .NAME vtkImageProgressIterator - a simple image iterator with progress
// .SECTION Description
// This is a simple image iterator that can be used to iterate over an 
// image. Typically used to iterate over the output image

// .SECTION See also
// vtkImage vtkImageIterator

#ifndef __vtkImageProgressIterator_h
#define __vtkImageProgressIterator_h

#include "vtkImageIterator.h"
class vtkProcessObject;

template<typename DType> class VTK_COMMON_EXPORT vtkImageProgressIterator : 
  public vtkImageIterator<DType> 
{
public:        

  // Description:
  // Create a progress iterator for the provided image data
  // and extent to iterate over. The passes progress object will
  // receive any UpdateProgress calls if the thread id is zero
  vtkImageProgressIterator(vtkImageData *imgd, int *ext, 
                           vtkProcessObject *po, int id);

  // Description:
  // Move the iterator to the next span, may call UpdateProgress on the
  // filter (vtkProcessObject)
  void NextSpan();
  
protected:
  vtkProcessObject *ProcessObject;
  unsigned long     Count;
  unsigned long     Count2;
  unsigned long     Target;
  int               ID;
};

#ifdef CMAKE_NO_EXPLICIT_TEMPLATE_INSTANTIATION
// include the code
#include "vtkImageProgressIterator.cxx"
#endif

#endif