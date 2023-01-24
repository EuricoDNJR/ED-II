#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
	int valor;
	struct no *esquerda, *direita;
}ARVORE_BINARIA;


ARVORE_BINARIA *criar_no(int valor);
void inserir(ARVORE_BINARIA **raiz, int valor);
void desalocar_arvore(ARVORE_BINARIA *raiz);
void in_ordem(ARVORE_BINARIA *raiz);
ARVORE_BINARIA *buscar(ARVORE_BINARIA *raiz, int numero);


#endif