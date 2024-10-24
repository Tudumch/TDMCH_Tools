@echo off

:: Puts Cleanup script files into UE-project root directory.

:: Changing path to project root dir
cd ".."
cd ".."
cd ".."
cd ".."

:: Creating script folder structure and copying initial files
set PROJECT_DIR=%cd%
set PLUGIN_FOLDERS_STRUCTURE=DevOps\CleanAndRegenerate
set FULL_SCRIPT_PATH=%PROJECT_DIR%\%PLUGIN_FOLDERS_STRUCTURE%

mkdir %FULL_SCRIPT_PATH%

xcopy /Y /s %~dp0\ScriptFiles\** %FULL_SCRIPT_PATH%
::mklink "%PROJECT_DIR%\CleanAndRegenerate.bat" "%FULL_SCRIPT_PATH%\CleanAndRegenerate.bat"

echo.
echo CleanUp script setup was finished. You can make additional tweaks for it into "YOUR_PROJECT_FOLDER/DevOps/CleanAndRegenerate/config.bat"
echo.
pause