/*	ARM assembly programming
	Integer Division algorithm. 
 */
	.text
	.global start

start:
	ldr	sp, = stack_top 

	ldr	r2, =a
	ldr	r3, =b
	ldr	r2, [r2]
	ldr	r3, [r3]
	mov	r4, #0	
	mov	r5, #1

gcd:	
	cmp	r2, r3	
	subgt	r2, r2, r3
	add	r4, r4, #1
	
	cmp	r2, r3
	addlt	r5, #1	

	cmp	r5,#1	
	beq	gcd	


stop:
	b	stop

	.data
	
	a:	.word	101	
	b:	.word	2
	k:	.word	0
	mflag:	.word	1

