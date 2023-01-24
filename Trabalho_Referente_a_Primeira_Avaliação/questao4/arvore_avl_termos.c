#include "arvore_avl_termos.h"


ARVORE_AVL_TERMOS *criar_no_termo(char *termo){
	ARVORE_AVL_TERMOS *no = (ARVORE_AVL_TERMOS *)malloc(sizeof(ARVORE_AVL_TERMOS));

	copiar_string(&(no->termo), termo);
	no->altura = 0;
	no->esquerda = NULL;
	no->direita = NULL;
	no->pai = NULL;
	no->sub_termos = NULL;
	no->paginas = NULL;

	return no;
}

int fator_balanceamento_termo(ARVORE_AVL_TERMOS *raiz){

	int fator_balanceamento_termo, altura_esquerda=-1, altura_direita=-1;

	if(raiz->esquerda != NULL)
		altura_esquerda = raiz->esquerda->altura;

	if(raiz->direita != NULL)
		altura_direita = raiz->direita->altura;

	fator_balanceamento_termo = altura_esquerda - altura_direita;

	return fator_balanceamento_termo;
}

void atualizar_altura_termo(ARVORE_AVL_TERMOS *raiz){

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

void modificar_filho_termo(ARVORE_AVL_TERMOS **raiz,  ARVORE_AVL_TERMOS *no){

	ARVORE_AVL_TERMOS *pai = (*raiz)->pai;

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

void rotacao_para_esquerda_termo(ARVORE_AVL_TERMOS **raiz){

	ARVORE_AVL_TERMOS *no = *raiz, *no_filho = (*raiz)->direita;

	no->direita = no_filho->esquerda;
	if(no->direita != NULL)
		no->direita->pai = no;
	no_filho->esquerda = no;

	modificar_filho_termo(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura_termo(no);
	atualizar_altura_termo(no_filho);
}

void rotacao_para_direita_termo(ARVORE_AVL_TERMOS **raiz){

	ARVORE_AVL_TERMOS *no = *raiz, *no_filho = (*raiz)->esquerda;

	no->esquerda = no_filho->direita;
	if(no->esquerda != NULL)
		no->esquerda->pai = no;
	no_filho->direita = no;

	modificar_filho_termo(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura_termo(no);
	atualizar_altura_termo(no_filho);
}

void inserir_termo(ARVORE_AVL_TERMOS **raiz, char *termo, ARVORE_AVL_TERMOS **aux){

	int fator_balanceamento_raiz, fator_balanceamento_filho;

	if(*raiz != NULL){
		if(ordem_alfabetica(termo, (*raiz)->termo) == -1){
			inserir_termo(&((*raiz)->esquerda), termo, aux);
			(*raiz)->esquerda->pai = *raiz;
		}else if(ordem_alfabetica(termo, (*raiz)->termo) == 1){ 
			inserir_termo(&((*raiz)->direita), termo, aux);
			(*raiz)->direita->pai = *raiz;
		}

		// DESCOBRIR QUAL ROTAÇÃO FAZER OU SE NÃO É NECESSÁRIO ROTAÇÃO
		fator_balanceamento_raiz = fator_balanceamento_termo(*raiz);

		if(1 < fator_balanceamento_raiz){// ROTAÇÃO PARA A DIREITA
			fator_balanceamento_filho = fator_balanceamento_termo((*raiz)->esquerda);

			if(fator_balanceamento_filho < 0)// ROTAÇÃO DUPLA
				rotacao_para_esquerda_termo(&((*raiz)->esquerda));

			rotacao_para_direita_termo(raiz);				
		}else if(fator_balanceamento_raiz < -1){//ROTAÇÃO PARA A ESQUERDA
			fator_balanceamento_filho = fator_balanceamento_termo((*raiz)->direita);

			if(fator_balanceamento_filho > 0)// ROTAÇÃO DUPLA
				rotacao_para_direita_termo(&((*raiz)->direita));
				
			rotacao_para_esquerda_termo(raiz);
		}else
			atualizar_altura_termo(*raiz);
	}else{
		*raiz = criar_no_termo(termo);
		*aux = *raiz;
	}
}

void desalocar_arvore_termo(ARVORE_AVL_TERMOS *raiz){

	if(raiz != NULL){
		desalocar_arvore_termo(raiz->esquerda);
		desalocar_arvore_termo(raiz->direita);
		liberar_string(raiz->termo);
		desalocar_arvore_paginas(raiz->paginas);
		desalocar_arvore_sub_termo(raiz->sub_termos);
		free(raiz);
	}
}

void print_termos(ARVORE_AVL_TERMOS *raiz){

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

ARVORE_AVL_TERMOS *buscar_termo(ARVORE_AVL_TERMOS *raiz, char *termo){
	
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
