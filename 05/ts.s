	.global		start,sum
	.text

	start:
		ldr	sp, =stack_top

		bl	main
	
		b	stop

	stop:	
		b	stop

	sum:
		
		// stack pointer needs to be pointing 
		// in an address that we can write actually.
<<<<<<< HEAD
		ldr	sp, =stack_top	
=======
		ldr	sp, = stack_top
>>>>>>> 9230dadd41ff78da25af39af13a97b19cce05620

		stmfd	sp!, {fp, lr}
		
		//add	fp, sp, #4

		add	r0,r0,r1
		add	r0,r0,r2
		add	r0,r0,r3
		
		//sub	sp, fp, #4
	
		ldmfd	sp!, {fp, pc}
		//add	pc, lr, #0
