#ifndef ARVORE_BINARIA_PAGINAS_H
#define ARVORE_BINARIA_PAGINAS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct no_paginas
{
	int numero_pagina;
	struct no_paginas *esquerda, *direita;
}ARVORE_BINARIA_PAGINAS;


ARVORE_BINARIA_PAGINAS *criar_no_pagina(int numero_pagina);
void inserir_pagina(ARVORE_BINARIA_PAGINAS **raiz, int numero_pagina);
void desalocar_arvore_paginas(ARVORE_BINARIA_PAGINAS *raiz);
void print_paginas(ARVORE_BINARIA_PAGINAS *raiz);


#endif