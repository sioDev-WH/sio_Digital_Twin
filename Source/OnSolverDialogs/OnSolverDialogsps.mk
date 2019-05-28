
OnSolverDialogsps.dll: dlldata.obj OnSolverDialogs_p.obj OnSolverDialogs_i.obj
	link /dll /out:OnSolverDialogsps.dll /def:OnSolverDialogsps.def /entry:DllMain dlldata.obj OnSolverDialogs_p.obj OnSolverDialogs_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OnSolverDialogsps.dll
	@del OnSolverDialogsps.lib
	@del OnSolverDialogsps.exp
	@del dlldata.obj
	@del OnSolverDialogs_p.obj
	@del OnSolverDialogs_i.obj
