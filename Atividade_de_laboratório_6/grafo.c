#include <stdio.h>
#include <stdlib.h>


struct Aresta{
    int vertice_destino; 
    struct Aresta *prox;
};

struct Vertice{
	int valor;
    struct Aresta *vertices_adjacentes;
};

struct Grafo{ 
    int quantidade_vertices; 
    int quantidade_arestas;
    struct Vertice *vertices;
};


struct Grafo *criar_grafo(){

	struct Grafo *grafo = (struct Grafo *)malloc(sizeof(struct Grafo));

	grafo->quantidade_vertices = 0;
	grafo->quantidade_arestas = 0;
	grafo->vertices = NULL;

	return grafo;
}	

void inserir_vertice(struct Grafo *grafo, int valor){

	struct Vertice *aux = grafo->vertices, novo;

	novo.valor = valor;
	novo.vertices_adjacentes = NULL;

	grafo->vertices = (struct Vertice *)realloc(grafo->vertices, sizeof(struct Vertice) * (grafo->quantidade_vertices + 1));

	grafo->vertices[grafo->quantidade_vertices] = novo;

	grafo->quantidade_vertices++;
}

void adicionar_vertice_adjacente(struct Vertice *vertice, int vertice_adjacente){

	struct Aresta *aux_aresta = vertice->vertices_adjacentes, *novo = (struct Aresta *)malloc(sizeof(struct Aresta));

	novo->vertice_destino = vertice_adjacente;
	novo->prox = NULL;

	if(aux_aresta == NULL){
		vertice->vertices_adjacentes = novo;
	}else{
		while(aux_aresta->prox != NULL)
			aux_aresta = aux_aresta->prox;
				
		aux_aresta->prox = novo;
	}
}

void inserir_aresta(struct Grafo *grafo, int vertice_inicial, int vertice_final){

	if(grafo != NULL){
		if(0 <= vertice_inicial && vertice_inicial < grafo->quantidade_vertices && 0 <= vertice_final && vertice_final < grafo->quantidade_vertices ){
			adicionar_vertice_adjacente((grafo->vertices) + vertice_final, vertice_inicial);
			adicionar_vertice_adjacente((grafo->vertices) + vertice_inicial, vertice_final);

			grafo->quantidade_arestas++;
		}
	}
}

void imprime(struct Grafo *grafo){

	struct Aresta *aux_aresta;
	int i;

	printf("Quantidade de vertices: %d\n", grafo->quantidade_vertices);
	printf("Quantidade de arestas: %d\n", grafo->quantidade_arestas);
	
	for(i=0; i<grafo->quantidade_vertices; i++){
		printf("Vertice %d valor: %d\n", i, grafo->vertices[i].valor);

		aux_aresta = grafo->vertices[i].vertices_adjacentes;

		while(aux_aresta != NULL){
			printf("\tVertice adjacente: %d\n", aux_aresta->vertice_destino);
			aux_aresta = aux_aresta->prox;
		}
	
	}
}

void busca_profundidade(struct Grafo *grafo, int vertice_inicial, int *distancia, int conta_distancia){
	
	struct Aresta *aux_aresta = grafo->vertices[vertice_inicial].vertices_adjacentes;

    distancia[vertice_inicial] = conta_distancia;

    while(aux_aresta != NULL){
        if(distancia[aux_aresta->vertice_destino] == 0 || distancia[aux_aresta->vertice_destino] > conta_distancia+1)
            busca_profundidade(grafo, aux_aresta->vertice_destino, distancia, conta_distancia+1);

        aux_aresta = aux_aresta->prox;
    }
}

void busca_largura(struct Grafo *grafo, int vertice_inicial, int *distancia, int conta_distancia){
	
	struct Aresta *aux_aresta = grafo->vertices[vertice_inicial].vertices_adjacentes;
	int *lista=NULL, tam=0, i;

	distancia[vertice_inicial] = conta_distancia++;

    while(aux_aresta != NULL){
        if(distancia[aux_aresta->vertice_destino] == 0){
        	distancia[aux_aresta->vertice_destino] = conta_distancia;
        	lista = (int *)realloc(lista, sizeof(int) * (tam+1));
        	lista[tam++] = aux_aresta->vertice_destino;
        }
        
        aux_aresta = aux_aresta->prox;
    }

    for(i=0; i<tam; i++){
    	aux_aresta = grafo->vertices[lista[i]].vertices_adjacentes;
    	conta_distancia++;

    	while(aux_aresta != NULL){
	        if(distancia[aux_aresta->vertice_destino] == 0){
	        	distancia[aux_aresta->vertice_destino] = conta_distancia;
	        	lista = (int *)realloc(lista, sizeof(int) * (tam+1));
	        	lista[tam++] = aux_aresta->vertice_destino;
	        }
	        
	        aux_aresta = aux_aresta->prox;
	    }
    }
}

void desalocar_arestas(struct Aresta *aresta){

	if(aresta != NULL){
		desalocar_arestas(aresta->prox);
		free(aresta);
	}
}

void desalocar_grafo(struct Grafo *grafo){

	int i;

	for(i=0; i<grafo->quantidade_vertices; i++)
		desalocar_arestas(grafo->vertices[i].vertices_adjacentes);
	free(grafo->vertices);
	free(grafo);
}


int main(){
	
	struct Grafo *grafo = criar_grafo();
	int *distancia = NULL, i;

	inserir_vertice(grafo, 5); // INDICE 0
	inserir_vertice(grafo, 4); // INDICE 1
	inserir_vertice(grafo, 3); // INDICE 2
	inserir_vertice(grafo, 1); // INDICE 3
	inserir_vertice(grafo, 1); // INDICE 4

	inserir_aresta(grafo, 0, 1);
	inserir_aresta(grafo, 0, 3);
	inserir_aresta(grafo, 1, 2);
	inserir_aresta(grafo, 1, 3);
	inserir_aresta(grafo, 1, 4);
	inserir_aresta(grafo, 2, 4);
	inserir_aresta(grafo, 3, 4);

    imprime(grafo);


    distancia = (int *)calloc(grafo->quantidade_vertices, sizeof(int));
   	busca_profundidade(grafo, 0, distancia, 1);
   	for(i=0; i<grafo->quantidade_vertices; i++){
   		printf("%d ", distancia[i]);
   	}
   	printf("\n");
   	free(distancia);

   	distancia = (int *)calloc(grafo->quantidade_vertices, sizeof(int));
   	busca_largura(grafo, 0, distancia, 1);
   	for(i=0; i<grafo->quantidade_vertices; i++){
   		printf("%d ", distancia[i]);
   	}
   	printf("\n");
   	free(distancia);


    desalocar_grafo(grafo);

    return 0;
}