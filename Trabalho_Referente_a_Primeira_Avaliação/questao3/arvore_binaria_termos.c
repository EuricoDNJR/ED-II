#include "arvore_binaria_termos.h"


ARVORE_BINARIA_TERMOS *criar_no_termo(char *termo){
	ARVORE_BINARIA_TERMOS *no = (ARVORE_BINARIA_TERMOS *)malloc(sizeof(ARVORE_BINARIA_TERMOS));

	copiar_string(&(no->termo), termo);

	no->esquerda = NULL;
	no->direita = NULL;
	no->paginas = NULL;
	no->sub_termos = NULL;

	return no;
}

void inserir_termo(ARVORE_BINARIA_TERMOS **raiz, char *termo, ARVORE_BINARIA_TERMOS **aux){

	if(*raiz != NULL){
		if(ordem_alfabetica(termo, (*raiz)->termo) == -1)
			inserir_termo(&((*raiz)->esquerda), termo, aux);
		else if(ordem_alfabetica(termo, (*raiz)->termo) == 1){
			inserir_termo(&((*raiz)->direita), termo, aux);
		}
	}else{
		*raiz = criar_no_termo(termo);
		*aux = *raiz;
	}
}

void desalocar_arvore_termo(ARVORE_BINARIA_TERMOS *raiz){

	if(raiz != NULL){
		desalocar_arvore_termo(raiz->esquerda);
		desalocar_arvore_termo(raiz->direita);
		liberar_string(raiz->termo);
		desalocar_arvore_paginas(raiz->paginas);
		desalocar_arvore_sub_termo(raiz->sub_termos);
		free(raiz);
	}
}

void print_termos(ARVORE_BINARIA_TERMOS *raiz){

	if(raiz != NULL){
		print_termos(raiz->esquerda);

		printf("%s ", raiz->termo);
		print_paginas(raiz->paginas);
		printf("\n");
		print_sub_termos(raiz->sub_termos);
		printf("\n");

		print_termos(raiz->direita);
	}
}

ARVORE_BINARIA_TERMOS *buscar_termo(ARVORE_BINARIA_TERMOS *raiz, char *termo){
	
	if(raiz != NULL){
		if(!string_igual(termo, raiz->termo)){
			if(ordem_alfabetica(termo, raiz->termo) == -1)
				raiz = buscar_termo(raiz->esquerda, termo);
			else
				raiz = buscar_termo(raiz->direita, termo);
		}
	}
	return raiz;
}

