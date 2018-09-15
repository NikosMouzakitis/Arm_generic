src=main

all:
	arm-none-eabi-as -o $(src).o $(src).s
	arm-none-eabi-ld -T $(src).ld -o $(src).elf $(src).o
	arm-none-eabi-nm $(src).elf
	arm-none-eabi-objcopy -O binary $(src).elf $(src).bin
	qemu-system-arm -M versatilepb -kernel $(src).bin -nographic -serial /dev/null

clean:
	rm $(src).elf $(src).o $(src).bin
