
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ONINTERVAL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ONINTERVAL_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef ONINTERVAL_EXPORTS
#define ONINTERVAL_API __declspec(dllexport)
#else
#define ONINTERVAL_API __declspec(dllimport)
#endif

/*
// This class is exported from the ONInterval.dll
class ONINTERVAL_API CONInterval {
public:
	CONInterval(void);
	// TODO: add your methods here.
};

extern ONINTERVAL_API int nONInterval;

ONINTERVAL_API int fnONInterval(void);
*/
