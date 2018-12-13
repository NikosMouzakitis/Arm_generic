.global _Reset

_Reset:
	ldr	sp, =stack_top
	bl	c_entry
	swi	0x0	
