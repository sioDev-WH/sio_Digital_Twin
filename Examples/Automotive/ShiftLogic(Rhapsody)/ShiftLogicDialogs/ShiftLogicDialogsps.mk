
ShiftLogicDialogsps.dll: dlldata.obj ShiftLogicDialogs_p.obj ShiftLogicDialogs_i.obj
	link /dll /out:ShiftLogicDialogsps.dll /def:ShiftLogicDialogsps.def /entry:DllMain dlldata.obj ShiftLogicDialogs_p.obj ShiftLogicDialogs_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ShiftLogicDialogsps.dll
	@del ShiftLogicDialogsps.lib
	@del ShiftLogicDialogsps.exp
	@del dlldata.obj
	@del ShiftLogicDialogs_p.obj
	@del ShiftLogicDialogs_i.obj
