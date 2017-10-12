#ifndef BIN_H
#define BIN_H

# define MAX 80

typedef int TipoChave;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} Registro;

typedef int Indice;

typedef struct {
  Registro Item[MAX + 1];
  Indice n;
} Tabela;

void Inicializa(Tabela *T);

Indice Pesquisa(TipoChave x, Tabela *T);

Indice Binaria(TipoChave x, Tabela *T);

void Insere(Registro Reg, Tabela *T);

TipoChave gen();

#endif
