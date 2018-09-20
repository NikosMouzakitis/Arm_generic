// address in hardware.
volatile unsigned int * const UART0DR = (unsigned int *) 0x101f1000;
volatile char data;;

	//print from uart0
void print_uart0(const char *s) {
	while(*s!='\0') {
		*UART0DR = (unsigned int) (*s);
		s++;
	}
}

char read_uart0(void)
{
	return *UART0DR;
}

void c_entry() 
{
	print_uart0("Enter a number!\n");
	data = read_uart0();
	print_uart0(&data);	
}
