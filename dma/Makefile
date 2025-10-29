TARGET = MKL25Z4_project

SRC_DIR = src
INC_DIR = inc
STARTUP_DIR = startup
LINKER_DIR = linker

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
GDB = arm-none-eabi-gdb

MCU = cortex-m0plus
CFLAGS = -mcpu=$(MCU) -mthumb -O0 -g3 -Wall -ffunction-sections -fdata-sections \
         -I$(INC_DIR)
LDFLAGS = -L$(LINKER_DIR) -T$(LINKER_DIR)/MKL25Z4_Project_Debug.ld -nostartfiles -Wl,--gc-sections -lc -lgcc -lnosys


OPENOCD = openocd
OPENOCD_INTERFACE = /opt/homebrew/Cellar/open-ocd/0.12.0_1/share/openocd/scripts/interface/cmsis-dap.cfg
OPENOCD_TARGET    = /opt/homebrew/Cellar/open-ocd/0.12.0_1/share/openocd/scripts/target/kl25.cfg

C_SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(STARTUP_DIR)/*.c)
OBJECTS = $(C_SOURCES:.c=.o)

all: $(TARGET).elf

$(TARGET).elf: $(OBJECTS)
	@echo "Linking"
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	@echo "Build completed successfully"

%.o: %.c
	@echo "Compiling"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Running make clean"
	rm -f $(SRC_DIR)/*.o $(STARTUP_DIR)/*.o $(TARGET).elf $(TARGET).hex $(TARGET).bin

flash: $(TARGET).elf
	@echo "Flashing to board"
	$(OPENOCD) -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) \
		-c "program $(TARGET).elf verify reset exit"

debug: $(TARGET).elf
	$(GDB) $(TARGET).elf -ex "target remote localhost:3333"

flash-debug: $(TARGET).elf
	$(OPENOCD) -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) -c "program $(TARGET).elf verify reset" &
	@echo "Running OpenOCD server..."
	sleep 2
	$(GDB) $(TARGET).elf -ex "target remote localhost:3333"
