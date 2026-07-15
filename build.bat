@echo off
REM ── FlappyChicken Build Script ─────────────────────────────
REM Usage: build.bat [Debug|Release]  (default: Debug)

cd /d "%~dp0"

set CONFIG=%1
if "%CONFIG%"=="" set CONFIG=Debug

echo.
echo === Configuring FlappyChicken (%CONFIG%) ===
cmake -B build -G "Visual Studio 17 2022" -A x64
if %ERRORLEVEL% NEQ 0 exit /b %ERRORLEVEL%

echo.
echo === Building FlappyChicken (%CONFIG%) ===
cmake --build build --config %CONFIG%
if %ERRORLEVEL% NEQ 0 exit /b %ERRORLEVEL%

echo.
echo === Build complete! ===
echo Output: build\%CONFIG%\FlappyChicken.exe
echo.
echo To run: build\%CONFIG%\FlappyChicken.exe
