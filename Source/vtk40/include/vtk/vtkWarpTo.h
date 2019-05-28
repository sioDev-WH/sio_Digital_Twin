/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkWarpTo.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:37:22 $
  Version:   $Revision: 1.31 $


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
// .NAME vtkWarpTo - deform geometry by warping towards a point
// .SECTION Description
// vtkWarpTo is a filter that modifies point coordinates by moving the
// points towards a user specified position.

#ifndef __vtkWarpTo_h
#define __vtkWarpTo_h

#include "vtkPointSetToPointSetFilter.h"

class VTK_GRAPHICS_EXPORT vtkWarpTo : public vtkPointSetToPointSetFilter
{
public:
  static vtkWarpTo *New();
  vtkTypeMacro(vtkWarpTo,vtkPointSetToPointSetFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/Get the value to scale displacement.
  vtkSetMacro(ScaleFactor,float);
  vtkGetMacro(ScaleFactor,float);

  // Description:
  // Set/Get the position to warp towards.
  vtkGetVectorMacro(Position,float,3);
  vtkSetVector3Macro(Position,float);

  // Description:
  // Set/Get the Absolute ivar. Turning Absolute on causes scale factor
  // of the new position to be one unit away from Position.
  vtkSetMacro(Absolute,int);
  vtkGetMacro(Absolute,int);
  vtkBooleanMacro(Absolute,int);
  
protected:
  vtkWarpTo(); 
  ~vtkWarpTo() {};

  void Execute();
  float ScaleFactor;
  float Position[3];
  int   Absolute;
private:
  vtkWarpTo(const vtkWarpTo&);  // Not implemented.
  void operator=(const vtkWarpTo&);  // Not implemented.
};

#endif