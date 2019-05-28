/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jan 20 19:50:05 2003
 */
/* Compiler settings for C:\Rhapsody40\Reactor\RpyReactor\RpyReactor.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IRpyReactorTestHarness = {0xE36160FD,0xAA21,0x4318,{0xA4,0x52,0x15,0xFF,0x51,0x8B,0x5A,0x07}};


const IID LIBID_RPYREACTORLib = {0x7D17EB5E,0x6EA4,0x40A1,{0xB3,0xF3,0x98,0x52,0x83,0xEA,0xA5,0xA3}};


const CLSID CLSID_RpyReactorTestHarness = {0x774DFAF5,0xDEA7,0x4BB8,{0xB6,0x7D,0xBD,0x14,0x88,0x9E,0xA4,0x94}};


#ifdef __cplusplus
}
#endif

