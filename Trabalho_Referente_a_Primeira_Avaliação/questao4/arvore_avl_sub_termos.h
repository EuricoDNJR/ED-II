#ifndef ARVORE_AVL_SUB_TERMOS_H
#define ARVORE_AVL_SUB_TERMOS_H

#include <stdio.h>
#include <stdlib.h>
#include "operacoesString.h"
#include "arvore_avl_paginas.h"


typedef struct no_sub_termo
{
	char *sub_termo;
	struct no_sub_termo *esquerda, *direita, *pai;
	int altura;
	ARVORE_AVL_PAGINAS *paginas;
}ARVORE_AVL_SUB_TERMOS;


ARVORE_AVL_SUB_TERMOS *criar_no_sub_termo(char *sub_termo);
int fator_balanceamento_sub_termos(ARVORE_AVL_SUB_TERMOS *raiz);
void atualizar_altura_sub_termos(ARVORE_AVL_SUB_TERMOS *raiz);
void modificar_filho_sub_termos(ARVORE_AVL_SUB_TERMOS **raiz,  ARVORE_AVL_SUB_TERMOS *no);
void rotacao_para_esquerda_sub_termos(ARVORE_AVL_SUB_TERMOS **raiz);
void rotacao_para_direita_sub_termos(ARVORE_AVL_SUB_TERMOS **raiz);

void inserir_sub_termo(ARVORE_AVL_SUB_TERMOS **raiz, char *sub_termo, ARVORE_AVL_SUB_TERMOS **aux);
void desalocar_arvore_sub_termo(ARVORE_AVL_SUB_TERMOS *raiz);
void print_sub_termos(ARVORE_AVL_SUB_TERMOS *raiz);
ARVORE_AVL_SUB_TERMOS *buscar_sub_termo(ARVORE_AVL_SUB_TERMOS *raiz, char *sub_termo);


#endif