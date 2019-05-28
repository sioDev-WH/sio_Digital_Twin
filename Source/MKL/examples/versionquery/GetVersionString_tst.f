      program GetVersionString

      character*80    buf

      call MKLGetVersionString(buf)
      print*,buf
      end
