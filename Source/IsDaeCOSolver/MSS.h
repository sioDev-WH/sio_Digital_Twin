/////////////////////////////////////////////////////////////////////
// variable index / consistent initialization calculations

const long iMSS_OK = 0;
const long iMSS_MaxCalls = 1;

long iCalculateMSS(
  long& nAugmentedVars,               // [in, out]
  long& nEqns,                        // [in, out]
  long* in_VAL,                       // [in]
  long* in_edgeList_cRowNZ,           // [in]
  long* in_edgeList_ColIndices,       // [in]
  long*& out_VAL,                     // [out]
  long*& out_EAL,                     // [out]
  long& out_edgeList_nColumnIndices,  // [out]
  long*& out_edgeList_spRowPage,      // [out]
  long*& out_edgeList_cRowNZ,         // [out]
  long*& out_edgeList_ColIndices,     // [out]
  long*& out_assignedEqn,             // [out]
  short*& out_differentialIndex);     // [out]


