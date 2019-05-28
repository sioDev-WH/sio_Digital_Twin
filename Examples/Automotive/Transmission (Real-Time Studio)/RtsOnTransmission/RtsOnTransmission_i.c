/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 10 17:14:38 2003
 */
/* Compiler settings for C:\DistComponents\RtsOnTransmission\RtsOnTransmission.idl:
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

const IID IID_IOnChart = {0xE4814F69,0x68C9,0x49AE,{0x82,0x92,0xB6,0xA5,0xAC,0x3A,0x3B,0x43}};


const IID IID_ICOnTestHarness = {0x3669889E,0x81B0,0x4D6C,{0x92,0x30,0x10,0xFD,0x26,0x51,0x89,0xA5}};


const IID LIBID_RTSONTRANSMISSIONLib = {0x90658CC2,0xACB7,0x4219,{0xA9,0x77,0xDE,0x7A,0x31,0x04,0xF2,0x0D}};


const CLSID CLSID_OnChart = {0xA0B5F84A,0x7758,0x4EF9,{0x8B,0xE8,0x16,0xD1,0xC0,0xAB,0xFB,0x3E}};


const CLSID CLSID_COnTestHarness = {0x612AC51E,0x6CB5,0x46C3,{0xB6,0x03,0x62,0x68,0x20,0x2D,0x48,0xDC}};


#ifdef __cplusplus
}
#endif

