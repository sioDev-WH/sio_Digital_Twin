#include <iostream.h>
#include <math.h>
#include "IsGlobals.h"


// This file is used to calculate "uround" used by the stepper

void		dlamc2(int &beta, 
					int &t, 
					bool &rnd, 
					double &eps, 
					int &emin, 
					double &rmin, 
					int &emax, 
					double &rmax);

void dlamc1(int &beta, 
			  int &t,
			  bool &rnd, 
			  bool &ieee1);

double dlamc3( double a, double b );

void dlamc4( int &emin, double &start, int &base );

void dlamc5( int &beta, int &p, int &emin, bool &ieee, int &emax, double &rmax );


double dlamch( char cmach ){
//
//  -- lapack auxiliary routine (version 2.0) --
//     univ. of tennessee, univ. of california berkeley, nag ltd.,
//     courant institute, argonne national lab, and rice university
//     october 31, 1992
//
//     .. scalar arguments ..
//     ..
//
//  purpose
//  =======
//
//  dlamch determines double precision machine parameters.
//
//  arguments
//  =========
//
//  cmach   (input) character//1
//          specifies the value to be returned by dlamch:
//          = 'e' or 'e',   dlamch := eps
//          = 's' or 's ,   dlamch := sfmin
//          = 'b' or 'b',   dlamch := base
//          = 'p' or 'p',   dlamch := eps*base
//          = 'n' or 'n',   dlamch := t
//          = 'r' or 'r',   dlamch := rnd
//          = 'm' or 'm',   dlamch := emin
//          = 'u' or 'u',   dlamch := rmin
//          = 'l' or 'l',   dlamch := emax
//          = 'o' or 'o',   dlamch := rmax
//
//          where
//
//          eps   = relative machine precision
//          sfmin = safe minimum, such that 1/sfmin does not overflow
//          base  = base of the machine
//          prec  = eps*base
//          t     = number of (base) digits in the mantissa
//          rnd   = 1.0 when rounding occurs in addition, 0.0 otherwise
//          emin  = minimum exponent before (gradual) underflow
//          rmin  = underflow threshold - base**(emin-1)
//          emax  = largest exponent before overflow
//          rmax  = overflow threshold  - (base**emax)*(1-eps)
//
// =====================================================================
//
//     .. parameters ..
      double   one, zero;
      one = 1.0e+0; 
	  zero = 0.0e+0;
//     ..
//     .. local scalars ..
      static bool	first;
	  bool  lrnd;
      int	beta;
	  int   imax;
	  int   imin;
	  int   it;
      static double	base;
	  static double	emax;
	  static double	emin;
	  static double	eps;
	  static double	prec;
	  double	rmach;
	  static double	rmax;
	  static double	rmin;
	  static double	rnd;
	  static double	sfmin;
	  double	small;
	  static double	t;

//       save      first, eps, sfmin, base, t, rnd, emin, rmin,emax, rmax, prec (could be static vars?)

      first=true;
      if( first ){
         first = false;
         dlamc2( beta, it, lrnd, eps, imin, rmin, imax, rmax );
         base = beta;
         t = it;
         if( lrnd ){
            rnd = one;
            eps =  pow(base,( 1-it ) ) / 2;
		 }
         else{
            rnd = zero;
            eps = pow(base,( 1-it ));
         }
         prec = eps*base;
         emin = imin;
         emax = imax;
         sfmin = rmin;
         small = one / rmax;
         if( small >= sfmin ){
//
//           use small plus a bit, to avoid the possibility of rounding
//           causing overflow when computing  1/sfmin.
//
            sfmin = small*( one+eps );
         }
      }
//


	  switch(cmach){
		case ('E'):
		case ('e'):
			rmach = eps;
			break;
		case ('S'):
		case ('s'):
			rmach = sfmin;
			break;
		case ('B'):
		case ('b'):
			rmach = base;
			break;
		case ('P'):
		case ('p'):
			rmach = prec;
			break;
		case ('N'):
		case ('n'):
			rmach =  t;
			break;
		case ('R'):
		case ('r'):
			rmach = rnd;
			break;
		case ('M'):
		case ('m'):
			rmach = emin;
			break;
		case ('U'):
		case ('u'):
			rmach = rmin;
			break;
		case ('L'):
		case ('l'):
			rmach = emax;
			break;
		case ('O'):
		case ('o'):
			rmach = rmax;
			break;
		default:
			cerr << "Illegal input value for dlamch(char) \n";
			break;
	  }

      return rmach;
}


//
////**********************************************************************
//
void dlamc1(int &beta, 
		  int &t,
		  bool &rnd, 
		  bool &ieee1 ){
//
//  -- lapack auxiliary routine (version 2.0) --
//     univ. of tennessee, univ. of california berkeley, nag ltd.,
//     courant institute, argonne national lab, and rice university
//     october 31, 1992
//     ..
//
//  purpose
//  =======
//
//  dlamc1 determines the machine parameters given by beta, t, rnd, and
//  ieee1.
//
//  arguments
//  =========
//
//  beta    (output) integer
//          the base of the machine.
//
//  t       (output) integer
//          the number of ( beta ) digits in the mantissa.
//
//  rnd     (output) logical
//          specifies whether proper rounding  ( rnd = .true. )  or
//          chopping  ( rnd = .false. )  occurs in addition. this may not
//          be a reliable guide to the way in which the machine performs
//          its arithmetic.
//
//  ieee1   (output) logical
//          specifies whether rounding appears to be done in the ieee
//          'round to nearest' style.
//
//  further details
//  ===============
//
//  the routine is based on the routine  envron  by malcolm and
//  incorporates suggestions by gentleman and marovich. see
//
//     malcolm m. a. (1972) algorithms to reveal properties of
//        floating-point arithmetic. comms. of the acm, 15, 949-951.
//
//     gentleman w. m. and marovich s. b. (1974) more on algorithms
//        that reveal properties of floating point arithmetic units.
//        comms. of the acm, 17, 276-277.
//
// =====================================================================
//
//     .. local scalars ..
      static bool            first, lieee1, lrnd;
      static int            lbeta, lt;
      double   a, b, c, f, one, qtr, savec, t1, t2;

//     ..
//     .. save statement ..
      // save               first, lieee1, lbeta, lrnd, lt
//     ..
//     .. data statements ..
      first=true;
//     ..
//     .. executable statements ..
//
      if( first ){
         first = false;
         one = 1;
//
//        lbeta,  lieee1,  lt and  lrnd  are the  local values  of  beta,
//        ieee1, t and rnd.
//
//        throughout this routine  we use the function  dlamc3  to ensure
//        that relevant values are  stored and not held in registers,  or
//        are not affected by optimizers.
//
//        compute  a = 2.0**m  with the  smallest positive integer m such
//        that
//
//           fl( a + 1.0 ) = a.
//
         a = 1;
         c = 1;
//
//+       while( c.eq.one )loop
		 do{
            a = 2*a;
            c = dlamc3( a, one );
            c = dlamc3( c, -a );
         } while( c == one );
//+       end while
//
//        now compute  b = 2.0**m  with the smallest positive integer m
//        such that
//
//           fl( a + b ) .gt. a.
//
         b = 1;
         c = dlamc3( a, b );
//
//+       while( c.eq.a )loop
		 do{
            b = 2*b;
            c = dlamc3( a, b );
		 }while( c==a );
//+       end while
//
//        now compute the base.  a and c  are neighbouring floating point
//        numbers  in the  interval  ( beta**t, beta**( t + 1 ) )  and so
//        their difference is beta. adding 0.25 to c is to ensure that it
//        is truncated to beta and not ( beta - 1 ).
//
         qtr = one / 4;
         savec = c;
         c = dlamc3( c, -a );
         lbeta = (int) (c + qtr);
//
//        now determine whether rounding or chopping occurs,  by adding a
//        bit  less  than  beta/2  and a  bit  more  than  beta/2  to  a.
//
         b = lbeta;
         f = dlamc3( b / 2, -b / 100 );
         c = dlamc3( f, a );
         if( c==a )
            lrnd = true;
         else
            lrnd = false;

         f = dlamc3( b / 2, b / 100 );
         c = dlamc3( f, a );

         if(  lrnd  && ( c==a ) )
			lrnd = false;
//
//        try and decide whether rounding is done in the  ieee  'round to
//        nearest' style. b/2 is half a unit in the last place of the two
//        numbers a and savec. furthermore, a is even, i.e. has last  bit
//        zero, and savec is odd. thus adding b/2 to a should not  change
//        a, but adding b/2 to savec should change savec.
//
         t1 = dlamc3( b / 2, a );
         t2 = dlamc3( b / 2, savec );
         lieee1 = ( t1 > a ) && ( t2 > savec ) && lrnd;
//
//        now find  the  mantissa, t.  it should  be the  integer part of
//        log to the base beta of a,  however it is safer to determine  t
//        by powering.  so we find t as the smallest positive integer for
//        which
//
//           fl( beta**t + 1.0 ) = 1.0.
//
         lt = 0;
         a = 1;
         c = 1;
//
//+       while( c.eq.one )loop
		 do{
            lt = lt + 1;
            a = a*lbeta;
            c = dlamc3( a, one );
            c = dlamc3( c, -a );
		 } while( c==one );
//+       end while
//
      }
//
      beta = lbeta;
      t = lt;
      rnd = lrnd;
      ieee1 = lieee1;
      return;
}
//
//***********************************************************************
//

	void		dlamc2(int &beta, 
					int &t, 
					bool &rnd, 
					double &eps, 
					int &emin, 
					double &rmin, 
					int &emax, 
					double &rmax){
//
//  -- lapack auxiliary routine (version 2.0) --
//     univ. of tennessee, univ. of california berkeley, nag ltd.,
//     courant institute, argonne national lab, and rice university
//     october 31, 1992
//
//     .. scalar arguments ..

//
//  purpose
//  =======
//
//  dlamc2 determines the machine parameters specified in its argument
//  list.
//
//  arguments
//  =========
//
//  beta    (output) integer
//          the base of the machine.
//
//  t       (output) integer
//          the number of ( beta ) digits in the mantissa.
//
//  rnd     (output) logical
//          specifies whether proper rounding  ( rnd = .true. )  or
//          chopping  ( rnd = .false. )  occurs in addition. this may not
//          be a reliable guide to the way in which the machine performs
//          its arithmetic.
//
//  eps     (output) double precision
//          the smallest positive number such that
//
//             fl( 1.0 - eps ) .lt. 1.0,
//
//          where fl denotes the computed value.
//
//  emin    (output) integer
//          the minimum exponent before (gradual) underflow occurs.
//
//  rmin    (output) double precision
//          the smallest normalized number for the machine, given by
//          base**( emin - 1 ), where  base  is the floating point value
//          of beta.
//
//  emax    (output) integer
//          the maximum exponent before overflow occurs.
//
//  rmax    (output) double precision
//          the largest positive number for the machine, given by
//          base**emax * ( 1 - eps ), where  base  is the floating point
//          value of beta.
//
//  further details
//  ===============
//
//  the computation of  eps  is based on a routine paranoia by
//  w. kahan of the university of california at berkeley.
//
// =====================================================================
//
//     .. local scalars ..
      static bool  first;
	  bool	ieee;
	  static bool	iwarn;
	  bool	lieee1;
	  bool	lrnd;
      int   gnmin;
	  int	gpmin;
	  int	i;
	  static int	lbeta;
	  static int	lemax;
	  static int	lemin;
	  static int	lt;
      int   ngnmin;
	  int	ngpmin;
      static double leps, lrmax,lrmin;
	  double          a, b, c, half, one, rbase;
      double		  sixth, small, third, two, zero;


//     ..
//     .. save statement ..
//     save               first, iwarn, lbeta, lemax, lemin, leps, lrmax,lrmin, lt
//     ..
//     .. data statements ..
      first=true; 
	  iwarn=false;
//     ..
//     .. executable statements ..
//
      if( first ){
         first = false;
         zero = 0;
         one = 1;
         two = 2;
//
//        lbeta, lt, lrnd, leps, lemin and lrmin  are the local values of
//        beta, t, rnd, eps, emin and rmin.
//
//        throughout this routine  we use the function  dlamc3  to ensure
//        that relevant values are stored  and not held in registers,  or
//        are not affected by optimizers.
//
//        dlamc1 returns the parameters  lbeta, lt, lrnd and lieee1.
//
         dlamc1( lbeta, lt, lrnd, lieee1 );
//
//        start to find eps.
//
         b = lbeta;
         a = pow(b,-lt);
         leps = a;
//
//        try some tricks to see whether or not this is the correct  eps.
//
         b = two / 3;
         half = one / 2;
         sixth = dlamc3( b, -half );
         third = dlamc3( sixth, sixth );
         b = dlamc3( third, -half );
         b = dlamc3( b, sixth );
         b = fabs( b );
         if( b < leps ) b = leps;
//
         leps = 1;
//
//+       while( ( leps.gt.b ).and.( b.gt.zero ) )loop
	     do{
            leps = b;
            c = dlamc3( half*leps, ( pow(two,5) )*( pow(leps,2) ) );
            c = dlamc3( half, -c );
            b = dlamc3( half, c );
            c = dlamc3( half, -b );
            b = dlamc3( half, c );
		 }
		 while( ( leps > b ) && ( b > zero ) );
			//+       end while
//
         if( a < leps )leps = a;
//
//        computation of eps complete.
//
//        now find  emin.  let a = + or - 1, and + or - (1 + base**(-3)).
//        keep dividing  a by beta until (gradual) underflow occurs. this
//        is detected when we cannot recover the previous a.
//
         rbase = one / lbeta;
         small = one;
         for(i =0;i<3;i++)
            small = dlamc3( small*rbase, zero );

         a = dlamc3( one, small );
		 double minusOne = -one;
		 double minusA = -a;
         dlamc4( ngpmin, one, lbeta );
         dlamc4( ngnmin, minusOne, lbeta );
         dlamc4( gpmin, a, lbeta );
         dlamc4( gnmin, minusA, lbeta );
         ieee = false;
//
         if( ( ngpmin == ngnmin ) && ( gpmin == gnmin ) ){
            if( ngpmin == gpmin ) lemin = ngpmin;
//            ( non twos-complement machines, no gradual underflow; e.g.,  vax )
            else if( ( gpmin-ngpmin )==3 ){
               lemin = ngpmin - 1 + lt;
               ieee = true;
//            ( non twos-complement machines, with gradual underflow;
//              e.g., ieee standard followers )
            }
			else{
               lemin = IMIN( ngpmin, gpmin );
//            ( a guess; no known machine )
               iwarn = true;
			}
//
		 }
		 else if( ( ngpmin==gpmin ) && ( ngnmin==gnmin ) ){
            if( abs( ngpmin-ngnmin )==1 ) lemin = IMAX( ngpmin, ngnmin );
//            ( twos-complement machines, no gradual underflow;
//              e.g., cyber 205 )
            else{
               lemin = IMIN( ngpmin, ngnmin );
//            ( a guess; no known machine )
               iwarn = true;
            }
		 }
         else if( ( abs( ngpmin-ngnmin ) == 1 ) && ( gpmin == gnmin ) ) {
            if( ( gpmin-IMIN( ngpmin, ngnmin ) ) == 3 )
               lemin = IMAX( ngpmin, ngnmin ) - 1 + lt;
//            ( twos-complement machines with gradual underflow;
//              no known machine )
            else{
               lemin = IMIN( ngpmin, ngnmin );
//            ( a guess; no known machine )
               iwarn = true;
			}
//
         }
		 else{
            lemin = IMIN( ngpmin, ngnmin);
			lemin = IMIN(lemin,gpmin);
			lemin = IMIN(lemin, gnmin );
//         ( a guess; no known machine )
            iwarn = true;
		 }
         
////*
// comment out this if block if emin is ok
         if( iwarn ){
            first = true;
            cerr << "warning. the value emin may be incorrect:-   emin = " << lemin << "\n";
			cerr << "Please supply emin explicitly.\n";
         }
////*
//
//        assume ieee arithmetic if we found denormalised  numbers above,
//        or if arithmetic seems to round in the  ieee style,  determined
//        in routine dlamc1. a true ieee machine should have both  things
//        true; however, faulty machines may have one or the other.
//
         ieee = ieee || lieee1;
//
//        compute  rmin by successive division by  beta. we could compute
//        rmin as base**( emin - 1 ),  but some machines underflow during
//        this computation.
//
         lrmin = 1;
         for(i = 1;i<= 1 - lemin;i++)
            lrmin = dlamc3( lrmin*rbase, zero );
//
//        finally, call dlamc5 to compute emax and rmax.
//
         dlamc5( lbeta, lt, lemin, ieee, lemax, lrmax );
      }
//
      beta = lbeta;
      t = lt;
      rnd = lrnd;
      eps = leps;
      emin = lemin;
      rmin = lrmin;
      emax = lemax;
      rmax = lrmax;
	  
	  return;
}
//
//***********************************************************************
//
double dlamc3( double a, double b ){
//
// -- lapack auxiliary routine (version 2.0) --
//    univ. of tennessee, univ. of california berkeley, nag ltd.,
//    courant institute, argonne national lab, and rice university
//    october 31, 1992
//
//     .. scalar arguments ..

//     ..
//
//  purpose
//  =======
//
//  dlamc3  is intended to force  a  and  b  to be stored prior to doing
//  the addition of  a  and  b ,  for use in situations where optimizers
//  might hold one of these in a register.
//
//  arguments
//  =========
//
//  a, b    (input) double precision
//          the values a and b.
//
// =====================================================================
//
//     .. executable statements ..
//
      return a + b;
}
//
//
//***********************************************************************
//
void dlamc4( int &emin, double &start, int &base ){
//
//  -- lapack auxiliary routine (version 2.0) --
//     univ. of tennessee, univ. of california berkeley, nag ltd.,
//     courant institute, argonne national lab, and rice university
//     october 31, 1992
//
//     .. scalar arguments ..
//     ..
//
//  purpose
//  =======
//
//  dlamc4 is a service routine for dlamc2.
//
//  arguments
//  =========
//
//  emin    (output) emin
//          the minimum exponent before (gradual) underflow, computed by
//          setting a = start and dividing by base until the previous a
//          can not be recovered.
//
//  start   (input) double precision
//          the starting point for determining emin.
//
//  base    (input) integer
//          the base of the machine.
//
// =====================================================================
//
//     .. local scalars ..
      int            i;
      double   a, b1, b2, c1, c2, d1, d2, one, rbase, zero;

//     ..
//     .. executable statements ..
//
      a = start;
      one = 1;
      rbase = one / base;
      zero = 0;
      emin = 1;
      b1 = dlamc3( a*rbase, zero );
      c1 = a;
      c2 = a;
      d1 = a;
      d2 = a;
//+    while( ( c1.eq.a ).and.( c2.eq.a ).and.
//    $       ( d1.eq.a ).and.( d2.eq.a )      )loop

	  do{
         emin = emin - 1;
         a = b1;
         b1 = dlamc3( a / base, zero );
         c1 = dlamc3( b1*base, zero );
         d1 = zero;
         for(i = 1; i<=base;i++)
            d1 = d1 + b1;
         b2 = dlamc3( a*rbase, zero );
         c2 = dlamc3( b2 / rbase, zero );
         d2 = zero;
         for(i = 1; i<= base;i++)
            d2 = d2 + b2;
	  }while( (c1==a)&&(c2==a)&&(d1==a)&&(d2==a));
//+    end while
//
}


//
//***********************************************************************
//
void dlamc5( int &beta, int &p, int &emin, bool &ieee, int &emax, double &rmax ){
//
//  -- lapack auxiliary routine (version 2.0) --
//     univ. of tennessee, univ. of california berkeley, nag ltd.,
//     courant institute, argonne national lab, and rice university
//     october 31, 1992
//
//     .. scalar arguments ..

//     ..
//
//  purpose
//  =======
//
//  dlamc5 attempts to compute rmax, the largest machine floating-point
//  number, without overflow.  it assumes that emax + abs(emin) sum
//  approximately to a power of 2.  it will fail on machines where this
//  assumption does not hold, for example, the cyber 205 (emin = -28625,
//  emax = 28718).  it will also fail if the value supplied for emin is
//  too large (i.e. too close to zero), probably with overflow.
//
//  arguments
//  =========
//
//  beta    (input) integer
//          the base of floating-point arithmetic.
//
//  p       (input) integer
//          the number of base beta digits in the mantissa of a
//          floating-point value.
//
//  emin    (input) integer
//          the minimum exponent before (gradual) underflow.
//
//  ieee    (input) logical
//          a logical flag specifying whether or not the arithmetic
//          system is thought to comply with the ieee standard.
//
//  emax    (output) integer
//          the largest exponent before overflow
//
//  rmax    (output) double precision
//          the largest machine floating-point number.
//
// =====================================================================
//
//     .. parameters ..
      double   zero, one;

      zero = 0.0e0;
	  one = 1.0e0;

//     ..
//     .. local scalars ..
      int   exbits, expsum, i, lexp, nbits, xtry, uexp;
      double   oldy, recbas, y, z;

//     ..
//     .. executable statements ..
//
//     first compute lexp and uexp, two powers of 2 that bound
//     abs(emin). we then assume that emax + abs(emin) will sum
//     approximately to the bound that is closest to abs(emin).
//     (emax is the exponent of the required number rmax).
//
      lexp = 1;
      exbits = 1;

      xtry = lexp*2;
      do{
         lexp = xtry;
         exbits = exbits + 1;
		 xtry = lexp*2;
      }while( xtry <= (-emin));

      if( lexp == -emin )
         uexp = lexp;
      else{
         uexp = xtry;
         exbits = exbits + 1;
	  }

//
//     now -lexp is less than or equal to emin, and -uexp is greater
//     than or equal to emin. exbits is the number of bits needed to
//     store the exponent.
//
      if( ( uexp+emin ) > ( -lexp-emin ) )
         expsum = 2*lexp;
      else
         expsum = 2*uexp;

//
//     expsum is the exponent range, approximately equal to
//     emax - emin + 1 .
//
      emax = expsum + emin - 1;
      nbits = 1 + exbits + p;
//
//     nbits is the total number of bits needed to store a
//     floating-point number.
//
      if( (  (nbits%2 ) == 1 ) && ( beta == 2 ) )
//
//        either there are an odd number of bits used to store a
//        floating-point number, which is unlikely, or some bits are
//        not used in the representation of numbers, which is possible,
//        (e.g. cray machines) or the mantissa has an implicit bit,
//        (e.g. ieee machines, dec vax machines), which is perhaps the
//        most likely. we have to assume the last alternative.
//        if this is true, then we need to reduce emax by one because
//        there must be some way of representing zero in an implicit-bit
//        system. on machines like cray, we are reducing emax by one
//        unnecessarily.
//
         emax = emax - 1;
//
      if( ieee )
//
//        assume we are on an ieee machine which reserves one exponent
//        for infinity and nan.
//
         emax = emax - 1;

//
//     now create rmax, the largest machine number, which should
//     be equal to (1.0 - beta**(-p)) * beta**emax .
//
//     first compute 1.0 - beta**(-p), being careful that the
//     result is less than 1.0 .
//
      recbas = one / beta;
      z = beta - one;
      y = zero;
      for(i = 1;i<= p;i++){
         z = z*recbas;
         if( y < one ) oldy = y;
         y = dlamc3( y, z );
	  }
      if( y >= one )  y = oldy;
//
//     now multiply by beta**emax to get rmax.
//
      for(i = 1; i<=emax;i++)
         y = dlamc3( y*beta, zero );

      rmax = y;
      return;
}

