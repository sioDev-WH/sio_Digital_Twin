/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkOpenGLVolumeRayCastMapper.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:38:20 $
  Version:   $Revision: 1.3 $


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

// .NAME vtkOpenGLVolumeRayCastMapper - OpenGL subclass that draws the image to the screen
// .SECTION Description
// This is the concrete implementation of a ray cast mapper - it is 
// responsible for drawing the image to the screen. The remaining
// functionality all comes from vtkVolumeRayCastMapper

// .SECTION see also
// vtkVolumeRayCastMapper vtkVolumeMapper

#ifndef __vtkOpenGLVolumeRayCastMapper_h
#define __vtkOpenGLVolumeRayCastMapper_h

#include "vtkVolumeRayCastMapper.h"
#include <stdlib.h>
#ifndef VTK_IMPLEMENT_MESA_CXX
  #ifdef __APPLE__
    #include <OpenGL/gl.h>
  #else
    #include <GL/gl.h>
  #endif
#endif

class VTK_RENDERING_EXPORT vtkOpenGLVolumeRayCastMapper : public vtkVolumeRayCastMapper
{
public:
  static vtkOpenGLVolumeRayCastMapper *New();
  vtkTypeMacro(vtkOpenGLVolumeRayCastMapper,vtkVolumeRayCastMapper);

protected:
  vtkOpenGLVolumeRayCastMapper();
  ~vtkOpenGLVolumeRayCastMapper();

  void RenderTexture( vtkVolume *vol, vtkRenderer *ren);

private:
  vtkOpenGLVolumeRayCastMapper(const vtkOpenGLVolumeRayCastMapper&);  // Not implemented.
  void operator=(const vtkOpenGLVolumeRayCastMapper&);  // Not implemented.
};

#endif

