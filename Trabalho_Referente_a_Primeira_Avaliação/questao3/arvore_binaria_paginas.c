#include "arvore_binaria_paginas.h"


ARVORE_BINARIA_PAGINAS *criar_no_pagina(int numero_pagina){
	ARVORE_BINARIA_PAGINAS *no = (ARVORE_BINARIA_PAGINAS *)malloc(sizeof(ARVORE_BINARIA_PAGINAS));

	no->numero_pagina = numero_pagina;

	no->esquerda = NULL;
	no->direita = NULL;

	return no;
}

void inserir_pagina(ARVORE_BINARIA_PAGINAS **raiz, int numero_pagina){

	if(*raiz != NULL){
		if(numero_pagina < (*raiz)->numero_pagina)
			inserir_pagina(&((*raiz)->esquerda), numero_pagina);
		else if(numero_pagina > (*raiz)->numero_pagina){
			inserir_pagina(&((*raiz)->direita), numero_pagina);
		}
	}else{
		*raiz = criar_no_pagina(numero_pagina);
	}
}

void desalocar_arvore_paginas(ARVORE_BINARIA_PAGINAS *raiz){

	if(raiz != NULL){
		desalocar_arvore_paginas(raiz->esquerda);
		desalocar_arvore_paginas(raiz->direita);
		free(raiz);
	}
}

void print_paginas(ARVORE_BINARIA_PAGINAS *raiz){

	if(raiz != NULL){
		print_paginas(raiz->esquerda);
		printf("%d ", raiz->numero_pagina);
		print_paginas(raiz->direita);
	}
}
