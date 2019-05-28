	programm MKL_VML_TEST

	include "mkl_vml.fi"
	include "func_interv.fi"

	integer*4 VMLGETERRORCALLBACK
	integer*4 errcb

	print *,"vmlSetErrorCallBack/vmlGetErrorCallBack/vmlClearErrorCallBack example programm"
	print *,""
	print *,""

	errcb=VMLGETERRORCALLBACK()
	print 10,"Initial address of CallBack function: ",errcb,"h"

	call VMLSETERRORCALLBACK(StubCallBack)
	errcb=VMLGETERRORCALLBACK()
	print 10,"Address of CallBack function after using vmlSetErrorCallBack: ",errcb,"h"

	call VMLCLEARERRORCALLBACK()
	errcb=VMLGETERRORCALLBACK()
	print 10,"Address of CallBack function after using vmlClearErrorCallBack: ",errcb,"h"

10	format (A,Z,A)

	end

	
	integer function StubCallBack(p)

	StubCallBack=0

	end
