	/*	ARM assembly programming
	
		Algorithm to evaluate if given possitive number is even.

		sets -->R0 to 1 if yes, 0 otherwise.
			sets R0--> -1 if number is not greater than 0.
	*/
	.text
	.global start

start:
	
	ldr	r1, =a
	ldr	r1, [r1]	

	mov	r0, #-1
	
	/* check if greater than zero	*/
	
	cmp	r1, #0


	blt	stop
	beq	stop
			

	/*	possitive number greater than zero,
		change condition on register 0.	 */
	mov	r0, #0

loop:
	sub	r1, r1,	#2
	
	cmp	r1, #0

	beq	even
	blt	stop
	bgt	loop

stop:
	b	stop

	.data
	
	a:	.word	34

even:
	mov	r0,#1
	b	stop


