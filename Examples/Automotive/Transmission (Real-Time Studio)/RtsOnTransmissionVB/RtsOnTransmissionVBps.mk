
RtsOnTransmissionVBps.dll: dlldata.obj RtsOnTransmissionVB_p.obj RtsOnTransmissionVB_i.obj
	link /dll /out:RtsOnTransmissionVBps.dll /def:RtsOnTransmissionVBps.def /entry:DllMain dlldata.obj RtsOnTransmissionVB_p.obj RtsOnTransmissionVB_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del RtsOnTransmissionVBps.dll
	@del RtsOnTransmissionVBps.lib
	@del RtsOnTransmissionVBps.exp
	@del dlldata.obj
	@del RtsOnTransmissionVB_p.obj
	@del RtsOnTransmissionVB_i.obj
