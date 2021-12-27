#ifndef INFO_H
#define INFO_H
#include <sys/resource.h>
#include <time.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct algoinfo{
  unsigned int ativacoes,troca,comparacoes;//inside data
  double utime,stime,total_time;// time
}algoinfo;
void timeusage(struct rusage *resources,char start,algoinfo* ai);
void printalgoinfo(const algoinfo *ai,FILE* f);
#endif
