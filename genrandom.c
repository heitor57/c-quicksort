#include "genrandom.h"
const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void vint_random(int *vint, size_t size){
	for(int i=0;i<size;i++)
		vint[i] = rand()%(size*randn);
}

void lint_random(lista *lint, size_t max){
	for(int i=0;i<max;i++)
		insere_inicio(rand()%(max*randn),lint);
}
void struct_random(elem *vstruct, size_t size){
	int i,j,z;
	for(i=0;i<size;i++){
		vstruct[i].ch = rand()%(size*randn);
		for(j=0;j<numstr;j++){
			for(z=0;z<strsize;z++){
				vstruct[i].str[j][z] = charset[rand()%sizeof(charset)];
				if(vstruct[i].str[j][z] == '\0')
					break;

			}
			vstruct[i].str[j][strsize-1] = '\0';// if dont get any '\0' this will fix, its better to put her because this inside the if(up here) the program will slow down
		}
		vstruct[i].b = rand()%booltotaln;
		for (j=0 ; j < realn; ++j) {
			vstruct[i].r[j] =  (float)rand()/(float)(RAND_MAX/(size*randn));
		}
	}
}
