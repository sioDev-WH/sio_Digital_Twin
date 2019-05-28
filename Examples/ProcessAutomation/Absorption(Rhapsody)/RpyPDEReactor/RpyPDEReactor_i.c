/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 17 11:06:46 2002
 */
/* Compiler settings for C:\Rhapsody40\PDEReactor\RpyPDEReactor\RpyPDEReactor.idl:
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

const IID IID_IRpyPDEReactorTest = {0x225F917C,0xE26F,0x4E35,{0xB5,0xDB,0xC6,0xEA,0x50,0x1C,0x55,0x1C}};


const IID LIBID_RPYPDEREACTORLib = {0x50A4441F,0x8E87,0x4E5E,{0xAA,0x02,0x68,0x3A,0x12,0xA1,0xDD,0xCA}};


const CLSID CLSID_RpyPDEReactorTest = {0x162A3AE1,0x0CAE,0x4DA1,{0x96,0x75,0x74,0xC9,0x8A,0xC7,0x94,0x0D}};


#ifdef __cplusplus
}
#endif

