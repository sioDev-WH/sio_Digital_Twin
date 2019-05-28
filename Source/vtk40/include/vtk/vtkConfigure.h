/* 
 * here is where system comupted values get stored these values should only
 * change when the target compile platform changes 
 */

/* what byte order */
#undef CMAKE_WORDS_BIGENDIAN
#ifdef CMAKE_WORDS_BIGENDIAN
  #define VTK_WORDS_BIGENDIAN 
#endif

/* what threading system are we using */
#undef CMAKE_USE_PTHREADS
#ifdef CMAKE_USE_PTHREADS
#define VTK_USE_PTHREADS
#endif

#undef CMAKE_USE_SPROC
#ifdef CMAKE_USE_SPROC
#define VTK_USE_SPROC
#endif

#undef CMAKE_HP_PTHREADS
#ifdef CMAKE_HP_PTHREADS
#define VTK_HP_PTHREADS
#endif

#define CMAKE_USE_WIN32_THREADS
#ifdef CMAKE_USE_WIN32_THREADS
#define VTK_USE_WIN32_THREADS
#endif

#define BUILD_SHARED_LIBS
#ifdef BUILD_SHARED_LIBS
#define VTKDLL
#else
#define VTKSTATIC
#endif

#undef VTK_USE_64BIT_IDS

#undef VTK_USE_ANSI_STDLIB

/* compiler used */
#define VTK_CXX_COMPILER "VC++60"
