// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__167AC996_C15D_4D19_807B_B6C896AB09A7__INCLUDED_)
#define AFX_STDAFX_H__167AC996_C15D_4D19_807B_B6C896AB09A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED


#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
// end of insertion

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#import	 "c:\distcomponents\bin\OnUMLEso.tlb" no_namespace raw_interfaces_only

#endif // !defined(AFX_STDAFX_H__167AC996_C15D_4D19_807B_B6C896AB09A7__INCLUDED_)