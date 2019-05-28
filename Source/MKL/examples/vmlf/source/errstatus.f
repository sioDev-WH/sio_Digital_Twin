	programm MKL_VML_TEST

	integer*2 VMLGETERRSTATUS

	include "mkl_vml.fi"
	include "func_interv.fi"

	integer errst;

	print *,"vmlSetErrStatus/vmlGetErrStatus/vmlClearErrStatus example programm"
	print *,""
	print *,""

	errst=VMLGETERRSTATUS()

	print 10,"Initial value of vmlErrStatus: ",errst,"h"
	call PrintTextVmlErrStatus(errst)

	errst=VML_STATUS_BADMEM
	call VMLSETERRSTATUS(errst)
	errst=VMLGETERRSTATUS()
	print 10,"Value of vmlErrStatus after using vmlSetErrStatus: ",errst,"h"
	call PrintTextVmlErrStatus(errst)

	call VMLCLEARERRSTATUS()
	errst=VMLGETERRSTATUS()
	print 10,"Value of vmlErrStatus after using vmlClearErrStatus: ",errst,"h"
	call PrintTextVmlErrStatus(errst)

10	format(A,Z,A)

	end

	subroutine PrintTextVmlErrStatus(errst)

	include "mkl_vml.fi"

	integer*2 errst
	
	if(errst.eq.VML_STATUS_OK       ) print *,"VML_STATUS_OK       "
	if(errst.eq.VML_STATUS_BADSIZE  ) print *,"VML_STATUS_BADSIZE  "
	if(errst.eq.VML_STATUS_BADMEM   ) print *,"VML_STATUS_BADMEM   "
	if(errst.eq.VML_STATUS_ERRDOM   ) print *,"VML_STATUS_ERRDOM   "
	if(errst.eq.VML_STATUS_SING     ) print *,"VML_STATUS_SING     "
	if(errst.eq.VML_STATUS_OVERFLOW ) print *,"VML_STATUS_OVERFLOW "
	if(errst.eq.VML_STATUS_UNDERFLOW) print *,"VML_STATUS_UNDERFLOW"
	
	end
