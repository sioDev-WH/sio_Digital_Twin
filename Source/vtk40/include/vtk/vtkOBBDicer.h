/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkOBBDicer.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:37:09 $
  Version:   $Revision: 1.12 $


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
// .NAME vtkOBBDicer - divide dataset into spatially aggregated pieces
// .SECTION Description
// vtkOBBDicer separates the cells of a dataset into spatially
// aggregated pieces using a Oriented Bounding Box (OBB). These pieces
// can then be operated on by other filters (e.g., vtkThreshold). One
// application is to break very large polygonal models into pieces and
// performing viewing and occlusion culling on the pieces.
//
// Refer to the superclass documentation (vtkDicer) for more information.

// .SECTION See Also
// vtkDicer vtkConnectedDicer

#ifndef __vtkOBBDicer_h
#define __vtkOBBDicer_h

#include "vtkDicer.h"
#include "vtkOBBTree.h"
class vtkShortArray;

class VTK_GRAPHICS_EXPORT vtkOBBDicer : public vtkDicer 
{
public:
  vtkTypeMacro(vtkOBBDicer,vtkDicer);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Instantiate an object.
  static vtkOBBDicer *New();

protected:
  vtkOBBDicer() {};
  ~vtkOBBDicer() {};

  // Usual data generation method
  void Execute();

  //implementation ivars and methods
  void BuildTree(vtkIdList *ptIds, vtkOBBNode *OBBptr);
  void MarkPoints(vtkOBBNode *OBBptr, vtkShortArray *groupIds);
  void DeleteTree(vtkOBBNode *OBBptr);
  vtkPoints *PointsList;
  
private:
  vtkOBBDicer(const vtkOBBDicer&);  // Not implemented.
  void operator=(const vtkOBBDicer&);  // Not implemented.
};

#endif

