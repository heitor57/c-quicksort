#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "lista.h"
#include "elem.h"
#include "info.h"
int particiona_int(int vetor[], int inicio, int fim,algoinfo* ai);
void quick_int(int vetor[], int inicio, int fim, algoinfo* ai);
celula* particiona_int_l(celula* inicio, celula* fim,algoinfo* ai);
void quick_int_l(celula* inicio,celula* fim,algoinfo* ai);
int particiona_struct(elem* rgs, int inicio, int fim,algoinfo* ai);
void quick_struct(elem* rgs, int inicio, int fim, algoinfo* ai);

#endif
