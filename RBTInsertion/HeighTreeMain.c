#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"
#include "RBT.h"
#include "TreeGen.h"

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int RBT_Height(RedBlackTree T) {
  int height_esq = 0;
  int height_dir = 0;
  if (!isNullNode(T->Left))
    height_esq = RBT_Height(T->Left);
  if (!isNullNode(T->Right))
    height_dir = RBT_Height(T->Right);
  return MAX(height_esq, height_dir) + 1;
}

int Tree_Height(Apontador T) {
  int height_esq = 0;
  int height_dir = 0;
  if (T->Esq)
    height_esq = Tree_Height(T->Esq);
  if (T->Dir)
    height_dir = Tree_Height(T->Dir);
  return MAX(height_esq, height_dir) + 1;
}

void print(ElementType e) {
  printf("%d\n", e);
}

int  main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Syntax: %s num_nodes [opts]\n", argv[0]);
    fprintf(stderr, " where opts is\n");
    fprintf(stderr, "  0:tr-degen\n  1:tr-rand\n  2:rbt-gen\n  3:rbt-rand\n");
  } else {
    const int num_nodes = atoi(argv[1]);
    const int tree_option = atoi(argv[2]);
    switch(tree_option) {
      case 0: {
        Apontador P0 = genDegenerateTree(num_nodes);
        printf("Altura da arvore: %d\n", Tree_Height(P0));
        break;
      }
      case 1: {
        Apontador P1 = genRandomTree(num_nodes, 5 * num_nodes);
        printf("Altura da arvore: %d\n", Tree_Height(P1));
        break;
      }
      case 2: {
        RedBlackTree P2 = genDegenerateRBT(num_nodes);
        printf("Altura da arvore: %d\n", RBT_Height(P2));
        break;
      }
      case 3: {
        RedBlackTree P3 = genRandomRBT(num_nodes, 5 * num_nodes);
        printf("Altura da arvore: %d\n", RBT_Height(P3));
        break;
      }
      default:
        fprintf(stderr, "Unknown option: %d\n", tree_option);
    }
  }
}
