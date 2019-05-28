/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkMapper2D.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:36:17 $
  Version:   $Revision: 1.24 $
  Thanks:    Thanks to Matt Turek who developed this class.

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
// .NAME vtkMapper2D
// .SECTION Description
// vtkMapper2D is an abstract class which defines the interface for objects
// which render two dimensional actors (vtkActor2D).

// .SECTION See Also
// vtkActor2D

#ifndef __vtkMapper2D_h
#define __vtkMapper2D_h

#include "vtkAbstractMapper.h"
#include "vtkWindow.h"

class vtkViewport;
class vtkActor2D;

class VTK_COMMON_EXPORT vtkMapper2D : public vtkAbstractMapper
{
public:
  static vtkMapper2D* New();

  vtkTypeMacro(vtkMapper2D,vtkAbstractMapper);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  virtual void RenderOverlay(vtkViewport*, vtkActor2D*) {};
  virtual void RenderOpaqueGeometry(vtkViewport*, vtkActor2D*) {};
  virtual void RenderTranslucentGeometry(vtkViewport*, vtkActor2D*) {};

protected:
  vtkMapper2D() {};
  ~vtkMapper2D() {};

private:
  vtkMapper2D(const vtkMapper2D&);  // Not implemented.
  void operator=(const vtkMapper2D&);  // Not implemented.
};

#endif


