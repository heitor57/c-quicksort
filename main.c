#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "info.h"
#include "genrandom.h"
#define repeat 5
#define argcreq 3
#define seed 1
#define in 2
#define out 3

int main(int argc, char *argv[])
{

	if(argc>argcreq)
	{
		struct rusage *resources= malloc(sizeof(struct rusage)); // estrutura para contabilizar o tempo
		int N,n; // N é o tamanho do vetor, n é a quantidade de tamanhos de vetores dados no arquivo de entrada
		FILE *entrada = fopen(argv[in],"r");
		FILE *saida = fopen(argv[out],"w");
		if(entrada == NULL || saida == NULL){
			printf("Error!");   
			exit(1);             
		}

		fscanf(entrada,"%d\n",&n);
		// N's...
		for(int ncount=0;!feof(entrada) && ncount<n;ncount++)//Lendo n N's(tamanho do vetor) dados no arquivo de entrada
		{
			fscanf(entrada,"%d\n",&N);
			algoinfo aimediav={0,0,0,0,0,0},//Estruturas para fazer a media das estatisticas de cada algoritmo
					 aimedial={0,0,0,0,0,0},
					 aimediastruct={0,0,0,0,0,0};

			elem* vstruct = malloc(sizeof(elem)*N);
			int *vint = malloc(sizeof(int)*N);
			for(int nsed=0;nsed<repeat;nsed++){
				srand(atoi(argv[seed])+nsed*randn);

				// vetor de inteiros
				algoinfo ai={0,0,0,0,0,0};
				vint_random(vint,N);//cria valores random
				timeusage(resources,TRUE,&ai);//Começa a contar o tempo
				quick_int(vint,0,N-1,&ai);// Sort
				timeusage(resources,FALSE,&ai);//Para de contar o tempo
				fprintf(saida,"Sort em Vetor de inteiros [%d]\n",N);
				printalgoinfo(&ai,saida);//print nas informaçoes do algoritmo
				aimediav = (algoinfo){ai.ativacoes+aimediav.ativacoes,ai.troca+aimediav.troca,ai.comparacoes+aimediav.comparacoes,
					ai.utime+aimediav.utime,ai.stime+aimediav.stime,ai.total_time+aimediav.total_time};
				//vetor de inteiros duplamente encadeado
				ai=(algoinfo){0,0,0,0,0,0};
				lista* l= cria();
				lint_random(l,N);//random list
				timeusage(resources,TRUE,&ai);//Começa a contar o tempo
				quick_int_l(l->inicio,l->fim,&ai);
				timeusage(resources,FALSE,&ai);//Termina de contar o tempo
				fprintf(saida,"Sort em Lista duplamente encadeada [%d]\n",N);
				printalgoinfo(&ai,saida);
				destroi(l);// free list
				aimedial = (algoinfo){ai.ativacoes+aimedial.ativacoes,ai.troca+aimedial.troca,ai.comparacoes+aimedial.comparacoes,
					ai.utime+aimedial.utime,ai.stime+aimedial.stime,ai.total_time+aimedial.total_time};
				//vetor de struct
				ai=(algoinfo){0,0,0,0,0,0};
				struct_random(vstruct,N);
				timeusage(resources,TRUE,&ai);
				quick_struct(vstruct,0,N-1,&ai);
				timeusage(resources,FALSE,&ai);
				fprintf(saida,"Sort em Vetor de struct [%d]\n",N);
				printalgoinfo(&ai,saida);
				aimediastruct = (algoinfo){ai.ativacoes+aimediastruct.ativacoes,ai.troca+aimediastruct.troca,ai.comparacoes+aimediastruct.comparacoes,
					ai.utime+aimediastruct.utime,ai.stime+aimediastruct.stime,ai.total_time+aimediastruct.total_time};
			}
			free(vstruct);
			free(vint);
			// Divide pelo numero de repetiçao para dar a media
			aimediav = (algoinfo){aimediav.ativacoes/repeat,aimediav.troca/repeat,aimediav.comparacoes/repeat,
				aimediav.utime/repeat,aimediav.stime/repeat,aimediav.total_time/repeat};
			aimedial = (algoinfo){aimedial.ativacoes/repeat,aimedial.troca/repeat,aimedial.comparacoes/repeat,
				aimedial.utime/repeat,aimedial.stime/repeat,aimedial.total_time/repeat};
			aimediastruct = (algoinfo){aimediastruct.ativacoes/repeat,aimediastruct.troca/repeat,aimediastruct.comparacoes/repeat,
				aimediastruct.utime/repeat,aimediastruct.stime/repeat,aimediastruct.total_time/repeat};
			fprintf(saida,"[Media vetor] [%d]\n",N);
			printalgoinfo(&aimediav,saida);
			fprintf(saida,"[Media lista duplamente encadeada] [%d]\n",N);
			printalgoinfo(&aimedial,saida);
			fprintf(saida,"[Media struct] [%d]\n",N);
			printalgoinfo(&aimediastruct,saida);
		}


		free(resources);
		fclose(entrada);
		fclose(saida);

	}
	return 0;
}

