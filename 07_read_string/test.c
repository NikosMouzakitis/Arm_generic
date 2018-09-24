// address in hardware.

volatile unsigned int * const UART0DR = (unsigned int *) 0x101f1000;
volatile char data[20];

//print from uart0

void print_uart0(const char *s) {

	while(*s!='\0') {
		*UART0DR = (unsigned int) (*s);
		s++;
	}
}


void read_uart0(void)
{
	char ch;
	
	int i = 0;

	while ( (ch = *UART0DR) != 0x000) {

		data[i] = ch;
		i++;
	}	

	data[i] = '\0';	

}


void c_entry() 
{
	print_uart0("type\n");
	
	read_uart0();

	print_uart0(&data);	
}
