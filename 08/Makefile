
all:
	arm-none-eabi-as  -mcpu=arm926ej-s -g startup.s -o startup.o
	arm-none-eabi-gcc -c -mcpu=arm926ej-s -g test.c -o test.o
	arm-none-eabi-ld -T test.ld test.o startup.o -o test.elf
	arm-none-eabi-objcopy -O binary test.elf test.bin
	qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel test.bin	
clean:
	rm startup.o test.o test.bin test.elf
