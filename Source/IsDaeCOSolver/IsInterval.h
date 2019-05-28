// zero calculation moved to this file because the interval library
// causes all kinds of compile errors otherwise.

bool CalculateZeros(double y0, double y1, double ydot0, double ydot1, double t0, double t1, long& cZero, double* vZero);
int Krawczyk(double s_inf, double s_sup);
bool iSimplifiedNewton(double y_inf, double y_sup);
double fVal(double tau);
double deriv(double tau);
