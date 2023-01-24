#include "arvore_avl_paginas.h"


ARVORE_AVL_PAGINAS *criar_no_pagina(int numero_pagina){
	ARVORE_AVL_PAGINAS *no = (ARVORE_AVL_PAGINAS *)malloc(sizeof(ARVORE_AVL_PAGINAS));

	no->numero_pagina = numero_pagina;
	no->altura = 0;
	no->esquerda = NULL;
	no->direita = NULL;
	no->pai = NULL;

	return no;
}

int fator_balanceamento_paginas(ARVORE_AVL_PAGINAS *raiz){

	int fator_balanceamento, altura_esquerda=-1, altura_direita=-1;

	if(raiz->esquerda != NULL)
		altura_esquerda = raiz->esquerda->altura;

	if(raiz->direita != NULL)
		altura_direita = raiz->direita->altura;

	fator_balanceamento = altura_esquerda - altura_direita;

	return fator_balanceamento;
}

void atualizar_altura_paginas(ARVORE_AVL_PAGINAS *raiz){

	int altura_esquerda=-1, altura_direita=-1;

	if(raiz->esquerda != NULL)
		altura_esquerda = raiz->esquerda->altura;

	if(raiz->direita != NULL)
		altura_direita = raiz->direita->altura;

	if(altura_esquerda > altura_direita)
		raiz->altura = 1 + altura_esquerda;
	else
		raiz->altura = 1 + altura_direita;
}

void modificar_filho_paginas(ARVORE_AVL_PAGINAS **raiz,  ARVORE_AVL_PAGINAS *no){

	ARVORE_AVL_PAGINAS *pai = (*raiz)->pai;

	no->pai = pai;

	if(pai == NULL){
		*raiz = no;
	}else if(pai->esquerda == *raiz){
		pai->esquerda = no;
		no->pai = pai;
	}else{
		pai->direita = no;
	}
}

void rotacao_para_esquerda_paginas(ARVORE_AVL_PAGINAS **raiz){

	ARVORE_AVL_PAGINAS *no = *raiz, *no_filho = (*raiz)->direita;

	no->direita = no_filho->esquerda;
	if(no->direita != NULL)
		no->direita->pai = no;
	no_filho->esquerda = no;

	modificar_filho_paginas(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura_paginas(no);
	atualizar_altura_paginas(no_filho);
}

void rotacao_para_direita_paginas(ARVORE_AVL_PAGINAS **raiz){

	ARVORE_AVL_PAGINAS *no = *raiz, *no_filho = (*raiz)->esquerda;

	no->esquerda = no_filho->direita;
	if(no->esquerda != NULL)
		no->esquerda->pai = no;
	no_filho->direita = no;

	modificar_filho_paginas(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura_paginas(no);
	atualizar_altura_paginas(no_filho);
}


void inserir_pagina(ARVORE_AVL_PAGINAS **raiz, int numero_pagina){

	int fator_balanceamento_raiz, fator_balanceamento_filho;

	if(*raiz != NULL){
		// INSERIR
		if(numero_pagina < (*raiz)->numero_pagina){
			inserir_pagina(&((*raiz)->esquerda), numero_pagina);
			(*raiz)->esquerda->pai = *raiz;
		}else if(numero_pagina > (*raiz)->numero_pagina){
			inserir_pagina(&((*raiz)->direita), numero_pagina);
			(*raiz)->direita->pai = *raiz;
		}


		// DESCOBRIR QUAL ROTAÇÃO FAZER OU SE NÃO É NECESSÁRIO ROTAÇÃO
		fator_balanceamento_raiz = fator_balanceamento_paginas(*raiz);

		if(1 < fator_balanceamento_raiz){// ROTAÇÃO PARA A DIREITA
			fator_balanceamento_filho = fator_balanceamento_paginas((*raiz)->esquerda);

			if(fator_balanceamento_filho < 0)// ROTAÇÃO DUPLA
				rotacao_para_esquerda_paginas(&((*raiz)->esquerda));

			rotacao_para_direita_paginas(raiz);				
		}else if(fator_balanceamento_raiz < -1){//ROTAÇÃO PARA A ESQUERDA
			fator_balanceamento_filho = fator_balanceamento_paginas((*raiz)->direita);

			if(fator_balanceamento_filho > 0)// ROTAÇÃO DUPLA
				rotacao_para_direita_paginas(&((*raiz)->direita));
				
			rotacao_para_esquerda_paginas(raiz);
		}else
			atualizar_altura_paginas(*raiz);
	}else
		*raiz = criar_no_pagina(numero_pagina);
}

void desalocar_arvore_paginas(ARVORE_AVL_PAGINAS *raiz){

	if(raiz != NULL){
		desalocar_arvore_paginas(raiz->esquerda);
		desalocar_arvore_paginas(raiz->direita);
		free(raiz);
	}
}

void print_paginas(ARVORE_AVL_PAGINAS *raiz){

	if(raiz != NULL){
		print_paginas(raiz->esquerda);
		printf("%d ", raiz->numero_pagina);
		print_paginas(raiz->direita);
	}
}
