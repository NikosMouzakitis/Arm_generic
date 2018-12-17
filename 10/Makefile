
all:
	arm-none-eabi-as  -mcpu=arm926ej-s -g startup.s -o startup.o
	arm-none-eabi-as  -mcpu=arm926ej-s -g division.s -o division.o
	arm-none-eabi-gcc -c -mcpu=arm926ej-s -g test.c -o test.o
	arm-none-eabi-ld -T test.ld test.o startup.o division.o -o test.elf  -L /usr/lib/gcc/arm-none-eabi/6.3.1 -lgcc 
	arm-none-eabi-objcopy -O binary test.elf test.bin
	qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel test.bin	
clean:
	rm startup.o test.o test.bin test.elf
