// OnDataCollector.h: interface for the COnDataCollector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONDATACOLLECTOR_H__F7094561_D83D_446A_B11D_995F7A19C573__INCLUDED_)
#define AFX_ONDATACOLLECTOR_H__F7094561_D83D_446A_B11D_995F7A19C573__INCLUDED_

#include "OnDaeCOSolverExport.h"
#include "EventBroadcast.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct IIsDaeEsoCImpl;



//===========================================================================================
// Data collection classes for supporting poll data communication between objects
//===========================================================================================

class ONDAECOSOLVER_API COnDataCollector : public COnBroadcaster<double>  
{
public:

	COnDataCollector(_TCHAR* Name, IIsDaeEsoCImpl* pSrc);
	virtual ~COnDataCollector();
  bool SetVariables(_TCHAR** varNames, long varCount);
  void clean();
  bool broadcast();

protected:
  long m_varCount;

  SAFEARRAY* m_psaVarIds;
  long* m_pVarIds; 

  SAFEARRAY* m_psaVarVals1;
  SAFEARRAY* m_psaVarVals2;
  SAFEARRAY* m_psaActiveBuffer;
  IIsDaeEsoCImpl* m_pSrcModel;

};





#endif // !defined(AFX_ONDATACOLLECTOR_H__F7094561_D83D_446A_B11D_995F7A19C573__INCLUDED_)
