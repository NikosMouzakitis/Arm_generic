all:	
	arm-none-eabi-as -mcpu=arm926ej-s -g  ts.s -o ts.o
	arm-none-eabi-gcc -c -mcpu=arm926ej-s -g t.c -o t.o
	arm-none-eabi-ld -T t.ld -o t.elf t.o ts.o
	arm-none-eabi-nm t.elf
	arm-none-eabi-objcopy -O binary t.elf t.bin
	qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel t.bin
clean:	
	rm ts.o t.o t.elf t.bin 
