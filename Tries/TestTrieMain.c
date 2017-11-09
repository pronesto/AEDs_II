#include <stdio.h>
#include <stdlib.h>

#include "Trie.h"

/*
 * Auxiliary function used in a tree traversal that prints key information for
 * all the keys in the tree.
 */
void visita(Apontador p) {
  printf("Key = %8d, Dir? = %d, Esq? = %d\n", p->reg->chave, p->dir != NULL,
      p->esq != NULL);
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
      printf("%4d", reg->chave);
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
  }
}
