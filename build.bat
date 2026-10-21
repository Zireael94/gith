@echo off
chcp 65001 >nul
setlocal

cd /d "%~dp0"

set "GCC=gcc"
where gcc >nul 2>nul
if errorlevel 1 goto try_local
goto build

:try_local
if exist "%~dp0.tools\w64devkit\bin\gcc.exe" (
    set "GCC=%~dp0.tools\w64devkit\bin\gcc.exe"
) else (
    echo [ERROR] gcc not found.
    echo         Install MinGW-w64, or put w64devkit in .tools\w64devkit
    exit /b 1
)

:build
echo Compiler: %GCC%
"%GCC%" -std=c11 -Wall -Wextra -Werror -O2 -o c_tutorial.exe c_tutorial.c
if errorlevel 1 (
    echo.
    echo [FAILED] compile error
    exit /b 1
)

echo.
echo [OK] built: c_tutorial.exe
echo Run it with:  c_tutorial.exe
