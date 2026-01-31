CC = gcc
CFLAGS = -Wall -I../UTest -I../../../Software/NUCLEO-F091RC/Inc -DDEBUG_PRINTS_ENABLED
DUT_SRC_PATH = ../../../Software/NUCLEO-F091RC/Src/

default: all

all: test_gm_histogram.o gm_histogram.o stub_gm_circular_buffer.o
	$(CC) $(CFLAGS) -o test_gm_histogram test_gm_histogram.o gm_histogram.o stub_gm_circular_buffer.o


test_gm_histogram.o: test_gm_histogram.c
	$(CC) $(CFLAGS) -c test_gm_histogram.c

gm_histogram.o: $(DUT_SRC_PATH)/gm_histogram.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_histogram.c

stub_gm_circular_buffer.o: stub_gm_circular_buffer.c
	$(CC) $(CFLAGS) -c stub_gm_circular_buffer.c

clean: 
	$(RM) *.o *.exe
