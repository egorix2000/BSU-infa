.386
PUBLIC _calcExpressionInt@8 ; calling convention: __stcall, data type - double word
PUBLIC	@calcExpressionShort@8 ; calling convention: __fastcall, data type - word
.model flat
.code

_calcExpressionInt@8 proc
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	mov ebx, [ebp + 12]
	cmp eax, ebx ; compare param1 and param2
	jl ALessB
	je AEqualsB
	jg AGreaterB
ALessB:
	mov eax, [ebp + 12] ; eax = b
	mov ebx, [ebp + 8]; ebx = a
	add ebx, 1
	cdq
	idiv ebx
	jmp _End
AEqualsB:
	mov eax, 4
	jmp _End
AGreaterB:
	mov eax, [ebp + 8] ; eax = a
	mov ebx, [ebp + 12]; ebx = b
	mov ecx, [ebp + 8]; ecx = a
	imul ecx
	imul ecx; eax = a^3
	sub eax, 5
	cdq
	idiv ebx; eax = (a^3 - 5) / b
	jmp _End
_End:
	pop ebp 
	ret 8
_calcExpressionInt@8 endp


@calcExpressionShort@8 proc
	mov ax, cx
	mov bx, dx
	cmp ax, bx
	jl A_less_B
	je A_equals_to_B
	jg A_greater_B
A_less_B:
	xchg ax, bx ; ax = b, bx = a
	add bx, 1
	cwd 
	idiv bx ; ax = b / (a + 1)
	jmp _End
A_equals_to_B:
	mov ax, 4
	jmp _End
A_greater_B:
	imul ax ; ax = a^2
	imul cx
	sub ax, 5 ; ax = a^3 - 5
	cwd 
	idiv bx ; ax = (a^3 - 5) / b
	jmp _End
_End:
	ret
@calcExpressionShort@8 endp

end