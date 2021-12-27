#ifndef GENRANDOM_H
#define GENRANDOM_H
#include "elem.h"
#include "stddef.h"
#include "lista.h"
#define randn 100
void vint_random(int *vint, size_t size);
void lint_random(lista *lint, size_t max);
void struct_random(elem *vstruct, size_t size);
#endif
