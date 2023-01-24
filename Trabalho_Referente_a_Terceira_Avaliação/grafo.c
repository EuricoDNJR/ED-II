#include <stdio.h>
#include <stdlib.h>

struct grafos{
	int ehPonderado;
	int nVertices;
	int **arestas;
	float **pesos;
	int *grau;
};

typedef struct grafos Grafo;


Grafo* criaGrafo(int Vertices, int ehPonderado){

	int i;
	Grafo *gr;

	gr = (Grafo *) malloc(sizeof(struct grafos));

	if(gr != NULL){
		gr->nVertices = Vertices;
		gr->ehPonderado = ehPonderado;
		gr->grau = (int *) calloc(Vertices,sizeof(int));
		gr->arestas = (int **) malloc(Vertices*sizeof(int*));

		// LISTA DE ADJACÊNCIA
		for(i=0;i < Vertices;i++){
			gr->arestas[i] = (int *) malloc(Vertices*sizeof(int));
		}

		if(gr->ehPonderado){
			gr->pesos = (float **) malloc(Vertices*sizeof(float*));

			for(i=0;i < Vertices;i++){
				gr->pesos[i] = (float *) malloc(Vertices*sizeof(float));
			}
		}else{
			gr->pesos = NULL;
		}
	}

	return gr;
}

void liberaGrafo(Grafo* gr){
	int i;

	if(gr != NULL){
		for(i=0;i < gr->nVertices;i++)
			free(gr->arestas[i]);
		free(gr->arestas);
		if(gr->ehPonderado){
			for(i=0;i < gr->nVertices;i++)
				free(gr->pesos[i]);
			free(gr->pesos);
		}

		free(gr->grau);
		free(gr);
	}
}

int insereAresta(Grafo* gr,int origem,int destino,int digrafo,float peso){

	int criou = 0;

	if(gr != NULL){
		if(origem >= 0 && origem < gr->nVertices){
			if(destino >= 0 && destino < gr->nVertices){
				gr->arestas[origem][gr->grau[origem]] = destino;

				if(gr->ehPonderado)
					gr->pesos[origem][gr->grau[origem]] = peso; // SUBSTITUIR gr->grau[origem] POR destino E TESTAR

				(gr->grau[origem])++;

				if(digrafo == 0)
					insereAresta(gr,destino,origem,1,peso); // DÍGRADO IGUAL 1 PRA NÃO ENCERRAR A RECURSÃO

				criou = 1;
			}
		} 
	}

	return criou;
}

void mostraGrafo(Grafo *gr){
	int i, d;
	printf("origem \t\t destino \n");

	for(i=0; i < gr->nVertices;i++){
		for(d=0; d < gr->grau[i];d++)
			if(gr->arestas[i][d] != 0)
	
		printf("%d \t\t %d \n",i,gr->arestas[i][d]);
	}
}


void inicia_dijkstra(Grafo *gr, int *distancia, int *predecessor, int vertice_origem){

    int vertice;

    for(vertice = 0; vertice < gr->nVertices; vertice++){
        distancia[vertice] = -1; //utilizando -1 como se fosse infinito
        predecessor[vertice] = -1; //utilizando -1 como se fosse sem predecessor
    }
    distancia[vertice_origem] = 0;//inicializando a distancia do vertice inicial com 0
    predecessor[vertice_origem] = vertice_origem;
}

int tem_aberto(Grafo *gr, int *no_aberto){

    int i = 0, r = 0;

    while(i < gr->nVertices && r == 0){
        if(no_aberto[i]){
            r = 1;
        }

        i += 1;
    }

    return r;
}

int menor_distancia(Grafo *gr, int *no_aberto, int *distancia){

    int i = 0, j, menor;

    while(i < gr->nVertices && !no_aberto[i]){//procuro o primeiro nó aberto para assumir a posição de menor por enquanto
        i += 1;
    }

    if(i == gr->nVertices){
        menor = -1;
    }else{
	    menor = i;
	    j = menor + 1;
	    while(j < gr->nVertices){
	        if(no_aberto[j] && distancia[j] != -1 && (distancia[j] < distancia[menor])){//se esse vertice for aberto, e a distancia dele for menor que a do menor ate agora
	            menor = j;//então substitui
	        }

	        j += 1;
	    }
	}

    return menor;
}

void dijkstra(Grafo *gr, int *distancia, int *predecessor, int vertice_inicial){

    int i, menor, no_aberto[gr->nVertices];//vetor para saber se o nó ta aberto
    
    inicia_dijkstra(gr, distancia, predecessor, vertice_inicial);

    for (i = 0; i < gr->nVertices; i++){//preencho meus vertices todos como abertos
        no_aberto[i] = 1;
    }
    
    while( (menor = menor_distancia(gr, no_aberto, distancia)) != -1 ){//enquanto existir no aberto, procuramos entre os abertos o que tem a menor estimativa de distancia
        no_aberto[menor] = 0;//fecho esse nó

        for(i=0; i<gr->grau[menor]; i++){
        	if(((distancia[menor] + gr->pesos[menor][i]) < distancia[gr->arestas[menor][i]]) || distancia[gr->arestas[menor][i]] == -1){
        		distancia[gr->arestas[menor][i]] = distancia[menor] + gr->pesos[menor][i];//foi encontrado um menor caminho, então altera o valor.
            	predecessor[gr->arestas[menor][i]] = menor;//juntamente com agora seu novo predecessor
        	}
        }
    }
}

void printa_menor_caminho(Grafo *gr, int origem, int destino){

	int i, distancia[gr->nVertices], predecessor[gr->nVertices];

	dijkstra(gr, distancia, predecessor, origem);

	for(i=0; i<gr->nVertices; i++){
		printf("%c: (%c, %d)\n", i+97, predecessor[i] + 97, distancia[i]);
	}

	printf("DISTANCIA DO MENOR CAMINHO: %d\n", distancia[destino]);
	printf("MENOR CAMINHO: ");
	while(predecessor[destino] != destino){
		printf("%c->", 97+destino);
		destino = predecessor[destino]; 
	}
	printf("%c\n", 97+destino);
}

int main() {

	int naoEhDigrafo = 0, ehPonderado = 1, numeroVertices = 10;
	Grafo *grafo;
	int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8, j = 9;

	grafo = criaGrafo(numeroVertices,ehPonderado);

	insereAresta(grafo,a,b,naoEhDigrafo, 60);
	insereAresta(grafo,a,c,naoEhDigrafo, 54);
	insereAresta(grafo,a,d,naoEhDigrafo, 42);
	insereAresta(grafo,b,d,naoEhDigrafo, 71);
	insereAresta(grafo,b,f,naoEhDigrafo, 29);
	insereAresta(grafo,c,d,naoEhDigrafo, 56);
	insereAresta(grafo,c,e,naoEhDigrafo, 67);
	insereAresta(grafo,d,e,naoEhDigrafo, 26);
	insereAresta(grafo,d,f,naoEhDigrafo, 52);
	insereAresta(grafo,d,g,naoEhDigrafo, 87);
	insereAresta(grafo,e,g,naoEhDigrafo, 70);
	insereAresta(grafo,e,i,naoEhDigrafo, 73);
	insereAresta(grafo,f,g,naoEhDigrafo, 20);
	insereAresta(grafo,f,h,naoEhDigrafo, 25);
	insereAresta(grafo,g,h,naoEhDigrafo, 36);
	insereAresta(grafo,g,i,naoEhDigrafo, 59);
	insereAresta(grafo,g,j,naoEhDigrafo, 32);
	insereAresta(grafo,h,j,naoEhDigrafo, 25);
	insereAresta(grafo,i,j,naoEhDigrafo, 26);

	mostraGrafo(grafo);	

	printa_menor_caminho(grafo, a, j);


	liberaGrafo(grafo);

	return 0;
}