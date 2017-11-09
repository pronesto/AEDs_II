#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "Trie.h"

/*
 * Generate a binary representation of the key.
 */
char* int2bin(int num) {
  // Remember: sizeof(char) == 1 always, always (defined in the C standard).
  int num_bits = CHAR_BIT * sizeof(int);
  char* str = (char*)malloc(num_bits + 1);
  str[num_bits] = '\0';
  for (int i = 0; i < num_bits; i++) {
    str[i] = num & (1 << i) ? '1' : '0';
  }
  return str;
}

/*
 * Prints the tree in dot format, using the auxiliary function printDot_aux.
 */
void printDot_aux(Apontador p) {
  if (!(p->reg)) {
    printf("  %lu [shape = point];\n", (long)p);
  } else {
    printf("  %lu [shape = box, label = \"%s(%d)\"];\n",
		    (long)p, int2bin(p->reg->chave), p->reg->chave);
  }
  if (p->esq)
    printf("  %lu -> %lu [label = 0]\n", (long)p, (long)p->esq);
  if (p->dir)
    printf("  %lu -> %lu [label = 1]\n", (long)p, (long)p->dir);
}

void printDot(Apontador p) {
  printf("\ndigraph tree {\n  graph[rankdir=LR]\n");
  Central(p, &printDot_aux);
  printf("}\n");
}

int gen(const int MAX_KEY) {
  return random() % MAX_KEY + 1;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Syntaxe: %s num_nodes\n", argv[0]);
    return 1;
  } else {
    Apontador trie;
    inicializa(&trie);
    int i;
    const int MAX_NUM_KEYS = atoi(argv[1]);
    //
    // Inserts elements in the tree.
    for (i = 0; i < MAX_NUM_KEYS; i++) {
      Registro *reg = (Registro*) malloc(sizeof(Registro));
      reg->chave = gen(MAX_NUM_KEYS);
      insere(&trie, reg);
    }
    printf("\n");
    //
    // Print the tree in dot format:
    printDot(trie);
    //
    // Searches elements in the tree.
    printf("\nSearching:\n");
    for (i = 0; i < MAX_NUM_KEYS; i++) {
      int chave = i;
      if (pesquisa(trie, chave))
        printf("%4d%4s", i, "+");
      else
        printf("%4d%4s", i, "-");
    }
    printf("\n");
  }
}
