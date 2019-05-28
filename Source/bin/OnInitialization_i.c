/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Aug 02 23:24:23 2003
 */
/* Compiler settings for C:\DistComponents\idl\OnInitialization.IDL:
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

const IID LIBID_OnInitialization = {0x0AD9F58C,0xD5A4,0x489E,{0x8C,0x61,0x92,0xDB,0x65,0xAB,0x82,0x48}};


const IID IID__ctlInitialization = {0xED7DF5FA,0x20BE,0x45C3,{0xB1,0x01,0x6A,0x4B,0x53,0xC2,0xB2,0xFE}};


const IID IID__clsVar = {0x4C9143EA,0x7080,0x4BC1,{0x84,0xF6,0x50,0x93,0x54,0x35,0xE0,0xA7}};


const IID IID__clsCVar = {0x53163479,0x35EC,0x4972,{0xB4,0x81,0xFA,0xA0,0xF5,0x3B,0xCC,0x89}};


const IID IID__clsVarManager = {0xDECA34C4,0x1F6B,0x4DF0,{0x8F,0x19,0x35,0x33,0xDC,0x83,0xB0,0xDB}};


const IID IID__ctlEquationEditor = {0x4ACDF901,0x8C5E,0x4F8B,{0x8F,0xFD,0xAF,0xDF,0x55,0x09,0xC4,0x5D}};


const IID IID__ctlMessageWindow = {0xC9A0A35F,0x4543,0x433B,{0x9F,0xD2,0xEE,0x99,0xD9,0x85,0xAE,0xA3}};


const IID IID__OnScriptParser = {0x388305A9,0xA31C,0x4D2E,{0xBA,0xC8,0x52,0xD6,0xAF,0x9F,0x9D,0x26}};


const IID DIID___ctlInitialization = {0x64970E55,0x6C10,0x4F33,{0x90,0xE9,0x62,0xEF,0xC3,0x1E,0x3C,0x07}};


const IID DIID___ctlEquationEditor = {0x0ECAEA74,0x52A4,0x4A81,{0x95,0x57,0x60,0x1E,0xD4,0x11,0x2F,0xFB}};


const IID DIID___ctlMessageWindow = {0x7785B142,0xE38D,0x4A67,{0x9E,0xDD,0x5B,0x25,0x43,0x9F,0x09,0xDE}};


const IID DIID___OnScriptParser = {0xF2D89834,0xD2C8,0x47AA,{0x89,0x3F,0xC1,0x9C,0x01,0xAF,0xD0,0x0B}};


const CLSID CLSID_ctlInitialization = {0xD16FD96C,0xE4D6,0x46B6,{0xAC,0x9E,0xBD,0x2C,0xE0,0xBE,0x9F,0x2E}};


const CLSID CLSID_clsVar = {0x0897D1F1,0x6FC5,0x4649,{0x98,0x54,0xAF,0x14,0x8E,0xD6,0x00,0x49}};


const CLSID CLSID_clsCVar = {0x47A4423A,0x34A8,0x4DE5,{0xAB,0x74,0x39,0x48,0xB3,0xF7,0xAA,0x2A}};


const CLSID CLSID_clsVarManager = {0xF469F156,0x6AC1,0x4063,{0xA5,0x34,0xE0,0x54,0xBF,0x7B,0x8A,0x86}};


const CLSID CLSID_ctlEquationEditor = {0xF16D8DA2,0xA244,0x4F7A,{0x9E,0x2C,0xAB,0xF5,0xC1,0xAB,0x12,0x6A}};


const CLSID CLSID_ctlMessageWindow = {0xFDC0FDCE,0xFD09,0x42D9,{0xA6,0x67,0x0B,0xE7,0xA7,0x55,0x91,0xD0}};


const CLSID CLSID_OnScriptParser = {0xFBE4C91A,0x6686,0x4133,{0xBB,0x27,0x99,0x56,0x85,0x7B,0x6C,0x99}};


#ifdef __cplusplus
}
#endif

