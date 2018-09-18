	// address in hardware.
volatile unsigned int * const UART0DR = (unsigned int *) 0x101f1000;

	//print from uart0
void print_uart0(const char *s) {
	while(*s!='\0') {
		*UART0DR = (unsigned int) (*s);
		s++;
	}
}

void c_entry() 
{
	print_uart0("Hello user!\n");
	
}
