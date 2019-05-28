#ifndef _AVIONICS_UNITS
#define _AVIONICS_UNITS

#define NAME_SIZE 16

#define PI 3.1415926535897932384626433832795

typedef enum  {uTEMPERATURE,
             uANGLE,
			 uLENGTH,
			 uANGULAR_VELOCITY,
			 uVELOCITY,
			 uANGULAR_ACCELERATION,
			 uACCELERATION,
			 uMASS,
			 uINERTIA,
			 uFORCE,
			 uTORQUE,
			 uPRESSURE,
			 uDENSITY,
			 uOTHERS} UNITS_T;


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

#define MASS_LBF_FT2	"lbf*ft^2"
#define MASS_KG_M2		"kg*m^2"
#define MASS_SLUG_M2	"slug*m^2"

#define FORCE_LBF			"lbf"
#define FORCE_N				"N"

#define TORQUE_LBF_FT "lbf*ft"
#define TORQUE_N_M    "N*m"

#define PRESSURE_PSI		"psi"
#define PRESSURE_PA			"Pa"
#define PRESSURE_PSF		"psf"
#define PRESSURE_ATM		"atm"

#define DENISTY_LB_FT3		"lbm/ft^3"
#define DENISTY_KG_M3		"kg/m^3"
#define DENISTY_LB_IN3		"lbm/in^3"


class Units{

public:	
	Units(){}
	Units(UNITS_T Type);
	Units(const char unitSymbol[]);
	~Units(){}
	operator = (Units& u);
	UNITS_T type;
	char  name[NAME_SIZE];
	double slope;
	double bias;
};

extern double fromMKS(double data, Units& unit);
extern double toMKS(double data, Units& unit);

#endif

