#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "help.h"
#include "memory.h"

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

void help(){
	printf("-c, --compact >> Processa ficheiros iniciados por -f ou -d compactando-os.\n");
	printf("-d, --dir >> Processa todos os ficheiros existentes no diretorio.\n");
	printf("--discrete >> Mostra a contagem de valores da lista.\n");
	printf("-f, --file >> Processa ficheiros da lista.\n");
	printf("-h, --help >> Mostra nomes numeros e termina o processo.\n");
	printf("-m, --mode >> Faz contagem orientada (-m 1,-m 2,-m 4) por ordem, octeto, bi-octeto, ou quad-octeto.\n");
	printf("-o, --output >> Escreve o resultado da aplicacao num ficheiro file.\n");
	printf("-s, --search >> Apresenta todas as ocorrencias dos octetos.\n");
	printf("--time >> Mostra o tempo de execucao da aplicacao, em segundos.\n");
	printf("Marcelo Lima - 2160866 \n");
	printf("Ruben Oliveira - 2192236 \n");
}  