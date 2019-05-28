
RtsOnTransmissionps.dll: dlldata.obj RtsOnTransmission_p.obj RtsOnTransmission_i.obj
	link /dll /out:RtsOnTransmissionps.dll /def:RtsOnTransmissionps.def /entry:DllMain dlldata.obj RtsOnTransmission_p.obj RtsOnTransmission_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del RtsOnTransmissionps.dll
	@del RtsOnTransmissionps.lib
	@del RtsOnTransmissionps.exp
	@del dlldata.obj
	@del RtsOnTransmission_p.obj
	@del RtsOnTransmission_i.obj
