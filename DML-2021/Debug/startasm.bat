@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 
   ml /c /coff /Zi Source.txt.asm
   link /OPT:NOREF /DEBUG /SUBSYSTEM:CONSOLE libucrt.lib Source.txt.obj
   Source.txt.exe
pause
   