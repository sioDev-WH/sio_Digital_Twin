
/////////////////////////////////////////////////////////////////////////////////////////
// Includes

#define _DLLEXPORT_
#include "SMHarness.h"

/////////////////////////////////////////////////////////////////////////////////////////
//	Function: DllMain
//
//  Args:     HINSTANCE hDllInst - Instance handle of the DLL.
//            DWORD fdwReason - Process attach/detach or thread attach/detach,
//								Reason for calling.
//            LPVOID lpvReserved - Reserved and not used.
//
//  Returns:  BOOL - Return value is used only when fdwReason == DLL_PROCESS_ATTACH.
//              TRUE  -  Used to signify that the DLL should remain loaded.
//              FALSE -  Used to signify that the DLL should be immediately unloaded.

BOOL WINAPI DllMain( HINSTANCE hDllInst, DWORD fdwReason, LPVOID lpvReserved )
{
	// Dispatch this call based on the reason it was called.
	switch (fdwReason)
	{
    case DLL_PROCESS_ATTACH:
		// Initialise harness state machine code.
		SMConstructor();

		break;

    case DLL_PROCESS_DETACH:
		// Tidy up harness state machine code.
		SMDestructor();

		break;
	} // end switch

	return (TRUE);
}
