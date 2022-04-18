ninja 
arm-none-eabi-objcopy -O binary blinky.elf blinky.bin
arm-none-eabi-objcopy -O ihex blinky.elf blinky.hex
arm-none-eabi-objdump -S .\blinky.elf > .\blinky.elf.dump
arm-none-eabi-readelf -a .\blinky.elf > .\blinky.elf.all

C:\ode\HC32L.Download\HC32L.Download\bin\Debug\net6.0\hc32tool.exe download .\blinky.elf COM7
