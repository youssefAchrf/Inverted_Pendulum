@echo off

cd .

if "%1"=="" ("D:\matlab2021\bin\win64\gmake"  -f wrapper.mk all) else ("D:\matlab2021\bin\win64\gmake"  -f wrapper.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1