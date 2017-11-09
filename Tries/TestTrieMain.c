#include <stdio.h>
#include <stdlib.h>

#include "Trie.h"

/*
 * Prints the tree in dot format, using the auxiliary function printDot_aux.
 */
void printDot_aux(Apontador p) {
  if (!(p->reg)) {
    printf("  %lu [shape = point];\n", (long)p);
  } else {
    printf("  %lu [label = %d];\n", (long)p, p->reg->chave);
  }
  if (p->esq)
    printf("  %lu -> %lu [label = 0]\n", (long)p, (long)p->esq);
  if (p->dir)
    printf("  %lu -> %lu [label = 1]\n", (long)p, (long)p->dir);
}

void printDot(Apontador p) {
  printf("\ndigraph tree {\n");
  Central(p, &printDot_aux);
  printf("\n}\n");
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
    printf("Inserting:\n");
    for (i = 0; i < MAX_NUM_KEYS; i++) {
      Registro *reg = (Registro*) malloc(sizeof(Registro));
      reg->chave = gen(16);
      insere(&trie, reg);
      printDot(trie);
    }
    printf("\n");
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
