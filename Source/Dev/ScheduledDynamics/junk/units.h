#ifndef _AVIONICS_UNITS
#define _AVIONICS_UNITS

#define MAX_UNITS 5
#define NAME_SIZE 32

#define PI 3.1415926535897932384626433832795

typedef enum{TEMPERATURE,
             ANGLE,
			 LENGTH,
			 ANGULAR_VELOCITY,
			 VELOCITY,
			 ANGULAR_ACCELERATION,
			 ACCELERATION,
			 MASS,
			 FORCE,
			 PRESSURE,
			 DENSITY,
			 OTHERS} UNIT_T;


#define DEGREE_C			"C"
#define DEGREE_K			"K"
#define DEGREE_F			"F"

#define ANGLE_DEG			"deg"
#define ANGLE_RAD			"rad"
#define ANGLE_REV			"rev"
	
#define DISTANCE_FT			"ft"
#define DISTANCE_METER		"m"
#define DISTANCE_KM			"km"
#define DISTANCE_IN			"in"
#define DISTANCE_MILE		"mi"
#define DISTANCE_NAUT		"naut mi"

#define ANGULAR_VEL_DEG_S	"deg/s"
#define ANGULAR_VEL_RAD_S	"rad/s"
#define ANGULAR_VEL_RPM		"rpm"

#define VEL_FT_S			"ft/s"
#define VEL_METER_S			"m/s"
#define VEL_KM_S			"km/s"
#define VEL_IN_S			"in/s"
#define VEL_KM_HR			"km/h"
#define VEL_MI_HR			"mph"
#define VEL_KNOTS			"kts"

#define ANGULAR_ACC_DEG_S2	"deg/s^2"
#define ANGULAR_ACC_RAD_S2	"rad/s^2"
#define ANGULAR_ACC_RPM_S	"rpm/sec"

#define ACC_FT_S2			"ft/s^2"
#define ACC_METER_S2		"m/s^2"
#define ACC_KM_S2			"km/s^2"
#define ACC_IN_S2			"in/s^2"
#define ACC_KM_HR_S			"km/h-s"
#define ACC_MI_HR_S			"mph/s"

#define MASS_LBM			"lbm"
#define MASS_KG				"kg"
#define MASS_SLUG			"slug"

#define FORCE_LBF			"lbf"
#define FORCE_N				"N"

#define PRESSURE_PSI		"psi"
#define PRESSURE_PA			"Pa"
#define PRESSURE_PSF		"psf"
#define PRESSURE_ATM		"atm"

#define DENISTY_LB_FT3		"lbm/ft^3"
#define DENISTY_KG_M3		"kg/m^3"
#define DENISTY_LB_IN3		"lbm/in^3"


struct UNITS{
	UNIT_T type;
	char  name[NAME_SIZE];
	double slope;
	double bias;
};


void init(UNIT_T Type, UNITS& unit){

	unit.slope=1.0;
	unit.bias=0.0;
	unit.type = Type;
	switch(unit.type){
		case TEMPERATURE:
			strcpy(unit.name,DEGREE_C);
			break;
		case ANGLE:
			strcpy(unit.name,ANGLE_DEG);
			break;
		case LENGTH:
			strcpy(unit.name,DISTANCE_METER);
			break;
		case ANGULAR_VELOCITY:
			strcpy(unit.name,ANGULAR_VEL_RAD_S);
			break;
		case VELOCITY:
			strcpy(unit.name,VEL_METER_S);
			break;
		case ANGULAR_ACCELERATION:
			strcpy(unit.name,ANGULAR_ACC_RAD_S2);
			break;
		case ACCELERATION:
			strcpy(unit.name,ACC_METER_S2);
			break;
		case MASS:
			strcpy(unit.name,MASS_KG);
			break;
		case FORCE:
			strcpy(unit.name,FORCE_N);
			break;
		case PRESSURE:
			strcpy(unit.name,PRESSURE_PA);
			break;
		case DENSITY:
			strcpy(unit.name,DENISTY_KG_M3);
			break;
		case OTHERS:
			strcpy(unit.name,"");
		default: ;
	}
}

void convert(const char TargetUnit[], UNITS& unit){

	double slope;
	double bias;

		if(strcmp(DEGREE_C,TargetUnit)==0){slope = 1.0; bias=0.0; } else
		if(strcmp(DEGREE_K,TargetUnit)==0){slope = 1.0;bias  = -273.15;} else
		if(strcmp(DEGREE_F,TargetUnit)==0){slope = 5.0/9.0;bias=-32.0*slope; } else

		if(strcmp(ANGLE_DEG,TargetUnit)==0){slope = PI/180.0;} else
		if(strcmp(ANGLE_RAD	,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(ANGLE_REV	,TargetUnit)==0){slope = 2*PI;} else
			
		if(strcmp(DISTANCE_FT,TargetUnit)==0){slope = 0.3048; } else
		if(strcmp(DISTANCE_METER,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(DISTANCE_KM,TargetUnit)==0){slope = 1000.0; } else
		if(strcmp(DISTANCE_IN,TargetUnit)==0){slope = 0.0254; } else
		if(strcmp(DISTANCE_MILE	,TargetUnit)==0){slope = 1609.344; } else
		if(strcmp(DISTANCE_NAUT	,TargetUnit)==0){slope = 1852.0; } else

		if(strcmp(ANGULAR_VEL_DEG_S	,TargetUnit)==0){slope = PI/180.0;} else
		if(strcmp(ANGULAR_VEL_RAD_S	,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(ANGULAR_VEL_RPM	,TargetUnit)==0){slope = 0.10471975512;} else

		if(strcmp(VEL_FT_S	,TargetUnit)==0){slope = 0.3048; } else
		if(strcmp(VEL_METER_S,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(VEL_KM_S	,TargetUnit)==0){slope = 1000.0; } else
		if(strcmp(VEL_IN_S	,TargetUnit)==0){slope = 0.0254; } else
		if(strcmp(VEL_KM_HR	,TargetUnit)==0){slope = 0.2777777777778; } else
		if(strcmp(VEL_MI_HR	,TargetUnit)==0){slope = 0.44704; } else
		if(strcmp(VEL_KNOTS	,TargetUnit)==0){slope =  0.514444444444; } else

		if(strcmp(ANGULAR_ACC_DEG_S2,TargetUnit)==0){slope = PI/180.0; } else
		if(strcmp(ANGULAR_ACC_RAD_S2,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(ANGULAR_ACC_RPM_S	,TargetUnit)==0){slope = 0.10471975512; } else

		if(strcmp(ACC_FT_S2	,TargetUnit)==0){slope = 0.3048; } else
		if(strcmp(ACC_METER_S2	,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(ACC_KM_S2	,TargetUnit)==0){slope = 1000.0; } else
		if(strcmp(ACC_IN_S2	,TargetUnit)==0){ slope = 0.0254;} else
		if(strcmp(ACC_KM_HR_S,TargetUnit)==0){slope = 0.2777777777778; } else
		if(strcmp(ACC_MI_HR_S,TargetUnit)==0){slope = 0.44704; } else

		if(strcmp(MASS_LBM,TargetUnit)==0){slope = 0.45359237; } else
		if(strcmp(MASS_KG,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(MASS_SLUG	,TargetUnit)==0){slope = 14.5939029; } else

		if(strcmp(FORCE_LBF	,TargetUnit)==0){slope = 4.448222; } else
		if(strcmp(FORCE_N,TargetUnit)==0){slope = 1.0;} else

		if(strcmp(PRESSURE_PSI,TargetUnit)==0){slope = 6894.757889516; } else
		if(strcmp(PRESSURE_PA,TargetUnit)==0){slope = 1.0; } else
		if(strcmp(PRESSURE_PSF	,TargetUnit)==0){slope = 47.8802631216; } else
		if(strcmp(PRESSURE_ATM,TargetUnit)==0){slope = 101325.0; } else

		if(strcmp(DENISTY_LB_FT3,TargetUnit)==0){slope = 16.018463374; } else
		if(strcmp(DENISTY_KG_M3	,TargetUnit)==0){slope = 1.0; } else
		if((DENISTY_LB_IN3,TargetUnit)==0){slope = 27679.904710203;} else
		cerr << "target unit name does not match any existing unit name\n";

		unit.slope /= slope;
		unit.bias = (unit.bias - bias )/slope;
		strcpy(unit.name,TargetUnit);
};
#endif

