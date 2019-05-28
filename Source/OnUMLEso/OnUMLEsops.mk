
OnUMLEsops.dll: dlldata.obj OnUMLEso_p.obj OnUMLEso_i.obj
	link /dll /out:OnUMLEsops.dll /def:OnUMLEsops.def /entry:DllMain dlldata.obj OnUMLEso_p.obj OnUMLEso_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OnUMLEsops.dll
	@del OnUMLEsops.lib
	@del OnUMLEsops.exp
	@del dlldata.obj
	@del OnUMLEso_p.obj
	@del OnUMLEso_i.obj
