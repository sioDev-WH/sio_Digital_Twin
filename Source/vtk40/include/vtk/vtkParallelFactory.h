/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkParallelFactory.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:38:00 $
  Version:   $Revision: 1.6 $


Copyright (c) 1999-2000 Mercury Computers Inc. All rigts reserved.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.


=========================================================================*/
// .NAME vtkParallelFactory - 
// .SECTION Description

#ifndef __vtkParallelFactory_h
#define __vtkParallelFactory_h

#include "vtkObjectFactory.h"

class VTK_PARALLEL_EXPORT vtkParallelFactory : public vtkObjectFactory
{
public: 
// Methods from vtkObject
  vtkTypeMacro(vtkParallelFactory,vtkObjectFactory);
  static vtkParallelFactory *New();
  void PrintSelf(ostream& os, vtkIndent indent);
  virtual const char* GetVTKSourceVersion();
  virtual const char* GetDescription();
protected:
  vtkParallelFactory();
  ~vtkParallelFactory() { }
private:
  vtkParallelFactory(const vtkParallelFactory&);  // Not implemented.
  void operator=(const vtkParallelFactory&);  // Not implemented.
};

extern "C" VTK_PARALLEL_EXPORT vtkObjectFactory* vtkLoad();
#endif