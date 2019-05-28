// RTSONTRANSMISSIONExport.h
// provides import / export defines for exported classes

#ifndef _RTSONTRANSMISSIONEXPORT_H_
#define _RTSONTRANSMISSIONEXPORT_H_

#ifndef RTSONTRANSMISSION_API
#ifdef _RTSONTRANSMISSIONLIB_EXPORTS
#define RTSONTRANSMISSION_API __declspec(dllexport)
#else
#define RTSONTRANSMISSION_API __declspec(dllimport)
#endif
#endif // RTSONTRANSMISSION_API

#endif // _RTSONTRANSMISSIONEXPORT_H_