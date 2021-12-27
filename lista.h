#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

struct TLista
{
  struct TCelula* inicio;
  int tamanho;
  struct TCelula* fim;
};

struct TCelula
{
  struct TCelula* ant;
  int valor;
  struct TCelula* prox;
};

typedef struct TLista lista;
typedef struct TCelula celula;

lista* cria();

void destroi(lista* l);

void insere_inicio(int v, lista* l);

celula* retorna_inicio(lista* l);

celula* retorna_fim(lista* l);

int retorna_tamanho(lista* l);

void imprime_lista(lista* l);

celula* cel_index(lista* l,int pos);

int get_index(celula *c);

celula* cel_index_r(celula* c,int pos);//index relativo a uma celula, melhora a performance
#endif
