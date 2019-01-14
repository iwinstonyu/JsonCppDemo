@echo off

set "folder=Solution\\VS2010_32"

echo ÕıÔÚÉ¾³ı%folder%
if exist %folder% rd %folder% /q /s
timeout 2

md %folder%
cd %folder%
cmake -G "Visual Studio 15 2017" ../../../

pause