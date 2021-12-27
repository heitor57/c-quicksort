#include "info.h"
void timeusage(struct rusage *resources,char start,algoinfo *ai){
	double utime, stime, total_time;
	int rc;
	if(start == TRUE){
		if((rc = getrusage(RUSAGE_SELF,resources)) != 0) {
			perror("getrusage failed");
		}
	}else if(start == FALSE){
		utime = (double) resources->ru_utime.tv_sec + 1.e-6 * (double) resources->ru_utime.tv_usec;
		stime = (double) resources->ru_stime.tv_sec + 1.e-6 * (double) resources->ru_stime.tv_usec;

		if((rc = getrusage(RUSAGE_SELF,resources)) != 0) {
			perror("getrusage failed");
		}
		utime = (double) resources->ru_utime.tv_sec + 1.e-6 * (double) resources->ru_utime.tv_usec - utime;
		stime = (double) resources->ru_stime.tv_sec + 1.e-6 * (double) resources->ru_stime.tv_usec - stime;
		total_time = utime+stime;
		ai->utime = utime;
		ai->stime = stime;
		ai->total_time = total_time;
	}
}
void printalgotime(const algoinfo *ai,FILE* f){
	fprintf(f,"User time %.5f, System time %.5f, Total Time %.5f\n",ai->utime, ai->stime, ai->total_time);
}

void printalgoinsdata(const algoinfo *ai,FILE* f){
	fprintf(f,"Ativações: %d; Trocas/Copias: %d; Comparações: %d.\n",ai->ativacoes,ai->troca,ai->comparacoes);
}

void printalgoinfo(const algoinfo *ai,FILE* f){
	printalgotime(ai,f);
	printalgoinsdata(ai,f);
}
