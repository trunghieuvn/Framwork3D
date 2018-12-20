@echo off
title %~nx0
color 2
REM mode con lines=18 cols=70

set GameEngine=%cd%
set DIR=%cd%
set PRJ_WIN32_SLN="project/Framework.sln"

set BUILD_TOOL="C:\Program Files (x86)\Microsoft Visual Studio\2017\WDExpress\MSBuild\15.0\Bin"

:Start
cls
echo.
cd /d 	%GameEngine%
echo	%cd%
echo.
echo 	===============================================
echo 	===============================================
echo 	====================MENU=======================
echo 	===============================================
echo 	===============================================
echo.
echo 	1.Start
echo 	2.Update Head
echo 	3.Copy Data
echo 	4.Build WIN32
echo 	5.Build Android
echo 	99.Exit Application
echo.
set 	/p Chose= ^Your chose:
echo.

if %Chose% EQU 1 echo 	Your chose is 1
if %Chose% EQU 2 echo	You want to update Head
if %Chose% EQU 3 goto Copy
if %Chose% EQU 4 goto Build_Win32
if %Chose% EQU 5 goto Build_Android
if %Chose% EQU 99 exit
echo.



goto Start
exit

:Copy
	echo Copy data
	set folder="prj\Android\app\src\main\assets"
	cd /d %folder%
	for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)
	cd /d %GameEngine%
	xcopy /s "data" "prj\Android\app\src\main\assets"
	pause
	goto Start
	
:Build_Win32
	echo Build WIN32
	%BUILD_TOOL%\msbuild %PRJ_WIN32_SLN%
	pause
	goto Start
	
:Build_Android
	echo Build Android
	cd /d "prj\Android"
	call gradlew installDebug
	
	cd /d %GameEngine%
	cd /d "bin\apk"
	for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)
	cd /d %GameEngine%
	xcopy /s "prj\Android\app\build\outputs\apk" "bin\apk"
	pause
	goto Start