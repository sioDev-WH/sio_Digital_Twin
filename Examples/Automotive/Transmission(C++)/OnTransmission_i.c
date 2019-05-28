/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Aug 31 13:37:45 2001
 */
/* Compiler settings for C:\DistComponents\OnTransmission\OnTransmission.idl:
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

const IID IID_IOnTransModelFactory = {0xC632D18B,0x80C1,0x49A2,{0xA8,0xE4,0x86,0x76,0x2B,0x65,0x4A,0x13}};


const IID IID_ICBroadcastTest = {0x0B55BCFE,0xDD2D,0x46E0,{0xA6,0x24,0x3C,0xAA,0x4F,0x1D,0x40,0xBC}};


const IID LIBID_ONTRANSMISSIONLib = {0xFB938A98,0x05B5,0x48AE,{0xA8,0xC0,0x07,0xAA,0xA6,0xFC,0xF8,0x8B}};


const CLSID CLSID_OnTransModelFactory = {0x881EE912,0x657D,0x4CFA,{0xB9,0x27,0xC6,0x45,0x81,0xCD,0xE6,0x6F}};


const CLSID CLSID_CBroadcastTest = {0x67532C3D,0xF849,0x4AC7,{0xA1,0xA1,0x06,0x7F,0x3E,0x90,0xCB,0x67}};


#ifdef __cplusplus
}
#endif

