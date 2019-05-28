
/* what toolkits was VTK built with */
#define VTK_USE_HYBRID
#define VTK_USE_PARALLEL
#undef VTK_USE_PATENTED
#define VTK_USE_RENDERING
#undef VTK_USE_VOLUMEPRO
#undef VTK_HAVE_VG500
#undef VTK_HAVE_VP1000

/* what rendering libraries to use */
#define OPENGL_LIBRARY
#ifdef OPENGL_LIBRARY
 #ifndef _WIN32
   #define VTK_USE_OGLR 
 #endif
#endif

#undef VTK_OPENGL_HAS_OSMESA

#undef VTK_MANGLE_MESA 
#ifdef VTK_MANGLE_MESA
 #ifndef _WIN32
   #define VTK_USE_OGLR 
 #endif
#endif

#undef VTK_USE_QUARTZ
#ifdef VTK_USE_QUARTZ
 #undef VTK_USE_OGLR
#endif

/* use MPI */
#undef VTK_USE_MPI

/* java awt support */
#define JAVA_AWT_INCLUDE_PATH
#ifdef JAVA_AWT_INCLUDE_PATH
  #define VTK_USE_JAWT 
#endif

/* debug leaks */
#undef VTK_DEBUG_LEAKS
