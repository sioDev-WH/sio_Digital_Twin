
RpyPDEReactorps.dll: dlldata.obj RpyPDEReactor_p.obj RpyPDEReactor_i.obj
	link /dll /out:RpyPDEReactorps.dll /def:RpyPDEReactorps.def /entry:DllMain dlldata.obj RpyPDEReactor_p.obj RpyPDEReactor_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del RpyPDEReactorps.dll
	@del RpyPDEReactorps.lib
	@del RpyPDEReactorps.exp
	@del dlldata.obj
	@del RpyPDEReactor_p.obj
	@del RpyPDEReactor_i.obj
