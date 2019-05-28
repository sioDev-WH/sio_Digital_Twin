#ifndef __SHIFTLEVER_H
#define __SHIFTLEVER_H

#include "shiftLogic.h"

class CShiftDlg;

//{{SCG_HEADER(ShiftLever.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class ShiftLever 
                  
//}}SCG_CLASS_INFO
{

public:
  long AddRef();
  long Release();
  void SetName(LPCTSTR cszName);
  long m_cRef;

    //{{SCG_CLASS_PROPS(0)
    public:
        double lastUpdateTime;     
        Port_Int* positionPort;     
        bool bInit;     
        int currentPosition;     
    public:
        void handle_tick(double *time);             
        void init();             
        void clean();             
        ShiftLever();             
        ~ShiftLever(); 
        
        CShiftDlg* m_dlg;
        void get_Position(long* val);
        void put_Position(long val);

        long val;

    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










