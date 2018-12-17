/*	Implemented possitive integer division function */

.global division

division:
	mov	r5, r0	/* Dividend */
	mov	r6, r1	/* Divisor */
	mov	r0, #0	/* return value */
	mov	r3, #0	/* for checking */	

back:
	sub	r5, r5, r6
	cmp	r5, r0	//checking if we are under zero.	
	addge	r0, #1	// executed only if r5 >= 0.
	
	cmp     r5, r0	
	blt	exit
	b	back	

exit:	
	bx	lr
