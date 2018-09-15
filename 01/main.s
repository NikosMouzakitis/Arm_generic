/*	ARM assembly programming
	adding elements of an array */
	.text
	.global start

start:	ldr	sp, = stack_top 
	bl	sum

stop:

	swi	0x11
	b	stop

sum:	
	stmfd	sp!, {r0 - r4, lr}
	mov	r0, #0
	ldr	r1, =Array
	ldr	r2, =N

	ldr	r2, [r2]

loop:
	ldr	r3, [r1], #4
	add	r0, r0, r3
	sub	r2, r2, #1
	cmp	r2, #0
	bne	loop
	ldr	r4, =Result
	add	r5, r0, #0	
	str	r0, [r4]

	ldmfd	sp!, {r0 - r4, pc}
	b	stop
	.data
	
	N:	.word	6
	Array:	.word	1, 2, 3, 4, 5, 6
	Result:	.word	0

