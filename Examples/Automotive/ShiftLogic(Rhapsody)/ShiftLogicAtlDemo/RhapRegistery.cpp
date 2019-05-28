#include "RhapRegistery.h"

// Set the given key and its value.
BOOL setKeyAndValue(const char *pszPath, const char *szSubkey, const char *szValue);

// Open a key and set a value.
BOOL setValueInKey(const char *szKey, const char *szNamedValue, const char *szValue);

// Convert a CLSID into a char string.
void CLSIDtochar(REFCLSID clsid, char *szCLSID, int length);

// Delete szKeyChild and all of its descendents.
LONG recursiveDeleteKey(HKEY hKeyParent, const char *szKeyChild);

// Size of a CLSID as a string
const int CLSID_STRING_SIZE = 39;

// Register the component in the registry.
HRESULT RegisterServer(HINSTANCE hModule,  // module handle
					   REFCLSID clsid,     // Class ID
					   const char *TypeName, //class type name
					   const char *VerIndProgID, //version indep Programmatic ID
					   const char *ProgID,//ProgrammaticID
					   const char *ThreadingModel, // ThreadingModel
					   REFCLSID appid)  //appid
{
	// Get server location.
	char szModule[512];
	DWORD dwResult = GetModuleFileName(hModule, szModule, sizeof(szModule)/sizeof(char));
	if(dwResult == 0)
		return GetLastError() ;

	const int length = strlen(szModule) ;

	if( length < 5 ) //component name should contain ".exe | .dll"
		return E_FAIL ; 

	// Convert the CLSID into a char.
	char szCLSID[CLSID_STRING_SIZE];
	CLSIDtochar(clsid, szCLSID, sizeof(szCLSID));

	// Build the key CLSID\\{...}
	char szKey[64];
	strcpy(szKey, "CLSID\\");
	strcat(szKey, szCLSID);
  
	// Add the CLSID to the registry.
	setKeyAndValue(szKey, NULL, TypeName);

	//extract the extension and convert to lower case
	char szExtension[5] ;
	memset( szExtension, '\0', sizeof(szExtension) ) ;

	signed int i = 4 ; //just take last four letters

	while( i >= 0 ) {
		szExtension[i] = szModule[length-4+i--] ;
	}
	_strlwr( szExtension ) ;


	// Add the server filename subkey under the CLSID key.
	char szServer[64];
	if(strstr(szExtension, ".exe") == NULL)
	{
		setKeyAndValue(szKey, "InprocServer32", szModule);
		strcpy(szServer, szKey);
		strcat(szServer, "\\InprocServer32");
		setValueInKey(szServer, "ThreadingModel", ThreadingModel);
	}
	else
	{
		memset( szServer, '\0', sizeof(szServer) ); 
		strcpy(szServer, szKey);
		strcat(szServer, "\\InprocServer32");
		recursiveDeleteKey(HKEY_CLASSES_ROOT, szServer );
		setKeyAndValue(szKey, "LocalServer32", szModule);
	}

	// Add the ProgID subkey under the CLSID key.
	setKeyAndValue(szKey, "ProgID", ProgID);

	// Add the version-independent ProgID subkey under CLSID key.
	setKeyAndValue(szKey, "VersionIndependentProgID", VerIndProgID);

	//Add the AppID subkey 
	CLSIDtochar(appid, szCLSID, sizeof(szCLSID));
	setKeyAndValue(szKey, "AppID", szCLSID);

	//set APPID value
	setValueInKey( szKey, "AppID", szCLSID);

	// Add the version-independent ProgID subkey under HKEY_CLASSES_ROOT.
	setKeyAndValue(VerIndProgID, NULL, TypeName); 
	setKeyAndValue(VerIndProgID, "CLSID", szCLSID);
	setKeyAndValue(VerIndProgID, "CurVer", ProgID);

	// Add the versioned ProgID subkey under HKEY_CLASSES_ROOT.
	setKeyAndValue(ProgID, NULL, TypeName); 
	setKeyAndValue(ProgID, "CLSID", szCLSID);

	return S_OK;
}

HRESULT RegisterApp( REFCLSID appid, const char *appName )
{
	if(!appName) return E_FAIL ;

	// Convert the CLSID into a char.
	char szCLSID[CLSID_STRING_SIZE];
	CLSIDtochar(appid, szCLSID, sizeof(szCLSID));

	// Build the key CLSID\\{...}
	char szKey[64];
	strcpy(szKey, "AppID\\");
	strcat(szKey, szCLSID);
  
	// Add the CLSID to the registry.
	setKeyAndValue(szKey, NULL, appName);

	return S_OK ;

}


HRESULT RegisterTLB( const WCHAR *TypeLibName, bool bRegister )
{
	if(!TypeLibName)
		return S_OK ;  //Don't do anything just return

	ITypeLib* pTypeLib = NULL ;
	HRESULT hr = LoadTypeLibEx(TypeLibName, REGKIND_REGISTER, &pTypeLib);

	if( bRegister || !pTypeLib || FAILED(hr) )  {
		if(pTypeLib) pTypeLib->Release() ;
		return hr ;
	}

	TLIBATTR* ptla = NULL ;
	hr = pTypeLib->GetLibAttr(&ptla);

	if(FAILED(hr))	return hr ;

	hr = UnRegisterTypeLib(ptla->guid, ptla->wMajorVerNum, ptla->wMinorVerNum,
						ptla->lcid, ptla->syskind ) ;

	pTypeLib->ReleaseTLibAttr(ptla);

	return hr ;
}


HRESULT UnregisterServer(REFCLSID clsid, // Class ID
					     const char *VerIndProgID, //version indep Programmatic ID
						 const char *ProgID) //Programmatic ID
{
	// Convert the CLSID into a char.
	char szCLSID[CLSID_STRING_SIZE];
	CLSIDtochar(clsid, szCLSID, sizeof(szCLSID));

	// Build the key CLSID\\{...}
	char szKey[64];
	strcpy(szKey, "CLSID\\");
	strcat(szKey, szCLSID);

	// Delete the CLSID Key - CLSID\{...}
	LONG lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szKey);

	// Delete the version-independent ProgID Key.
	lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, VerIndProgID);

	// Delete the ProgID key.
	lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, ProgID);

	return S_OK;
}

// Convert a CLSID to a char string.
void CLSIDtochar(REFCLSID clsid, char *szCLSID, int length)
{
	// Get CLSID
	LPOLESTR wszCLSID = NULL;
	StringFromCLSID(clsid, &wszCLSID);

	// Covert from wide characters to non-wide.
	wcstombs(szCLSID, wszCLSID, length);

	// Free memory.
	CoTaskMemFree(wszCLSID);
}

// Delete a key and all of its descendents.
LONG recursiveDeleteKey(HKEY hKeyParent,           // Parent of key to delete
                        const char *lpszKeyChild)  // Key to delete
{
	// Open the child.
	HKEY hKeyChild;
	LONG lRes = RegOpenKeyEx(hKeyParent, lpszKeyChild, 0, KEY_ALL_ACCESS, &hKeyChild);
	if(lRes != ERROR_SUCCESS)
		return lRes;

	// Enumerate all of the decendents of this child.
	FILETIME time;
	char szBuffer[256];
	DWORD dwSize = 256;
	while(RegEnumKeyEx(hKeyChild, 0, szBuffer, &dwSize, NULL, NULL, NULL, &time) == S_OK)
	{
		// Delete the decendents of this child.
		lRes = recursiveDeleteKey(hKeyChild, szBuffer);
		if(lRes != ERROR_SUCCESS)
		{
			// Cleanup before exiting.
			RegCloseKey(hKeyChild);
			return lRes;
		}
		dwSize = 256;
	}

	// Close the child.
	RegCloseKey(hKeyChild);

	// Delete this child.
	return RegDeleteKey(hKeyParent, lpszKeyChild);
}

// Create a key and set its value.
BOOL setKeyAndValue(const char *szKey, const char *szSubkey, const char *szValue)
{
	HKEY hKey;
	char szKeyBuf[1024];

	// Copy keyname into buffer.
	strcpy(szKeyBuf, szKey);

	// Add subkey name to buffer.
	if(szSubkey != NULL)
	{
		strcat(szKeyBuf, "\\");
		strcat(szKeyBuf, szSubkey );
	}

	// Create and open key and subkey.
	long lResult = RegCreateKeyEx(HKEY_CLASSES_ROOT, szKeyBuf, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if(lResult != ERROR_SUCCESS)
		return FALSE;

	// Set the Value.
	if(szValue != NULL)
		RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)szValue, strlen(szValue)+1);

	RegCloseKey(hKey);
	return TRUE;
}

// Open a key and set a value.
BOOL setValueInKey(const char *szKey, const char *szNamedValue, const char *szValue)
{
	HKEY hKey;
	char szKeyBuf[1024];

	// Copy keyname into buffer.
	strcpy(szKeyBuf, szKey);

	// Create and open key and subkey.
	long lResult = RegOpenKeyEx(HKEY_CLASSES_ROOT, szKeyBuf, 0, KEY_SET_VALUE, &hKey);
	if(lResult != ERROR_SUCCESS)
		return FALSE;

    // Set the Value.
	if(szValue != NULL)
		RegSetValueEx(hKey, szNamedValue, 0, REG_SZ, (BYTE*)szValue, strlen(szValue)+1);

	RegCloseKey(hKey);
	return TRUE;
}