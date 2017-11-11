IDIR   = include
CC     = clang
CFLAGS = -g -I$(IDIR)

DEPS   = Tree.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Trie: TestTrieMain.o Trie.o Tree.o
	$(CC) -Wall -o TrieMain TestTrieMain.o Trie.o -I.

BinT: TestTrieMain.o BinT.o
	$(CC) -Wall -o BinTMain TestTrieMain.o BinT.o -I.

RBT: TestTrieMain.o RBT.o
	$(CC) -Wall -o RBTMain TestTrieMain.o RBT.o -I.

.PHONY: clean

clean:
	rm -f *.o TrieMain BinTMain RBTMain
