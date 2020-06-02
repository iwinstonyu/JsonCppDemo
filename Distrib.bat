@echo off

if exist Build rd /q /s Build
mkdir Build
cd Build
cmake -DCMAKE_UTILITY_ROOT=E:\GitRepo\CMakeUtility -DJSONCPP_ROOT=G:\ThirdParty\jsoncpp\1.8.1\Visual_Studio_15_2017\Win64\MD\Debug ..

pause