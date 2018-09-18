src=ts
c_code=main

all:
	arm-none-eabi-as -o $(src).o $(src).s
	arm-none-eabi-gcc -c $(c_code).c
	arm-none-eabi-ld -T $(src).ld -o $(src).elf $(c_code).o  $(src).o
	arm-none-eabi-objcopy -O binary $(src).elf $(src).bin
	qemu-system-arm -M versatilepb -kernel $(src).bin -nographic -serial /dev/null

clean:
	rm $(src).elf $(src).o $(src).bin $(c_code).o
