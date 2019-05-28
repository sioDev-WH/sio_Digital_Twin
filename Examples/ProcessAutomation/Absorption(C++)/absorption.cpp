// absorption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "DistributionDomain.h"
#include "DistributedVar.h"

#define DER(Var) Var

void Example();

int main(int argc, char* argv[])
{
	double L,R;
	long i,j;

	L = 3.0;
	R = 1.0;
	DistributionDomain Axial("Axial",0,L,false,false);
	DistributionDomain Radial("Radial",0,R,false,false);
	
	D_Mesh axialMesh(BFDM,1,30), radialMesh(BFDM,1,10);
	Axial.setMesh(axialMesh);
	Radial.setMesh(radialMesh);



	DistributedVar* phi;
	// Use add domain of DistributedVar class
	// Actually create collections where we can reference a domain by its name
		DistributionDomain phi_domains[2];
		phi_domains[0] = Axial; 
		phi_domains[1] = Radial;

	phi = (DistributedVar*) new DistributedVar("Concenetration","kmol/m^3",2,phi_domains/*, 3 */);
    

	// Domain manipulation
	DistributionDomain BoundaryPt, LUB, GLB, Radial_0, Radial_R; 
	BoundaryPt = phi_domains[0] | L;// Axial (z=L) boundary points
	LUB = Axial-L; // Axial z=[0,L)
	GLB = Axial-0; // Axial z=(0,L]	
	Radial_0 = Radial << R/2; // Radial r=[0,R/2)
	Radial_R = Radial >> R/2; // Radial r=(R/2,R]

	// Variable manipulation
	// Warning: To avoid creating too many copies of the discretized data
	// copy constructors of DistributedVar should make the new var
	// to reference the SrcVar (forming a tree that have a single root
	// which is the original variable defined in the whole domain
	// values for all derived variables (i.e., variables with sliced
	// domains) should be computed through a map to the data var of the
	// the original variable. The map is to be constructed based on the
	// the discretization method and the relationship between the sliced
	// domain of the derived var and the original doamin.
	// Several maps might be involved. The map should be encoded implicitly
	// in terms of the domain relationship and not explicitly (no allocated
	// memory is assigned to the derived var -- except for caching - e.g.,
	// outside the derived variable object - e.g., temp array).
	// Interpolation might be invoked as part of the mapping, when the sliced domain
	// boundaries do not align with the root variable's grid.
	// Summary: There's one and only one centeralized source for each data (grid) 
	// point of a variable.

	DistributedVar phi_R(*phi | Radial_R), phi_LR2(*phi | Radial_R | BoundaryPt); // Derived Vars (a var over a sliced domain of its root var)
	
	// Derived from phi, a 3-D root var over Axial[0,L] and Radial[0,R]
	// phi_R = *phi | Radial_R; // phi_R is same as phi but a 3-D over Axial[0,L] and (R/2, R]
	
	// doubly sliced domains of a single variable 
	// phi_LR2 = *phi | Radial_R | BoundaryPt;  // phi_LR = phi @ {z=L and r(R/2,R]} -- a ring at the end of a reactor

	// Now we can write equations in terms of derived vars, their DER and PARTIAL
	// we just need to overaload +,-,*,/ and math operators and functions that manipulate
	// the discretized values of the derived variables over their specified domains.
	// Interpolation functions and Operators, like [], can be used to access a values
	// at discretized domain points  and ranges (e.g., collocation points for plotting).

	// First of all we really do not need the member Dimension in the DistributedVar
	// We can simply use arrays of Dimension, e.g.,  We write the equations
	// for multiple concentration components in a similar manner
	DistributedVar Conc[3];
	for(i=0;i<3;i++) Conc[i] = *phi | Radial_R | BoundaryPt;

	// Second to avoid excessive uncessary computations it is recommended
	// that we create sliced equation variables over an equation domain before writing
	// the equation expressions. (i.e., perform computation over subdomin 
	// points rather than performing computation over the whole domain and
	// slicing it to the equation domain). Declaring slicing variables is not
	// costly since they just point (read) data from their root parent var
	// and they do not allocate memory themselves -- except may for unstructured
	// maps.


	// Add data to phi for axial and radial (exponentially decaying in both)
	// exp(-0.5*Axial*Axial-0.5*Radial*Radial)

	double z,r; // Axial and Radial variables
	for(j=0;j<Radial.mesh->nPts;j++)
		for(i=0;i<Axial.mesh->nPts;i++)
		{
			z=Axial.stepSize * i;
			r = Radial.stepSize * j;
			phi->pVal[i+ j* Axial.mesh->nPts]= exp(-0.5*(z*z + r*r));
		}

	DistributedVar dPhi_dAxial,dPhi_dRadial;
	
	for(i=0;i<1000;i++){
		dPhi_dAxial = phi->PARTIAL(Axial); // Which is also phi->Domains[0]
		dPhi_dRadial = phi->PARTIAL(Radial); // Which is also phi->Domains[0]
	}


	DistributedVar InteriorEquation, SurfaceEquation;
	DistributedVar BoundaryCondition_0,BoundaryCondition_L;
	DistributionDomain EquationDomains[2];

	DistributedVar Conc_Internal[3],Conc_Surface[3],Conc_BC_0[3],Conc_BC_L[3];
	for(i=0;i<3;i++){
	    Conc_Internal[i] = *phi | (Axial-L-0) | (Radial - R);	// InteriorDomain
		Conc_Surface[i] =  *phi |(Axial-L-0) | (Radial|R);		// SurfaceDomain
		Conc_BC_0[i] = *phi | (Axial| 0);						// BoundaryCondition_0
		Conc_BC_L[i]= *phi | (Axial| L);						// BoundaryCondition_L
	}
	
	 for(i=0;i<3;i++)
		InteriorEquation  // InteriorEquation.nVal and InteriorEquation.pVal to be return value to method res();
		    =  DER(Conc_Internal[i]) - (Conc_Internal[i].PARTIAL(Axial)).PARTIAL(Radial) 
			  + 2.0*Conc_Internal[0];
			  


	// InteriorEquation = 

	if(phi) delete phi;

	Example();

	return 0;
}


void Example(){  // Divid into three classes with ports. Define gas connection class
	
	long i;
	double L = 1.0; // All units are scled to length = 1

	// ****************
	// Tubular Reactor
	// ****************
	double K1 = 0.1;
	double K2 = 3.0;
	double phi_in[3]={0,0,0}; // initial input concentration
	double nu[3] = {-1,-1,+2}; // Stoichiometric coefficients
		
	// ****** Domains *******
	DistributionDomain Axial("Axial",0,L,false,false);
	D_Mesh Mesh(OCFEM,3,15);
	Axial.setMesh(Mesh);

	// ****** Variables *******
	DistributedVar phi[3], conc(" ","kmol/m^3",1,&Axial);
	for(i=0;i<3;i++)phi[i].init(conc); // set names to A,B and C


	DistributedVar phi_BC0[3], phi_MB[3], phi_BCL[3]; // Equation Variables
	for(i=0;i<3;i++){
		phi_BC0[i] = phi[i] | (Axial|0); // for Boundary condition at lambda=0
		phi_MB[i] = phi[i] | ((Axial - 0) -L); // for Mass Balance equation
		phi_BCL[i] = phi[i] | (Axial|L); // for Boundary condition at lambda=L=1.0
	}

	// ***** Equations *******
	DistributedVar BC0[3], MB[3], BCL[3]; // Equations
	for(i=0;i<3;i++){
		// Boundary condition at lambda=0
		BC0[i] = - K1 * phi_BC0[i].PARTIAL(Axial) + phi_BC0[i] -  phi_in[i] ;  
		
		// Mass Balance equation (applicable inside the reactor)
		MB[i] = - DER(phi_MB[i])
				+ K1 * phi_MB[i].PARTIAL(Axial).PARTIAL(Axial)
				+ phi_MB[i].PARTIAL(Axial)
				+ nu[i]*K2*phi_MB[0]*phi_MB[1]; 
		
		// Boundary condition at lambda=L=1.0
		BCL[i] = phi_BCL[i].PARTIAL(Axial); 
	}


	// ************
	// Gas Absorber
	// ************
	double K3 = 0.1;
	double K4 = 20.0;
	double K5 = 10.0;
	double K6 = 0.003;
	double K7 = 75.0;
	double psi_in[3]={0,0,0}; // initial input gas phase concentration
	double theta_in = 0.0;  // initial input liquid phase concentration

	// ****** Domains *******
	DistributionDomain Forward("Axial",0,L,false,false);
	DistributionDomain Reverse("Axial",0,L,false,false);
	D_Mesh ForwardMesh(BFDM,1,40), ReverseMesh(CFDM,2,40); // Make a single line constructor
	Forward.setMesh(ForwardMesh);
	Reverse.setMesh(ReverseMesh);

	// ***** Variables ******
	DistributedVar psi[3], theta("Liquid Phase","kmol/m^3",1,&Reverse);
	DistributedVar gasConc(" ","kmol/m^3",1,&Forward);
	for(i=0;i<3;i++)psi[i].init(gasConc); // set names to A,B and C gas phase
	
	DistributedVar psi_BC0[3], psi_MB[3], psi_MBL, theta_MBG, theta_BCL, theta_MBL; // Equation Variables
	for(i=0;i<3;i++){
		psi_BC0[i] = psi[i] | (Forward|0); // for Gas Boundary condition at zeta=0
		psi_MB[i] = psi[i] | ((Forward - 0)); // for Gas Phase Mass Balance equation
	}
	psi_MBL = psi[2] | (Forward - L);  // may require interpolation
	theta_MBG = theta | (Reverse - 0); // may require interpolation if grid points are not matching
	theta_BCL = theta | (Reverse|L); // for Boundary condition at zeta=L=1.0
	theta_MBL = theta | (Reverse - L); // for Liquid Phase Mass Balance equation
	
	// ***** Equations *******
	DistributedVar BCG0[3], MBG[3], MBL, BCLL; // Equations
	// Boundary condition at zeta=0
	for(i=0;i<3;i++) BCG0[i] = psi_BC0[i] -  psi_in[i];	  
	// Mass Balance equation (gas phase inside the absorber)
	MBG[0] = - DER(psi_MB[0]) - K3 * psi_MB[0].PARTIAL(Forward);
	MBG[1] = - DER(psi_MB[1]) - K3 * psi_MB[1].PARTIAL(Forward);
	MBG[2] = - DER(psi_MB[2]) - K3 * psi_MB[2].PARTIAL(Forward)
			 - K4 * (psi_MB[2] - K5 * theta_MBG);
	MBL = - DER(theta_MBL) + K6 * theta_MBL.PARTIAL(Reverse)
			 + (K4/K7) * (psi_MBL - K5 * theta_MBG);
	// Boundary condition liquid phase at zeta=L=1.0
	BCLL = theta_BCL - theta_in; // theta_in = 0 all time


	// ************
	// Mixer Tank
	// ************
	double K8 = 30.7;
	double K9 = 0.5;
	double feed_in[3]={0,0,0};
	double recycle_in[3]={0,0,0};
	double gamma[3], res[3];

	for(i=0;i<3;i++)
		res[i] = -DER(gamma[i]) + K8*(feed_in[i] + K9*recycle_in[i] - (1+K9)*gamma[i]); 
	

	// **********
	// Connections
	// **********

	// Mixer recycle and feed connections
	double res_mixer_recycle_port[3];
	double res_mixer_feed_port[3], feed[3];
	for(i=0;i<3;i++){
		res_mixer_recycle_port[i] = recycle_in[i] - psi[i].getVal(&L);
		res_mixer_feed_port[i] = feed_in[i] - feed[i];
	}

	// Reactor connections
	double res_reactor_feed_port[3];
	for(i=0;i<3;i++)
		res_reactor_feed_port[i] = phi_in[i] - gamma[i];

	// connection from reactor to absorber
	double res_absorber_feed_port[3];
	for(i=0;i<3;i++)
		res_absorber_feed_port[i] = psi_in[i] - phi[i].getVal(&L);

}