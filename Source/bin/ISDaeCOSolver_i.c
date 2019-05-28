/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Aug 02 23:24:24 2003
 */
/* Compiler settings for C:\DistComponents\idl\ISDaeCOSolver.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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

const IID IID_IIsDaeEso = {0xEFA96FD0,0xB83D,0x11d4,{0x83,0x9B,0x00,0x60,0x08,0x94,0xE8,0x02}};


const IID IID_IIsMatrix = {0x3F35CF66,0x839E,0x11D4,{0x83,0x8D,0x00,0x60,0x08,0x94,0xE8,0x02}};


const IID IID_IIsNlaSolver = {0x717E8183,0x92E1,0x11D4,{0x98,0xA8,0x00,0xC0,0x4F,0x68,0x01,0xA9}};


const IID IID_IIsNlaEso = {0xA6A32B44,0x92E2,0x11d4,{0x98,0xA8,0x00,0xC0,0x4F,0x68,0x01,0xA9}};


const IID IID_IIsDaeEsoImpl = {0xBFC328F0,0xCBF6,0x11d4,{0x83,0xA2,0x00,0x60,0x08,0x94,0xE8,0x02}};


const IID IID_IIsDaeEsoIImpl = {0x732A30A3,0xCBE5,0x11D4,{0x83,0xA2,0x00,0x60,0x08,0x94,0xE8,0x02}};


const IID IID_IIsDaeEsoCImpl = {0x43D71C20,0xE726,0x4786,{0x80,0x0E,0x15,0xC0,0x69,0x68,0xAD,0xF3}};


const IID IID_IOnModelExecEvents = {0x60453BD6,0x4CD9,0x425c,{0x86,0x8B,0xE0,0x4F,0x7D,0x4E,0x16,0xC2}};


const IID IID_IOnModelExec = {0x58CF6F05,0xD4AC,0x481E,{0xB9,0x4D,0xFA,0x4F,0x4D,0xE0,0x91,0xC7}};


const IID IID_IOnTest = {0x215F714B,0x4C21,0x476A,{0xA2,0x2E,0x72,0x5F,0x57,0x16,0x7B,0x83}};


const IID LIBID_ISDAECOSOLVERLib = {0x77CBD757,0x8006,0x11D4,{0x98,0xA7,0x00,0xC0,0x4F,0x68,0x01,0xA9}};


const IID DIID__IOnModelExecEvents = {0x77CBD767,0x8006,0x11D4,{0x98,0xA7,0x00,0xC0,0x4F,0x68,0x01,0xA9}};


const IID IID_IOnEnv = {0xBD8956DB,0xB293,0x44AB,{0x88,0xFD,0x8E,0x65,0x90,0x94,0xDD,0x86}};


const CLSID CLSID_IsMatrix = {0x3F35CF67,0x839E,0x11D4,{0x83,0x8D,0x00,0x60,0x08,0x94,0xE8,0x02}};


const CLSID CLSID_IsNlaSolver = {0x717E8184,0x92E1,0x11D4,{0x98,0xA8,0x00,0xC0,0x4F,0x68,0x01,0xA9}};


const CLSID CLSID_IsCINlaEso = {0xE3CA3C2A,0x9466,0x11D4,{0x98,0xA8,0x00,0xC0,0x4F,0x68,0x01,0xA9}};


const CLSID CLSID_IsDaeEsoIImpl = {0x732A30A4,0xCBE5,0x11D4,{0x83,0xA2,0x00,0x60,0x08,0x94,0xE8,0x02}};


const CLSID CLSID_IsDaeEsoCImpl = {0x704B0744,0xBE48,0x4E89,{0x84,0xB6,0x6A,0xC4,0x4B,0xA1,0x29,0x33}};


const CLSID CLSID_OnModelExec = {0x0BF65E89,0x4B0C,0x40E8,{0x80,0x65,0xDA,0x9E,0x82,0xEF,0x0F,0xAA}};


const CLSID CLSID_OnTest = {0x24BE2738,0xC38D,0x430E,{0xA9,0x66,0x28,0x96,0x23,0x8B,0x1D,0x0C}};


const CLSID CLSID_OnEnv = {0xF1B06AA9,0x2721,0x4516,{0x8B,0xC4,0x12,0xB5,0x6F,0x2C,0x5E,0x31}};


#ifdef __cplusplus
}
#endif
