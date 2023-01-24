#include "arvore_binaria.h"
#include <time.h> 
#include <math.h>


void calcula_profundidade(ARVORE_BINARIA *raiz, int profundidade, int *maior_profundidade, int *menor_profundidade);


int main(){
	srand(15);// time(NULL)

	ARVORE_BINARIA *raiz;
	int i, j, maior_profundidade, menor_profundidade; 
	int diferenca_profundidades[30], maior, cont;
	struct timespec tempo_inicial, tempo_final; 
	double total, media_insercao=0, media_busca=0;


	for(i=0; i<30; i++){
		maior_profundidade = -1;
		menor_profundidade= -1;
		raiz = NULL;

		clock_gettime(CLOCK_REALTIME, &tempo_inicial);
		for(j=0; j<1000; j++){
			inserir(&raiz, rand());
			inserir(&raiz, rand() % 1000);
		}
		clock_gettime(CLOCK_REALTIME, &tempo_final);
		printf("\nInsercao %d", i);
		total = (tempo_final.tv_nsec - tempo_inicial.tv_nsec);
		media_insercao += total;

		printf("\nTempo de insercao = %.2lf nanosegundos\n", total);
		calcula_profundidade(raiz, 0, &maior_profundidade, &menor_profundidade);
		printf("Nivel da folha de maior profundidade: %d\n", maior_profundidade);
		printf("Nivel da folha de menor profundidade: %d\n", menor_profundidade);

		clock_gettime(CLOCK_REALTIME, &tempo_inicial);
		for(j=0; j<1000; j++){
			buscar(raiz, rand());
		} 
		clock_gettime(CLOCK_REALTIME, &tempo_final);
		total = (tempo_final.tv_nsec - tempo_inicial.tv_nsec);
		media_busca += total;
		printf("Tempo de busca = %.2lf nanosegundos\n", total);

		diferenca_profundidades[i] = maior_profundidade - menor_profundidade;

		desalocar_arvore(raiz);
	}

	printf("\nMEDIA TEMPO DE INSERCAO: %.2lf\n", media_insercao / 30.0);
	printf("MEDIA TEMPO DE BUSCA: %.2lf\n", media_busca / 30.0);

	maior = diferenca_profundidades[0];
	for(i=1; i<30; i++){
		if(diferenca_profundidades[i] > maior)
			maior = diferenca_profundidades[i];
	}

	for(i=0; i<=maior; i++){
		cont = 0;

		for(j=0; j<30; j++){
			if(diferenca_profundidades[j] == i)
				cont++;
		}

		printf("%d apareceu %d vezes\n", i, cont);
	}


	printf("ACABOU\n");
	return 0;
}

// imprima o nível da folha de maior profundidade e o nível da folha de menor profundidade.
void calcula_profundidade(ARVORE_BINARIA *raiz, int profundidade, int *maior_profundidade, int *menor_profundidade){

	if(raiz != NULL){
		calcula_profundidade(raiz->esquerda, profundidade+1, maior_profundidade, menor_profundidade);
		calcula_profundidade(raiz->direita, profundidade+1, maior_profundidade, menor_profundidade);

		if(raiz->esquerda == NULL && raiz->direita == NULL){
			if(*maior_profundidade == -1)
				*maior_profundidade = profundidade;
			else if(*maior_profundidade < profundidade){
				*maior_profundidade = profundidade;
			}

			if(*menor_profundidade == -1)
				*menor_profundidade = profundidade;
			else if(*menor_profundidade > profundidade){
				*menor_profundidade = profundidade;
			}
		}
	}
}
