cc=gcc
CFLAGS=-g
EXEC=gene
SOURCE=main.c tree.c critter.c util.c

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXEC) $(SOURCE)

clean:
	rm -rf gene *.dSYM *.o
