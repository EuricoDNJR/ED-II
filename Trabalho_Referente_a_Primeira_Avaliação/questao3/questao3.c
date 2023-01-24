#include "arvore_binaria_termos.h"
#include <time.h> 
#include <stdlib.h>

int main(){
	struct timespec tempo_inicial, tempo_final;

	ARVORE_BINARIA_TERMOS *raiz = NULL, *termo = NULL, *aux = NULL;
	ARVORE_BINARIA_SUB_TERMOS *sub_termo = NULL, *aux2 = NULL;

	clock_gettime(CLOCK_REALTIME, &tempo_inicial);
	inserir_termo(&raiz, "assim", &aux);
	termo = aux;
	inserir_pagina(&(termo->paginas), 134);
	inserir_pagina(&(termo->paginas), 93);
	inserir_pagina(&(termo->paginas), 157);
	inserir_pagina(&(termo->paginas), 294);
	inserir_pagina(&(termo->paginas), 13);

	inserir_sub_termo(&(termo->sub_termos), "joga no mato", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 15);
	inserir_pagina(&(sub_termo->paginas), 24);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_sub_termo(&(termo->sub_termos), "sei la", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 79);
	inserir_pagina(&(sub_termo->paginas), 45);
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_sub_termo(&(termo->sub_termos), "joga no crato", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_termo(&raiz, "kaka", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);
	inserir_pagina(&(termo->paginas), 77);
	inserir_pagina(&(termo->paginas), 152);

	inserir_sub_termo(&(termo->sub_termos), "e ruim", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4)&&;
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "joga de patins", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 17);
	inserir_pagina(&(sub_termo->paginas), 99);
	inserir_pagina(&(sub_termo->paginas), 55);
	inserir_pagina(&(sub_termo->paginas), 54);

	inserir_sub_termo(&(termo->sub_termos), "joga bomba patch", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 14);
	inserir_pagina(&(sub_termo->paginas), 25);
	inserir_pagina(&(sub_termo->paginas), 59);
	inserir_pagina(&(sub_termo->paginas), 70);

	inserir_sub_termo(&(termo->sub_termos), "joga xadrez", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 8);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 7);

	inserir_termo(&raiz, "luscas", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);
	inserir_pagina(&(termo->paginas), 77);
	inserir_pagina(&(termo->paginas), 152);

	inserir_sub_termo(&(termo->sub_termos), "empina na moto", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "da uma cambalhota", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 17);
	inserir_pagina(&(sub_termo->paginas), 99);
	inserir_pagina(&(sub_termo->paginas), 55);
	inserir_pagina(&(sub_termo->paginas), 54);

	inserir_sub_termo(&(termo->sub_termos), "joga pokemon", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 14);
	inserir_pagina(&(sub_termo->paginas), 25);
	inserir_pagina(&(sub_termo->paginas), 59);
	inserir_pagina(&(sub_termo->paginas), 70);

	inserir_sub_termo(&(termo->sub_termos), "pro player", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 8);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 11);
	inserir_pagina(&(sub_termo->paginas), 15);

	inserir_termo(&raiz, "matue", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 134);
	inserir_pagina(&(termo->paginas), 93);
	inserir_pagina(&(termo->paginas), 157);
	inserir_pagina(&(termo->paginas), 294);
	inserir_pagina(&(termo->paginas), 13);

	inserir_sub_termo(&(termo->sub_termos), "voador", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 15);
	inserir_pagina(&(sub_termo->paginas), 24);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_sub_termo(&(termo->sub_termos), "artilheiro", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 79);
	inserir_pagina(&(sub_termo->paginas), 45);
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_sub_termo(&(termo->sub_termos), "importante", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_termo(&raiz, "eurecs", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);

	inserir_sub_termo(&(termo->sub_termos), "so to existindo", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);

	inserir_termo(&raiz, "mikazeldris", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 134);
	inserir_pagina(&(termo->paginas), 93);
	inserir_pagina(&(termo->paginas), 294);
	inserir_pagina(&(termo->paginas), 13);

	inserir_sub_termo(&(termo->sub_termos), "brabo", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 15);
	inserir_pagina(&(sub_termo->paginas), 24);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_sub_termo(&(termo->sub_termos), "monstro", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 45);
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_termo(&raiz, "philips", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 134);
	inserir_pagina(&(termo->paginas), 93);
	inserir_pagina(&(termo->paginas), 157);
	inserir_pagina(&(termo->paginas), 294);
	inserir_pagina(&(termo->paginas), 13);

	inserir_sub_termo(&(termo->sub_termos), "bombado", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 24);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_sub_termo(&(termo->sub_termos), "trincado", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 45);
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_sub_termo(&(termo->sub_termos), "bomba do rato", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_termo(&raiz, "jeandzz", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);
	inserir_pagina(&(termo->paginas), 77);

	inserir_sub_termo(&(termo->sub_termos), "galego", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "jogador de lol", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 17);
	inserir_pagina(&(sub_termo->paginas), 99);
	inserir_pagina(&(sub_termo->paginas), 54);

	inserir_sub_termo(&(termo->sub_termos), "estudioso", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 14);
	inserir_pagina(&(sub_termo->paginas), 25);
	inserir_pagina(&(sub_termo->paginas), 70);

	inserir_sub_termo(&(termo->sub_termos), "brabo demais", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 8);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 15);

	inserir_termo(&raiz, "welson", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 93);

	inserir_sub_termo(&(termo->sub_termos), "gatao", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 24);

	inserir_sub_termo(&(termo->sub_termos), "joga rocket league", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_termo(&raiz, "moto", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 134);
	inserir_pagina(&(termo->paginas), 294);
	inserir_pagina(&(termo->paginas), 13);

	inserir_sub_termo(&(termo->sub_termos), "quebrada", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 24);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_sub_termo(&(termo->sub_termos), "turbinada", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 45);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 7);

	inserir_termo(&raiz, "aviao", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 134);
	inserir_pagina(&(termo->paginas), 93);
	inserir_pagina(&(termo->paginas), 157);
	inserir_pagina(&(termo->paginas), 294);
	inserir_pagina(&(termo->paginas), 13);

	inserir_sub_termo(&(termo->sub_termos), "planador", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 24);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_sub_termo(&(termo->sub_termos), "cheio", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 45);
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_sub_termo(&(termo->sub_termos), "vazio", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 1);

	inserir_termo(&raiz, "boby", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 222);
	inserir_pagina(&(termo->paginas), 500);
	inserir_pagina(&(termo->paginas), 422);
	inserir_pagina(&(termo->paginas), 33);

	inserir_sub_termo(&(termo->sub_termos), "esponja", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_termo(&raiz, "flavin", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 55);
	inserir_pagina(&(termo->paginas), 3);
	inserir_pagina(&(termo->paginas), 1);
	inserir_pagina(&(termo->paginas), 7);

	inserir_sub_termo(&(termo->sub_termos), "autopecas", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "mecanico", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 17);
	inserir_pagina(&(sub_termo->paginas), 99);

	inserir_termo(&raiz, "cachorro", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);
	inserir_pagina(&(termo->paginas), 77);

	inserir_sub_termo(&(termo->sub_termos), "doido", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "atleta", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 99);
	inserir_pagina(&(sub_termo->paginas), 54);

	inserir_sub_termo(&(termo->sub_termos), "carinhoso", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 14);
	inserir_pagina(&(sub_termo->paginas), 25);
	inserir_pagina(&(sub_termo->paginas), 70);

	inserir_sub_termo(&(termo->sub_termos), "docil", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 8);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 15);

	inserir_termo(&raiz, "caminhao", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 137);
	inserir_pagina(&(termo->paginas), 295);
	inserir_pagina(&(termo->paginas), 122);

	inserir_sub_termo(&(termo->sub_termos), "economico", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);

	inserir_termo(&raiz, "estrada", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 131);

	inserir_sub_termo(&(termo->sub_termos), "mal feita", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);

	inserir_termo(&raiz, "patrick", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 93);

	inserir_sub_termo(&(termo->sub_termos), "estrela", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 24);

	inserir_sub_termo(&(termo->sub_termos), "rosa", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 5);
	inserir_pagina(&(sub_termo->paginas), 78);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 6);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 222);

	inserir_termo(&raiz, "piaba", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);
	inserir_pagina(&(termo->paginas), 77);

	inserir_sub_termo(&(termo->sub_termos), "grande homem", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "cratos", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 17);
	inserir_pagina(&(sub_termo->paginas), 99);
	inserir_pagina(&(sub_termo->paginas), 54);

	inserir_sub_termo(&(termo->sub_termos), "dedicado", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 14);
	inserir_pagina(&(sub_termo->paginas), 25);
	inserir_pagina(&(sub_termo->paginas), 70);

	inserir_termo(&raiz, "panda", &aux);
	termo = aux;
	
	inserir_pagina(&(termo->paginas), 155);
	inserir_pagina(&(termo->paginas), 23);
	inserir_pagina(&(termo->paginas), 25);
	inserir_pagina(&(termo->paginas), 77);

	inserir_sub_termo(&(termo->sub_termos), "fofinho", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 4);
	inserir_pagina(&(sub_termo->paginas), 10);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 18);

	inserir_sub_termo(&(termo->sub_termos), "maneiro", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 3);
	inserir_pagina(&(sub_termo->paginas), 17);
	inserir_pagina(&(sub_termo->paginas), 99);
	inserir_pagina(&(sub_termo->paginas), 54);

	inserir_sub_termo(&(termo->sub_termos), "preto e branco", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 14);
	inserir_pagina(&(sub_termo->paginas), 25);
	inserir_pagina(&(sub_termo->paginas), 70);

	inserir_sub_termo(&(termo->sub_termos), "comilao", &aux2);
	sub_termo = aux2;
	inserir_pagina(&(sub_termo->paginas), 8);
	inserir_pagina(&(sub_termo->paginas), 2);
	inserir_pagina(&(sub_termo->paginas), 9);
	inserir_pagina(&(sub_termo->paginas), 7);
	inserir_pagina(&(sub_termo->paginas), 15);

	clock_gettime(CLOCK_REALTIME, &tempo_final);
	double total = (tempo_final.tv_nsec - tempo_inicial.tv_nsec);
	printf("Tempo de insercao = %lf\n", total);

	clock_gettime(CLOCK_REALTIME, &tempo_inicial);
	aux = buscar_termo(raiz, "piaba");
	aux2 = buscar_sub_termo(aux->sub_termos, "grande homem");

	aux = buscar_termo(raiz, "moto");
	aux2 = buscar_sub_termo(aux->sub_termos, "acelera");

	aux = buscar_termo(raiz, "helicoptero");

	aux = buscar_termo(raiz, "cachorro");
	aux2 = buscar_sub_termo(aux->sub_termos, "atleta");

	aux = buscar_termo(raiz, "flavin");
	aux2 = buscar_sub_termo(aux->sub_termos, "do pneu");

	aux = buscar_termo(raiz, "jorginho");

	aux = buscar_termo(raiz, "caminhao");
	aux2 = buscar_sub_termo(aux->sub_termos, "economico");

	aux = buscar_termo(raiz, "boby");
	aux2 = buscar_sub_termo(aux->sub_termos, "esponja");

	aux = buscar_termo(raiz, "linda");

	aux = buscar_termo(raiz, "philips");
	aux2 = buscar_sub_termo(aux->sub_termos, "trincado");

	aux = buscar_termo(raiz, "mikazeldris");
	aux2 = buscar_sub_termo(aux->sub_termos, "zoiudo");

	aux = buscar_termo(raiz, "fafa de belem");

	aux = buscar_termo(raiz, "moto");
	aux2 = buscar_sub_termo(aux->sub_termos, "quebrada");

	aux = buscar_termo(raiz, "matue");
	aux2 = buscar_sub_termo(aux->sub_termos, "pao");

	aux = buscar_termo(raiz, "roberto carlos");

	aux = buscar_termo(raiz, "kaka");
	aux2 = buscar_sub_termo(aux->sub_termos, "e ruim");

	aux = buscar_termo(raiz, "panda");
	aux2 = buscar_sub_termo(aux->sub_termos, "pula muito");

	aux = buscar_termo(raiz, "xandao");
	clock_gettime(CLOCK_REALTIME, &tempo_final);
	total = (tempo_final.tv_nsec - tempo_inicial.tv_nsec);
	printf("Tempo de busca = %lf\n", total);
	
	print_termos(raiz);

	desalocar_arvore_termo(raiz);
	

	return 0;
}
