CC  = gcc
INC =
OPC = -g -c
LIB =
LIBH =
EXECUTABLES = ej1.0.out ej1.1.out ej2.0.out ej2.1.out

.c.o:
	$(CC) $(OPC) $(INC) $<

all: $(EXECUTABLES)

ej1.0.out: ej1.0.o
	$(CC) -o $@ $< $(LIB)

ej1.1.out: ej1.1.o
	$(CC) -o $@ $< $(LIB)

ej2.0.out: ej2.0.o
	$(CC) -o $@ $< $(LIB)

ej2.1.out: ej2.1.o
	$(CC) -o $@ $< $(LIBH)

clean:
	rm -fr *~ *.o $(EXECUTABLES)

