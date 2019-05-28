#include "aeroUnits.h"
#include "aeroVec.h"

void testUnits(){

	int i;
	double T=20;							// Temperature meant to be in MKS
	Units u1("F");
	T=fromMKS(T, u1);
	T=toMKS(T,u1);
	
	double V=1000;							// Velocity meant to be in ft/s (not an MKS unit)
	Units u2("ft/s");
	V=toMKS(V,u2);
	V=fromMKS(V,u2);

	double omega=1000;						// Rotational Velocity meant to be in RPM (not an MKS unit)
	Units u3("RPM");
	omega=toMKS(omega,u3);
	omega=fromMKS(omega,u3);

	Units u(uPRESSURE);						// create an MKS unit for PRESSURE (an enum value), will automatically assign Pa unit
	double P=1500.0;
	P = fromMKS(P,u);						// no changes
	P = toMKS(P,u);							// no changes

	aeroForce<double> F;
	Units u4(uFORCE);						// MKS
	for(i=0;i<3;i++) F[i] = 1000.0/(i+1);	// in Newton, N
	F.units = u4;
	cerr << "Force units: " << F.units.name << "\n";
	Units u5("lbf");						// create new unit object to convert aeroForce object to lbf units
	if(u5.type== F.units.type){
		
		for(i=0;i<3;i++) 
			F[i] = fromMKS(F[i],u5);		// convert data member to be in lbf
		F.units = u5;
											// Then set units of aeroForce object to be in lbf
		cerr << "Force units: " << F.units.name << "\n";
	}
	
	for(i=0;i<3;i++) F[i] = toMKS(F[i],u5);
	F.units = u4;							// Now returning back to MKS units - notice order; data then units
	cerr << "Force units: " << F.units.name << "\n";
		
}
