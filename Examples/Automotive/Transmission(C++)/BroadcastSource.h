// BroadcastSource.h : Declaration of the CBroadcastSource

#ifndef __BROADCASTSOURCE_H_
#define __BROADCASTSOURCE_H_

template <class A>
class COnBroadcaster;

/////////////////////////////////////////////////////////////////////////////
// CBroadcastSource
class CBroadcastSource 
{
public:
	CBroadcastSource();
  virtual ~CBroadcastSource();

public:

  COnBroadcaster<long>* Port1;
  COnBroadcaster<long>* Port2;

  void Fire_Port1();
  void Fire_Port2();
};

#endif //__BROADCASTSOURCE_H_
