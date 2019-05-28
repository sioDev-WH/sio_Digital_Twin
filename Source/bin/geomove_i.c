/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Oct 19 15:13:00 2001
 */
/* Compiler settings for C:\DistComponents\Geomov\geomove.idl:
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

const IID IID_IGeoObject = {0x4942183F,0xC793,0x11D3,{0x83,0xDD,0x00,0xC0,0x93,0x02,0x2C,0xC1}};


const IID IID_IModel = {0xA49A1201,0xC930,0x11D3,{0x83,0xDF,0x00,0xC0,0x93,0x02,0x2C,0xC1}};


const IID IID_DIModel = {0x8E0C8539,0x576C,0x4060,{0xB5,0x36,0x6B,0x75,0x81,0xE1,0x4E,0x46}};


const IID LIBID_GEOMOVELib = {0x49421831,0xC793,0x11D3,{0x83,0xDD,0x00,0xC0,0x93,0x02,0x2C,0xC1}};


const CLSID CLSID_GeoObject = {0x49421840,0xC793,0x11D3,{0x83,0xDD,0x00,0xC0,0x93,0x02,0x2C,0xC1}};


#ifdef __cplusplus
}
#endif

