/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jun 10 22:33:23 2003
 */
/* Compiler settings for C:\DistComponents\ShiftLogic\ShiftLogicDialogs\ShiftLogicDialogs.idl:
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

const IID LIBID_SHIFTLOGICDIALOGSLib = {0x2C49A668,0x4B60,0x4287,{0x91,0x4A,0x50,0x18,0xFE,0xC8,0xBA,0xE5}};


#ifdef __cplusplus
}
#endif

