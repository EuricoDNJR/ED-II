#ifndef ARVORE_AVL_PAGINAS_H
#define ARVORE_AVL_PAGINAS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct no_paginas
{
	int numero_pagina;
	int altura;
	struct no_paginas *esquerda, *direita, *pai;
}ARVORE_AVL_PAGINAS;


ARVORE_AVL_PAGINAS *criar_no_pagina(int numero_pagina);
int fator_balanceamento_paginas(ARVORE_AVL_PAGINAS *raiz);
void atualizar_altura_paginas(ARVORE_AVL_PAGINAS *raiz);
void modificar_filho_paginas(ARVORE_AVL_PAGINAS **raiz,  ARVORE_AVL_PAGINAS *no);
void rotacao_para_esquerda_paginas(ARVORE_AVL_PAGINAS **raiz);
void rotacao_para_direita_paginas(ARVORE_AVL_PAGINAS **raiz);

void inserir_pagina(ARVORE_AVL_PAGINAS **raiz, int numero_pagina);
void desalocar_arvore_paginas(ARVORE_AVL_PAGINAS *raiz);
void print_paginas(ARVORE_AVL_PAGINAS *raiz);


#endif