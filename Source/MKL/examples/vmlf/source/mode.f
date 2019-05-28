	programm MKL_VML_TEST

	integer*2 VMLGETMODE

	include "mkl_vml.fi"
	include "func_interv.fi"

	integer*2 mode

	mode=0

	print *,"vmlSetMode/vmlGetMode example programm"
	print *,""
	print *,""

	mode=VMLGETMODE()
	print 10,"Default value of vmlMode: ",mode,"h"
	call PrintTextVmlMode(mode)

	mode=ior(VML_LA,ior(VML_FLOAT_CONSISTENT,VML_ERRMODE_IGNORE))
	call VMLSETMODE(mode)
	mode=VMLGETMODE()
	print 10,"Value of vmlMode after using vmlSetMode: ",mode,"h"
	call PrintTextVmlMode(mode)

10	format(A,Z,A)

	end

	
	subroutine PrintTextVmlMode(mode)

	include "mkl_vml.fi"

	integer*2 mode
	integer*2 mask
	
	mask=VML_ACCURACY_MASK
	if(iand(mode,mask).eq.1) print *,"VML_LA"
	if(iand(mode,mask).eq.2) print *,"VML_HA"

	mask=VML_FPUMODE_MASK
	if(iand(mode,mask).eq.0) print *,"VML_DEFAULT_PRECISION"
	if(iand(mode,mask).eq.16) print *,"VML_FLOAT_CONSISTENT "
	if(iand(mode,mask).eq.32) print *,"VML_DOUBLE_CONSISTENT"
	if(iand(mode,mask).eq.48) print *,"VML_RESTORE"

	mask=VML_ERRMODE_MASK
	if(iand(mode,VML_ERRMODE_IGNORE).eq.VML_ERRMODE_IGNORE) print *,"VML_ERRMODE_IGNORE"
	if(iand(mode,VML_ERRMODE_ERRNO).eq.VML_ERRMODE_ERRNO) print *,"VML_ERRMODE_ERRNO"
	if(iand(mode,VML_ERRMODE_STDERR).eq.VML_ERRMODE_STDERR) print *,"VML_ERRMODE_STDERR"
	if(iand(mode,VML_ERRMODE_EXCEPT).eq.VML_ERRMODE_EXCEPT) print *,"VML_ERRMODE_EXCEPT"
	if(iand(mode,VML_ERRMODE_CALLBACK).eq.VML_ERRMODE_CALLBACK) print *,"VML_ERRMODE_CALLBACK"

	end
