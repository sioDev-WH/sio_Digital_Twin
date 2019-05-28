// CommonTools.h: Common utility functions
//
//////////////////////////////////////////////////////////////////////

#ifndef _CommonTools_h
#define _CommonTools_h

const long grow_by = 20;

template <class T>
HRESULT size_ptr_array(long grow, long Count, long& Dim, T**& Array, long delta = 1)
{
  HRESULT hr = S_OK;
  if ( (Dim == 0) || ((Count + delta) >= Dim) )
  {
    long i;
    long newDim;
    T** newArray;

    newDim = Dim + grow + delta;
    newArray = new T*[newDim];
    if (newArray)
    {
      // copy original pointers
      if (Array)
      {
        for (i = 0; i < Count; i++)
          newArray[i] = Array[i];
      }
      else
      {
        Count = 0;
      }

      // NULL remaining pointers
      for (i = Count; i < newDim; i++)
        newArray[i] = NULL;

      if (Array)
        delete[] Array;

      Array = newArray;
      Dim = newDim;
    }
    else
      hr = E_OUTOFMEMORY;
  }

  return hr;
};

template <class T>
HRESULT size_array(long grow, long Count, long& Dim, T*& Array, long delta = 1)
{
  HRESULT hr = S_OK;
  if ( (Dim == 0) || ((Count + delta) >= Dim) )
  {
    long i;
    long newDim;
    T* newArray;

    newDim = Dim + grow + delta;
    newArray = new T[newDim];
    if (newArray)
    {
      // copy original pointers
      if (Array)
      {
        for (i = 0; i < Count; i++)
          newArray[i] = Array[i];
      }
      else
      {
        Count = 0;
      }

      // NULL remaining pointers
      for (i = Count; i < newDim; i++)
        newArray[i] = NULL;

      if (Array)
        delete[] Array;

      Array = newArray;
      Dim = newDim;
    }
    else
      hr = E_OUTOFMEMORY;
  }

  return hr;
};


template <class T>
void compress_ptr_array(long idx_remove, long& Count, T**& Array)
{
  if (idx_remove >= 0 && idx_remove < Count)
  {
    Count--;
    for (long i = idx_remove; i < Count; i++)
      Array[i] = Array[i + 1];

    Array[Count] = NULL;
  }
}

template <class T>
void compress_array(long idx_remove, long& Count, T*& Array)
{
  if (idx_remove >= 0 && idx_remove < Count)
  {
    Count--;
    for (long i = idx_remove; i < Count; i++)
      Array[i] = Array[i + 1];

    Array[Count] = NULL;
  }
}


inline HRESULT CreateGUID(GUID& guid)
{
  guid = GUID_NULL;
  return ::CoCreateGuid (&guid);
}

inline void FormatGUID(GUID& guid, CComBSTR& bstrguid)
{
  if (guid != GUID_NULL)
  {
    _TCHAR buffer[50];
    _stprintf( buffer, _T("{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}"), 
      guid.Data1, 
      guid.Data2, 
      guid.Data3, 
      guid.Data4[0], 
      guid.Data4[1], 
      guid.Data4[2], 
      guid.Data4[3], 
      guid.Data4[4], 
      guid.Data4[5], 
      guid.Data4[6], 
      guid.Data4[7]);

    bstrguid = buffer;
  }
}

#endif // _CommonTools_h