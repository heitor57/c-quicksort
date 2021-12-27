#ifndef ELEM_H
#define ELEM_H

#define numstr 10
#define strsize 200
#define realn 4
#define booltotaln 2
typedef char bool;
typedef struct elem{
  int ch;//Chave para ordenação
  char str[numstr][strsize];//numstr strings, cada uma com strsize caracters
  bool b; // booleano
  float r[realn];//numeros reais
}elem;
#endif
