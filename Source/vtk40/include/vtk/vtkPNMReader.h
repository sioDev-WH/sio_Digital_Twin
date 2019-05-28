/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPNMReader.h,v $
  Language:  C++
  Date:      $Date: 2001/10/11 13:37:32 $
  Version:   $Revision: 1.14 $


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
// .NAME vtkPNMReader - read pnm (i.e., portable anymap) files

// .SECTION Description
// vtkPNMReader is a source object that reads pnm (portable anymap) files.
// This includes .pbm (bitmap), .pgm (grayscale), and .ppm (pixmap) files.
// (Currently this object only reads binary versions of these files.)
//
// PNMReader creates structured point datasets. The dimension of the 
// dataset depends upon the number of files read. Reading a single file 
// results in a 2D image, while reading more than one file results in a 
// 3D volume.
//
// To read a volume, files must be of the form "FileName.<number>" (e.g.,
// foo.ppm.0, foo.ppm.1, ...). You must also specify the DataExtent.  The
// fifth and sixth values of the DataExtent specify the beginning and ending
// files to read.


#ifndef __vtkPNMReader_h
#define __vtkPNMReader_h

#include <stdio.h>
#include "vtkImageReader.h"

class VTK_IO_EXPORT vtkPNMReader : public vtkImageReader
{
public:
  static vtkPNMReader *New();
  vtkTypeMacro(vtkPNMReader,vtkImageReader);
  
protected:
  vtkPNMReader() {};
  ~vtkPNMReader() {};
  void ExecuteInformation();
private:
  vtkPNMReader(const vtkPNMReader&);  // Not implemented.
  void operator=(const vtkPNMReader&);  // Not implemented.
};

#endif

