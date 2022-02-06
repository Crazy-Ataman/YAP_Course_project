.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/StaticLib.lib
ExitProcess PROTO :DWORD

EXTRN Date: proc
EXTRN Time: proc
EXTRN OutputInt: proc
EXTRN OutputStr: proc

.stack 4096

.CONST
	L1 DWORD 0
	L2 DWORD 10
	L3 DWORD 50
	L4 BYTE "Положительное", 0
	L5 BYTE "Отрицательное", 0
	L6 DWORD 13

.data
	buffer BYTE 256 dup(0)
	maindate DWORD ?
	maintime DWORD ?
	mainx DWORD 0
	mainy DWORD 0
	mainpos DWORD ?
	mainneg DWORD ?
	mainres DWORD ?
	maini DWORD 0
	mainpolish DWORD 0

.code

fposneg PROC fposnegn : DWORD, fposnegpos : DWORD, fposnegneg : DWORD
	mov eax, fposnegn
	cmp eax, L1
	jae m0
	jb m1
	je m1
m0:
	push fposnegpos
	jmp local0
	jmp e0
m1:
	push fposnegneg
	jmp local0
e0:
local0:
	pop eax
	ret
fposneg ENDP

pow PROC powx : DWORD
	push powx
	push powx
	pop eax
	pop ebx
	mul ebx
	push eax
	pop powx
	push powx
	jmp local1
local1:
	pop eax
	ret
pow ENDP

main PROC
	call Date
	push eax
	pop maindate
	push maindate
	call OutputStr
	call Time
	push eax
	pop maintime
	push maintime
	call OutputStr
	push L2
	pop mainy
	push mainy
	push L3
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop mainx
	push mainx
	call OutputInt
	push offset L4
	pop mainpos
	push offset L5
	pop mainneg
	push mainx
	push mainpos
	push mainneg
	pop edx
	pop edx
	pop edx
	push mainneg
	push mainpos
	push mainx
	call fposneg
	push eax
	pop mainres
	push mainres
	call OutputStr
	push L6
	pop maini
	push maini
	call OutputInt
	push mainy
	push mainy
	pop edx
	push mainy
	call pow
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop mainpolish
	push mainpolish
	call OutputInt
	call ExitProcess
main ENDP
end main