#include "Set.h"
#include "RBT.h"

struct set_concrete {
  RedBlackNode T;
};

void initialize(Set* s) {
  Initialize();
  MakeEmpty(s->T);
}

void insert(Set s, int i) {
  Insert(i, s->T);
}

int contains(Set s, int i) {
  return Contains(i, s->T);
}

void close(Set s) {
  MakeEmpty(s->T);
}
