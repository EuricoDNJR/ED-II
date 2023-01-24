#ifndef ARVORE_AVL_TERMOS_H
#define ARVORE_AVL_TERMOS_H

#include <stdio.h>
#include <stdlib.h>
#include "operacoesString.h"
#include "arvore_avl_paginas.h"
#include "arvore_avl_sub_termos.h"


typedef struct no_termo
{
	char *termo;
	struct no_termo *esquerda, *direita, *pai;
	int altura;
	ARVORE_AVL_PAGINAS *paginas;
	ARVORE_AVL_SUB_TERMOS *sub_termos;
}ARVORE_AVL_TERMOS;


ARVORE_AVL_TERMOS *criar_no_termo(char *termo);
int fator_balanceamento_termo(ARVORE_AVL_TERMOS *raiz);
void atualizar_altura_termo(ARVORE_AVL_TERMOS *raiz);
void modificar_filho_termo(ARVORE_AVL_TERMOS **raiz,  ARVORE_AVL_TERMOS *no);
void rotacao_para_esquerda_termo(ARVORE_AVL_TERMOS **raiz);
void rotacao_para_direita_termo(ARVORE_AVL_TERMOS **raiz);

void inserir_termo(ARVORE_AVL_TERMOS **raiz, char *termo, ARVORE_AVL_TERMOS **aux);
void desalocar_arvore_termo(ARVORE_AVL_TERMOS *raiz);
void print_termos(ARVORE_AVL_TERMOS *raiz);
ARVORE_AVL_TERMOS *buscar_termo(ARVORE_AVL_TERMOS *raiz, char *termo);


#endif