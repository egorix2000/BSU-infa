.386
PUBLIC _Swap
.model flat
.code

_Swap proc
	push ebp
	mov ebp, esp
	mov esi, [ebp + 8]
	mov edi, [ebp + 12]
	mov eax, [esi]
	xchg eax, [edi]
	mov [esi], eax
	pop ebp 
	ret 
_Swap endp

end 