/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AnimationComComponent
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\MainAnimationComComponent.cpp
*********************************************************************/

#include "MainAnimationComComponent.h"
#include "theApp.h"
#include "crossProduct.h"
#include "dotProduct.h"
#include "ScheduledController_1D.h"
#include "ScheduledController_1D_Coeff.h"
#include "transformAngle_DMC2Euler.h"
#include "transformAngle_Euler2Quaternion.h"
#include "transformAngleRate.h"
#include "transformPosition_B2I.h"
#include "transformPosition_I2B.h"
#include "WindGust.h"

//----------------------------------------------------------------------------
// MainAnimationComComponent.cpp                                                                  
//----------------------------------------------------------------------------
static const GUID COMPAPPID = { 0xd26546d3, 0x231e, 0x11d7, { 0xb3, 0x34, 0x0, 0xc0, 0x4f, 0x68, 0xd, 0x9d } };



#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#include <statreg.cpp>
#endif

#include <atlimpl.cpp>


const DWORD dwTimeOut = 5000; // time for EXE to be idle before shutting down
const DWORD dwPause = 1000; // time to wait for threads to finish up

// Passed to CreateThread to monitor the shutdown event
static DWORD WINAPI MonitorProc(void* pv)
{
    CExeModule* p = (CExeModule*)pv;
	p->MonitorShutdown();
	return 0;
}

LONG CExeModule::Unlock()
{
    LONG l = CComModule::Unlock();
	if (l == 0)
	{
	    bActivity = true;
		SetEvent(hEventShutdown); // tell monitor that we transitioned to zero
	}
	return l;
}

//Monitors the shutdown event
void CExeModule::MonitorShutdown()
{
    while (1)
	{
	    WaitForSingleObject(hEventShutdown, INFINITE);
		DWORD dwWait=0;
		do
		{
		    bActivity = false;
			dwWait = WaitForSingleObject(hEventShutdown, dwTimeOut);
		} while (dwWait == WAIT_OBJECT_0);
		// timed out
		if (!bActivity && m_nLockCnt == 0) // if no activity let's really bail
		{
#if _WIN32_WINNT >= 0x0400 & defined(_ATL_FREE_THREADED)
            CoSuspendClassObjects();
			if (!bActivity && m_nLockCnt == 0)
#endif
                break;
		}
	}
	CloseHandle(hEventShutdown);
	PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
}

bool CExeModule::StartMonitor()
{
    hEventShutdown = CreateEvent(NULL, false, false, NULL);
	if (hEventShutdown == NULL)
	    return false;
	DWORD dwThreadID;
	HANDLE h = CreateThread(NULL, 0, MonitorProc, this, 0, &dwThreadID);
	return (h != NULL);
}

CExeModule _Module; 


LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
    while (p1 != NULL && *p1 != NULL)
	{
	    LPCTSTR p = p2;
		while (p != NULL && *p != NULL)
		{
		    if (*p1 == *p)
				return CharNext(p1);
			p = CharNext(p);
		}
		p1 = CharNext(p1);
	}
	return NULL;
}

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()
//## configuration AnimationComComponent::DefaultConfig 
extern "C" int WINAPI _tWinMain(HINSTANCE  hInstance, HINSTANCE  /*hPrevInstance*/, LPTSTR  lpCmdLine, int  /*nShowCmd*/) {
    
    lpCmdLine = GetCommandLine(); //this line necessary for _ATL_MIN_CRT
    
    #if _WIN32_WINNT >= 0x0400 & defined(_ATL_FREE_THREADED)
        HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    #else 
        HRESULT hRes = CoInitialize(NULL);
    #endif 
    _ASSERTE(SUCCEEDED(hRes)); 
    _Module.Init(ObjectMap, hInstance ); /*, &LIBID_$package);*/
    _Module.dwThreadID = GetCurrentThreadId(); 
    TCHAR szTokens[] = _T("-/"); 
    
    int nRet = 0; 
    BOOL bRun = TRUE; 
    LPCTSTR lpszToken = FindOneOf(lpCmdLine, szTokens); 
    while (lpszToken != NULL) 
    {
        if (lstrcmpi(lpszToken, _T("UnregServer"))==0)
    	{
    	    nRet = _Module.UnregisterServer(FALSE);
    		bRun = FALSE;
    		break;
    	}
    	if (lstrcmpi(lpszToken, _T("RegServer"))==0)
    	{
    	    nRet = _Module.RegisterServer(FALSE);
    		RegisterApp(COMPAPPID, "AnimationComComponent" ) ;
    		bRun = FALSE;
    		break;
    	}
    	lpszToken = FindOneOf(lpszToken, szTokens);
    }
    
    if(!bRun)
    {
    	_Module.Term();
    	CoUninitialize();
    	return nRet; 
    }
    if(OXF::init(0, NULL, 6423))
        {
            theApp * p_theApp;
            crossProduct * p_crossProduct;
            dotProduct * p_dotProduct;
            ScheduledController_1D * p_ScheduledController_1D;
            ScheduledController_1D_Coeff * p_ScheduledController_1D_Coeff;
            transformAngle_DMC2Euler * p_transformAngle_DMC2Euler;
            transformAngle_Euler2Quaternion * p_transformAngle_Euler2Quaternion;
            transformAngleRate * p_transformAngleRate;
            transformPosition_B2I * p_transformPosition_B2I;
            transformPosition_I2B * p_transformPosition_I2B;
            WindGust * p_WindGust;
            p_theApp = new theApp;
            p_theApp->startBehavior();
            p_crossProduct = new crossProduct;
            p_dotProduct = new dotProduct;
            p_ScheduledController_1D = new ScheduledController_1D;
            p_ScheduledController_1D->startBehavior();
            p_ScheduledController_1D_Coeff = new ScheduledController_1D_Coeff;
            p_transformAngle_DMC2Euler = new transformAngle_DMC2Euler;
            p_transformAngle_Euler2Quaternion = new transformAngle_Euler2Quaternion;
            p_transformAngleRate = new transformAngleRate;
            p_transformPosition_B2I = new transformPosition_B2I;
            p_transformPosition_I2B = new transformPosition_I2B;
            p_WindGust = new WindGust;
            p_WindGust->startBehavior();
            //#[ configuration AnimationComComponent::DefaultConfig 
            //#]
            OXF::start(TRUE);
            
            _Module.StartMonitor();
            #if _WIN32_WINNT >= 0x0400 & defined(_ATL_FREE_THREADED)
            	hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
            		REGCLS_MULTIPLEUSE | REGCLS_SUSPENDED);
            	_ASSERTE(SUCCEEDED(hRes));
            	hRes = CoResumeClassObjects();
            #else
                hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
            	          REGCLS_MULTIPLEUSE);
            #endif
            _ASSERTE(SUCCEEDED(hRes));
            
            MSG msg;
            while (GetMessage(&msg, 0, 0, 0))
            DispatchMessage(&msg);
            
            _Module.RevokeClassObjects();
            Sleep(dwPause); //wait for any threads to finish
            _Module.Term();
            CoUninitialize();
            
            delete p_theApp;
            delete p_crossProduct;
            delete p_dotProduct;
            delete p_ScheduledController_1D;
            delete p_ScheduledController_1D_Coeff;
            delete p_transformAngle_DMC2Euler;
            delete p_transformAngle_Euler2Quaternion;
            delete p_transformAngleRate;
            delete p_transformPosition_B2I;
            delete p_transformPosition_I2B;
            delete p_WindGust;
            return 0;
        }
    else
        return 1;
}


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\MainAnimationComComponent.cpp
*********************************************************************/

