CC = gcc
CFLAGS = -Wall -I../UTest -I../../../Software/NUCLEO-F091RC/Inc -DDEBUG_PRINTS_ENABLED
DUT_SRC_PATH = ../../../Software/NUCLEO-F091RC/Src/

default: all

all: test_gm_circular_buffer.o gm_circular_buffer.o 
	$(CC) $(CFLAGS) -o test_gm_circular_buffer test_gm_circular_buffer.o gm_circular_buffer.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

gm_circular_buffer.o: $(DUT_SRC_PATH)/gm_circular_buffer.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_circular_buffer.c

clean: 
	$(RM) *.o *.exe
