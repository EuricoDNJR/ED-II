#include <stdio.h>
#include <stdlib.h>

struct Arv23{
	int Info1, Info2, NInfos;
	struct Arv23 *esq, *cen,*dir;
};


struct Arv23 *criaNo(int valor,struct Arv23 *FEsq,struct Arv23 *FCen,struct Arv23 *FDir)
{
	struct Arv23 *No;
	
	No = (struct Arv23 *) malloc(sizeof(struct Arv23));
	
	(*No).Info1 = valor;
	(*No).Info2 = 0;
	(*No).NInfos = 1;
	(*No).esq = FEsq;
	(*No).cen = FCen;
	(*No).dir = FDir;
	
	return No;	
}

int ehFolha(struct Arv23 *R)
{ int folha = 0; 
	
	if(R->esq == NULL && R->cen == NULL && R->dir == NULL){
		folha = 1;
	}
	
	return folha;
}

void adiciona(struct Arv23 **Raiz, int Valor, struct Arv23 *MaiorNo)
{
	if(Valor > (*Raiz)->Info1)
		{ (*Raiz)->Info2 = Valor;
		  (*Raiz)->dir = MaiorNo;
		}	
	else {
		(*Raiz)->Info2 = (*Raiz)->Info1;
		(*Raiz)->Info1 = Valor;
		(*Raiz)->dir = (*Raiz)->cen;
		(*Raiz)->cen = MaiorNo;
	}
	
	(*Raiz)->NInfos = 2;
}

struct Arv23 *quebraNo(struct Arv23 **Raiz,int valor,int *sobe, struct Arv23 *MaiorNo)
{ struct Arv23 *Novo;
	
 if(valor < (*Raiz)->Info1)
  {
	*sobe = (*Raiz)->Info1;
	Novo = criaNo((*Raiz)->Info2,(*Raiz)->cen,(*Raiz)->dir,NULL);
	(*Raiz)->Info1 = valor;
	(*Raiz)->cen = MaiorNo;
	
   }
 else if (valor < (*Raiz)->Info2) 	
        {
	       *sobe = valor;
		   Novo = criaNo((*Raiz)->Info2,MaiorNo,(*Raiz)->dir,NULL);
        }
	   else{
			*sobe = (*Raiz)->Info2;
			Novo = criaNo(valor,(*Raiz)->dir,MaiorNo,NULL);
		}
(*Raiz)->Info2 = 0;
(*Raiz)->NInfos = 1;
(*Raiz)->dir = NULL;

return(Novo);	
}

struct Arv23 *insereArv23(struct Arv23 *Pai, struct Arv23 **Raiz, int valor, int *sobe)
{ 
	struct Arv23 *maiorNo;
	maiorNo = NULL;
	if(*Raiz == NULL){
		*Raiz = criaNo(valor,NULL,NULL,NULL);	
	}
	else{
		if(ehFolha(*Raiz)){ 
			if((*Raiz)->NInfos == 1){
				adiciona(Raiz,valor,maiorNo);
			}else{  
				struct Arv23 *novo;	
				novo = quebraNo(Raiz,valor,sobe,maiorNo);
				if(Pai == NULL){	
					struct Arv23 *no;
					no = criaNo(*sobe,*Raiz,novo,NULL);
					*Raiz = no;
				}else{
					maiorNo = novo;
				} 
			}
		}else{
			if(valor < (*Raiz)->Info1){
				maiorNo = insereArv23(*Raiz, &((*Raiz)->esq), valor,sobe);
			}else if((*Raiz)->NInfos == 1 || (valor < (*Raiz)->Info2)){
				maiorNo = insereArv23(*Raiz, &((*Raiz)->cen), valor,sobe);
			}else{
				maiorNo = insereArv23(*Raiz, &((*Raiz)->dir), valor,sobe);	
			}
			if(maiorNo != NULL){
				if((*Raiz)->NInfos == 1){
					adiciona(Raiz,*sobe,maiorNo);
					maiorNo = NULL;
				}else{
					int sobe1;
					struct Arv23 *novo;	
					novo=quebraNo(Raiz,*sobe,&sobe1,maiorNo);
					if(Pai == NULL){	
						struct Arv23 *no;
						no = criaNo(sobe1,*Raiz,novo,NULL);
						*Raiz = no;
						maiorNo = NULL;
					}else{
						maiorNo = novo;
					}
				}
			}  
		}
	}
	return maiorNo;	
}

void in_ordem(struct Arv23 *Raiz){
	if(Raiz != NULL){
		in_ordem(Raiz->esq);
		printf("%d\n", Raiz->Info1);
		if(Raiz->Info2 != 0){
			printf("%d\n", Raiz->Info2);
		}
		in_ordem(Raiz->cen);
		in_ordem(Raiz->dir);
	}
}

int pesquisa(struct Arv23 *raiz, int n){
	int achou = 0;
	if(raiz != NULL){
		achou += pesquisa(raiz->esq, n);
		if(raiz->Info1 == n || raiz->Info2 == n){
			achou = 1;
		}
		achou += pesquisa(raiz->cen, n);
		achou += pesquisa(raiz->dir, n);
	}
	return achou;
} 

void nivel_arvore(struct Arv23 *raiz, int *nivel, int nivel_aux){
	if(raiz != NULL){
		nivel_arvore(raiz->esq, nivel, nivel_aux + 1);
		if(ehFolha(raiz)){
			if(nivel_aux > (*nivel)){
				*nivel = nivel_aux;
			}
		}
		nivel_arvore(raiz->cen, nivel, nivel_aux + 1);
		nivel_arvore(raiz->dir, nivel, nivel_aux + 1);
	}
}

void qtd_folha_qtd_info_por_folha(struct Arv23 *raiz, int *qtd_folha){
	if(raiz != NULL){
		qtd_folha_qtd_info_por_folha(raiz->esq, qtd_folha);
		if(ehFolha(raiz)){
			*qtd_folha += 1;
			printf("Folha %d tem %d info\n", *qtd_folha, raiz->NInfos);
		}
		qtd_folha_qtd_info_por_folha(raiz->cen, qtd_folha);
		qtd_folha_qtd_info_por_folha(raiz->dir, qtd_folha);
	}
}
int main() {
	
	struct Arv23 *Raiz, *Pai, *aux;
	int sobe = 0;

	Raiz = NULL;
	Pai = NULL;

	aux = insereArv23(Pai,&Raiz,500,&sobe);
	aux = insereArv23(Pai,&Raiz,100,&sobe);
	aux = insereArv23(Pai,&Raiz,400,&sobe);
	aux = insereArv23(Pai,&Raiz,300,&sobe);
	aux = insereArv23(Pai,&Raiz,600,&sobe);
	aux = insereArv23(Pai,&Raiz,450,&sobe);
	aux = insereArv23(Pai,&Raiz,200,&sobe);
	//////////////////////////////////////// 1 questao ///////////////////////////////////
	in_ordem(Raiz);
	//////////////////////////////////////// 2 questao ///////////////////////////////////
	if(pesquisa(Raiz, 300)){
		printf("Achou\n");
	}else{
		printf("Nao achou\n");
	}
	//////////////////////////////////////// 3 questao ///////////////////////////////////
	int nivel = 0;
	nivel_arvore(Raiz, &nivel, 0);
	printf("Nivel = %d\n", nivel);
	//////////////////////////////////////// 4 questao ///////////////////////////////////
	int qtd_folha = 0;
	aux = insereArv23(Pai,&Raiz,350,&sobe); //precisei inserir pra ter mais de uma info em ao menos uma folha
	qtd_folha_qtd_info_por_folha(Raiz, &qtd_folha);
	printf("Quantidade de folhas: %d", qtd_folha);
	return 0;
}