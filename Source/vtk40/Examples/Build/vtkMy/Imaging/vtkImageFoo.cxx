/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageFoo.cxx,v $
  Language:  C++
  Date:      $Date: 2001/12/20 19:03:48 $
  Version:   $Revision: 1.2.2.1 $

=========================================================================*/

#include "vtkBar.h"
#include "vtkImageFoo.h"
#include "vtkObjectFactory.h"

//----------------------------------------------------------------------------

vtkImageFoo* vtkImageFoo::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkImageFoo");
  if(ret)
    {
    return (vtkImageFoo*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkImageFoo;
}

//----------------------------------------------------------------------------

vtkImageFoo::vtkImageFoo()
{
  this->Foo = 0.0;
  this->OutputScalarType = -1;
  this->Bar = vtkBar::New();
}

//----------------------------------------------------------------------------

vtkImageFoo::~vtkImageFoo()
{
  if (this->Bar)
    {
    this->Bar->Delete();
    this->Bar = NULL;
    }
}

//----------------------------------------------------------------------------

void vtkImageFoo::ExecuteInformation(vtkImageData *inData, 
                                     vtkImageData *outData)
{
  this->vtkImageToImageFilter::ExecuteInformation(inData, outData);

  if (this->OutputScalarType != -1)
    {
    outData->SetScalarType(this->OutputScalarType);
    }
}

//----------------------------------------------------------------------------

// This templated function executes the filter for any type of data.

template <class IT, class OT>
static void vtkImageFooExecute(vtkImageFoo *self,
                               vtkImageData *inData, IT *inPtr,
                               vtkImageData *outData, OT *outPtr,
                               int outExt[6], int id)
{
  float foo = self->GetFoo();

  int idxR, idxY, idxZ;
  int maxY, maxZ;
  int inIncX, inIncY, inIncZ;
  int outIncX, outIncY, outIncZ;
  int rowLength;

  unsigned long count = 0;
  unsigned long target;

  // find the region to loop over

  rowLength = (outExt[1] - outExt[0]+1)*inData->GetNumberOfScalarComponents();
  maxY = outExt[3] - outExt[2]; 
  maxZ = outExt[5] - outExt[4];
  target = (unsigned long)((maxZ+1)*(maxY+1)/50.0);
  target++;
  
  // Get increments to march through data 

  inData->GetContinuousIncrements(outExt, inIncX, inIncY, inIncZ);
  outData->GetContinuousIncrements(outExt, outIncX, outIncY, outIncZ);

  // Loop through ouput pixels

  for (idxZ = 0; idxZ <= maxZ; idxZ++)
    {
    for (idxY = 0; !self->AbortExecute && idxY <= maxY; idxY++)
      {
      for (idxR = 0; idxR < rowLength; idxR++)
        {
        // Pixel operation. Add foo. Dumber would be impossible.
        *outPtr = (OT)((float)(*inPtr) + foo);
        outPtr++;
        inPtr++;
        }
      outPtr += outIncY;
      inPtr += inIncY;
      }
    outPtr += outIncZ;
    inPtr += inIncZ;
    }
}


//----------------------------------------------------------------------------

template <class T>
static void vtkImageFooExecute1(vtkImageFoo *self,
                                vtkImageData *inData, T *inPtr,
                                vtkImageData *outData,
                                int outExt[6], int id)
{
  void *outPtr = outData->GetScalarPointerForExtent(outExt);
  
  switch (outData->GetScalarType())
    {
    vtkTemplateMacro7(vtkImageFooExecute, self, inData, inPtr,
                      outData, (VTK_TT *)(outPtr),outExt, id);
    default:
      vtkGenericWarningMacro("Execute: Unknown input ScalarType");
      return;
    }
}

//----------------------------------------------------------------------------

// This method is passed a input and output data, and executes the filter
// algorithm to fill the output from the input.
// It just executes a switch statement to call the correct function for
// the datas data types.

void vtkImageFoo::ThreadedExecute(vtkImageData *inData, 
                                  vtkImageData *outData,
                                  int outExt[6], int id)
{
  void *inPtr = inData->GetScalarPointerForExtent(outExt);
  
  switch (inData->GetScalarType())
    {
    vtkTemplateMacro6(vtkImageFooExecute1, this, 
                      inData, (VTK_TT *)(inPtr), outData, outExt, id);
    default:
      vtkErrorMacro(<< "Execute: Unknown ScalarType");
      return;
    }
}

//----------------------------------------------------------------------------

void vtkImageFoo::PrintSelf(ostream& os, vtkIndent indent)
{
  vtkImageToImageFilter::PrintSelf(os,indent);

  os << indent << "Foo: " << this->Foo << "\n";
  os << indent << "Output Scalar Type: " << this->OutputScalarType << "\n";
}
