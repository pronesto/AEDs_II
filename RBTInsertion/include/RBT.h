// #include <stdlib.h>
#include <limits.h>
 
#ifndef _RedBlack_H
#define _RedBlack_H
 
typedef int ElementType;
#define NegInfinity (INT_MIN)
 
typedef enum ColorType {
    Red, Black
} ColorType;
 
typedef struct RedBlackNode *RedBlackTree;
 
struct RedBlackNode {
    ElementType Element;
    RedBlackTree Left;
    RedBlackTree Right;
    ColorType Color;
};

int isNullNode(RedBlackTree p);
RedBlackTree MakeEmpty(RedBlackTree T);
RedBlackTree Initialize(void);
RedBlackTree Insert(ElementType X, RedBlackTree T);
ElementType Retrieve(RedBlackTree P);
void Central_RBT_Header(RedBlackTree T, void (*visitor)(RedBlackTree));
 
#endif  /* _RedBlack_H */
