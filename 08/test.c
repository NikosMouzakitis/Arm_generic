	// address in hardware for the UART peripheral.
volatile unsigned int * const UART0DR = (unsigned int *) 0x101f1000;
static char converted[16];
static char help[16];

void convert(int source)
{
	int tmp;
	int j;	
	int num = 0;
	int res = source;
	int ak;
	int i;

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
	convert(a);
	print_uart0(help);
	
}
