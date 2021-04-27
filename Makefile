CC = gcc
CFLAGS = -O4 -Wall -I $(INCLUDE_DIR)
LIBS = -lpthread -lm 
INCLUDE_DIR = /home/class_projects/thread-cycles
O_FILES = $(INCLUDE_DIR)/fcycmmt.o $(INCLUDE_DIR)/clock.o

all: mm 

mm: mm.c mm.h
	$(CC) $(CFLAGS) -o mm mm.c $(O_FILES) $(LIBS)

clean:
	rm -f *.o mm *~



