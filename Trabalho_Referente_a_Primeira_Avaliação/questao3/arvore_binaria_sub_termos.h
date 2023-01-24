#ifndef ARVORE_BINARIA_SUB_TERMOS_H
#define ARVORE_BINARIA_SUB_TERMOS_H

#include <stdio.h>
#include <stdlib.h>
#include "operacoesString.h"
#include "arvore_binaria_paginas.h"


typedef struct no_sub_termo
{
	char *sub_termo;
	struct no_sub_termo *esquerda, *direita;
	ARVORE_BINARIA_PAGINAS *paginas;
}ARVORE_BINARIA_SUB_TERMOS;


ARVORE_BINARIA_SUB_TERMOS *criar_no_sub_termo(char *sub_termo);
void inserir_sub_termo(ARVORE_BINARIA_SUB_TERMOS **raiz, char *sub_termo, ARVORE_BINARIA_SUB_TERMOS **aux);
void desalocar_arvore_sub_termo(ARVORE_BINARIA_SUB_TERMOS *raiz);
void print_sub_termos(ARVORE_BINARIA_SUB_TERMOS *raiz);
ARVORE_BINARIA_SUB_TERMOS *buscar_sub_termo(ARVORE_BINARIA_SUB_TERMOS *raiz, char *sub_termo);


#endif