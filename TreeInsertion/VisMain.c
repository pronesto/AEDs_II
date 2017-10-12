#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

/*
 * Auxiliary function used in a tree traversal that prints key information for
 * all the keys in the tree.
 */
void visita(Apontador p) {
  printf("%8d", p->Reg.Chave);
}

/*
 * Finds the largest key of the tree, and stores it in the global variable
 * largestKey. This variable is updated within the auxiliary function
 * getLargestKey_aux.
 */
int largestKey = 0;

void getLargestKey_aux(Apontador p) {
  if (p->Reg.Chave > largestKey)
    largestKey = p->Reg.Chave;
}

int getLargestKey(Apontador p) {
  Central(p, &getLargestKey_aux);
  return largestKey;
}

#define MAX 80

TipoChave gen(const int MAX_KEY) {
  return random() % MAX_KEY + 1;
}

int main() {
  Apontador D;
  Inicializa(&D);
  int i;
  // Inserts elements in the tree.
  printf("Inserting:\n");
  for (i = 0; i < MAX; i++) {
    Registro Reg;
    Reg.Chave = gen(160);
    if (Insere(Reg, &D))
      printf("%4s%4d", "+", Reg.Chave);
    else
      printf("%4s%4d", "*", Reg.Chave);
  }
  // Searches elements in the tree.
  printf("\nSearching:\n");
  for (i = 0; i < MAX; i++) {
    TipoChave Chave = i;
    if (Pesquisa(Chave, D))
      printf("%4d%4s", i, "+");
    else
      printf("%4d%4s", i, "-");
  }
  // Visits every key in the tree.
  printf("\nPre-Order:\n");
  Central(D, &visita);
  // Gets the largest key:
  printf("\nLargest key = %d\n", getLargestKey(D));
}
