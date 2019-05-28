@echo off

SETLOCAL EnableDelayedExpansion

set INIT_DIR="C:/External"
set REPO_URL="https://github.com/open-source-parsers/jsoncpp.git"
set REPO_VER="1.8.4"
set GENERATOR="Visual Studio 15 2017"
echo GENERATOR: %GENERATOR%

rem generator with underline
set generator_ul=%GENERATOR: =_%
echo generator_ul: %generator_ul%

for /f "tokens=4* delims=/" %%i in (%REPO_URL%) do (
	set repo_name=%%i
)
for /f "tokens=1* delims=." %%i in ("%repo_name%") do (
	set repo_name=%%i
)
echo repo_name: %repo_name%

set repo_path=%INIT_DIR%/%repo_name%/%REPO_VER%
echo repo_path: %repo_path%

set install_prefix=%repo_path%/%generator_ul%

mkdir %repo_path%
cd /d %repo_path%

if not exist %repo_name% (
	echo "Try to download source code from %REPO_URL%..."
	git clone https://github.com/open-source-parsers/jsoncpp.git
	cd %repo_name%
	git checkout -b %REPO_VER% %REPO_VER%
	cd ..
)
cd %repo_name%
mkdir build 
cd build

rd /q /s %generator_ul%
:wait_rd_generator_ul
timeout 1
if exist %generator_ul% (
	goto wait_rd_generator_ul
)
mkdir %generator_ul%
cd %generator_ul%
cmake -G %GENERATOR% ../.. -DJSONCPP_WITH_CMAKE_PACKAGE=ON -DCMAKE_INSTALL_PREFIX=%install_prefix%
cmake --build . --config Debug --target install || goto :error

:error
pause