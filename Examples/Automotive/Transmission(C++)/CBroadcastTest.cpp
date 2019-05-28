// CBroadcastTest.cpp : Implementation of CCBroadcastTest
#include "stdafx.h"
#include "OnTransmission.h"
#include "CBroadcastTest.h"
#include "BroadcastSource.h"
#include "EventBroadcast.h"

/////////////////////////////////////////////////////////////////////////////
// CCBroadcastTest


STDMETHODIMP CCBroadcastTest::RunTest()
{
  // initialization
  // create 2 objects that are going to broadcast events with connection at runtime
  CBroadcastSource* src1 = new CBroadcastSource();
  CBroadcastSource* src2 = new CBroadcastSource();
  
#define SINK COnListener<CCBroadcastTest, long>

  // create 8 sinks, 2 for each port on the source objects
  SINK* pSink1 = new  SINK(this, &CCBroadcastTest::Listen1); 
  SINK* pSink2 = new  SINK(this, &CCBroadcastTest::Listen2); 
  SINK* pSink3 = new  SINK(this, &CCBroadcastTest::Listen3); 
  SINK* pSink4 = new  SINK(this, &CCBroadcastTest::Listen4); 
  SINK* pSink5 = new  SINK(this, &CCBroadcastTest::Listen1); 
  SINK* pSink6 = new  SINK(this, &CCBroadcastTest::Listen2); 
  SINK* pSink7 = new  SINK(this, &CCBroadcastTest::Listen3); 
  SINK* pSink8 = new  SINK(this, &CCBroadcastTest::Listen4); 

  pSink1->AddRef();
  pSink2->AddRef();
  pSink3->AddRef();
  pSink4->AddRef();
  pSink5->AddRef();
  pSink6->AddRef();
  pSink7->AddRef();
  pSink8->AddRef();

  // connect the sink objects
  src1->Port1->Advise(pSink1);
  src1->Port2->Advise(pSink2);
  src2->Port1->Advise(pSink3);
  src2->Port2->Advise(pSink4);
  src1->Port1->Advise(pSink5);
  src1->Port2->Advise(pSink6);
  src2->Port1->Advise(pSink7);
  src2->Port2->Advise(pSink8);
  
  // test
  src1->Fire_Port1();
  src1->Fire_Port2();
  src2->Fire_Port1();
  src2->Fire_Port2();

  // cleanup
  // connections could be released a variety of ways.
  // 1) clean and release each sink:
        // sink->clean() --> source->Unadvise();
  // 2) clean and release each source:
        // source->clean() --> sink->Disconnect() --> sink->clean() --> source->Unadvise();

  // the source and sink classes are both reference counted so the order in which the above takes place
  // doesn't matter.

#if 0
  pSink1->clean();
  pSink2->clean();
  pSink3->clean();
  pSink4->clean();
  pSink5->clean();
  pSink6->clean();
  pSink7->clean();
  pSink8->clean();
#else
  if (src1) 
  {
    delete src1;
    src1 = NULL;
  }

  if (src2)
  {
    delete src2;
    src2 = NULL;
  }
#endif

  pSink1->Release();
  pSink2->Release();
  pSink3->Release();
  pSink4->Release();
  pSink5->Release();
  pSink6->Release();
  pSink7->Release();
  pSink8->Release();

  if (src1) 
  {
    delete src1;
    src1 = NULL;
  }

  if (src2)
  {
    delete src2;
    src2 = NULL;
  }

  return S_OK;
}
