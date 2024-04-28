@echo off

set "godotPath=C:\Users\lukas\Downloads\Godot_v4.2.2-stable_mono_win64\Godot_v4.2.2-stable_mono_win64\Godot_v4.2.2-stable_mono_win64.exe"

scons

if !ERRORLEVEL! EQU 0 (
  echo Error: scons build failed. Exiting...
  exit /b 1
)

set "currentDir=%cd%"

:searchLoop
cd ..

if exist "*.godot" (
  echo Found Godot project in "%cd%".
  goto foundProject
)

if "%cd%" EQU "%currentDir%" (
  echo Godot project not found in any parent directories.
  exit /b 1
)

goto searchLoop

:foundProject

"%godotPath%" godot -e

popd