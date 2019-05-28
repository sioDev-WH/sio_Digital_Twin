// OnShiftLogicDialogExport.h
// provides import / export defines for exported classes

#ifndef _ONSHIFTLOGICDIALOGEXPORT_H_
#define _ONSHIFTLOGICDIALOGEXPORT_H_

#ifndef ONSHIFTLOGICDIALOG_API
#ifdef _ONSHIFTLOGICDIALOGLIB_EXPORTS
#define ONSHIFTLOGICDIALOG_API __declspec(dllexport)
#else
#define ONSHIFTLOGICDIALOG_API __declspec(dllimport)
#endif
#endif // ONSHIFTLOGICDIALOG_API

#endif // _ONSHIFTLOGICDIALOGEXPORT_H_