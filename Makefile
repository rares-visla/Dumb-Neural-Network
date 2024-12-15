CC=gcc

SDIR=src
ODIR=build

LIBS=-lm

_DEPS = neuralnet.h datasets.h
DEPS = $(patsubst %,$(SDIR)/%, $(_DEPS))

_OBJ = neuralnet.o main.o
OBJ = $(patsubst %,$(ODIR)/%, $(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -Wall -o $@ $<

neuralnet: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 
	rm neuralnet