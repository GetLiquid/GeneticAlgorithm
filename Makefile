cc=gcc
CFLAGS=-g
EXEC=gene
SOURCE=gene.c critter.c util.c equation.c

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXEC) $(SOURCE)

clean:
	rm -rf gene *.dSYM *.o
