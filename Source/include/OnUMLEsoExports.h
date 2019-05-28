// OnUMLEsoExports.h
// import export defines for classes

#ifndef _ONUMLESOEXPORTS_H_
#define _ONUMLESOEXPORTS_H_

#ifdef _ONUMLLIB_EXPORTS
#define ONUML_API __declspec(dllexport)
#else
#define ONUML_API __declspec(dllimport)
#endif


#endif // _ONUMLESOEXPORTS_H_
