remove-item *.o
remove-item *.elf
#@REM arm-none-eabi-as hc32l110_boot.s -mcpu=cortex-m0 -mthumb -o hc32l110_boot.o
#@REM arm-none-eabi-gcc.exe main.c -I C:\ode\hc32l110\lib\include -mcpu=cortex-m0 -mthumb -ffreestanding -specs=nosys.specs -c -o main.o
#@REM arm-none-eabi-ld hc32l110_boot.o hc32l110_system.o main.o -nostdlib -LC:\tools\gcc-arm-none-eabi-10.3-2021.10-win32\lib\gcc\arm-none-eabi\10.3.1\libgcc.a -T ..\hc32l110x6.ld -o blink.elf
#arm-none-eabi-gcc.exe foo.c -I C:\ode\hc32l110\lib\include -O3 -mcpu=cortex-m0 -mthumb -ffreestanding -nostdlib -S -o foo.S -LC:\tools\gcc-arm-none-eabi-10.3-2021.10-win32\lib\gcc\arm-none-eabi\10.3.1\libgcc.a -lgcc 
arm-none-eabi-gcc.exe -T .\hc32l110x6.ld -O3  .\mcu\hc32l110_boot.c .\mcu\main.c .\lib\src\hc32l110_ddl_core.c  .\lib\src\hc32l110_ddl_gpio.c -I C:\ode\hc32l110\lib\include -I C:\ode\hc32l110\cmsis  -mcpu=cortex-m0 -mthumb -ffreestanding -nostdlib -o blink.elf -LC:\tools\gcc-arm-none-eabi-10.3-2021.10-win32\lib\gcc\arm-none-eabi\10.3.1\libgcc.a -lgcc 
arm-none-eabi-objdump -S blink.elf > blink.elf.dump  
# arm-none-eabi-readelf -a blink.elf > blink.elf.txt  
arm-none-eabi-objcopy -O binary blink.elf blink.bin
C:\ode\HC32L.Download\HC32L.Download\bin\Debug\net6.0\HC32L.Download.exe .\blink.elf -p COM7