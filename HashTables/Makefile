IDIR   = include
CC     = clang
CFLAGS = -I$(IDIR)

DEPS   = Set.h RBT.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

IntArraySet: CompSetMain.o IntArraySet.o
	$(CC) -Wall -o IntArraySet CompSetMain.o IntArraySet.o -I.

BitArraySet: CompSetMain.o BitArraySet.o
	$(CC) -Wall -o BitArraySet CompSetMain.o BitArraySet.o -I.

HashSet: CompSetMain.o HashSet.o
	$(CC) -Wall -o HashSet CompSetMain.o HashSet.o -I.

.PHONY: clean

clean:
	rm -f *.o IntArraySet BitArraySet
