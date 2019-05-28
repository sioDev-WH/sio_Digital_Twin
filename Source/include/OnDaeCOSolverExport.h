// OnDaeCOSolverExport.h
// provides import / export defines for exported classes

#ifndef _ONDAECOSOLVEREXPORT_H_
#define _ONDAECOSOLVEREXPORT_H_

#ifndef ONDAECOSOLVER_API
#ifdef _ONDAECOSOLVERLIB_EXPORTS
#define ONDAECOSOLVER_API __declspec(dllexport)
#else
#define ONDAECOSOLVER_API __declspec(dllimport)
#endif
#endif // ONDAECOSOLVER_API

#endif // _ONDAECOSOLVEREXPORT_H_