#include <stdio.h>
#include <stdlib.h>

#include "RBT.h"
 
static RedBlackTree NullNode = NULL;
 
/* Initialization procedure */
RedBlackTree Initialize(void) {
  RedBlackTree T;

  if (NullNode == NULL) {
    NullNode = malloc(sizeof ( struct RedBlackNode));
    NullNode->Left = NullNode->Right = NullNode;
    NullNode->Color = Black;
    NullNode->Element = ~0U;
  }

  /* Create the header node */
  T = malloc(sizeof ( struct RedBlackNode));
  T->Element = NegInfinity;
  T->Left = T->Right = NullNode;
  T->Color = Black;

  return T;
}

/* END */

static void
Central_RBT(RedBlackTree T, void (*visitor)(RedBlackTree)) {
  if (T != NullNode) {
    Central_RBT(T->Left, visitor);
    (*visitor)(T);
    Central_RBT(T->Right, visitor);
  }
}

void
Central_RBT_Header(RedBlackTree T, void (*visitor)(RedBlackTree)) {
  Central_RBT(T->Right, visitor);
}

/* END */

void
Output(ElementType Element) {
  printf("%d\n", Element);
}

/* Print the tree, watch out for NullNode, */

/* and skip header */

static void
DoPrint(RedBlackTree T) {
  if (T != NullNode) {
    DoPrint(T->Left);
    Output(T->Element);
    DoPrint(T->Right);
  }
}

void
PrintTree(RedBlackTree T) {
  DoPrint(T->Right);
}

/* END */

static RedBlackTree
MakeEmptyRec(RedBlackTree T) {
  if (T != NullNode) {
    MakeEmptyRec(T->Left);
    MakeEmptyRec(T->Right);
    free(T);
  }
  return NullNode;
}

RedBlackTree MakeEmpty(RedBlackTree T) {
  T->Right = MakeEmptyRec(T->Right);
  return T;
}

/* This function can be called only if K2 has a left child */
/* Perform a rotate between a node (K2) and its left child */

/* Update heights, then return new root */

static RedBlackTree
SingleRotateWithLeft(RedBlackTree K2) {
  RedBlackTree K1;

  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;

  return K1; /* New root */
}

/* This function can be called only if K1 has a right child */
/* Perform a rotate between a node (K1) and its right child */

/* Update heights, then return new root */

static RedBlackTree
SingleRotateWithRight(RedBlackTree K1) {
  RedBlackTree K2;

  K2 = K1->Right;
  K1->Right = K2->Left;
  K2->Left = K1;

  return K2; /* New root */
}

/* Perform a rotation at node X */
/* (whose parent is passed as a parameter) */

/* The child is deduced by examining Item */

static RedBlackTree Rotate(ElementType Item, RedBlackTree Parent) {
  if (Item < Parent->Element)
    return Parent->Left = Item < Parent->Left->Element ?
      SingleRotateWithLeft(Parent->Left) :
    SingleRotateWithRight(Parent->Left);
  else
    return Parent->Right = Item < Parent->Right->Element ?
      SingleRotateWithLeft(Parent->Right) :
    SingleRotateWithRight(Parent->Right);
}

static RedBlackTree X, P, GP, GGP;

static
void HandleReorient(ElementType Item, RedBlackTree T) {
  X->Color = Red; /* Do the color flip */
  X->Left->Color = Black;
  X->Right->Color = Black;

  if (P->Color == Red) /* Have to rotate */ {
    GP->Color = Red;
    if ((Item < GP->Element) != (Item < P->Element))
      P = Rotate(Item, GP); /* Start double rotate */
    X = Rotate(Item, GGP);
    X->Color = Black;
  }
  T->Right->Color = Black; /* Make root black */
}

RedBlackTree Insert(ElementType Item, RedBlackTree T) {
  X = P = GP = T;
  NullNode->Element = Item;
  while (X->Element != Item) /* Descend down the tree */ {
    GGP = GP;
    GP = P;
    P = X;
    if (Item < X->Element)
      X = X->Left;
    else
      X = X->Right;
    if (X->Left->Color == Red && X->Right->Color == Red)
      HandleReorient(Item, T);
  }

  if (X != NullNode)
    return T; /* Duplicate */

  X = malloc(sizeof(struct RedBlackNode));
  X->Element = Item;
  X->Left = X->Right = NullNode;

  if (Item < P->Element) /* Attach to its parent */
    P->Left = X;
  else
    P->Right = X;

  HandleReorient(Item, T); /* Color it red; maybe rotate */

  return T;
}

ElementType Retrieve(RedBlackTree P) {
  return P->Element;
}
