@echo off

echo ÕýÔÚÉ¾³ýBuild
:rm_build
if exist Build rd Build /q /s
timeout 1
if exist Build goto rm_build

mkdir Build
cd Build
cmake -DCMAKE_UTILITY_ROOT=E:\GitRepo\CMakeUtility -DJSONCPP_ROOT=G:\ThirdParty\jsoncpp\1.8.1\Visual_Studio_15_2017\Win64\MD\Debug ..

pause