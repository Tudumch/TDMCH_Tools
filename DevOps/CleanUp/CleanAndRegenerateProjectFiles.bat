@echo off

:: The script makes a clean-up of the project by deleting folders with temporary files. 
:: Then recompile the project and generate a file for VS.

set PLATFORM=Win64
set PROJECT_PURE_NAME=""
set PLUGINS_NAMES_FILE=PluginsToCleanup.txt

:: Check if the UE_ENGINE_PATH environment variable is set
if not defined UE_ENGINE_PATH (
    echo Error: UE_ENGINE_PATH environment variable is not set.
    echo Please set the UE_ENGINE_PATH variable to the Unreal Engine installation path.
    echo Example: setx UE_ENGINE_PATH "C:\Program Files\Epic Games\UE_5.3\Engine"

    pause
    exit /b 1
)
set RUN_BUILD_PATH=%UE_ENGINE_PATH%\Build\BatchFiles\Build.bat

echo Unreal Engine Path: "%UE_ENGINE_PATH%"

:: Change directory to the project directory
cd "%~dp0"



:: Find the first .uproject file in the directory
for /R %%i in (*.uproject) do (
    set "UPROJECT=%%i"

    :: If ProjectName was not set - parse it from UPROJECT path
    if %PROJECT_PURE_NAME%=="" set PROJECT_PURE_NAME=%%~ni
)

echo Project search successfully complete!

:: Remove intermediate dirs and files
set DIRS_TO_REMOVE=Intermediate DerivedDataCache Binaries Binaries Build
set FILES_TO_REMOVE=*.sln

for %%a in (%DIRS_TO_REMOVE%) do (
    rmdir /S /Q %%a
)

for %%a in (%FILES_TO_REMOVE%) do (
   del %%a
)
echo Removing temporary files in project successfully complete!

:: Remove intermediate dirs and files in marked plugin folders
set PLUGINS_FOLDER=%~dp0Plugins

setlocal EnableDelayedExpansion
for /F "delims=" %%a in (%PLUGINS_NAMES_FILE%) do (
    set PLUGIN_FULL_PATH=%PLUGINS_FOLDER%\%%a

    cd /d "!PLUGIN_FULL_PATH!"

    for %%i in (%DIRS_TO_REMOVE%) do (
        rmdir /S /Q %%i
        )

    for %%f in (%FILES_TO_REMOVE%) do (
        del %%f
        )
    )

echo Removing temporary files in plugins successfully complete!


:: Run UnrealBuildTool to generate project files
cd "%~dp0"

call "%RUN_BUILD_PATH%" "%PROJECT_PURE_NAME%"Editor "%PLATFORM%" Development "%UPROJECT%" -waitmutex

"%UE_ENGINE_PATH%\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -projectfiles -project="%UPROJECT%" -game -rocket -progress

pause
goto:EOF