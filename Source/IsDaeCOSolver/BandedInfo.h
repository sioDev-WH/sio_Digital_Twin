#ifndef _BANDED_INFO_H_
#define _BANDED_INFO_H_

class MatInfo;

extern double dlamch(char);

extern bool isBanded (long nRows, long nCols, double** StructureMatrix, long& lowerBandwidth, long& upperBandwidth);
bool isBandedCompact (MatInfo& mat, long* ActiveRows, long nActiveRows, long* itActiveCols);

#endif // _BANDED_INFO_H_