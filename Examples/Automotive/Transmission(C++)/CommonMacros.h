#ifndef _DEFINE_VAR_
#define _DEFINE_VAR_

#define define_var(VAR) double der_##VAR; double old_##VAR; double der_old_##VAR; \
                        Fdouble ad_##VAR; Fdouble der_ad_##VAR;

#endif