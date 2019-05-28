// BroadcastSource.cpp : Implementation of CBroadcastSource
#include "stdafx.h"
#include "OnTransmission.h"
#include "BroadcastSource.h"
#include "EventBroadcast.h"

/////////////////////////////////////////////////////////////////////////////
// CBroadcastSource

CBroadcastSource::CBroadcastSource()
{
  Port1 = new COnBroadcaster<long>();
  Port2 = new COnBroadcaster<long>();

  Port1->AddRef();
  Port2->AddRef();
}


CBroadcastSource::~CBroadcastSource()
{
  Port1->clean();
  Port2->clean();
  Port1->Release();
  Port2->Release();
}

void CBroadcastSource::Fire_Port1() 
{ 
  long val = 10;
  Port1->Fire_Event(&val); 
}

void CBroadcastSource::Fire_Port2() 
{ 
  long val = 20;
  Port2->Fire_Event(&val); 
}
