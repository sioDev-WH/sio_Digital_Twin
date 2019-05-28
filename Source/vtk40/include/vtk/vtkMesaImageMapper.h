/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkMesaImageMapper.h,v $
  Language:  C++
  Date:      $Date: 2001/11/13 14:17:23 $
  Version:   $Revision: 1.9 $

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
// .NAME vtkMesaImageMapper - 2D image display support for Mesa
// .SECTION Description
// vtkMesaImageMapper is a concrete subclass of vtkImageMapper that
// renders images under Mesa

// .SECTION See Also
// vtkImageMapper

#ifndef __vtkMesaImageMapper_h
#define __vtkMesaImageMapper_h


#include "vtkImageMapper.h"
class vtkActor2D;


class VTK_RENDERING_EXPORT vtkMesaImageMapper : public vtkImageMapper
{
public:
  static vtkMesaImageMapper *New();
  vtkTypeMacro(vtkMesaImageMapper,vtkImageMapper);
  
  // Description:
  // Handle the render method.
  void RenderOpaqueGeometry(vtkViewport* viewport, vtkActor2D* actor) {
    this->RenderStart(viewport,actor);}

  // Description:
  // Called by the Render function in vtkImageMapper.  Actually draws
  // the image to the screen.
  void RenderData(vtkViewport* viewport, vtkImageData* data, 
                  vtkActor2D* actor);

protected:
  vtkMesaImageMapper();
  ~vtkMesaImageMapper();

private:
  vtkMesaImageMapper(const vtkMesaImageMapper&);  // Not implemented.
  void operator=(const vtkMesaImageMapper&);  // Not implemented.
};


#endif








