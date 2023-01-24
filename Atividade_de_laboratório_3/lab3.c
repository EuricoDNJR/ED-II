#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct participante Participante;
typedef struct temporada Temporada;
typedef struct serie Serie;

struct participante
{
    char artista[30];
    char personagem[30];
    char descricao[80];
    Participante *esquerda;
    Participante *direita;
};

struct temporada
{
    int numero;
    char titulo[50];
    int quantidade_eps;
    int ano;
    Participante *part;
    Temporada *prox;
};

struct serie
{
    int codigo;
    char titulo[30];
    int numero_temporadas;
    Temporada *temp;
    Serie *direita;
    Serie *esquerda;
};

/////////////////////////////////////// Funções de serie/////////////////////////////////////////////////////////////////////////
Serie *serie_no_criar(int codigo, char *titulo, int numero_temporadas){
    Serie *no = (Serie*)malloc(sizeof(Serie));
    no->codigo = codigo;
    strcpy(no->titulo, titulo);
    no->numero_temporadas = numero_temporadas;
    no->temp = NULL;
    no->direita = NULL;
    no->esquerda = NULL;
    return no;
}

void insere_serie(Serie **raiz, int codigo, char *titulo, int numero_temporadas){//raiz da arvore de series, codigo da serie, titulo da serie, numero de temporadas da serie
    if(*raiz != NULL){
       if(codigo > (*raiz)->codigo){
            insere_serie(&((*raiz)->direita), codigo, titulo, numero_temporadas);
        }else{
            insere_serie(&((*raiz)->esquerda), codigo, titulo, numero_temporadas);
       }
    }else{
        *raiz = serie_no_criar(codigo, titulo, numero_temporadas);
    }
}


Serie *busca_serie(Serie *raiz, int codigo_serie){
    Serie *aux = NULL;
    if(raiz != NULL){
        if(raiz->codigo == codigo_serie){
            aux = raiz;
        }else if(codigo_serie < raiz->codigo){
            aux = busca_serie(raiz->esquerda, codigo_serie);
        }else{
            aux = busca_serie(raiz->direita, codigo_serie);
        }
    }
    return aux;
}
/////////////////////////////////////// Funções de temporada/////////////////////////////////////////////////////////////////////////
void no_insere_lista(Temporada **my_serie, Temporada *temp){//cabeca da lista da temporada da serie, temporada a ser inserida na lista temporada
    if(*my_serie != NULL){
        if(temp->numero < (*my_serie)->numero){
            temp->prox = *my_serie;
            *my_serie = temp;
        }else{
            no_insere_lista(&(*my_serie)->prox, temp);
        }
    }else{
        *my_serie = temp;
    }
}

void insere_temporada(Serie *raiz, int codigo_serie, int numero, char *titulo, int quantidade_eps, int ano){
    Serie *my_serie = busca_serie(raiz, codigo_serie);
    Temporada *nova_temp = (Temporada*)malloc(sizeof(Temporada));
    nova_temp->numero = numero;
    strcpy(nova_temp->titulo, titulo);
    nova_temp->quantidade_eps = quantidade_eps;
    nova_temp->ano = ano;
    nova_temp->prox = NULL;
    nova_temp->part = NULL;
    no_insere_lista((&(my_serie->temp)), nova_temp);
}

Temporada *busca_temporada(Temporada *my_temporadas, int numero_temporada){
    Temporada *aux = NULL;
    if(my_temporadas != NULL){
        if(my_temporadas->numero == numero_temporada){
            aux = my_temporadas;
        }else{
            aux = busca_temporada(my_temporadas->prox, numero_temporada);
        }
    }
    return aux;
}

/////////////////////////////////////// Funções de participantes/////////////////////////////////////////////////////////////////////////
Participante *participante_no_criar(char *artista, char *personagem, char *descricao){
    Participante *no = (Participante*)malloc(sizeof(Participante));
    strcpy(no->artista, artista);
    strcpy(no->personagem, personagem);
    strcpy(no->descricao, descricao);
    no->direita = NULL;
    no->esquerda = NULL;
    return no;
}
void insere_no_Participante(Participante **raiz, char *artista, char *personagem, char *descricao){//raiz da arvore de participantes, artista da temporada, personagem da temporada, descricao do artista da temporada
    if(*raiz != NULL){
       if(strcmp(personagem, (*raiz)->personagem) > 0){
            insere_no_Participante(&((*raiz)->direita), artista, personagem, descricao);
        }else{
            insere_no_Participante(&((*raiz)->esquerda), artista, personagem, descricao);
        }
    }else{
        *raiz = participante_no_criar(artista, personagem, descricao);
    }
}
void insere_participante(Serie *raiz, int codigo_serie, int numero_temporada, char *artista, char *personagem, char *descricao){
    Serie *my_serie = busca_serie(raiz, codigo_serie);
    if(my_serie != NULL){
        Temporada *my_temporada = busca_temporada(my_serie->temp, numero_temporada);
        if(my_temporada != NULL){
            insere_no_Participante(&(my_temporada->part), artista, personagem, descricao);
        }
    }
}
////////////////////////////////////////////Funcoes de impressão//////////////////////////////////////////////////////////
void in_ordem(Serie *raiz){
    if(raiz != NULL){
        in_ordem(raiz->esquerda);
        printf("%s\n", raiz->titulo);
        printf("%d\n", raiz->numero_temporadas);
        in_ordem(raiz->direita);
    }
}
void printa_temp(Temporada *raiz){
    if(raiz != NULL){
        printf("Numero = %d\n", raiz->numero);
        printf("Titulo = %s\n", raiz->titulo);
        printf("Quantidade de episodios = %d\n", raiz->quantidade_eps);
        printf("Ano = %d\n", raiz->ano);
        printa_temp(raiz->prox);
    }
}

void printa_participantes(Participante *partic){
    if(partic != NULL){
        printf("%s\n", partic->personagem);
        printa_participantes(partic->esquerda);
        printa_participantes(partic->direita);
    }

}
void devolve_personagens_primeira_temp(Participante *partic, char ***ma, int *quantidade){//nessa função coloco os participantes da primeira temporada em uma matriz
    if(partic != NULL){
        *quantidade += 2;
        *ma = (char **)realloc(*ma, sizeof(char *) * (*quantidade));
        (*ma)[(*quantidade)-2] = partic->artista;
        (*ma)[(*quantidade)-1] = partic->personagem;
        devolve_personagens_primeira_temp(partic->esquerda, ma, quantidade);
        devolve_personagens_primeira_temp(partic->direita, ma, quantidade);
    }
}

int teste(char *artista, char *personagem, Participante *part){
    //nessa função eu percorro a arvore comparando o artista e o personagem la da matriz(primeira temporada) com todos os participantes daquela determinada temporada
    //se eu achar ele e ele estiver interpretando aquele personagem da primeira temporada ele retorna 1(tudo bem)
    //senão ele retorna 0, então ou o artista não está nessa temporada ou ele interpreta outro personagem; 
    int flag = 0;

    if(part != NULL){
        if(strcmp(part->artista, artista) == 0 && strcmp(part->personagem,personagem) == 0){
            flag = 1;
        }else{
            if(strcmp(personagem, part->personagem) > 0){
                flag = teste(artista, personagem, part->direita);
            }else{
                flag = teste(artista, personagem, part->esquerda);
            }
        }
    }

    return flag;
}

void compara_artist_perso_temporada(Participante *part, char ***ma, int *quantidade){
    int i = (*quantidade), resultado=0;
    char *aux;

    while (i > 0){
        resultado = teste((*ma)[i-2], (*ma)[i-1], part);
        
        if(resultado == 0){
            //aqui eu so faço a troca de lugar artista e personagem que devem ser excluidos com os ultimos da matriz
            aux = (*ma)[i-2];
            (*ma)[i-2] = (*ma)[(*quantidade)-2];
            (*ma)[(*quantidade)-2] = aux;

            aux = (*ma)[i-1];
            (*ma)[i-1] = (*ma)[(*quantidade)-1];
            (*ma)[(*quantidade)-1] = aux;

            (*quantidade) -= 2;
            //e depois eu realoco com a quantidade decrementada em -2
            *ma = (char **)realloc(*ma, sizeof(char *) * (*quantidade));   
        }
        i -= 2;
    }
}

void printa_personagens(Temporada *my_temporada){
    Temporada *aux_temp = my_temporada;
    char **ma = NULL;
    int quantidade_matriz = 0;

    devolve_personagens_primeira_temp(aux_temp->part, &ma, &quantidade_matriz);
   
    aux_temp = aux_temp->prox;
    while(aux_temp != NULL)
    {
        //aqui eu so fico passando de temporada em temporada
        compara_artist_perso_temporada(aux_temp->part, &ma, &quantidade_matriz);
        aux_temp = aux_temp->prox;
    }
    
    while(quantidade_matriz > 0){
        //aqui é para printar os que ficaram na matriz la, ou seja os que não foram excluidos, por interpretarem o mesmo papel nas outras temporadas
        printf("Artista = %s\n", ma[quantidade_matriz-2]);
        quantidade_matriz -= 2;
    }
    free(ma);
}

int menu(){
    int op;
    printf("\nDigite 1 - Imprimir em ordem pelo codigo da serie: o titulo, o numero de temporadas.\n");
    printf("Digite 2 - Imprimir os dados de todas as temporadas de uma serie, cujo o usuario informe o codigo da serie.\n");
    printf("Digite 3 - Imprimir todos os personagens de uma determinada temporada de uma dada serie, cujo o usuario informe o codigo da serie e o numero da temporada.\n");
    printf("Digite 4 - Imprimir o nome de todos os artistas que interpretaram um determinado personagem em todas as temporadas de uma dada serie, cujo o usuario informe o codigo da serie.\n");
    printf("Digite 0 - Para sair\n");
    scanf("%d", &op);
    return op;
}
int main(){
    Serie *raiz = NULL;
    int op = 1;
    
    insere_serie(&raiz, 2, "Stranger Things", 3);//arvore series, codigo da serie, titulo, numero de temporadas
    insere_serie(&raiz, 1, "Euphoria", 2);
    insere_serie(&raiz, 3, "Elite", 4);
    insere_serie(&raiz, 6, "Peaky blinders", 3);
    
    //////////////////////////////////////////////////////////////////////////
    
    insere_temporada(raiz, 2, 3, "Stranger Chapter 3", 7, 2020);//arvore series, codigo da serie, numero da temporada, quantidade de eps, ano
    insere_temporada(raiz, 3, 1, "Elite 1", 5, 2019);
    insere_temporada(raiz, 1, 2, "Euphoria 2", 10, 2020);
    insere_temporada(raiz, 6, 1, "Peaky blinders 1", 8, 2017);
    insere_temporada(raiz, 6, 2, "Peaky blinders 2", 5, 2019);
    insere_temporada(raiz, 3, 3, "Elite 3", 8, 2021);
    insere_temporada(raiz, 6, 3, "Peaky blinders 3", 5, 2021);
    insere_temporada(raiz, 3, 4, "Elite 4", 8, 2022);
    insere_temporada(raiz, 2, 1, "Stranger Chapter 1", 7, 2018);
    insere_temporada(raiz, 3, 2, "Elite 2", 11, 2020);
    insere_temporada(raiz, 1, 1, "Euphoria 1", 5, 2019);
    insere_temporada(raiz, 2, 2, "Stranger Chapter 2", 7, 2019);
    ////////////////////////////////////////////////////////////////////////
    insere_participante(raiz, 2, 3, "Finn Wolfhard", "Mike", "Um garoto onde bem investigativo e corajoso");
    insere_participante(raiz, 2, 3, "Millie Bobby", "Eleven", "Superpoderosa");
    insere_participante(raiz, 2, 2, "Finn Wolfhard", "Jose", "Um garoto onde bem investigativo e corajoso");
    insere_participante(raiz, 2, 1, "Finn Wolfhard", "Mike", "Um garoto onde bem investigativo e corajoso");
    ////////////////////////////////////////////////////////////////////////
    insere_participante(raiz, 1, 1, "Zendaya", "Rue", "Dependente quimica");
    insere_participante(raiz, 1, 1, "Maude Apatow", "Lexi Howard", "Super sensata");
    insere_participante(raiz, 1, 2, "Zendaya", "Rue", "Dependente quimica");
    ////////////////////////////////////////////////////////////////////////
    insere_participante(raiz, 3, 1, "María Pedraza", "Marina Nunier", "Bailarina");
    insere_participante(raiz, 3, 3, "María Pedraza", "Marina Nunier", "Bailarina");
    insere_participante(raiz, 3, 1, "Itzan Escamilla", "Samu", "Bolsista");
    insere_participante(raiz, 3, 2, "Itzan Escamilla", "Samu", "Bolsista");
    insere_participante(raiz, 3, 3, "Itzan Escamilla", "Samu", "Bolsista");
    ////////////////////////////////////////////////////////////////////////
    insere_participante(raiz, 6, 1, "Cillian Murphy", "Tommy", "Lider");
    insere_participante(raiz, 6, 3, "Cillian Murphy", "Tommy", "Lider");
    insere_participante(raiz, 6, 1, "Sam Neill", "Chester Campbell", "Major");
    insere_participante(raiz, 6, 3, "Paddy Considine", "Padre John", "Padre");
    //////////////////////////////////Menu//////////////////////////////////
   
    int codigo_serie, numero_temporada;
    while ((op = menu()) != 0){
        if(op == 1){
            in_ordem(raiz);
        }
        else if(op == 2){
            printf("Insira o codigo da serie:\n");
            scanf("%d", &codigo_serie);
            Serie *my_serie = busca_serie(raiz, codigo_serie);
            if(my_serie != NULL){
                printa_temp(my_serie->temp);
            }else{
                printf("Serie nao encontrada\n");
            }
        }
        else if(op == 3){
            printf("Insira o codigo da serie:\n");
            scanf("%d", &codigo_serie);
            Serie *my_serie = busca_serie(raiz, codigo_serie);
            printf("Insira o numero da temporada:\n");
            scanf("%d", &numero_temporada);
            Temporada *my_temporada = busca_temporada(my_serie->temp, numero_temporada);
            printa_participantes(my_temporada->part);
        }
        else if(op == 4){
            printf("Insira o codigo da serie:\n");
            scanf("%d", &codigo_serie);
            Serie *my_serie = busca_serie(raiz, codigo_serie);
            printa_personagens(my_serie->temp);
        }
        
    }
    ////////////////////////////////////////////////////////////////////////

    return 0;
}