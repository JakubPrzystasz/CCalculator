IDIR=inc/
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=/obj
LDIR=/lib

LIBS=-lm -Wall

_DEPS = calculator.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = calculator.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

FILES = $(wildcard lib/*.c)

all: lib.o
	$(CC) -o main.o $< $(CFLAGS) $(LIBS)

lib.o:  $(wildcard lib/*.c)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 

