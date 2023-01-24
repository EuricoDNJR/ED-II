#include "arvore_avl.h"


ARVORE_BINARIA *criar_no(int valor){
	ARVORE_BINARIA *no = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));

	no->valor = valor;
	no->altura = 0;
	no->esquerda = NULL;
	no->direita = NULL;
	no->pai = NULL;

	return no;
}

int fator_balanceamento(ARVORE_BINARIA *raiz){

	int fator_balanceamento, altura_esquerda=-1, altura_direita=-1;

	if(raiz->esquerda != NULL)
		altura_esquerda = raiz->esquerda->altura;

	if(raiz->direita != NULL)
		altura_direita = raiz->direita->altura;

	fator_balanceamento = altura_esquerda - altura_direita;

	return fator_balanceamento;
}

void atualizar_altura(ARVORE_BINARIA *raiz){

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

void modificar_filho(ARVORE_BINARIA **raiz,  ARVORE_BINARIA *no){

	ARVORE_BINARIA *pai = (*raiz)->pai;

	no->pai = pai;

	if(pai == NULL){
		*raiz = no;
	}else if(pai->esquerda == *raiz){
		pai->esquerda = no;
	}else{
		pai->direita = no;
	}
}

void rotacao_para_esquerda(ARVORE_BINARIA **raiz){

	ARVORE_BINARIA *no = *raiz, *no_filho = (*raiz)->direita;

	no->direita = no_filho->esquerda;
	if(no->direita != NULL)
		no->direita->pai = no;
	no_filho->esquerda = no;

	modificar_filho(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura(no);
	atualizar_altura(no_filho);
}

void rotacao_para_direita(ARVORE_BINARIA **raiz){

	ARVORE_BINARIA *no = *raiz, *no_filho = (*raiz)->esquerda;

	no->esquerda = no_filho->direita;
	if(no->esquerda != NULL)
		no->esquerda->pai = no;
	no_filho->direita = no;

	modificar_filho(raiz, no_filho);
	no->pai = no_filho;

	atualizar_altura(no);
	atualizar_altura(no_filho);
}


void inserir(ARVORE_BINARIA **raiz, int valor){

	int fator_balanceamento_raiz, fator_balanceamento_filho;

	if(*raiz != NULL){
		// INSERIR
		if(valor < (*raiz)->valor){
			inserir(&((*raiz)->esquerda), valor);
			(*raiz)->esquerda->pai = *raiz;
		}else{
			inserir(&((*raiz)->direita), valor);
			(*raiz)->direita->pai = *raiz;
		}


		// DESCOBRIR QUAL ROTAÇÃO FAZER OU SE NÃO É NECESSÁRIO ROTAÇÃO
		fator_balanceamento_raiz = fator_balanceamento(*raiz);

		if(1 < fator_balanceamento_raiz){// ROTAÇÃO PARA A DIREITA
			fator_balanceamento_filho = fator_balanceamento((*raiz)->esquerda);

			if(fator_balanceamento_filho < 0)// ROTAÇÃO DUPLA
				rotacao_para_esquerda(&((*raiz)->esquerda));

			rotacao_para_direita(raiz);				
		}else if(fator_balanceamento_raiz < -1){//ROTAÇÃO PARA A ESQUERDA
			fator_balanceamento_filho = fator_balanceamento((*raiz)->direita);

			if(fator_balanceamento_filho > 0)// ROTAÇÃO DUPLA
				rotacao_para_direita(&((*raiz)->direita));
				
			rotacao_para_esquerda(raiz);
		}else
			atualizar_altura(*raiz);
	}else
		*raiz = criar_no(valor);
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
		printf("FB: %d\n\n", fator_balanceamento(raiz));
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
