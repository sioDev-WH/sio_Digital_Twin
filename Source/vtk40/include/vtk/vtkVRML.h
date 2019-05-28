/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkVRML.h,v $
  Language:  C++
  Date:      $Date: 2001/12/04 21:24:45 $
  Version:   $Revision: 1.18 $
  Thanks:    Tom Citriniti who implemented and contributed this class


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
/* ======================================================================
 
   Importer based on BNF Yacc and Lex parser definition from:

    **************************************************
        * VRML 2.0 Parser
        * Copyright (C) 1996 Silicon Graphics, Inc.
        *
        * Author(s) :    Gavin Bell
        *                Daniel Woods (first port)
        **************************************************

  Ported to VTK By:     Thomas D. Citriniti
                        Rensselaer Polytechnic Institute
                        citrit@rpi.edu

=======================================================================*/
#ifndef _VTKVRML_H_
#define _VTKVRML_H_

#define DEFAULTINCREMENT        100
#include <stdlib.h>

#include "vtkConfigure.h"

#ifdef VTK_USE_ANSI_STDLIB
#include <new>
#include <iostream>
#else
#include <new.h>
#include <iostream.h>
#endif

#ifdef __BORLANDC__
// seems to be missing from new.h and new for borland
void* operator new[](unsigned int,void *v)
{
  return v;
}
#endif

#include <string.h>

#include "vtkWin32Header.h"

// Use a user-managed heap to remove memory leaks
// This code must come before "#include vtkVRML.h" because
// it uses the functions below.
#include "vtkHeap.h"
struct vtkVRMLAllocator
{
  static void Initialize();
  static void *AllocateMemory(size_t n);
  static void CleanUp();
  static char* StrDup(const char *str);
  static vtkHeap *Heap;
};


  
template <class T> 
class VTK_HYBRID_EXPORT VectorType
{
protected:
  T *Data;
  int Allocated;
  int Used;
public:
  void Init()
    {
      Allocated=DEFAULTINCREMENT;
      if (!this->UseNew)
        {
        vtkVRMLAllocator::Initialize();
        void* mem = vtkVRMLAllocator::AllocateMemory(Allocated*sizeof(T));
        Data=new(mem) T[Allocated];
        }
      else
        {
        Data = new T[Allocated];
        }
      Used=0;
    }
  VectorType()
    { 
      this->UseNew = 0;
      this->Init();
    }
  VectorType(int usenew) : UseNew(usenew)
    { 
      this->Init();
    }
  ~VectorType(void)
    {
      if (this->UseNew)
        {
        delete[] Data;
        }
    }
  void Reserve(int newSize)
    {
      T *temp;
      int oldSize;
      if(newSize >= Allocated)
        {
        oldSize=Allocated;
        Allocated=newSize+DEFAULTINCREMENT;
        temp=Data;
        if (!this->UseNew)
          {
          void* mem = vtkVRMLAllocator::AllocateMemory(Allocated*sizeof(T));
          Data=new(mem) T[Allocated];
          }
        else
          {
          Data=new T[Allocated];
          }
        if(Data==(T *)'\0')
          {
          return;
          }
        memcpy((void*)Data, (void*)temp, oldSize*sizeof(T));
        if (this->UseNew)
          {
          delete[] temp;
          }
        }
    }
  
  void Demand(int newSize)
    {
      Reserve(newSize);
      Used=newSize;
    }
  int Count(void) const
    {
      return Used;
    }
  T& Get(int index) const
    {
      if (index > Used)
        return Data[Used-1];
      return Data[index];
    }
  T& operator[](int index)
    {
      if (index > Used)
        Demand(index);
      return Data[index];
    }
  operator T*() const
    {
      return Data;
    }
  VectorType<T>& operator+=(T datum)
    {
      Reserve(Used+1);
      Data[Used]=datum;
      Used++;
      return *this;
    }
  void Push(T datum)
    {
      Reserve(Used+1);
      Data[Used]=datum;
      Used++;
    }
  T& Pop()
    {
      Used--;
      return Data[Used];
    }
  T& Top()
    {
      return Data[Used-1];
    }

  void* operator new(size_t n)
    {
      return vtkVRMLAllocator::AllocateMemory(n);
    }

  void operator delete(void *)
    {
    }

  int UseNew;
};

static const char standardNodes[][2042] = {
  "#VRML V2.0 utf8 \n\
# \n\
# ************************************************** \n\
# * VRML 2.0 Parser \n\
# * Copyright (C) 1996 Silicon Graphics, Inc. \n\
# * \n\
# * Author(s)    : Gavin Bell \n\
# *                Daniel Woods (first port) \n\
# ************************************************** \n\
# \n\
# Definitions for all of the nodes built-in to the spec. \n\
# Taken almost directly from the VRML 2.0 final spec: \n\
 \n\
PROTO Anchor [ \n\
  eventIn      MFNode   addChildren \n\
  eventIn      MFNode   removeChildren \n\
  exposedField MFNode   children        [] \n\
  exposedField SFString description     \"\"  \n\
  exposedField MFString parameter       [] \n\
  exposedField MFString url             [] \n\
  field        SFVec3f  bboxCenter      0.0 0.0 0.0 \n\
  field        SFVec3f  bboxSize        -1.0 -1.0 -1.0 \n\
] { } \n\
 \n\
PROTO Appearance [ \n\
  exposedField SFNode material          NULL \n\
  exposedField SFNode texture           NULL \n\
  exposedField SFNode textureTransform  NULL \n\
] { } \n\
 \n\
PROTO AudioClip [ \n\
  exposedField   SFString description  \"\" \n\
  exposedField   SFBool   loop         FALSE \n\
  exposedField   SFFloat  pitch        1.0 \n\
  exposedField   SFTime   startTime    0 \n\
  exposedField   SFTime   stopTime     0 \n\
  exposedField   MFString url          [] \n\
  eventOut       SFTime   duration_changed \n\
  eventOut       SFBool   isActive \n\
] { } \n\
 \n\
PROTO Background [ \n\
  eventIn      SFBool   set_bind \n\
  exposedField MFFloat  groundAngle  [] \n\
  exposedField MFColor  groundColor  [] \n\
  exposedField MFString backUrl      [] \n\
  exposedField MFString bottomUrl    [] \n\
  exposedField MFString frontUrl     [] \n\
  exposedField MFString leftUrl      [] \n\
  exposedField MFString rightUrl     [] \n\
  exposedField MFString topUrl       [] \n\
  exposedField MFFloat  skyAngle     [] \n\
  exposedField MFColor  skyColor     [ 0 0 0  ] \n\
  eventOut     SFBool   isBound \n\
] { }",
  "PROTO Billboard [ \n\
  eventIn      MFNode   addChildren \n\
  eventIn      MFNode   removeChildren \n\
  exposedField SFVec3f  axisOfRotation  0 1 0 \n\
  exposedField MFNode   children        [] \n\
  field        SFVec3f  bboxCenter      0 0 0 \n\
  field        SFVec3f  bboxSize        -1 -1 -1 \n\
] { } \n\
 \n\
PROTO Box [ \n\
  field    SFVec3f size  2 2 2  \n\
] { } \n\
 \n\
PROTO Collision [  \n\
  eventIn      MFNode   addChildren \n\
  eventIn      MFNode   removeChildren \n\
  exposedField MFNode   children        [] \n\
  exposedField SFBool   collide         TRUE \n\
  field        SFVec3f  bboxCenter      0 0 0 \n\
  field        SFVec3f  bboxSize        -1 -1 -1 \n\
  field        SFNode   proxy           NULL \n\
  eventOut     SFTime   collideTime \n\
] { } \n\
 \n\
PROTO Color [ \n\
  exposedField MFColor color     [] \n\
] { } \n\
 \n\
PROTO ColorInterpolator [ \n\
  eventIn      SFFloat set_fraction \n\
  exposedField MFFloat key       [] \n\
  exposedField MFColor keyValue  [] \n\
  eventOut     SFColor value_changed \n\
] { } \n\
 \n\
PROTO Cone [ \n\
  field     SFFloat   bottomRadius 1 \n\
  field     SFFloat   height       2 \n\
  field     SFBool    side         TRUE \n\
  field     SFBool    bottom       TRUE \n\
] { } \n\
 \n\
PROTO Coordinate [ \n\
  exposedField MFVec3f point  [] \n\
] { } \n\
 \n\
PROTO CoordinateInterpolator [ \n\
  eventIn      SFFloat set_fraction \n\
  exposedField MFFloat key       [] \n\
  exposedField MFVec3f keyValue  [] \n\
  eventOut     MFVec3f value_changed \n\
] { } \n\
 \n\
PROTO Cylinder [ \n\
  field    SFBool    bottom  TRUE \n\
  field    SFFloat   height  2 \n\
  field    SFFloat   radius  1 \n\
  field    SFBool    side    TRUE \n\
  field    SFBool    top     TRUE \n\
] { } \n\
 \n\
PROTO CylinderSensor [ \n\
  exposedField SFBool     autoOffset TRUE \n\
  exposedField SFFloat    diskAngle  0.262 \n\
  exposedField SFBool     enabled    TRUE \n\
  exposedField SFFloat    maxAngle   -1 \n\
  exposedField SFFloat    minAngle   0 \n\
  exposedField SFFloat    offset     0 \n\
  eventOut     SFBool     isActive \n\
  eventOut     SFRotation rotation_changed \n\
  eventOut     SFVec3f    trackPoint_changed \n\
] { }",
  "PROTO DirectionalLight [ \n\
  exposedField SFFloat ambientIntensity  0  \n\
  exposedField SFColor color             1 1 1 \n\
  exposedField SFVec3f direction         0 0 -1 \n\
  exposedField SFFloat intensity         1  \n\
  exposedField SFBool  on                TRUE  \n\
] { } \n\
 \n\
PROTO ElevationGrid [ \n\
  eventIn      MFFloat  set_height \n\
  exposedField SFNode   color             NULL \n\
  exposedField SFNode   normal            NULL \n\
  exposedField SFNode   texCoord          NULL \n\
  field        SFBool   ccw               TRUE \n\
  field        SFBool   colorPerVertex    TRUE \n\
  field        SFFloat  creaseAngle       0 \n\
  field        MFFloat  height            [] \n\
  field        SFBool   normalPerVertex   TRUE \n\
  field        SFBool   solid             TRUE \n\
  field        SFInt32  xDimension        0 \n\
  field        SFFloat  xSpacing          0.0 \n\
  field        SFInt32  zDimension        0 \n\
  field        SFFloat  zSpacing          0.0 \n\
 \n\
] { } \n\
 \n\
PROTO Extrusion [ \n\
  eventIn MFVec2f    set_crossSection \n\
  eventIn MFRotation set_orientation \n\
  eventIn MFVec2f    set_scale \n\
  eventIn MFVec3f    set_spine \n\
  field   SFBool     beginCap         TRUE \n\
  field   SFBool     ccw              TRUE \n\
  field   SFBool     convex           TRUE \n\
  field   SFFloat    creaseAngle      0 \n\
  field   MFVec2f    crossSection     [ 1 1, 1 -1, -1 -1, -1 1, 1 1 ] \n\
  field   SFBool     endCap           TRUE \n\
  field   MFRotation orientation      0 0 1 0 \n\
  field   MFVec2f    scale            1 1 \n\
  field   SFBool     solid            TRUE \n\
  field   MFVec3f    spine            [ 0 0 0, 0 1 0 ] \n\
] { } \n\
 \n\
PROTO Fog [ \n\
  exposedField SFColor  color            1 1 1 \n\
  exposedField SFString fogType          \"LINEAR\" \n\
  exposedField SFFloat  visibilityRange  0 \n\
  eventIn      SFBool   set_bind \n\
  eventOut     SFBool   isBound \n\
] { }",
  "PROTO FontStyle [ \n\
  field SFString family     \"SERIF\" \n\
  field SFBool   horizontal  TRUE \n\
  field MFString justify     \"BEGIN\" \n\
  field SFString language    \"\" \n\
  field SFBool   leftToRight TRUE \n\
  field SFFloat  size       1.0 \n\
  field SFFloat  spacing     1.0 \n\
  field SFString style       \"PLAIN\" \n\
  field SFBool   topToBottom TRUE \n\
] { } \n\
 \n\
PROTO Group [ \n\
  eventIn      MFNode  addChildren \n\
  eventIn      MFNode  removeChildren \n\
  exposedField MFNode  children   [] \n\
  field        SFVec3f bboxCenter 0 0 0 \n\
  field        SFVec3f bboxSize   -1 -1 -1 \n\
] { } \n\
 \n\
PROTO ImageTexture [ \n\
  exposedField MFString url     [] \n\
  field        SFBool   repeatS TRUE \n\
  field        SFBool   repeatT TRUE \n\
] { } \n\
 \n\
PROTO IndexedFaceSet [  \n\
  eventIn       MFInt32 set_colorIndex \n\
  eventIn       MFInt32 set_coordIndex \n\
  eventIn       MFInt32 set_normalIndex \n\
  eventIn       MFInt32 set_texCoordIndex \n\
  exposedField  SFNode  color             NULL \n\
  exposedField  SFNode  coord             NULL \n\
  exposedField  SFNode  normal            NULL \n\
  exposedField  SFNode  texCoord          NULL \n\
  field         SFBool  ccw               TRUE \n\
  field         MFInt32 colorIndex        [] \n\
  field         SFBool  colorPerVertex    TRUE \n\
  field         SFBool  convex            TRUE \n\
  field         MFInt32 coordIndex        [] \n\
  field         SFFloat creaseAngle       0 \n\
  field         MFInt32 normalIndex       [] \n\
  field         SFBool  normalPerVertex   TRUE \n\
  field         SFBool  solid             TRUE \n\
  field         MFInt32 texCoordIndex     [] \n\
] { } \n\
 \n\
PROTO IndexedLineSet [ \n\
  eventIn       MFInt32 set_colorIndex \n\
  eventIn       MFInt32 set_coordIndex \n\
  exposedField  SFNode  color             NULL \n\
  exposedField  SFNode  coord             NULL \n\
  field         MFInt32 colorIndex        [] \n\
  field         SFBool  colorPerVertex    TRUE \n\
  field         MFInt32 coordIndex        [] \n\
] { }",
  "PROTO Inline [ \n\
  exposedField MFString url        [] \n\
  field        SFVec3f  bboxCenter 0 0 0 \n\
  field        SFVec3f  bboxSize   -1 -1 -1 \n\
] { } \n\
PROTO LOD [ \n\
  exposedField MFNode  level    []  \n\
  field        SFVec3f center   0 0 0 \n\
  field        MFFloat range    []  \n\
] { } \n\
 \n\
PROTO Material [ \n\
  exposedField SFFloat ambientIntensity  0.2 \n\
  exposedField SFColor diffuseColor      0.8 0.8 0.8 \n\
  exposedField SFColor emissiveColor     0 0 0 \n\
  exposedField SFFloat shininess         0.2 \n\
  exposedField SFColor specularColor     0 0 0 \n\
  exposedField SFFloat transparency      0 \n\
] { } \n\
 \n\
PROTO MovieTexture [ \n\
  exposedField SFBool   loop       FALSE \n\
  exposedField SFFloat  speed      1 \n\
  exposedField SFTime   startTime  0 \n\
  exposedField SFTime   stopTime   0 \n\
  exposedField MFString url       [] \n\
  field        SFBool   repeatS    TRUE \n\
  field        SFBool   repeatT    TRUE \n\
  eventOut     SFFloat  duration_changed \n\
  eventOut     SFBool   isActive \n\
] { } \n\
 \n\
PROTO NavigationInfo [ \n\
  eventIn      SFBool   set_bind \n\
  exposedField MFFloat  avatarSize       [ 0.25, 1.6, 0.75 ] \n\
  exposedField SFBool   headlight        TRUE \n\
  exposedField SFFloat  speed            1.0  \n\
  exposedField MFString type             \"WALK\"  \n\
  exposedField SFFloat  visibilityLimit  0.0  \n\
  eventOut     SFBool   isBound \n\
] { } \n\
 \n\
PROTO Normal [ \n\
  exposedField MFVec3f vector [] \n\
] { } \n\
 \n\
PROTO NormalInterpolator [ \n\
  eventIn      SFFloat set_fraction \n\
  exposedField MFFloat key       [] \n\
  exposedField MFVec3f keyValue  [] \n\
  eventOut     MFVec3f value_changed \n\
] { } \n\
 \n\
PROTO OrientationInterpolator [ \n\
  eventIn      SFFloat    set_fraction \n\
  exposedField MFFloat    key       [] \n\
  exposedField MFRotation keyValue  [] \n\
  eventOut     SFRotation value_changed \n\
] { } \n\
 \n\
PROTO PixelTexture [ \n\
  exposedField SFImage  image      0 0 0 \n\
  field        SFBool   repeatS    TRUE \n\
  field        SFBool   repeatT    TRUE \n\
] { }",
  "PROTO PlaneSensor [ \n\
  exposedField SFBool  autoOffset  TRUE \n\
  exposedField SFBool  enabled     TRUE \n\
  exposedField SFVec2f maxPosition -1 -1 \n\
  exposedField SFVec2f minPosition 0 0 \n\
  exposedField SFVec3f offset      0 0 0 \n\
  eventOut     SFBool  isActive \n\
  eventOut     SFVec3f trackPoint_changed \n\
  eventOut     SFVec3f translation_changed \n\
] { } \n\
 \n\
PROTO PointLight [ \n\
  exposedField SFFloat ambientIntensity  0  \n\
  exposedField SFVec3f attenuation       1 0 0 \n\
  exposedField SFColor color             1 1 1  \n\
  exposedField SFFloat intensity         1 \n\
  exposedField SFVec3f location          0 0 0 \n\
  exposedField SFBool  on                TRUE  \n\
  exposedField SFFloat radius            100 \n\
] { } \n\
 \n\
PROTO PointSet [ \n\
  exposedField  SFNode  color      NULL \n\
  exposedField  SFNode  coord      NULL \n\
] { } \n\
 \n\
PROTO PositionInterpolator [ \n\
  eventIn      SFFloat set_fraction \n\
  exposedField MFFloat key       [] \n\
  exposedField MFVec3f keyValue  [] \n\
  eventOut     SFVec3f value_changed \n\
] { } \n\
 \n\
PROTO ProximitySensor [ \n\
  exposedField SFVec3f    center      0 0 0 \n\
  exposedField SFVec3f    size        0 0 0 \n\
  exposedField SFBool     enabled     TRUE \n\
  eventOut     SFBool     isActive \n\
  eventOut     SFVec3f    position_changed \n\
  eventOut     SFRotation orientation_changed \n\
  eventOut     SFTime     enterTime \n\
  eventOut     SFTime     exitTime \n\
] { }",
  "PROTO ScalarInterpolator [ \n\
  eventIn      SFFloat set_fraction \n\
  exposedField MFFloat key       [] \n\
  exposedField MFFloat keyValue  [] \n\
  eventOut     SFFloat value_changed \n\
] { } \n\
 \n\
PROTO Script [ \n\
  exposedField MFString url           [ ]  \n\
  field        SFBool   directOutput  FALSE \n\
  field        SFBool   mustEvaluate  FALSE \n\
] { } \n\
 \n\
PROTO Shape [ \n\
  field SFNode appearance NULL \n\
  field SFNode geometry   NULL \n\
] { } \n\
 \n\
PROTO Sound [ \n\
  exposedField SFVec3f  direction     0 0 1 \n\
  exposedField SFFloat  intensity     1 \n\
  exposedField SFVec3f  location      0 0 0 \n\
  exposedField SFFloat  maxBack       10 \n\
  exposedField SFFloat  maxFront      10 \n\
  exposedField SFFloat  minBack       1 \n\
  exposedField SFFloat  minFront      1 \n\
  exposedField SFFloat  priority      0 \n\
  exposedField SFNode   source        NULL \n\
  field        SFBool   spatialize    TRUE \n\
] { } \n\
 \n\
PROTO Sphere [ \n\
  field SFFloat radius  1 \n\
] { } \n\
 \n\
PROTO SphereSensor [ \n\
  exposedField SFBool     autoOffset TRUE \n\
  exposedField SFBool     enabled    TRUE \n\
  exposedField SFRotation offset     0 1 0 0 \n\
  eventOut     SFBool     isActive \n\
  eventOut     SFRotation rotation_changed \n\
  eventOut     SFVec3f    trackPoint_changed \n\
] { } \n\
 \n\
PROTO SpotLight [ \n\
  exposedField SFFloat ambientIntensity  0  \n\
  exposedField SFVec3f attenuation       1 0 0 \n\
  exposedField SFFloat beamWidth         1.570796 \n\
  exposedField SFColor color             1 1 1  \n\
  exposedField SFFloat cutOffAngle       0.785398  \n\
  exposedField SFVec3f direction         0 0 -1 \n\
  exposedField SFFloat intensity         1   \n\
  exposedField SFVec3f location          0 0 0   \n\
  exposedField SFBool  on                TRUE \n\
  exposedField SFFloat radius            100 \n\
] { } \n\
 \n\
PROTO Switch [ \n\
  exposedField    MFNode  choice      [] \n\
  exposedField    SFInt32 whichChoice -1 \n\
] { } \n\
 \n\
PROTO Text [ \n\
  exposedField  MFString string    [] \n\
  field         SFNode   fontStyle NULL \n\
  field         MFFloat  length    [] \n\
  field         SFFloat  maxExtent 0.0 \n\
] { }",
  "PROTO TextureCoordinate [ \n\
  exposedField MFVec2f point [] \n\
] { } \n\
PROTO TextureTransform [ \n\
  exposedField SFVec2f center      0 0 \n\
  exposedField SFFloat rotation    0 \n\
  exposedField SFVec2f scale       1 1 \n\
  exposedField SFVec2f translation 0 0 \n\
] { } \n\
 \n\
PROTO TimeSensor [ \n\
  exposedField SFTime   cycleInterval 1 \n\
  exposedField SFBool   enabled       TRUE \n\
  exposedField SFBool   loop          FALSE \n\
  exposedField SFTime   startTime     0 \n\
  exposedField SFTime   stopTime      0 \n\
  eventOut     SFTime   cycleTime \n\
  eventOut     SFFloat  fraction_changed \n\
  eventOut     SFBool   isActive \n\
  eventOut     SFTime   time \n\
] { } \n\
 \n\
PROTO TouchSensor [ \n\
  exposedField SFBool  enabled TRUE \n\
  eventOut     SFVec3f hitNormal_changed \n\
  eventOut     SFVec3f hitPoint_changed \n\
  eventOut     SFVec2f hitTexCoord_changed \n\
  eventOut     SFBool  isActive \n\
  eventOut     SFBool  isOver \n\
  eventOut     SFTime  touchTime \n\
] { } \n\
 \n\
PROTO Transform [ \n\
  eventIn      MFNode      addChildren \n\
  eventIn      MFNode      removeChildren \n\
  exposedField SFVec3f     center           0 0 0 \n\
  exposedField MFNode      children         [] \n\
  exposedField SFRotation  rotation         0 0 1  0 \n\
  exposedField SFVec3f     scale            1 1 1 \n\
  exposedField SFRotation  scaleOrientation 0 0 1  0 \n\
  exposedField SFVec3f     translation      0 0 0 \n\
  field        SFVec3f     bboxCenter       0 0 0 \n\
  field        SFVec3f     bboxSize         -1 -1 -1 \n\
] { } \n\
 \n\
PROTO Viewpoint [ \n\
  eventIn      SFBool     set_bind \n\
  exposedField SFFloat    fieldOfView    0.785398 \n\
  exposedField SFBool     jump           TRUE \n\
  exposedField SFRotation orientation    0 0 1  0 \n\
  exposedField SFVec3f    position       0 0 10 \n\
  field        SFString   description    \"\" \n\
  eventOut     SFTime     bindTime \n\
  eventOut     SFBool     isBound \n\
] { }",
  "PROTO VisibilitySensor [ \n\
  exposedField SFVec3f center   0 0 0 \n\
  exposedField SFBool  enabled  TRUE \n\
  exposedField SFVec3f size     0 0 0 \n\
  eventOut     SFTime  enterTime \n\
  eventOut     SFTime  exitTime \n\
  eventOut     SFBool  isActive \n\
] { } \n\
 \n\
PROTO WorldInfo [ \n\
  field MFString info  [] \n\
  field SFString title \"\" \n\
] { }",""
};
#endif 