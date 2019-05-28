#ifndef RHAPREGISTERY_H
#define RHAPREGISTERY_H

#include <objbase.h>
#include <wchar.h>


extern HRESULT RegisterServer(HINSTANCE aModule, REFCLSID clsid,
	 						  const char *TypeName, const char *VerIndProgID,
							  const char *ProgID, const char *ThreadingModel,
							  REFCLSID AppID);

extern HRESULT RegisterTLB( const WCHAR *TypeLibName, bool bRegister ) ;

extern HRESULT UnregisterServer(REFCLSID clsid, const char *VerIndProgID,
									  const char *ProgID);

extern HRESULT RegisterApp( REFCLSID appid, const char *appName ) ;


#define DECLARE_RHAPSODY_REGISTER(CoClassID,TypeName,VersIndepProgID,ProgID,ThreadingModel,AppID) \
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)\
	{ 	if(bRegister) return RegisterServer( _Module.GetModuleInstance(),CoClassID,TypeName,VersIndepProgID,ProgID,ThreadingModel,AppID);\
		else return UnregisterServer(CoClassID,VersIndepProgID,ProgID) ;  }


#endif