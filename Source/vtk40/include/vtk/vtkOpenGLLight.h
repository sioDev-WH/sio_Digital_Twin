/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkOpenGLLight.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:38:18 $
  Version:   $Revision: 1.15 $


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
// .NAME vtkOpenGLLight - OpenGL light
// .SECTION Description
// vtkOpenGLLight is a concrete implementation of the abstract class vtkLight.
// vtkOpenGLLight interfaces to the OpenGL rendering library.

#ifndef __vtkOpenGLLight_h
#define __vtkOpenGLLight_h

#include "vtkLight.h"

class vtkOpenGLRenderer;

class VTK_RENDERING_EXPORT vtkOpenGLLight : public vtkLight
{
public:
  static vtkOpenGLLight *New();
  vtkTypeMacro(vtkOpenGLLight,vtkLight);

  // Description:
  // Implement base class method.
  void Render(vtkRenderer *ren,int light_index);
  
protected:  
  vtkOpenGLLight() {};
  ~vtkOpenGLLight() {};
private:
  vtkOpenGLLight(const vtkOpenGLLight&);  // Not implemented.
  void operator=(const vtkOpenGLLight&);  // Not implemented.
};

#endif
