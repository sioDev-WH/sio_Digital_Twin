/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkAbstractTransform.h,v $
  Language:  C++
  Date:      $Date: 2001/11/30 19:14:13 $
  Version:   $Revision: 1.16 $
  Thanks:    Thanks to David G. Gobbi who developed this class.

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
// .NAME vtkAbstractTransform - superclass for all geometric transformations
// .SECTION Description
// vtkAbstractTransform is the superclass for all VTK geometric 
// transformations.  The VTK transform hierarchy is split into two
// major branches: warp transformations and homogeneous (including linear)
// transformations.  The latter can be represented in terms of a 4x4
// transformation matrix, the former cannot.  
// <p>Transformations can be pipelined through two mechanisms:  
// <p>1) GetInverse() returns the pipelined
// inverse of a transformation i.e. if you modify the original transform,
// any transform previously returned by the GetInverse() method will
// automatically update itself according to the change.
// <p>2) You can do pipelined concatenation of transformations through 
// the vtkGeneralTransform class, the vtkPerspectiveTransform class,
// or the vtkTransform class. 
// .SECTION see also
// vtkGeneralTransform vtkWarpTransform vtkHomogeneousTransform
// vtkLinearTransform vtkIdentityTransform
// vtkTransformPolyDataFilter vtkTransformFilter vtkImageReslice
// vtkImplicitFunction


#ifndef __vtkAbstractTransform_h
#define __vtkAbstractTransform_h

#include "vtkObject.h"
#include "vtkMatrix4x4.h"
#include "vtkPoints.h"

class vtkSimpleCriticalSection;


class VTK_COMMON_EXPORT vtkAbstractTransform : public vtkObject
{
public:

  vtkTypeMacro(vtkAbstractTransform,vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Apply the transformation to a coordinate.  You can use the same 
  // array to store both the input and output point.
  void TransformPoint(const float in[3], float out[3]) {
    this->Update(); this->InternalTransformPoint(in,out); };

  // Description:
  // Apply the transformation to a double-precision coordinate.  
  // You can use the same array to store both the input and output point.
  void TransformPoint(const double in[3], double out[3]) {
    this->Update(); this->InternalTransformPoint(in,out); };

  // Description:
  // Apply the transformation to a double-precision coordinate.  
  // Use this if you are programming in Python, tcl or Java.
  double *TransformPoint(double x, double y, double z) {
    return this->TransformDoublePoint(x,y,z); }
  double *TransformPoint(const double point[3]) {
    return this->TransformPoint(point[0],point[1],point[2]); };

  // Description:
  // Apply the transformation to an (x,y,z) coordinate.
  // Use this if you are programming in Python, tcl or Java.
  float *TransformFloatPoint(float x, float y, float z) {
      this->InternalFloatPoint[0] = x;
      this->InternalFloatPoint[1] = y;
      this->InternalFloatPoint[2] = z;
      this->TransformPoint(this->InternalFloatPoint,this->InternalFloatPoint);
      return this->InternalFloatPoint; };
  float *TransformFloatPoint(const float point[3]) {
    return this->TransformFloatPoint(point[0],point[1],point[2]); };

  // Description:
  // Apply the transformation to a double-precision (x,y,z) coordinate.
  // Use this if you are programming in Python, tcl or Java.
  double *TransformDoublePoint(double x, double y, double z) {
    this->InternalDoublePoint[0] = x;
    this->InternalDoublePoint[1] = y;
    this->InternalDoublePoint[2] = z;
    this->TransformPoint(this->InternalDoublePoint,this->InternalDoublePoint);
    return this->InternalDoublePoint; };
  double *TransformDoublePoint(const double point[3]) {
    return this->TransformDoublePoint(point[0],point[1],point[2]); };

  // Description:
  // Apply the transformation to a normal at the specified vertex.  If the
  // transformation is a vtkLinearTransform, you can use TransformNormal()
  // instead.
  void TransformNormalAtPoint(const float point[3], const float in[3],
                              float out[3]);
  void TransformNormalAtPoint(const double point[3], const double in[3],
                              double out[3]);

  double *TransformNormalAtPoint(const double point[3], 
                                 const double normal[3]) {
    this->TransformNormalAtPoint(point,normal,this->InternalDoublePoint);
    return this->InternalDoublePoint; };

  // Description:
  // Apply the transformation to a double-precision normal at the specified
  // vertex.  If the transformation is a vtkLinearTransform, you can use
  // TransformDoubleNormal() instead.
  double *TransformDoubleNormalAtPoint(const double point[3],
                                       const double normal[3]) {
    this->TransformNormalAtPoint(point,normal,this->InternalDoublePoint);
    return this->InternalDoublePoint; };
  
  // Description:
  // Apply the transformation to a single-precision normal at the specified
  // vertex.  If the transformation is a vtkLinearTransform, you can use
  // TransformFloatNormal() instead.
  float *TransformFloatNormalAtPoint(const float point[3],
                                     const float normal[3]) {
    this->TransformNormalAtPoint(point,normal,this->InternalFloatPoint);
    return this->InternalFloatPoint; };

  // Description:
  // Apply the transformation to a vector at the specified vertex.  If the
  // transformation is a vtkLinearTransform, you can use TransformVector()
  // instead.
  void TransformVectorAtPoint(const float point[3], const float in[3],
                              float out[3]);
  void TransformVectorAtPoint(const double point[3], const double in[3],
                              double out[3]);

  double *TransformVectorAtPoint(const double point[3], 
                                 const double vector[3]) {
    this->TransformVectorAtPoint(point,vector,this->InternalDoublePoint);
    return this->InternalDoublePoint; };

  // Description:
  // Apply the transformation to a double-precision vector at the specified
  // vertex.  If the transformation is a vtkLinearTransform, you can use
  // TransformDoubleVector() instead.
  double *TransformDoubleVectorAtPoint(const double point[3],
                                       const double vector[3]) {
    this->TransformVectorAtPoint(point,vector,this->InternalDoublePoint);
    return this->InternalDoublePoint; };
  
  // Description:
  // Apply the transformation to a single-precision vector at the specified
  // vertex.  If the transformation is a vtkLinearTransform, you can use
  // TransformFloatVector() instead.
  float *TransformFloatVectorAtPoint(const float point[3],
                                     const float vector[3]) {
    this->TransformVectorAtPoint(point,vector,this->InternalFloatPoint);
    return this->InternalFloatPoint; };

  // Description:
  // Apply the transformation to a series of points, and append the
  // results to outPts.  
  virtual void TransformPoints(vtkPoints *inPts, vtkPoints *outPts);

  // Description:
  // Apply the transformation to a combination of points, normals
  // and vectors.  
  virtual void TransformPointsNormalsVectors(vtkPoints *inPts, 
                                             vtkPoints *outPts, 
                                             vtkDataArray *inNms, 
                                             vtkDataArray *outNms,
                                             vtkDataArray *inVrs, 
                                             vtkDataArray *outVrs);

  // Description:
  // Get the inverse of this transform.  If you modify this transform,
  // the returned inverse transform will automatically update.  If you
  // want the inverse of a vtkTransform, you might want to use
  // GetLinearInverse() instead which will type cast the result from
  // vtkAbstractTransform to vtkLinearTransform.
  vtkAbstractTransform *GetInverse();

  // Description:
  // Set a transformation that this transform will be the inverse of.
  // This transform will automatically update to agree with the 
  // inverse transform that you set.
  void SetInverse(vtkAbstractTransform *transform);

  // Description:
  // Invert the transformation.
  virtual void Inverse() = 0;

  // Description:
  // Copy this transform from another of the same type.
  void DeepCopy(vtkAbstractTransform *);

  // Description:
  // Update the transform to account for any changes which
  // have been made.  You do not have to call this method 
  // yourself, it is called automatically whenever the
  // transform needs an update.
  void Update();

  // Description:
  // This will calculate the transformation without calling Update.
  // Meant for use only within other VTK classes.
  virtual void InternalTransformPoint(const float in[3], float out[3]) = 0;
  virtual void InternalTransformPoint(const double in[3], double out[3]) = 0;

  // Description:
  // This will transform a point and, at the same time, calculate a
  // 3x3 Jacobian matrix that provides the partial derivatives of the
  // transformation at that point.  This method does not call Update.
  // Meant for use only within other VTK classes.
  virtual void InternalTransformDerivative(const float in[3], float out[3],
                                           float derivative[3][3]) = 0;
  virtual void InternalTransformDerivative(const double in[3], double out[3],
                                           double derivative[3][3]) = 0;

  // Description:
  // Make another transform of the same type.
  virtual vtkAbstractTransform *MakeTransform() = 0;

  // Description:
  // Check for self-reference.  Will return true if concatenating
  // with the specified transform, setting it to be our inverse,
  // or setting it to be our input will create a circular reference.
  // CircuitCheck is automatically called by SetInput(), SetInverse(),
  // and Concatenate(vtkXTransform *).  Avoid using this function,
  // it is experimental.
  virtual int CircuitCheck(vtkAbstractTransform *transform);

  // Description:
  // Override GetMTime necessary because of inverse transforms.
  unsigned long GetMTime();

  // Description:
  // Needs a special UnRegister() implementation to avoid
  // circular references.
  void UnRegister(vtkObject *O);

  // Description:
  // This method is deprecated in the base class.  It is still valid
  // to use it on many of the specialized classes.
  void Identity() { 
    vtkWarningMacro("vtkAbstractTransform::Identity() is deprecated"); };

protected:
  vtkAbstractTransform();
  ~vtkAbstractTransform();

  // Description:
  // Perform any subclass-specific Update.
  virtual void InternalUpdate() {};

  // Description:
  // Perform any subclass-specific DeepCopy. 
  virtual void InternalDeepCopy(vtkAbstractTransform *) {};

  float InternalFloatPoint[3];
  double InternalDoublePoint[3];

private:
  
//BTX
  // We need to record the time of the last update, and we also need
  // to do mutex locking so updates don't collide.  These are private
  // because Update() is not virtual.
  // If DependsOnInverse is set, then this transform object will
  // check its inverse on every update, and update itself accordingly
  // if necessary.
//ETX
  vtkTimeStamp UpdateTime;
  vtkSimpleCriticalSection *UpdateMutex;
  vtkSimpleCriticalSection *InverseMutex;
  int DependsOnInverse;

//BTX
  // MyInverse is a transform which is the inverse of this one.
//ETX
  vtkAbstractTransform *MyInverse;

  int InUnRegister;
  
private:
  vtkAbstractTransform(const vtkAbstractTransform&);  // Not implemented.
  void operator=(const vtkAbstractTransform&);  // Not implemented.
};

//BTX
//-------------------------------------------------------------------------
// A simple data structure to hold both a transform and its inverse.
// One of ForwardTransform or InverseTransform might be NULL,
// and must be acquired by calling GetInverse() on the other.
class vtkTransformPair
{
public:
  vtkAbstractTransform *ForwardTransform;
  vtkAbstractTransform *InverseTransform;
  
  void SwapForwardInverse() {
    vtkAbstractTransform *tmp = this->ForwardTransform;
    this->ForwardTransform = this->InverseTransform;
    this->InverseTransform = tmp; };
};

// A helper class (not derived from vtkObject) to store a series of
// transformations in a pipelined concatenation.
class VTK_COMMON_EXPORT vtkTransformConcatenation
{
public:
  static vtkTransformConcatenation *New() {
    return new vtkTransformConcatenation(); };
  void Delete() { delete this; };

  // add a transform to the list according to Pre/PostMultiply semantics
  void Concatenate(vtkAbstractTransform *transform); 
    
  // concatenate with a matrix according to Pre/PostMultiply semantics
  void Concatenate(const double elements[16]);

  // set the PreMultiply flag
  void SetPreMultiplyFlag(int flag) { this->PreMultiplyFlag = flag; };
  int GetPreMultiplyFlag() { return this->PreMultiplyFlag; };
  
  // the three basic linear transformations
  void Translate(double x, double y, double z);
  void Rotate(double angle, double x, double y, double z);
  void Scale(double x, double y, double z);

  // invert the concatenation
  void Inverse();
  
  // get the inverse flag
  int GetInverseFlag() { return this->InverseFlag; };
  
  // identity simply clears the transform list
  void Identity();
    
  // copy the list
  void DeepCopy(vtkTransformConcatenation *transform);
    
  // the number of stored transforms
  int GetNumberOfTransforms() { return this->NumberOfTransforms; };
    
  // the number of transforms that were pre-concatenated (note that
  // whenever Iverse() is called, the pre-concatenated and
  // post-concatenated transforms are switched)
  int GetNumberOfPreTransforms() { return this->NumberOfPreTransforms; };

  // the number of transforms that were post-concatenated.
  int GetNumberOfPostTransforms() { 
    return this->NumberOfTransforms-this->NumberOfPreTransforms; };

  // get one of the transforms
  vtkAbstractTransform *GetTransform(int i);
    
  // get maximum MTime of all transforms
  unsigned long GetMaxMTime();
    
  void PrintSelf(ostream& os, vtkIndent indent);

protected:
  vtkTransformConcatenation();
  ~vtkTransformConcatenation();  
    
  int InverseFlag;
  int PreMultiplyFlag;
    
  vtkMatrix4x4 *PreMatrix;
  vtkMatrix4x4 *PostMatrix;
  vtkAbstractTransform *PreMatrixTransform;
  vtkAbstractTransform *PostMatrixTransform;

  int NumberOfTransforms;
  int NumberOfPreTransforms;
  int MaxNumberOfTransforms;
  vtkTransformPair *TransformList;
};

// A helper class (not derived from vtkObject) to store a stack of
// concatenations.
class VTK_COMMON_EXPORT vtkTransformConcatenationStack
{
public:
  static vtkTransformConcatenationStack *New() {
    return new vtkTransformConcatenationStack(); };
  void Delete() { delete this; };

  // pop will pop delete 'concat', then pop the
  // top item on the stack onto 'concat'.
  void Pop(vtkTransformConcatenation **concat);

  // push will move 'concat' onto the stack, and
  // make 'concat' a copy of its previous self
  void Push(vtkTransformConcatenation **concat);

  void DeepCopy(vtkTransformConcatenationStack *stack);

protected:
  vtkTransformConcatenationStack();
  ~vtkTransformConcatenationStack();

  int StackSize;
  vtkTransformConcatenation **Stack;
  vtkTransformConcatenation **StackBottom;
};

//ETX

#endif




