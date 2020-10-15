CC = gcc
CFLAGS = -Wall -fpic -I./Inc
DUT_SRC_PATH = ./Src
STUB_SRC_PATH = ./DriversPCSimulation
default: all

all: simulation.o \
	gm_circular_buffer.o \
	gm_display_updater.o \
	gm_display_labels.o \
	gm_measurement_calculator.o \
	gm_logger.o \
	gm_display_hw.o \
	gm_logger_sim.o \
	ssd1306_i2c_sim.o \
	ssd1306.o \
	fonts.o
	$(CC) $(CFLAGS) -shared -o simulation.so simulation.o \
		gm_circular_buffer.o \
		gm_display_updater.o \
		gm_display_labels.o \
		gm_measurement_calculator.o \
		gm_logger.o \
		gm_display_hw.o \
		gm_logger_sim.o \
		ssd1306_i2c_sim.o \
		ssd1306.o \
		fonts.o

main.o:  simulation.c
	$(CC) $(CFLAGS) -c simulation.c

gm_circular_buffer.o:  $(DUT_SRC_PATH)/gm_circular_buffer.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_circular_buffer.c

gm_display_updater.o:  $(DUT_SRC_PATH)/gm_display_updater.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_display_updater.c

gm_display_labels.o:  $(DUT_SRC_PATH)/gm_display_labels.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_display_labels.c

gm_measurement_calculator.o:  $(DUT_SRC_PATH)/gm_measurement_calculator.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_measurement_calculator.c	

gm_logger.o:  $(DUT_SRC_PATH)/gm_logger.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_logger.c	

gm_display_hw.o:  $(DUT_SRC_PATH)/gm_display_hw.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_display_hw.c	

ssd1306.o:  $(DUT_SRC_PATH)/ssd1306.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/ssd1306.c	

fonts.o:  $(DUT_SRC_PATH)/fonts.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/fonts.c	


ssd1306_i2c_sim.o:  $(STUB_SRC_PATH)/ssd1306_i2c_sim.c
	$(CC) $(CFLAGS) -c $(STUB_SRC_PATH)/ssd1306_i2c_sim.c	

gm_logger_sim.o:  $(STUB_SRC_PATH)/gm_logger_sim.c
	$(CC) $(CFLAGS) -c $(STUB_SRC_PATH)/gm_logger_sim.c	


clean: 
	$(RM) *.so *.o *~
