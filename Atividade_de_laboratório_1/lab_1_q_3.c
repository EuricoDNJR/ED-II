#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 7

typedef struct lista Lista;
typedef struct pessoa Pessoa;
struct pessoa{
    int id;
    char nome[20];
    int anoNascimento;
    int altura;
};

struct lista{
    Pessoa info;
    Lista *prox;
};

Lista* lst_insere (Lista* l, int id, char *nome, int anoNascimento, int altura){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info.id = id;
    strcpy(novo->info.nome, nome);
    novo->info.anoNascimento = anoNascimento;
    novo->info.altura = altura;
    novo->prox = l;
    return novo;
}

void mais_baixa_da_lista(Lista* l, char ***s, int *quantidade, int *menor){
    Lista *aux = l;
    if(aux != NULL){
        if(aux->info.id == (TAM - 1)){
            *menor = aux->info.altura;
        }
        else{
            if(aux->info.altura < *menor){
                *menor = aux->info.altura;
            }
        }
        mais_baixa_da_lista(aux->prox, s, quantidade, menor);
        if(aux->info.altura == *menor){
            (*quantidade) += 1;
            *s = (char**)realloc(*s, (*quantidade) * sizeof(char *));
            (*s)[(*quantidade) - 1] = aux->info.nome;
        }
    }
    
}
void busca (Lista* l, int *menor, int* maior){
    Lista* aux = l;
    if(aux != NULL){
        if(aux->info.id == (TAM - 1)){
            *menor = aux->info.altura;
            *maior = aux->info.altura;
        }
        else{
            if(aux->info.altura < *menor){
                *menor = aux->info.altura;
            }
            else{
                if(aux->info.altura > *maior){
                    *maior = aux->info.altura;
                }
            }
        }
        busca(aux->prox, menor, maior);
    }
}

int quant_pessoas_com_alt_med(Lista* l, float media, int cont){
    Lista *aux = l;
    if(aux != NULL){
        if(aux->info.altura == media){
            cont = 1 + quant_pessoas_com_alt_med(aux->prox, media, cont);
        }
        else{
            cont = quant_pessoas_com_alt_med(aux->prox, media, cont);   
        }
    }
    return cont;
}

int qt_pesso_acim_50_alt_mai_alt_med(Lista* l, float media, int cont, int ano){
    Lista *aux = l;
    if(aux != NULL){
        if((aux->info.altura > media) && (ano - aux->info.anoNascimento > 50)){
            cont = 1 + quant_pessoas_com_alt_med(aux->prox, media, cont);
        }
        else{
            cont = quant_pessoas_com_alt_med(aux->prox, media, cont);   
        }
    }
    return cont;
}
int main(){
    Lista *l = NULL;
    char **s = NULL;
    int menor, maior, quantidade = 0, i;
    /*obs: caso a senhora deseje colocar mais pessoas para testar, lá no topo do código
    é so alterar o valor de TAM para a quantidade desejada.
    */
    l = lst_insere(l, 0, "mikacelsius", 1998, 168);
    l = lst_insere(l, 1, "mateus bigas", 1950, 188);
    l = lst_insere(l, 2, "lucas rebaixado", 1940, 144);
    l = lst_insere(l, 3, "juju", 1968, 167);
    l = lst_insere(l, 4, "filips", 1972, 186);
    l = lst_insere(l, 5, "eurics", 1968, 190);
    l = lst_insere(l, 6, "sla kkk cabo", 1954, 144);

    mais_baixa_da_lista(l, &s, &quantidade, &menor);

    printf("Pessoa(s) mais baixa(s)\n");
    for(i = 0; i < quantidade; i++){
        printf("%s\n", s[i]);
    }
    printf("\n");
    busca(l, &menor, &maior);

    printf("Menor = %d Maior = %d\n", menor, maior);
    printf("\n");

    int pessoas_com_altura_media = quant_pessoas_com_alt_med(l, (menor + maior) / 2, 0);

    printf("Quantidade de pessoas com a altura media = %d\n", pessoas_com_altura_media);
    printf("\n");

    printf("Quantidade de pessoas acima de 50 anos e altura maior que a media = %d", qt_pesso_acim_50_alt_mai_alt_med(l, (menor + maior) / 2, 0, 2022));
    printf("\n");
    return 1;
}