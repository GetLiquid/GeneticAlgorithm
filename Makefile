cc=gcc
CFLAGS=
EXEC=gene
SOURCE=gene.c critter.c util.c equation.c

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXEC) $(SOURCE)
