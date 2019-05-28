#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mkl_types.h"

void main(void)
{
    MKLVersion ver;
    MKLGetVersion(&ver);

printf("MajorVersion	%d\n",ver.MajorVersion);
printf("MinorVersion	%d\n",ver.MinorVersion);
printf("BuildNumber	%d\n",ver.BuildNumber);
printf("BuildDate	%s\n",ver.BuildDate);
printf("Processor	%s\n",ver.Processor);
printf("InterfaceString	%s\n",ver.Interface);
printf("================================================================\n");
printf("\n");

}
