
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ONLR_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ONLR_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef ONLR_EXPORTS
#define ONLR_API __declspec(dllexport)
#else
#define ONLR_API __declspec(dllimport)
#endif

/*
// This class is exported from the Onlr.dll
class ONLR_API COnlr {
public:
	COnlr(void);
	// TODO: add your methods here.
};

extern ONLR_API int nOnlr;

ONLR_API int fnOnlr(void);
*/
