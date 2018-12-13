
//09-program	In this program we are getting from assembly the 
//		CPSR in a C variable and we can use it in our program
//		as we intend. Afterwards we are printing it on the 
//		terminal by using the function created in folder 08/.


//	Address in hardware for the UART peripheral.
volatile unsigned int * const UART0DR = (unsigned int *) 0x101f1000;
static char converted[16];
static char help[16];

//	Function that will convert an integer into actually mapped in ASCII
//	code characters to be displayed in the terminal peripheral.
void convert(int source)
{
	int tmp, i, j, ak, res;
	int num = 0;
	
	res = source;

	for(i = 0; i < 16; i++) {
		converted[i] = 0;
		help[i] = 0;
	}

	//finding the last bit.
	ak = res % 10;
	num++;
	res = source / 10;		
	converted[0] = ak;

	while(res > 0) {
		tmp = res % 10;
		converted[num] = tmp;
		num++;
		res = res/10;
	}

	for(i = 0; i < num; i++) {

		switch (converted[i]) {
			case 0: converted[i] = 48;
				break;
			case 1: converted[i] = 49;
				break;
			case 2: converted[i] = 50;
				break;
			case 3: converted[i] = 51;
				break;
			case 4: converted[i] = 52;
				break;
			case 5: converted[i] = 53;
				break;
			case 6: converted[i] = 54;
				break;
			case 7: converted[i] = 55;
				break;
			case 8: converted[i] = 56;
				break;
			case 9: converted[i] = 57;
				break;
		}
	}

	// inverting the characters written in the array in order to have the forward instead of backward number.
	for(i = num-1; i >= 0; i--) {
		help[j] = converted[i];
		j++;	
	}
}
static inline unsigned long asm_get_cpsr(void)
{
	unsigned long retval;
	__asm(" mrs r0, cpsr");
	
	__asm(" mov %0, r0"
		: "=r"(retval)
		: "0"(retval)	
			); 


	return retval;

}
//print from uart0
void print_uart0(const char *s) {

	while(*s!='\0') {
		*UART0DR = (unsigned int) (*s);
		s++;
	}
}

void c_entry() 
{
	int a =945;
	unsigned long  b;

	// getting in register-9 the CPSR(current-program-status-register value
	// asm (" mrs  r9, cpsr ");
	b = asm_get_cpsr();
	
	convert(b);
	print_uart0(help);
	
}
