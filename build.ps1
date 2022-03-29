remove-item *.o
remove-item *.elf
#@REM arm-none-eabi-as hc32l110_boot.s -mcpu=cortex-m0 -mthumb -o hc32l110_boot.o
#@REM arm-none-eabi-gcc.exe main.c -I C:\ode\hc32l110\lib\include -mcpu=cortex-m0 -mthumb -ffreestanding -specs=nosys.specs -c -o main.o
#@REM arm-none-eabi-ld hc32l110_boot.o hc32l110_system.o main.o -nostdlib -LC:\tools\gcc-arm-none-eabi-10.3-2021.10-win32\lib\gcc\arm-none-eabi\10.3.1\libgcc.a -T ..\hc32l110x6.ld -o blink.elf
#arm-none-eabi-gcc.exe foo.c -I C:\ode\hc32l110\lib\include -O3 -mcpu=cortex-m0 -mthumb -ffreestanding -nostdlib -S -o foo.S -LC:\tools\gcc-arm-none-eabi-10.3-2021.10-win32\lib\gcc\arm-none-eabi\10.3.1\libgcc.a -lgcc 
arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -flto -nostdlib -I.\lib\include .\mcu\main.c -L.\lib\bin -lhc32l110_ddl_core -lhc32l110_ddl_gpio -lgcc -T .\hc32l110x6.ld -o blink.elf
arm-none-eabi-objdump -S blink.elf > blink.elf.dump  
arm-none-eabi-objcopy -O binary blink.elf blink.bin
:\ode\HC32L.Download\HC32L.Download\bin\Debug\net6.0\HC32L.Download.exe .\blink.elf -p COM7






# arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib -I C:\ode\hc32l110\lib\include -c -o .\lib\bin\hc32l110_ddl_core.o .\lib\src\hc32l110_ddl_core.c
# arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib -I C:\ode\hc32l110\lib\include -c -o .\lib\bin\hc32l110_boot.o .\lib\src\hc32l110_boot.c
# arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib -I C:\ode\hc32l110\lib\include -c -o .\lib\bin\hc32l110_ddl_gpio.o .\lib\src\hc32l110_ddl_gpio.c

# arm-none-eabi-ar rcs .\lib\bin\libhc32l110_ddl_core.a .\lib\bin\hc32l110_boot.o .\lib\bin\hc32l110_ddl_core.o

# arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib -I C:\ode\hc32l110\lib\include -c -o .\lib\bin\hc32l110_boot.o .\lib\src\hc32l110_boot.c
# arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib -I C:\ode\hc32l110\lib\include -c -o .\mcu\main.o .\mcu\main.c


# -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib -I C:\ode\hc32l110\lib\include -c -o .\mcu\main.o .\mcu\main.c

# arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -nostdlib .\mcu\hc32l110_boot.o .\mcu\main.o -L.\lib\bin -lhc32l110_ddl_core -lhc32l110_ddl_gpio -lgcc -T .\hc32l110x6.ld -o blink.elf

# arm-none-eabi-objdump -S .\lib\bin\hc32l110_boot.o > .\lib\bin\hc32l110_boot.o.dump


arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -ffreestanding -nostdlib -I C:\ode\hc32l110\lib\include .\mcu\main.c -L.\lib\bin -lhc32l110_ddl_core -lhc32l110_ddl_gpio -lgcc -T .\hc32l110x6.ld -o blink.elf