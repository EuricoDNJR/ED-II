#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
	int valor;
	int altura;
	struct no *esquerda, *direita, *pai;
}ARVORE_BINARIA;


ARVORE_BINARIA *criar_no(int valor);
int fator_balanceamento(ARVORE_BINARIA *raiz);
void atualizar_altura(ARVORE_BINARIA *raiz);
void modificar_filho(ARVORE_BINARIA **raiz,  ARVORE_BINARIA *no);
void rotacao_para_esquerda(ARVORE_BINARIA **raiz);
void rotacao_para_direita(ARVORE_BINARIA **raiz);

void inserir(ARVORE_BINARIA **raiz, int valor);
void desalocar_arvore(ARVORE_BINARIA *raiz);
void in_ordem(ARVORE_BINARIA *raiz);
ARVORE_BINARIA *buscar(ARVORE_BINARIA *raiz, int numero);


#endif