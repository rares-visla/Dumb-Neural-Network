CC=gcc

SDIR=src
ODIR=build

LIBS=-lm

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%, $(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c #(deps here)
	$(CC) -c -o $@ $<

neuralnet: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 