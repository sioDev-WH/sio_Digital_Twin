// RtsOnTransmissionVB.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f RtsOnTransmissionVBps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "RtsOnTransmissionVB.h"

#include "RtsOnTransmissionVB_i.c"
#include "IsDaeCOSolver_i.c"
#include "vbActuator.h"
#include "vbBand_Brake.h"
#include "vbBrakeActuator.h"
#include "vbDamper.h"
#include "vbFrame.h"
#include "vbClutch.h"
#include "vbMass.h"
#include "vbSpring.h"
#include "vbEngine.h"
#include "vbOneway_Clutch.h"
#include "vbRavigneaux.h"
#include "vbTorque_Converter.h"
#include "vbVehicle.h"
#include "vbVehicle2.h"
#include "vbVehicle5.h"
#include "vbComposite.h"


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_vbActuator, CvbActuator)
OBJECT_ENTRY(CLSID_vbBand_Brake, CvbBand_Brake)
OBJECT_ENTRY(CLSID_vbBrakeActuator, CvbBrakeActuator)
OBJECT_ENTRY(CLSID_vbDamper, CvbDamper)
OBJECT_ENTRY(CLSID_vbFrame, CvbFrame)
OBJECT_ENTRY(CLSID_vbClutch, CvbClutch)
OBJECT_ENTRY(CLSID_vbMass, CvbMass)
OBJECT_ENTRY(CLSID_vbSpring, CvbSpring)
OBJECT_ENTRY(CLSID_vbEngine, CvbEngine)
OBJECT_ENTRY(CLSID_vbOneway_Clutch, CvbOneway_Clutch)
OBJECT_ENTRY(CLSID_vbRavigneaux, CvbRavigneaux)
OBJECT_ENTRY(CLSID_vbTorque_Converter, CvbTorque_Converter)
OBJECT_ENTRY(CLSID_vbVehicle, CvbVehicle)
OBJECT_ENTRY(CLSID_vbVehicle2, CvbVehicle2)
OBJECT_ENTRY(CLSID_vbVehicle5, CvbVehicle5)
OBJECT_ENTRY(CLSID_vbComposite, CvbComposite)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_RTSONTRANSMISSIONVBLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}


#include "vbTorque_Converter.h"
#include "vbVehicle.h"
#include "vbVehicle2.h"
#include "vbVehicle5.h"
#include "vbComposite.h"
