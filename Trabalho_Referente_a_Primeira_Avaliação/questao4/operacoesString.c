#include "operacoesString.h"


void *copiar_string(char **destino, char *origem){

	int i=0;

	*destino = (char *)malloc(sizeof(char));

	while( ( (*destino)[i] = origem[i] ) ){
		i++;
		*destino = (char *)realloc(*destino, (i+1) * sizeof(char));
	}

}

void liberar_string(char *string){

	free(string);
}

void transformar_em_minusculo(char *caracter){

	if(64 < (*caracter) && (*caracter) < 91)
		(*caracter) += 32;
}

int ordem_alfabetica(char *string1, char *string2){

	int retorno = 0, i=0;
	char caracter_string1, caracter_string2;

	while((string1[i] != 0) && (string2[i] != 0) && (retorno == 0)){
		caracter_string1 = string1[i];
		caracter_string2 = string2[i];

		transformar_em_minusculo(&caracter_string1);
		transformar_em_minusculo(&caracter_string2);

		if(caracter_string1 < caracter_string2){
			retorno = -1;
		}else if(caracter_string1 > caracter_string2){
			retorno = 1;
		}

		i++;
	}	

	return retorno;
}

int string_igual(char *string1, char *string2){

	int i = 0, sao_iguais = 1;

	while((string1[i] || string2[i]) && sao_iguais == 1){
		if(string1[i] != string2[i])
			sao_iguais = 0;
		i++;
	}

	return sao_iguais;
}