#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#define LLTR(left, right)  (right != NULL && left != right && left != right->prox) // teste se a celula da esquerda é menor que a da direita em relação a posição
#define comparasionnumber 4
int particiona_int(int vetor[], int inicio, int fim,algoinfo* ai)
{
  int esq, dir;
  int pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = vetor[inicio];
  while(esq<dir)
  {
    while(vetor[esq] <= pivo && esq<fim){   // vetor[esq] <= pivo
      esq++;
      ai->comparacoes++;
    }

    while(pivo < vetor[dir]){    //  vetor[dir] > pivo
      dir--;
      ai->comparacoes++;
    }

    if(esq < dir)
    {
      aux = vetor[esq];          // troca vetor[esq] com vetor[dir]
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
      ai->troca++;
    }

    ai->comparacoes+=comparasionnumber;
  }

  ai->comparacoes++;
  vetor[inicio] = vetor[dir];
  vetor[dir] = pivo;
  return dir;                   //retorna dir, que é o índice que vai dividir o vetor
}

void quick_int(int vetor[], int inicio, int fim, algoinfo* ai)
{
  ai->ativacoes++;
  int pivo;
  if(inicio < fim)
  {
    pivo = particiona_int(vetor,inicio,fim,ai); // encontra um pivo que "divide" o vetor em dois
    quick_int(vetor, inicio, pivo-1, ai); // realiza a partição para a parte da esquerda
    quick_int(vetor, pivo+1, fim, ai);  // e realiza a partição para a parte de direita
  }
}


celula* particiona_int_l(celula* inicio, celula* fim,algoinfo* ai){
  int pivo = inicio->valor,aux;
  celula* dir = fim,*esq = inicio;
  while(LLTR(esq,dir)){
    while(esq->valor <= pivo && LLTR(esq,fim)){
      esq=esq->prox;
      ai->comparacoes++;
    }
    while(pivo < dir->valor){
      dir=dir->ant;
      ai->comparacoes++;
    }
    if(LLTR(esq,dir))
    {
      aux = dir->valor;
      dir->valor = esq->valor;
      esq->valor = aux;
      ai->troca++;
    }
    ai->comparacoes+=comparasionnumber;
  }
  ai->comparacoes++;
  inicio->valor = dir->valor;
  dir->valor = pivo;
  return dir;
}

void quick_int_l(celula* inicio,celula* fim,algoinfo* ai){
  ai->ativacoes++;
  if (LLTR(inicio,fim)){
    celula* pivo =  particiona_int_l(inicio,fim,ai);
    quick_int_l(inicio, pivo->ant,ai);
    quick_int_l(pivo->prox, fim,ai);
  }
}


int particiona_struct(elem* rgs, int inicio, int fim,algoinfo* ai)
{
  int esq, dir;
  elem pivo,aux;
  esq = inicio;
  dir = fim;
  pivo = rgs[inicio];
  while(esq<dir)
  {
    while(rgs[esq].ch <= pivo.ch && esq<fim){
      esq++;
      ai->comparacoes++;
    }

    while(pivo.ch < rgs[dir].ch){
      dir--;
      ai->comparacoes++;
    }

    if(esq < dir)
    {
      aux = rgs[esq]; 
      rgs[esq] = rgs[dir];
      rgs[dir] = aux;
      ai->troca++;
    }

    ai->comparacoes+=comparasionnumber;
  }

  ai->comparacoes++;
  rgs[inicio] = rgs[dir];
  rgs[dir] = pivo;
  return dir;                   //retorna dir, que é o índice que vai dividir o rgs
}

void quick_struct(elem* rgs, int inicio, int fim,algoinfo* ai)
{
  ai->ativacoes++;
  int pivo;
  if(inicio < fim)
  {
    pivo = particiona_struct(rgs,inicio,fim,ai); // encontra um pivo que "divide" o vetor em dois
    quick_struct(rgs, inicio, pivo-1, ai); // realiza a partição para a parte da esquerda
    quick_struct(rgs, pivo+1, fim, ai);  // e realiza a partição para a parte de direita
  }
}




