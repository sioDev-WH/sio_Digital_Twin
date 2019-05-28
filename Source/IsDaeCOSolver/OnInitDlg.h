
//----------------------------------------------------------------------------
// COnInitDlg.h                                                                  
//----------------------------------------------------------------------------


#ifndef COnInitDlg_H 
#define COnInitDlg_H 


#include "stdafx.h"
#include "atlhost.h"
#include "atlwin.h"

struct _ctlInitialization;
struct _Collection;
struct IOnModelExec;

class COnInitDlg  {
public :

////    Constructors and destructors    ////
public :
    COnInitDlg();
    ~COnInitDlg();

public :
    void clean();
    void init();
    
    void GetPosition(int * x, int * y, int * nWidth, int * nHeight);
    void Move(const int x, const int y, const int nWidth, const int nHeight);
    void SetCaption(LPCTSTR szCaption);
    void Show();
    void SetModelExec(IOnModelExec* pModelExec);

protected :
    
    _ctlInitialization* m_pOnInit;
    
private :
    
    CAxWindow m_wnd;		//## attribute m_wnd 
    

};

#endif  

