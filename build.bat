@echo off
REM Build script for Phonebook Management System (Windows)

set CC=gcc
set CFLAGS=-Wall -Wextra -std=c99 -I./include
set SRCDIR=src
set OBJDIR=obj
set BINDIR=bin
set TARGET=%BINDIR%\phonebook.exe

echo [Build] Creating directories...
if not exist %OBJDIR% mkdir %OBJDIR%
if not exist %BINDIR% mkdir %BINDIR%
if not exist data mkdir data

echo [Build] Compiling source files...
%CC% %CFLAGS% -c %SRCDIR%\main.c -o %OBJDIR%\main.o
%CC% %CFLAGS% -c %SRCDIR%\file.c -o %OBJDIR%\file.o
%CC% %CFLAGS% -c %SRCDIR%\add.c -o %OBJDIR%\add.o
%CC% %CFLAGS% -c %SRCDIR%\search.c -o %OBJDIR%\search.o
%CC% %CFLAGS% -c %SRCDIR%\update.c -o %OBJDIR%\update.o
%CC% %CFLAGS% -c %SRCDIR%\delete.c -o %OBJDIR%\delete.o

echo [Build] Linking executable...
%CC% %CFLAGS% %OBJDIR%\main.o %OBJDIR%\file.o %OBJDIR%\add.o %OBJDIR%\search.o %OBJDIR%\update.o %OBJDIR%\delete.o -o %TARGET%

if exist %TARGET% (
    echo [Build] Build successful: %TARGET%
) else (
    echo [Build] Build failed!
    exit /b 1
)

