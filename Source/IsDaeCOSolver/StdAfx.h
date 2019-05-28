// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__77CBD75A_8006_11D4_98A7_00C04F6801A9__INCLUDED_)
#define AFX_STDAFX_H__77CBD75A_8006_11D4_98A7_00C04F6801A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

// the following 3 includes are for memory leak debugging
#define _CRTDBG_MAP_ALLOC

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>


// comparison macros
// TODO: determine what to do with the following static declarations
static long longArg1,longArg2;
static double dblArg1,dblArg2;
static long intArg1,intArg2;
#define DMAX(a,b) (dblArg1=(a),dblArg2=(b),(dblArg1) > (dblArg2) ?  (dblArg1) : (dblArg2))
#define DMIN(a,b) (dblArg1=(a),dblArg2=(b),(dblArg1) < (dblArg2) ?  (dblArg1) : (dblArg2))
#define LMAX(a,b) (longArg1=(a),longArg2=(b),(longArg1) > (longArg2) ?  (longArg1) : (longArg2))
#define LMIN(a,b) (longArg1=(a),longArg2=(b),(longArg1) < (longArg2) ?  (longArg1) : (longArg2))
#define IMAX(a,b) (intArg1=(a),intArg2=(b),(intArg1) > (intArg2) ?  (intArg1) : (intArg2))
#define IMIN(a,b) (intArg1=(a),intArg2=(b),(intArg1) < (intArg2) ?  (intArg1) : (intArg2))

#define SWAP(a,b) {dum=(a);(a)=(b);(b)=dum;}
#define TINY 1.0e-20
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))

//#import	 "..\StateMachine\StateMachine.tlb" no_namespace raw_interfaces_only

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__77CBD75A_8006_11D4_98A7_00C04F6801A9__INCLUDED)
