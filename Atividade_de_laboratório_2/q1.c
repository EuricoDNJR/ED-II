#include <stdio.h>
#include <stdlib.h>
typedef struct no No;

struct no{
    int valor;
    No *direita;
    No *esquerda;
};

No *no_criar(int valor){
    No *n = (No*)malloc(sizeof(No));
    n->valor = valor;
    n->direita = NULL;
    n->esquerda = NULL;
    return n;
}
void insere(No **raiz, int valor){
    if(*raiz != NULL){
       if(valor > (*raiz)->valor){
           if((*raiz)->direita == NULL){
               (*raiz)->direita = no_criar(valor);
           }else{
               insere(&((*raiz)->direita), valor);
           }
       }else{
           if((*raiz)->esquerda == NULL){
               (*raiz)->esquerda = no_criar(valor);
           }else{
               insere(&((*raiz)->esquerda), valor);
           }
       }
    }else{
        *raiz = no_criar(valor);
    }
}

int prod_multi_5_maior_q_20(No *raiz, int produto){//OBS: O padrão de saida é 1.
    if(raiz != NULL){
        if((raiz->valor % 5 == 0) && (raiz->valor > 5)){
            produto = produto * raiz->valor;
        }
        produto = produto * prod_multi_5_maior_q_20(raiz->esquerda, 1);
        produto = produto * prod_multi_5_maior_q_20(raiz->direita, 1);
    }

    return produto;
}

void nos_folha(No *raiz, int *quantidade){
    if(raiz != NULL){
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            (*quantidade) += 1;
        }
        nos_folha(raiz->esquerda, quantidade);
        nos_folha(raiz->direita, quantidade);
    }
}

int devolve_pai(No *raiz, int valor, No **pai, int devolve, int cont){
    if(raiz != NULL){
        if(raiz->valor == valor && cont == 0){
            devolve = 1;
        }else if(raiz->valor == valor){
            devolve = 2;
        }else{
            *pai = raiz;
            devolve = devolve_pai(raiz->esquerda, valor, pai, devolve, cont + 1);
            if(devolve == -1){
                *pai = raiz;
                devolve = devolve_pai(raiz->direita, valor, pai, devolve, cont + 1);
            }
        }
    }
    return devolve;
}
 
No* excluir(No* raiz, int valor, int *excluiu)//essa eu comentei porque é mais complicada
{
    if(raiz == NULL){
        raiz = NULL;
    }
    //percorro a arvore buscando o Nó com o valor
    else if(raiz->valor > valor){
        raiz->esquerda = excluir(raiz->esquerda, valor, excluiu);
    }
    else if(raiz->valor < valor){
        raiz->direita = excluir(raiz->direita, valor, excluiu);
    }
    else{ 
        //Nó encontrado, ele tem filhos? não. Então so libero ele.
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            free (raiz);
            raiz = NULL;
            *excluiu = 1;
        }
        //se o no so tem filho na direita
        //então a raiz agora passa apontar para esse determinado Nó a direita e libera o no encontrado
        else if(raiz->esquerda == NULL){
            No *aux = raiz;
            raiz = raiz->direita;
            free (aux);
            *excluiu = 1;
        }
        //se o no so tem filho na esquerda
        //então a raiz agora passa apontar para esse determinado Nó a direita e libera o no encontrado
        else if(raiz->direita == NULL){
            No *aux = raiz;
            raiz = raiz->esquerda;
            free (aux);
            *excluiu = 1;
        }
        //Chegando esse ponto a unica alternativa é que ele tem dois filhos(esquerda e direita)
        else{
            //O Nó que vai ser removido ira apenas "trocar de lugar" com o Nó mais a direita da subarvore da esquerda
            No *aux = raiz->esquerda;
            while(aux->direita != NULL){
                aux = aux->direita;
            }
            raiz->valor = aux->valor; 
            aux->valor = valor;
            //Porem aquele Nó ainda existe ele so trocou de lugar, so chamar a função passando a subarvore da esquerda
            //e esperar ele ser excluido como no folha.
            raiz->esquerda = excluir(raiz->esquerda, valor, excluiu);
        }
    }
    return raiz;
}

void pre_ordem(No *raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d\n", raiz->valor);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

int main(){
    No *raiz = NULL;
    int quantidade_nos_folha = 0;
    
    insere(&raiz, 8);
    insere(&raiz, 4);
    insere(&raiz, 5);
    insere(&raiz, 2);
    insere(&raiz, 10);
    insere(&raiz, 11);
    insere(&raiz, 25);
    insere(&raiz, 3);
    insere(&raiz, 1);

    printf("\nProduto dos numeros multiplos de 5 maiores que 20 = %d\n", prod_multi_5_maior_q_20(raiz, 1));

    nos_folha(raiz, &quantidade_nos_folha);

    printf("Quantidade de nos folhas na arvore = %d\n", quantidade_nos_folha);

    No *pai = NULL;
    int devolve = -1, numero = 25;
    devolve = devolve_pai(raiz, numero, &pai, devolve, 0);
    if(devolve == -1){
        printf("Numero nao encontrado\n");
    }else if(devolve == 1){
        printf("Numero e a raiz\n");
    }else{
        printf("O pai do numero %d e o %d\n", numero, pai->valor);
    }

    int excluiu = 0;
    raiz = excluir(raiz, 5, &excluiu);
    if(excluiu == 1){
        printf("Excluiu\n");
    }else{
        printf("Nao excluiu\n");
    }
    printf("\n");
    //pre_ordem(raiz); função so pra ver a arvore msm
    return 0;
}