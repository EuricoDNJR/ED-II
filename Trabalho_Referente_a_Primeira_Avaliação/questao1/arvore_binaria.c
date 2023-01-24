#include "arvore_binaria.h"


ARVORE_BINARIA *criar_no(int valor){
	ARVORE_BINARIA *no = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));

	no->valor = valor;

	no->esquerda = NULL;
	no->direita = NULL;

	return no;
}

void inserir(ARVORE_BINARIA **raiz, int valor){

	if(*raiz != NULL){
		if(valor < (*raiz)->valor)
			inserir(&((*raiz)->esquerda), valor);
		else 
			inserir(&((*raiz)->direita), valor);
	}else{
		*raiz = criar_no(valor);
	}
}

void desalocar_arvore(ARVORE_BINARIA *raiz){

	if(raiz != NULL){
		desalocar_arvore(raiz->esquerda);
		desalocar_arvore(raiz->direita);
		free(raiz);
	}
}

void in_ordem(ARVORE_BINARIA *raiz){

	if(raiz != NULL){
		in_ordem(raiz->esquerda);
		printf("%d\n", raiz->valor);
		in_ordem(raiz->direita);
	}
}

ARVORE_BINARIA *buscar(ARVORE_BINARIA *raiz, int numero){
	
	if(raiz != NULL){
		if(raiz->valor != numero){
			if(numero < raiz->valor)
				raiz = buscar(raiz->esquerda, numero);
			else
				raiz = buscar(raiz->direita, numero);
		}
	}
	return raiz;
}
