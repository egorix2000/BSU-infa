.386
.MODEL flat
.DATA
gcd	dd	?
.CODE

@lcm@8 PROC
	mov edi, edx
	
	mov esi, 0
	mov eax, [ecx + esi*4]
	inc esi
	begin_gcd_loop:

		mov ebx, [ecx + esi*4]
		begin_loop :
		cmp eax, ebx
			jz end_loop

			jg if_a_greater
			sub ebx, eax
			jmp begin_loop
			if_a_greater :
		sub eax, ebx
			jmp begin_loop
			end_loop :

	inc esi
	cmp esi, edi
	jl begin_gcd_loop

	mov gcd, eax
	
	mov esi, 0
	mov eax, 1

	begin_mul_loop:
	mov ebx, [ecx + esi*4]
	imul ebx
	inc esi
	cmp esi, edi
	jl begin_mul_loop
	
	cdq
	idiv gcd

	ret
@lcm@8 ENDP

END