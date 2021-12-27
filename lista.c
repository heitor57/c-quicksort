#include "lista.h"
lista* cria()
{
	lista* l = (lista*) malloc(sizeof(lista));
	l->inicio = NULL;
	l->tamanho = 0;
	return l;
}

void destroi(lista* l)
{
	celula *celulatemp, *p;
	celulatemp = l->inicio;
	while(celulatemp != NULL)
	{
		p = celulatemp;
		celulatemp = celulatemp->prox;
		free(p);
	}
	free(l);
}

void insere_inicio(int v, lista* l)
{
	celula* novacelula = malloc(sizeof(celula));
	novacelula->valor = v;
	novacelula->ant = NULL;
	novacelula->prox = l->inicio;
	if(l->inicio!=NULL)
		l->inicio->ant = novacelula;
	else
		l->fim = novacelula;
	l->inicio = novacelula;
	l->tamanho++;
}

celula* retorna_inicio(lista* l)
{
	return l->inicio;
}

celula* retorna_fim(lista* l)
{
	celula* p = l->inicio, *q = p;
	while(p != NULL)
	{
		q = p;
		p = p->prox;
	}
	return q;
}

int retorna_tamanho(lista* l)
{
	return l->tamanho;
}

void imprime_lista(lista* l)
{
	celula* p = l->inicio;
	printf("Valores na lista: ");
	while(p != NULL)
	{
		printf("%d ",p->valor);
		p = p->prox;
	}
	printf("\n");
}

celula* cel_index(lista* l,int pos){
	if(pos<l->tamanho && pos>=0){
		celula* tmp = l->inicio;
		for(int i=0; i<pos;i++){
			tmp=tmp->prox;
		}
		return tmp;
	}
	return NULL;
}

int get_index(celula *c){
	if(c!=NULL){
		int i = 0;
		while(c->ant != NULL){
			c=c->ant;
			i++;
		}
		return i;
	}
	return ERROR;
}

celula* cel_index_r(celula* c,int pos){//index relativo a uma celula, melhora a performance
	if(pos>=0){
		for(int i=0; i<pos && c->prox!=NULL;i++){
			c=c->prox;
		}
		return c;
	}
	return NULL;
}
