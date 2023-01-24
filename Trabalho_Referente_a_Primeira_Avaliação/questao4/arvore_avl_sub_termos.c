#include "arvore_avl_sub_termos.h"


ARVORE_AVL_SUB_TERMOS *criar_no_sub_termo(char *sub_termo){
	ARVORE_AVL_SUB_TERMOS *no = (ARVORE_AVL_SUB_TERMOS *)malloc(sizeof(ARVORE_AVL_SUB_TERMOS));

	copiar_string(&(no->sub_termo), sub_termo);
	no->altura = 0;
	no->esquerda = NULL;
	no->direita = NULL;
	no->pai = NULL;
	no->paginas = NULL;

	return no;
}

int fator_balanceamento_sub_termos(ARVORE_AVL_SUB_TERMOS *raiz){

	int fator_balanceamento_sub_termos, altura_esquerda=-1, altura_direita=-1;

	if(raiz->esquerda != NULL)
		altura_esquerda = raiz->esquerda->altura;

	if(raiz->direita != NULL)
		altura_direita = raiz->direita->altura;

	fator_balanceamento_sub_termos = altura_esquerda - altura_direita;

	return fator_balanceamento_sub_termos;
}

void atualizar_altura_sub_termos(ARVORE_AVL_SUB_TERMOS *raiz){

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

void modificar_filho_sub_termos(ARVORE_AVL_SUB_TERMOS **raiz,  ARVORE_AVL_SUB_TERMOS *no){

	ARVORE_AVL_SUB_TERMOS *pai = (*raiz)->pai;

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

void rotacao_para_esquerda_sub_termos(ARVORE_AVL_SUB_TERMOS **raiz){

	ARVORE_AVL_SUB_TERMOS *no = *raiz, *no_filho = (*raiz)->direita;

	no->direita = no_filho->esquerda;
	if(no->direita != NULL)
		no->direita->pai = no;
	no_filho->esquerda = no;

	modificar_filho_sub_termos(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura_sub_termos(no);
	atualizar_altura_sub_termos(no_filho);
}

void rotacao_para_direita_sub_termos(ARVORE_AVL_SUB_TERMOS **raiz){

	ARVORE_AVL_SUB_TERMOS *no = *raiz, *no_filho = (*raiz)->esquerda;

	no->esquerda = no_filho->direita;
	if(no->esquerda != NULL)
		no->esquerda->pai = no;
	no_filho->direita = no;

	modificar_filho_sub_termos(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura_sub_termos(no);
	atualizar_altura_sub_termos(no_filho);
}

void inserir_sub_termo(ARVORE_AVL_SUB_TERMOS **raiz, char *sub_termo, ARVORE_AVL_SUB_TERMOS **aux){

	int fator_balanceamento_raiz, fator_balanceamento_filho;

	if(*raiz != NULL){
		if(ordem_alfabetica(sub_termo, (*raiz)->sub_termo) == -1){
			inserir_sub_termo(&((*raiz)->esquerda), sub_termo, aux);
			(*raiz)->esquerda->pai = *raiz;
		}else if(ordem_alfabetica(sub_termo, (*raiz)->sub_termo) == 1){ 
			inserir_sub_termo(&((*raiz)->direita), sub_termo, aux);
			(*raiz)->direita->pai = *raiz;
		}

		// DESCOBRIR QUAL ROTAÇÃO FAZER OU SE NÃO É NECESSÁRIO ROTAÇÃO
		fator_balanceamento_raiz = fator_balanceamento_sub_termos(*raiz);

		if(1 < fator_balanceamento_raiz){// ROTAÇÃO PARA A DIREITA
			fator_balanceamento_filho = fator_balanceamento_sub_termos((*raiz)->esquerda);

			if(fator_balanceamento_filho < 0)// ROTAÇÃO DUPLA
				rotacao_para_esquerda_sub_termos(&((*raiz)->esquerda));

			rotacao_para_direita_sub_termos(raiz);				
		}else if(fator_balanceamento_raiz < -1){//ROTAÇÃO PARA A ESQUERDA
			fator_balanceamento_filho = fator_balanceamento_sub_termos((*raiz)->direita);

			if(fator_balanceamento_filho > 0)// ROTAÇÃO DUPLA
				rotacao_para_direita_sub_termos(&((*raiz)->direita));
				
			rotacao_para_esquerda_sub_termos(raiz);
		}else
			atualizar_altura_sub_termos(*raiz);
	}else{
		*raiz = criar_no_sub_termo(sub_termo);
		*aux = *raiz;
	}
}

void desalocar_arvore_sub_termo(ARVORE_AVL_SUB_TERMOS *raiz){

	if(raiz != NULL){
		desalocar_arvore_sub_termo(raiz->esquerda);
		desalocar_arvore_sub_termo(raiz->direita);
		liberar_string(raiz->sub_termo);
		desalocar_arvore_paginas(raiz->paginas);
		free(raiz);
	}
}

void print_sub_termos(ARVORE_AVL_SUB_TERMOS *raiz){

	if(raiz != NULL){
		print_sub_termos(raiz->esquerda);
		printf("\t%s ", raiz->sub_termo);
		print_paginas(raiz->paginas);
		printf("\n");
		print_sub_termos(raiz->direita);
	}
}


ARVORE_AVL_SUB_TERMOS *buscar_sub_termo(ARVORE_AVL_SUB_TERMOS *raiz, char *sub_termo){
	
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

