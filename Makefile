cc=gcc
CFLAGS=-g
EXEC=gene
SOURCE=main.c tree.c critter.c util.c mergesort.c

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXEC) $(SOURCE)

clean:
	rm -rf gene *.dSYM *.o
