
MissileAtlDemops.dll: dlldata.obj MissileAtlDemo_p.obj MissileAtlDemo_i.obj
	link /dll /out:MissileAtlDemops.dll /def:MissileAtlDemops.def /entry:DllMain dlldata.obj MissileAtlDemo_p.obj MissileAtlDemo_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MissileAtlDemops.dll
	@del MissileAtlDemops.lib
	@del MissileAtlDemops.exp
	@del dlldata.obj
	@del MissileAtlDemo_p.obj
	@del MissileAtlDemo_i.obj
