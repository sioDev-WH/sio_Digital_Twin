
OnInitializationDialogsps.dll: dlldata.obj OnInitializationDialogs_p.obj OnInitializationDialogs_i.obj
	link /dll /out:OnInitializationDialogsps.dll /def:OnInitializationDialogsps.def /entry:DllMain dlldata.obj OnInitializationDialogs_p.obj OnInitializationDialogs_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OnInitializationDialogsps.dll
	@del OnInitializationDialogsps.lib
	@del OnInitializationDialogsps.exp
	@del dlldata.obj
	@del OnInitializationDialogs_p.obj
	@del OnInitializationDialogs_i.obj
