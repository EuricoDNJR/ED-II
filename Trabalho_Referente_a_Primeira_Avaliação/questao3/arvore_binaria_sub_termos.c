#include "arvore_binaria_sub_termos.h"


ARVORE_BINARIA_SUB_TERMOS *criar_no_sub_termo(char *sub_termo){
	ARVORE_BINARIA_SUB_TERMOS *no = (ARVORE_BINARIA_SUB_TERMOS *)malloc(sizeof(ARVORE_BINARIA_SUB_TERMOS));

	copiar_string(&(no->sub_termo), sub_termo);

	no->esquerda = NULL;
	no->direita = NULL;
	no->paginas = NULL;

	return no;
}

void inserir_sub_termo(ARVORE_BINARIA_SUB_TERMOS **raiz, char *sub_termo, ARVORE_BINARIA_SUB_TERMOS **aux){

	if(*raiz != NULL){
		if(ordem_alfabetica(sub_termo, (*raiz)->sub_termo) == -1)
			inserir_sub_termo(&((*raiz)->esquerda), sub_termo, aux);
		else if(ordem_alfabetica(sub_termo, (*raiz)->sub_termo) == 1){
			inserir_sub_termo(&((*raiz)->direita), sub_termo, aux);
		}
	}else{
		*raiz = criar_no_sub_termo(sub_termo);
		*aux = *raiz;
	}
}

void desalocar_arvore_sub_termo(ARVORE_BINARIA_SUB_TERMOS *raiz){

	if(raiz != NULL){
		desalocar_arvore_sub_termo(raiz->esquerda);
		desalocar_arvore_sub_termo(raiz->direita);
		liberar_string(raiz->sub_termo);
		desalocar_arvore_paginas(raiz->paginas);
		free(raiz);
	}
}

void print_sub_termos(ARVORE_BINARIA_SUB_TERMOS *raiz){

	if(raiz != NULL){
		print_sub_termos(raiz->esquerda);
		printf("\t%s ", raiz->sub_termo);
		print_paginas(raiz->paginas);
		printf("\n");
		print_sub_termos(raiz->direita);
	}
}


ARVORE_BINARIA_SUB_TERMOS *buscar_sub_termo(ARVORE_BINARIA_SUB_TERMOS *raiz, char *sub_termo){
	
	if(raiz != NULL){
		if(!string_igual(sub_termo, raiz->sub_termo)){
			if(ordem_alfabetica(sub_termo, raiz->sub_termo) == -1)
				raiz = buscar_sub_termo(raiz->esquerda, sub_termo);
			else
				raiz = buscar_sub_termo(raiz->direita, sub_termo);
		}
	}
	return raiz;
}

