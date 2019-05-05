.386
PUBLIC _solveEquation
.model flat
.code

_solveEquation proc
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8] ; first param (a)
	cmp eax, 0
	jz AEqualsZero
	jnz ANotEqualsZero
AEqualsZero:
	mov eax, [ebp + 12]; second param (b)
	cmp eax, 0
	jz BEqualsZero
	jnz BNotEqualsZero
BEqualsZero: ; x = R
	mov ebx, [ebp + 20]
	mov al, 1
	xchg al, [ebx]
	jmp _End
BNotEqualsZero: ; no x
	mov ebx, [ebp + 16]
	mov al, 0
	xchg [ebx], al
	jmp _End
ANotEqualsZero:
	mov eax, [ebp + 12] ; secon param (b)
	mov ebx, -1
	imul ebx
	mov ebx, [ebp + 8]
	idiv ebx
	jmp _End
_End:
	pop ebp 
	ret 
_solveEquation endp

end