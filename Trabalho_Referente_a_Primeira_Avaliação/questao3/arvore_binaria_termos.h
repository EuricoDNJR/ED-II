#ifndef ARVORE_BINARIA_TERMOS_H
#define ARVORE_BINARIA_TERMOS_H

#include <stdio.h>
#include <stdlib.h>
#include "operacoesString.h"
#include "arvore_binaria_paginas.h"
#include "arvore_binaria_sub_termos.h"


typedef struct no_termo
{
	char *termo;
	struct no_termo *esquerda, *direita;
	ARVORE_BINARIA_PAGINAS *paginas;
	ARVORE_BINARIA_SUB_TERMOS *sub_termos;
}ARVORE_BINARIA_TERMOS;


ARVORE_BINARIA_TERMOS *criar_no_termo(char *termo);
void inserir_termo(ARVORE_BINARIA_TERMOS **raiz, char *termo, ARVORE_BINARIA_TERMOS **aux);
void desalocar_arvore_termo(ARVORE_BINARIA_TERMOS *raiz);
void print_termos(ARVORE_BINARIA_TERMOS *raiz);
ARVORE_BINARIA_TERMOS *buscar_termo(ARVORE_BINARIA_TERMOS *raiz, char *termo);

#endif