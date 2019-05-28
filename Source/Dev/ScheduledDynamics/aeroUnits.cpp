#include <string.h>
#include <iostream.h>
#include "aeroUnits.h"

double fromMKS(double data, Units& unit){

	double newData;

	if(unit.bias==0.0)
		newData = data/unit.slope;
	else
		newData = data/unit.slope - unit.bias;

	return newData;
}

double toMKS(double data, Units& unit){

	double newData;

	if(unit.bias==0.0)
		newData = data*unit.slope;
	else
		newData = (data + unit.bias)*unit.slope ;

	return newData;
}

Units:: operator = (Units& u){
	strcpy(name,u.name);
	type=u.type; 
	slope=u.slope;
	bias=u.bias;
}

Units::Units(UNITS_T Type)
{
	slope=1.0;
	bias=0.0;
	type = Type;
	switch(type){
		case uTEMPERATURE:
			strcpy(name,DEGREE_C);
			break;
		case uANGLE:
			strcpy(name,ANGLE_DEG);
			break;
		case uLENGTH:
			strcpy(name,DISTANCE_METER);
			break;
		case uANGULAR_VELOCITY:
			strcpy(name,ANGULAR_VEL_RAD_S);
			break;
		case uVELOCITY:
			strcpy(name,VEL_METER_S);
			break;
		case uANGULAR_ACCELERATION:
			strcpy(name,ANGULAR_ACC_RAD_S2);
			break;
		case uACCELERATION:
			strcpy(name,ACC_METER_S2);
			break;
		case uMASS:
			strcpy(name,MASS_KG);
			break;
		case uFORCE:
			strcpy(name,FORCE_N);
			break;
		case uTORQUE:
			strcpy(name,TORQUE_N_M);
			break;
		case uPRESSURE:
			strcpy(name,PRESSURE_PA);
			break;
		case uDENSITY:
			strcpy(name,DENISTY_KG_M3);
			break;
		case uOTHERS:
			strcpy(name,"");
		default: ;
	}
};


Units::Units(const char unitSymbol[]){

	if(_stricmp(DEGREE_C,unitSymbol)==0){slope = 1.0; bias=0.0; type=uTEMPERATURE; } else
	if(_stricmp(DEGREE_K,unitSymbol)==0){slope = 1.0;bias  = -273.15;type=uTEMPERATURE;} else
	if(_stricmp(DEGREE_F,unitSymbol)==0){slope = 5.0/9.0;bias=-32.0; type=uTEMPERATURE;} else

	if(_stricmp(ANGLE_DEG,unitSymbol)==0){slope = PI/180.0;bias=0.0; type =uANGLE ; } else
	if(_stricmp(ANGLE_RAD	,unitSymbol)==0){slope = 1.0; bias=0.0; type = uANGLE; } else
	if(_stricmp(ANGLE_REV	,unitSymbol)==0){slope = 2*PI;bias=0.0; type = uANGLE ; } else
		
	if(_stricmp(DISTANCE_FT,unitSymbol)==0){slope = 0.3048; bias=0.0; type = uLENGTH; } else
	if(_stricmp(DISTANCE_METER,unitSymbol)==0){slope = 1.0; bias=0.0; type = uLENGTH; } else
	if(_stricmp(DISTANCE_KM,unitSymbol)==0){slope = 1000.0; bias=0.0; type = uLENGTH; } else
	if(_stricmp(DISTANCE_IN,unitSymbol)==0){slope = 0.0254; bias=0.0; type = uLENGTH; } else
	if(_stricmp(DISTANCE_MILE	,unitSymbol)==0){slope = 1609.344; bias=0.0; type = uLENGTH; } else
	if(_stricmp(DISTANCE_NAUT	,unitSymbol)==0){slope = 1852.0; bias=0.0; type = uLENGTH; } else

	if(_stricmp(ANGULAR_VEL_DEG_S	,unitSymbol)==0){slope = PI/180.0;bias=0.0; type =uANGULAR_VELOCITY ; } else
	if(_stricmp(ANGULAR_VEL_RAD_S	,unitSymbol)==0){slope = 1.0; bias=0.0; type = uANGULAR_VELOCITY; } else
	if(_stricmp(ANGULAR_VEL_RPM	,unitSymbol)==0){slope = 0.10471975512;bias=0.0; type = uANGULAR_VELOCITY; } else

	if(_stricmp(VEL_FT_S	,unitSymbol)==0){slope = 0.3048; bias=0.0; type = uVELOCITY; } else
	if(_stricmp(VEL_METER_S,unitSymbol)==0){slope = 1.0; bias=0.0; type = uVELOCITY; } else
	if(_stricmp(VEL_KM_S	,unitSymbol)==0){slope = 1000.0; bias=0.0; type = uVELOCITY; } else
	if(_stricmp(VEL_IN_S	,unitSymbol)==0){slope = 0.0254; bias=0.0; type = uVELOCITY; } else
	if(_stricmp(VEL_KM_HR	,unitSymbol)==0){slope = 0.2777777777778; bias=0.0; type = uVELOCITY; } else
	if(_stricmp(VEL_MI_HR	,unitSymbol)==0){slope = 0.44704; bias=0.0; type = uVELOCITY; } else
	if(_stricmp(VEL_KNOTS	,unitSymbol)==0){slope =  0.514444444444; bias=0.0; type = uVELOCITY; } else

	if(_stricmp(ANGULAR_ACC_DEG_S2,unitSymbol)==0){slope = PI/180.0; bias=0.0; type = uANGULAR_ACCELERATION; } else
	if(_stricmp(ANGULAR_ACC_RAD_S2,unitSymbol)==0){slope = 1.0; bias=0.0; type = uANGULAR_ACCELERATION; } else
	if(_stricmp(ANGULAR_ACC_RPM_S	,unitSymbol)==0){slope = 0.10471975512; bias=0.0; type = uANGULAR_ACCELERATION; } else

	if(_stricmp(ACC_FT_S2	,unitSymbol)==0){slope = 0.3048; bias=0.0; type = uACCELERATION; } else
	if(_stricmp(ACC_METER_S2	,unitSymbol)==0){slope = 1.0; bias=0.0; type = uACCELERATION; } else
	if(_stricmp(ACC_KM_S2	,unitSymbol)==0){slope = 1000.0; bias=0.0; type = uACCELERATION; } else
	if(_stricmp(ACC_IN_S2	,unitSymbol)==0){ slope = 0.0254;bias=0.0; type = uACCELERATION; } else
	if(_stricmp(ACC_KM_HR_S,unitSymbol)==0){slope = 0.2777777777778; bias=0.0; type = uACCELERATION; } else
	if(_stricmp(ACC_MI_HR_S,unitSymbol)==0){slope = 0.44704; bias=0.0; type = uACCELERATION; } else

	if(_stricmp(MASS_LBM,unitSymbol)==0){slope = 0.45359237; bias=0.0; type = uMASS; } else
	if(_stricmp(MASS_KG,unitSymbol)==0){slope = 1.0; bias=0.0; type = uMASS; } else
	if(_stricmp(MASS_SLUG	,unitSymbol)==0){slope = 14.5939029; bias=0.0; type = uMASS; } else

  if(_stricmp(MASS_LBF_FT2,unitSymbol)==0){slope = 0.042140; bias=0.0; type = uINERTIA; } else
	if(_stricmp(MASS_KG_M2,unitSymbol)==0){slope = 1.0; bias=0.0; type = uINERTIA; } else
	if(_stricmp(MASS_SLUG_M2	,unitSymbol)==0){slope = 14.593900; bias=0.0; type = uINERTIA; } else

	if(_stricmp(FORCE_LBF	,unitSymbol)==0){slope = 4.448222; bias=0.0; type = uFORCE; } else
	if(_stricmp(FORCE_N,unitSymbol)==0){slope = 1.0;bias=0.0; type = uFORCE; } else

  if(_stricmp(TORQUE_LBF_FT	,unitSymbol)==0){slope = 1.355818; bias=0.0; type = uTORQUE; } else
	if(_stricmp(TORQUE_N_M,unitSymbol)==0){slope = 1.0;bias=0.0; type = uTORQUE; } else

	if(_stricmp(PRESSURE_PSI,unitSymbol)==0){slope = 6894.757889516; bias=0.0; type = uPRESSURE; } else
	if(_stricmp(PRESSURE_PA,unitSymbol)==0){slope = 1.0; bias=0.0; type = uPRESSURE; } else
	if(_stricmp(PRESSURE_PSF	,unitSymbol)==0){slope = 47.8802631216; bias=0.0; type = uPRESSURE; } else
	if(_stricmp(PRESSURE_ATM,unitSymbol)==0){slope = 101325.0; bias=0.0; type = uPRESSURE; } else

	if(_stricmp(DENISTY_LB_FT3,unitSymbol)==0){slope = 16.018463374; bias=0.0; type = uDENSITY; } else
	if(_stricmp(DENISTY_KG_M3	,unitSymbol)==0){slope = 1.0; bias=0.0; type = uDENSITY; } else
	if((DENISTY_LB_IN3,unitSymbol)==0){slope = 27679.904710203;bias=0.0; type = uDENSITY; } else
	cerr << "target unit name does not match any existing unit name\n";

	strcpy(name,unitSymbol);
};

