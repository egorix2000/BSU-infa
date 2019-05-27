.386
.MODEL flat
.DATA
arraySize	dd	?
k	dd	?
.CODE

_shift PROC
	push ebp
	mov ebp, esp

	mov eax, [ebp+12] 
	mov ebx, [ebp+16]
	mul ebx

	pop ebp
	ret
_shift ENDP

END