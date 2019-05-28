
ShiftLogicAtlDemops.dll: dlldata.obj ShiftLogicAtlDemo_p.obj ShiftLogicAtlDemo_i.obj
	link /dll /out:ShiftLogicAtlDemops.dll /def:ShiftLogicAtlDemops.def /entry:DllMain dlldata.obj ShiftLogicAtlDemo_p.obj ShiftLogicAtlDemo_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ShiftLogicAtlDemops.dll
	@del ShiftLogicAtlDemops.lib
	@del ShiftLogicAtlDemops.exp
	@del dlldata.obj
	@del ShiftLogicAtlDemo_p.obj
	@del ShiftLogicAtlDemo_i.obj
