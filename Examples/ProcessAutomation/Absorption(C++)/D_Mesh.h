
#if !defined(_D_Mesh)
#define _D_Mesh

// Discretization Method
enum D_Method				// Center/Backward/Forward/Upwind Finite Diff 
{ CFDM, BFDM, FFDM, UFDM, OCFEM};	// and Orthogonal Collocation FEM


class D_Mesh{

public:
	D_Method method;	// Discretization Method
	long order;			// n = Lagrange Polynomial order
	long nElements;		// m = Number of elements (=1 for CFDM, BFDM, FFDM, UFDM)
	long nPts;			// N = Number of points

public:
	D_Mesh(){;}
	virtual ~D_Mesh(){;}
	D_Mesh(D_Method Method,long Order,long NElements){
		method=Method;
		order=Order;
		nElements = NElements;
		switch(method){
		case OCFEM:
			nPts =  nElements * Order + 1;
			break;
		case CFDM:
		case BFDM:
		case FFDM:
		case UFDM:
			nPts =  nElements + 1;
		}
	}

};

#endif