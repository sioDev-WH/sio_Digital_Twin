// OnDaeCOSolverMacros.h
#ifndef _ONDAECOSOLVERMACROS_H_
#define _ONDAECOSOLVERMACROS_H_

// Global Macros

#ifndef _DESTROY_VECTOR_
#define _DESTROY_VECTOR_
#define DESTROY_VECTOR(vec) { if (vec) delete[] vec; vec = NULL; }
#endif // _DESTROY_VECTOR_


// member and vector cleanup
#ifndef _DESTROY_MEMBER_
#define _DESTROY_MEMBER_
#define DESTROY_MEMBER(OBJ) { if (OBJ) delete OBJ; OBJ = NULL; }
#endif // _DESTROY_MEMBER_

#ifndef _RELEASE_MEMBER_
#define _RELEASE_MEMBER_
#define RELEASE_MEMBER(OBJ) { if (OBJ) OBJ->Release(); OBJ = NULL; }
#endif // _RELEASE_MEMBER_


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
#endif // _DESTROY_MATRIX_


#ifndef _ALLOC_SAFE_ARRAY_
#define _ALLOC_SAFE_ARRAY_
// SafeArray allocation macro
// NOTE: requires that lbound and ubound be declared in function
#define ALLOC_SAFE_ARRAY(PSA, SIZE, TYPE) \
if (PSA) \
{ \
  SafeArrayGetUBound(PSA, 1, &ubound); \
  SafeArrayGetLBound(PSA, 1, &lbound); \
  if ((ubound - lbound + 1) != SIZE) \
  { \
    SafeArrayDestroy(PSA); \
    lbound = 0; \
    ubound = SIZE - 1; \
    PSA = SafeArrayCreateVector(TYPE, 0, SIZE); \
  } \
} \
else \
{ \
  lbound = 0; \
  ubound = SIZE - 1; \
  PSA = SafeArrayCreateVector(TYPE, 0, SIZE); \
}


#ifndef _SA_DESTROY_
#define _SA_DESTROY_
#define SA_DESTROY(psa) \
if (psa) \
{ \
  SafeArrayUnaccessData(psa); \
  SafeArrayDestroy(psa); \
  psa = NULL; \
}
#endif _SA_DESTROY_


#ifndef _JAC_SOURCE_
#define _JAC_SOURCE_
typedef enum JAC_SOURCE
{
  JAC_SOURCE_NUMERIC,
  JAC_SOURCE_JACOBIAN,
  JAC_SOURCE_MASS,
};
#endif // _JAC_SOURCE_


#endif // _ALLOC_SAFE_ARRAY_


#ifndef _FILE_IO_MACROS_
#define _FILE_IO_MACROS_
#define WRITE_SCALAR( VAL ) fwrite( (void*) &VAL, sizeof( VAL ), 1, fs );
#define WRITE_VECTOR( VEC, TYPE, COUNT ) fwrite ( (void*) &COUNT, sizeof( long ), 1, fs ); fwrite( (void*) VEC, sizeof( TYPE ), COUNT, fs );
#define READ_SCALAR( VAL ) fread( (void*) &VAL, sizeof( VAL ), 1, fs );
#define READ_VECTOR( VEC, TYPE, COUNT ) fread ( (void*) &COUNT, sizeof( long ), 1, fs ); fread( (void*) VEC, sizeof( TYPE ), COUNT, fs );
#endif // _FILE_IO_MACROS_


#endif // _ONDAECOSOLVERMACROS_H_