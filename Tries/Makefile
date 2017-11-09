IDIR   = include
CC     = clang
CFLAGS = -g -I$(IDIR)

DEPS   = Set.h Trie.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestTrie: TestTrieMain.o Trie.o
	$(CC) -Wall -o TestTrieMain TestTrieMain.o Trie.o -I.

.PHONY: clean

clean:
	rm -f *.o TestTrieMain
