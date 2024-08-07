/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPolyDataCollection.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:36:36 $
  Version:   $Revision: 1.36 $


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
// .NAME vtkPolyDataCollection - maintain a list of polygonal data objects
// .SECTION Description
// vtkPolyDataCollection is an object that creates and manipulates lists of
// datasets of type vtkPolyData. 

// .SECTION See Also
// vtkDataSetCollection vtkCollection

#ifndef __vtkPolyDataCollection_h
#define __vtkPolyDataCollection_h

#include "vtkCollection.h"
#include "vtkPolyData.h"

class VTK_FILTERING_EXPORT vtkPolyDataCollection : public vtkCollection
{
public:
  static vtkPolyDataCollection *New();
  vtkTypeMacro(vtkPolyDataCollection,vtkCollection);

  // Description:
  // Add a poly data to the list.
  void AddItem(vtkPolyData *pd) {
    this->vtkCollection::AddItem((vtkObject *)pd);};

  // Description:
  // Get the next poly data in the list.
  vtkPolyData *GetNextItem() { 
    return static_cast<vtkPolyData *>(this->GetNextItemAsObject());};
protected:  
  vtkPolyDataCollection() {};
  ~vtkPolyDataCollection() {};

private:
  // hide the standard AddItem from the user and the compiler.
  void AddItem(vtkObject *o) { this->vtkCollection::AddItem(o); };

private:
  vtkPolyDataCollection(const vtkPolyDataCollection&);  // Not implemented.
  void operator=(const vtkPolyDataCollection&);  // Not implemented.
};


#endif
