// OnUMLEsoMacros.h
// Global macros and type definitions

#ifndef _ONUMLESOMACROS_H_
#define _ONUMLESOMACROS_H_


#ifndef _DESTROY_VECTOR_
#define _DESTROY_VECTOR_
#define DESTROY_VECTOR(VEC) { if (VEC) delete[] VEC; VEC = NULL; }
#endif

#ifndef _DESTROY_BSTR_ARRAY_
#define _DESTROY_BSTR_ARRAY_
#define DESTROY_BSTR_ARRAY(BSTR_ARRAY, SIZE) \
if (BSTR_ARRAY) \
{ \
  for (long i = 0; i < SIZE; i++) if (BSTR_ARRAY[i]) ::SysFreeString(BSTR_ARRAY[i]); \
  DESTROY_VECTOR(BSTR_ARRAY) \
}
#endif

#ifndef _DESTROY_MEMBER_
#define _DESTROY_MEMBER_
#define DESTROY_MEMBER(OBJ) { if (OBJ) delete OBJ; OBJ = NULL; }
#endif


#ifndef _DESTROY_MATRIX_
#define _DESTROY_MATRIX_
#define DESTROY_MATRIX(MAT, NROWS) \
{ \
  long i; \
  if (MAT) \
  { \
    for (i = 0; i < NROWS; i++) DESTROY_VECTOR(MAT[i]) \
    DESTROY_VECTOR(MAT) \
  } \
}
#endif

#ifndef _FILE_IO_MACROS_
#define _FILE_IO_MACROS_
#define WRITE_SCALAR( VAL ) fwrite( (void*) &VAL, sizeof( VAL ), 1, fs );
#define WRITE_VECTOR( VEC, TYPE, COUNT ) fwrite ( (void*) &COUNT, sizeof( long ), 1, fs ); fwrite( (void*) VEC, sizeof( TYPE ), COUNT, fs );
#define READ_SCALAR( VAL ) fread( (void*) &VAL, sizeof( VAL ), 1, fs );
#define READ_VECTOR( VEC, TYPE, COUNT ) fread ( (void*) &COUNT, sizeof( long ), 1, fs ); fread( (void*) VEC, sizeof( TYPE ), COUNT, fs );
#endif // _FILE_IO_MACROS_


#endif // _ONUMLESOMACROS_H_