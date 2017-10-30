IDIR   = include
CC     = clang
CFLAGS = -I$(IDIR)

DEPS   = Set.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ArraySet: CompSetMain.o ArraySet.o
	$(CC) -Wall -o ArraySet CompSetMain.o ArraySet.o -I.

SortedArraySet: CompSetMain.o SortedArraySet.o
	$(CC) -Wall -o SortedArraySet CompSetMain.o SortedArraySet.o -I.

TreeMain: CompSetMain.o TreeSet.o
	$(CC) -Wall -o ArraySet CompSetMain.o TreeSet.o -I.

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ArraySet SortedArraySet TreeMain
