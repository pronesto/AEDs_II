IDIR   = include
CC     = clang
CFLAGS = -I$(IDIR)

DEPS   = Set.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ArraySet: CompSetMain.o ArraySet.o
	$(CC) -Wall -o ArraySet CompSetMain.o ArraySet.o -I.

IsortArraySet: CompSetMain.o IsortArraySet.o
	$(CC) -Wall -o IsortArraySet CompSetMain.o IsortArraySet.o -I.

QsortArraySet: CompSetMain.o QsortArraySet.o
	$(CC) -Wall -o QsortArraySet CompSetMain.o QsortArraySet.o -I.

TreeMain: CompSetMain.o TreeSet.o
	$(CC) -Wall -o ArraySet CompSetMain.o TreeSet.o -I.

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ArraySet IsortArraySet QsortArraySet TreeMain
