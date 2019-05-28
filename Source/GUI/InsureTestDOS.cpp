// InsureTestDOS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "e:\August15\DistComponents\bin\IsDaeCOSolver_i.c"
#include "E:\August15\DistComponents\OnTransmission\OnTransmission_i.c"

#include <fstream.h>

void test_ravMSF();

int main(int argc, char* argv[])
{

#if 0
  // test 1
  HRESULT hr = S_OK;
  IOnTest* pTest = NULL;
  CoInitialize(NULL);
  hr = CoCreateInstance(CLSID_OnTest, NULL, CLSCTX_INPROC_SERVER, IID_IOnTest, (void**) &pTest);
  if (SUCCEEDED(hr))
    pTest->SparseTest();
  
#endif

  test_ravMSF();

  return 0;
}

void test_ravMSF()
{
  HRESULT hr = S_OK;

  ofstream fs( "ravMSF.txt", ios::out, filebuf::openprot );

  IOnModelExec* pModelExec = NULL;
  IOnTransModelFactory* pModelFactory = NULL;
  IIsDaeEsoCImpl* pModel = NULL;
  IDispatch* pDispatch = NULL;

  double t = 0.0;;
  double t_last = 0.0;
  double startTime = 0.0;
  double endTime = 4.0;
  bool bEvent1Fired = false;
  IIsDaeEsoCImpl* pEso = NULL;
  long nVars = 0;
  long i;

  double* v_atol = NULL;
  double* v_rtol = NULL;

  SAFEARRAY* psa_atol = NULL;
  SAFEARRAY* psa_rtol = NULL;
  long iterator;


  SAFEARRAY* psaEqnNames = NULL;
  SAFEARRAY* psaVarNames = NULL;
  SAFEARRAY* psaRParNames = NULL;
  SAFEARRAY* psaIParNames = NULL;

  BSTR* EqnNames = NULL;
  BSTR* VarNames = NULL;
  BSTR* RParNames = NULL;
  BSTR* IParNames = NULL;

  CoInitialize(NULL);

  //for (iterator = 0; iterator < 10; iterator++)
  //{

    hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &pModelExec);
    hr = CoCreateInstance(CLSID_OnTransModelFactory, NULL, CLSCTX_INPROC_SERVER, IID_IOnTransModelFactory, (void**) &pModelFactory);
  
    pModelFactory->CreateModel(L"OnRavMSF", &pDispatch);
    pDispatch->QueryInterface(IID_IIsDaeEsoCImpl, reinterpret_cast<void**> (&pModel) );
    pDispatch->Release();
    pModelExec->SetModel(pModel);
  
    // initialize tolerances

    pModel->GetNumVars(&nVars);

    psa_atol = SafeArrayCreateVector(VT_R8, 0, nVars);
    psa_rtol = SafeArrayCreateVector(VT_R8, 0, nVars);

    SafeArrayAccessData(psa_atol, (void HUGEP* FAR*)& v_atol);
    SafeArrayAccessData(psa_atol, (void HUGEP* FAR*)& v_rtol);

    for (i = 0; i < nVars; i++) 
    {
      v_atol[i] = 1e-6;
      v_rtol[i] = 1e-6;
    }
    v_atol[12] = 0.000000001;   // displacement of clutch
  
    SafeArrayUnaccessData(psa_atol);
    SafeArrayUnaccessData(psa_atol);

    pModel->SetAbsTolerance(&psa_atol);
    pModel->SetRelTolerance(&psa_rtol);
  
    SafeArrayDestroy(psa_atol);
    SafeArrayDestroy(psa_rtol);

    pModel->InitTime(startTime, VARIANT_FALSE);
    pModel->GetTime(&t);
    t_last = t;

#if 0
    pModel->GetEqnNames(&psaEqnNames);
    pModel->GetVarNames(&psaVarNames);
    pModel->GetRParNames(&RParNames);
    pModel->GetIParNames(&psaIParNames);
  
    SafeArrayAccessData(psaEqnNames, (void HUGEP* FAR*)& EqnNames);
    SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& VarNames);
    SafeArrayAccessData(psaRParNames, (void HUGEP* FAR*)& RParNames);
    SafeArrayAccessData(psaIParNames, (void HUGEP* FAR*)& IParNames);

    Debug.Print vbCrLf & "EqnNames"
    For i = 0 To UBound(EqnNames)
      Debug.Print i & "  " & EqnNames(i)
    Next i
  
    Debug.Print vbCrLf & "VarNames"
    For i = 0 To UBound(VarNames)
      Debug.Print i & "  " & VarNames(i)
    Next i
 
    Debug.Print vbCrLf & "RParNames"
    For i = 0 To UBound(RParNames)
      Debug.Print i & "  " & RParNames(i)
    Next i
 
    Debug.Print vbCrLf & "IParNames"
    For i = 0 To UBound(IParNames)
      Debug.Print i & "  " & IParNames(i)
    Next i
#endif

    //pModelExec->StepSize(0.05);
  
    while (t < endTime)
    {
      pModelExec->Step();
      pModel->GetTime(&t);
    
      if (t > 0.2 && !bEvent1Fired)
      {
        pModel->get_Eso(L"aBreak", &pEso);
        pModelExec->PostStateEvent(t, L"Engage", -1, pEso); 
        pEso->Release();
        bEvent1Fired = true;
      }
    }
  
    pModelExec->SetModel(NULL);
    pModel->Release();
    pModelExec->Release();
    pModelFactory->Release();

    fs.close();

    CoUninitialize();
  //}

}