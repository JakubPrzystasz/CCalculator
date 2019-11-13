IDIR =inc
CC=gcc
CFLAGS=-lm -Wall -I$(IDIR)

ODIR=obj
LDIR =lib

LIBS=-lm

_DEPS = calculator.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = calculator.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 

