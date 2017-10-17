#include <stdio.h>
#include <stdlib.h>

#include "RBT.h"
#include "Tree.h"
#include "TreeGen.h"

void printDot_aux(RedBlackTree p) {
  if (p->Left)
    printf("  %d -> %d\n", p->Element, p->Left->Element);
  else {
    printf("  %d -> l%d\n", p->Element, p->Element);
    printf("  l%d [shape = point]\n", p->Element);
  }
  if (p->Right)
    printf("  %d -> %d\n", p->Element, p->Right->Element);
  else {
    printf("  %d -> r%d\n", p->Element, p->Element);
    printf("  r%d [shape = point]\n", p->Element);
  }
}

void printDot(RedBlackTree p) {
  printf("\ndigraph tree {\n");
  Central_RBT_Header(p, &printDot);
  printf("\n}\n");
}

int main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Syntax: %s num_nodes\n", argv[0]);
  } else {
    const int num_nodes = atoi(argv[1]);
    RedBlackTree T = genDegenerateRBT(num_nodes);
    printDot(T);
  }
}
