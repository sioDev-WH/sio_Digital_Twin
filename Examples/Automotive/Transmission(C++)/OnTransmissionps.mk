
OnTransmissionps.dll: dlldata.obj OnTransmission_p.obj OnTransmission_i.obj
	link /dll /out:OnTransmissionps.dll /def:OnTransmissionps.def /entry:DllMain dlldata.obj OnTransmission_p.obj OnTransmission_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OnTransmissionps.dll
	@del OnTransmissionps.lib
	@del OnTransmissionps.exp
	@del dlldata.obj
	@del OnTransmission_p.obj
	@del OnTransmission_i.obj
