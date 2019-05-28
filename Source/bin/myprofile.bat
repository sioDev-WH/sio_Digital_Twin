COPY IsDaeCOSolver.dll IsDaeCOSolver.sav
PREP /OM /FT IsDaeCOSolver.dll
COPY IsDaeCOSolver._ll IsDaeCOSolver.dll
PROFILE /I IsDaeCOSolver /O IsDaeCOSolver C:\DistComponents\RtsOnTransmission\Test\OnSimTestClient.exe
PREP /M IsDaeCOSolver
PLIST IsDaeCOSolver > IsDaeCOSolver.txt
COPY IsDaeCOSolver.sav IsDaeCOSolver.dll

