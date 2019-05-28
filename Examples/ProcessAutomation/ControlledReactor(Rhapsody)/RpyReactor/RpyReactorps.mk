
RpyReactorps.dll: dlldata.obj RpyReactor_p.obj RpyReactor_i.obj
	link /dll /out:RpyReactorps.dll /def:RpyReactorps.def /entry:DllMain dlldata.obj RpyReactor_p.obj RpyReactor_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del RpyReactorps.dll
	@del RpyReactorps.lib
	@del RpyReactorps.exp
	@del dlldata.obj
	@del RpyReactor_p.obj
	@del RpyReactor_i.obj
