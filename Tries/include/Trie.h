#ifndef _TRIE_H
#define _TRIE_H

typedef struct registro {
  int chave;
  /* outros dados */
} Registro;

typedef struct No *Apontador;

struct No {
  Apontador esq;
  Apontador dir;
  Registro *reg;
};

void inicializa(Apontador *trie);

Apontador cria_trie(Registro *reg);

Registro *pesquisa(Apontador T, int chave);

void insere(Apontador *trie, Registro *reg);

#endif
