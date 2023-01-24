#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Calcado{
	int posicao, codigo, tamanho, quantidade;
	char *tipo, *marca;
	float preco;
};

struct Arv23{
	struct Calcado calcado1, calcado2;
	int numero_de_informacoes;
	struct Arv23 *esquerda, *centro, *direita;
};


void print_calcado(struct Calcado calcado){

	printf("\n");
	printf("Posicao: %d\n", calcado.posicao);
	printf("Codigo: %d\n", calcado.codigo);
	printf("Tipo: %s\n", calcado.tipo);
	printf("Marca: %s\n", calcado.marca);
	printf("Tamanho: %d\n", calcado.tamanho);
	printf("Quantidade: %d\n", calcado.quantidade);
	printf("Preco: %.2f\n", calcado.preco);	
}

char *ler_string_arquivo(FILE *arquivo){

	char *string = (char *)malloc(sizeof(char));
	int i=0;

	while((string[i] = fgetc(arquivo)) != ' '){
		i++;
		string = (char *)realloc(string, sizeof(char) * (i+1));
	}	
	string[i] = 0;

	return string;
}

struct Arv23 *criaNo(struct Calcado calcado, struct Arv23 *Fesquerda, struct Arv23 *Fcentro, struct Arv23 *Fdireita){
	struct Arv23 *No = (struct Arv23 *) malloc(sizeof(struct Arv23));
	
	(*No).calcado1 = calcado;
	(*No).numero_de_informacoes = 1;
	(*No).esquerda = Fesquerda;
	(*No).centro = Fcentro;
	(*No).direita = Fdireita;
	
	return No;	
}

int ehFolha(struct Arv23 *R){ 
	int folha = 0; // não é folha
	
	if(R->esquerda == NULL && R->centro == NULL && R->direita == NULL)
		folha = 1;
	
	return folha;
}

void adiciona(struct Arv23 **Raiz, struct Calcado calcado, struct Arv23 *MaiorNo){
	if(calcado.codigo > (*Raiz)->calcado1.codigo){ 
		(*Raiz)->calcado2 = calcado;
		(*Raiz)->direita = MaiorNo;
	}else{
		(*Raiz)->calcado2 = (*Raiz)->calcado1;
		(*Raiz)->calcado1 = calcado;
		(*Raiz)->direita = (*Raiz)->centro;
		(*Raiz)->centro = MaiorNo;
	}
	
	(*Raiz)->numero_de_informacoes = 2;
}

struct Arv23 *quebraNo(struct Arv23 **Raiz, struct Calcado calcado, struct Calcado *sobe, struct Arv23 *MaiorNo){ 

	struct Arv23 *Novo;
	
	if(calcado.codigo < (*Raiz)->calcado1.codigo){
		*sobe = (*Raiz)->calcado1;
		Novo = criaNo((*Raiz)->calcado2, (*Raiz)->centro, (*Raiz)->direita, NULL);
		(*Raiz)->calcado1 = calcado;
		(*Raiz)->centro = MaiorNo;
	}else if(calcado.codigo < (*Raiz)->calcado2.codigo){
		*sobe = calcado;
		Novo = criaNo((*Raiz)->calcado2, MaiorNo, (*Raiz)->direita, NULL);
	}else{
		*sobe = (*Raiz)->calcado2;
		Novo = criaNo(calcado, (*Raiz)->direita, MaiorNo, NULL);
	}

	(*Raiz)->numero_de_informacoes = 1;
	(*Raiz)->direita = NULL;

	return Novo;	
}

struct Arv23 *insereArv23(struct Arv23 *Pai, struct Arv23 **Raiz, struct Calcado calcado, struct Calcado *sobe){ 

	struct Arv23 *maiorNo = NULL;

	if(*Raiz == NULL){
		*Raiz = criaNo(calcado, NULL, NULL, NULL);	
	}else{ 
		if(ehFolha(*Raiz)){ 
			if((*Raiz)->numero_de_informacoes == 1){
				adiciona(Raiz, calcado, maiorNo);
			}else{ // quando não tem espaço
				struct Arv23 *novo = quebraNo(Raiz, calcado, sobe, maiorNo);	

				if(Pai == NULL){	
					*Raiz = criaNo(*sobe, *Raiz, novo, NULL);
				}else{
					maiorNo = novo;
				}
			}
		}else{//quando não é folha
			if(calcado.codigo < (*Raiz)->calcado1.codigo){
				maiorNo = insereArv23(*Raiz, &((*Raiz)->esquerda), calcado, sobe);
			}else if((*Raiz)->numero_de_informacoes == 1 || (calcado.codigo < (*Raiz)->calcado2.codigo)){
				maiorNo = insereArv23(*Raiz, &((*Raiz)->centro), calcado, sobe);
			}else{
				maiorNo = insereArv23(*Raiz, &((*Raiz)->direita), calcado, sobe);	
			}
				
			if(maiorNo != NULL){
				if((*Raiz)->numero_de_informacoes == 1){
					adiciona(Raiz, *sobe, maiorNo);
					maiorNo = NULL;
				}else{ // quando não tem espaço
					struct Calcado sobe1;
					struct Arv23 *novo = quebraNo(Raiz, *sobe, &sobe1, maiorNo);	

					if(Pai == NULL){	
						*Raiz = criaNo(sobe1, *Raiz, novo, NULL);
						maiorNo = NULL;
					}else{
						*sobe = sobe1;
						maiorNo = novo;
					}
				}
			}  
		}	
	}
	
	return maiorNo;	
}

struct Calcado *buscar_calcado(struct Arv23 *Raiz, int codigo, int flag){

	struct Calcado *calcado = NULL;

	if(Raiz != NULL){
		if(Raiz->calcado1.codigo == codigo){
			if(flag)
				printf("ENCONTROU NO CALCADO 1\n");
			calcado = &(Raiz->calcado1);
		}else if(Raiz->numero_de_informacoes == 2  && (codigo == Raiz->calcado2.codigo)){
			if(flag)
				printf("ENCONTROU NO CALCADO 2\n");
			calcado = &(Raiz->calcado2);
		}else if(codigo < Raiz->calcado1.codigo){
			if(flag)
				printf("ESQUERDA DO CALCADO DE CODIGO %d\n", Raiz->calcado1.codigo);
			calcado = buscar_calcado(Raiz->esquerda, codigo, flag);
		}else if(Raiz->numero_de_informacoes == 1 || (codigo < Raiz->calcado2.codigo)){
			if(flag)
				printf("DIREITA DO CALCADO DE CODIGO %d (CENTRO) \n", Raiz->calcado1.codigo);
			calcado = buscar_calcado(Raiz->centro, codigo, flag);
		}else{
			if(flag)
				printf("DIREITA DO CALCADO DE CODIGO %d\n", Raiz->calcado2.codigo);
			calcado = buscar_calcado(Raiz->direita, codigo, flag);	
		}
	}else{
		if(flag)
			printf("NAO ENCONTROU\n");
	}

	return calcado;
}

void in_ordem(struct Arv23 *Raiz){

	if(Raiz != NULL){
		in_ordem(Raiz->esquerda);
		print_calcado(Raiz->calcado1);
		in_ordem(Raiz->centro);
		if(Raiz->numero_de_informacoes == 2){
			print_calcado(Raiz->calcado2);
			in_ordem(Raiz->direita);
		}
	}
}

void desalocar_arvore(struct Arv23 *Raiz){

	if(Raiz != NULL){
		desalocar_arvore(Raiz->esquerda);
		desalocar_arvore(Raiz->centro);
		desalocar_arvore(Raiz->direita);

		free(Raiz->calcado1.tipo);
		free(Raiz->calcado1.marca);
		if(Raiz->numero_de_informacoes == 2){
			free(Raiz->calcado2.tipo);
			free(Raiz->calcado2.marca);
		}

		free(Raiz);
	}
}

int ultima_posicao(struct Arv23 *Raiz){

	int posicao = 0, posicao_aux;

	if(Raiz != NULL){
		posicao_aux = ultima_posicao(Raiz->esquerda);
		if(posicao < posicao_aux)
			posicao = posicao_aux;
		
		posicao_aux = ultima_posicao(Raiz->centro);
		if(posicao < posicao_aux)
			posicao = posicao_aux;

		if(posicao < Raiz->calcado1.posicao)
			posicao = Raiz->calcado1.posicao;
		
		if(Raiz->numero_de_informacoes == 2){
			posicao_aux = ultima_posicao(Raiz->direita);
			if(posicao < posicao_aux)
				posicao = posicao_aux;

			if(posicao < Raiz->calcado2.posicao)
				posicao = Raiz->calcado2.posicao;
		}
	}

	return posicao;
}

char *ler_string(){

	char *string = (char *)malloc(sizeof(char));
	int i = 0;

	setbuf(stdin, NULL);

	while((string[i] = getchar()) != '\n')
		string = (char *)realloc(string, sizeof(char) * (++i + 1));
	
	string[i] = 0;

	return string;
} 

char *numero_para_string(int numero){

	char *numero_string = (char *)malloc(sizeof(char)), aux;
	int i = 0, tam_numero_string;
	while(numero > 0){
		numero_string[i++] = 48 + (numero % 10); // TABELA ASCII
		numero_string = (char *)realloc(numero_string, sizeof(char) * (i + 1));
		numero = numero / 10;
	}
	numero_string[i] = 0;

	tam_numero_string = strlen(numero_string);

	for(i=0; i<tam_numero_string/2; i++){
		aux = numero_string[i];
		numero_string[i] = numero_string[tam_numero_string - i - 1];
		numero_string[tam_numero_string - i - 1] = aux;
	}

	return numero_string;
}

char *transforma_numero_em_string_com_zeros(char *string, int numero){

	int i, quantidade_digitos, tam_string = strlen(string);
	char *numero_string = numero_para_string(numero);

	quantidade_digitos = strlen(numero_string);

	if(quantidade_digitos < tam_string){
 		for(i=0; i<tam_string; i++){
			if(tam_string - i <= quantidade_digitos){
				string[i] = numero_string[quantidade_digitos - (tam_string - i)];
			}else{
				string[i] = '0';
			}
		}

		free(numero_string);
	}else{
		free(string);
		string = numero_string;
	}

	return string;
}

int menu(){

	int opcao;

	printf("\n");
	printf("=-=-=-=-=-=-=-=- MENU -=-=-=-=-=-=-=-=\n");
	printf("1 - Adicionar calcado\n");
	printf("2 - Vender calcado\n");
	printf("3 - Criar calcado\n");
	printf("4 - Buscar calcado\n");
	printf("5 - Listar calcados\n");
	printf("0 - Sair\n");
	printf("\n");
	printf("opcao: ");
	scanf("%d", &opcao);

	return opcao;
}


int main(){

	FILE *arquivo;
	struct Calcado calcado, *calcado_busca;
	int i=0;
	struct Arv23 *Raiz = NULL;
	struct Calcado sobe;
	int opcao, codigo, quantidade, fim_do_arquivo;
	fpos_t posicao;
	char *string = NULL;
	clock_t tempo_de_busca;

	arquivo = fopen("calcados.txt", "r");

	while (!feof(arquivo)){
		calcado.posicao = ++i;
		fscanf(arquivo, "%d", &(calcado.codigo));
		fgetc(arquivo);//REMOVE O PRIMEIRO ESPAÇO
		calcado.tipo = ler_string_arquivo(arquivo);
		calcado.marca = ler_string_arquivo(arquivo);
		fscanf(arquivo, "%d", &(calcado.tamanho));
		fscanf(arquivo, "%d", &(calcado.quantidade));
		fscanf(arquivo, "%f", &(calcado.preco));

		insereArv23(NULL, &Raiz, calcado, &sobe);
	}

	fclose(arquivo);
	
	while((opcao = menu())){
		if(opcao == 1){
			printf("Codigo: ");
			scanf("%d", &codigo);

			calcado_busca = buscar_calcado(Raiz, codigo, 0);

			if(calcado_busca){
				printf("Quantidade: ");
				scanf("%d", &quantidade);

				if(quantidade > 0)
					calcado_busca->quantidade += quantidade;

				// ATUALIZAR TXT (ADICIONAR)
				arquivo = fopen("calcados.txt", "r+");

				
				do{
					fscanf(arquivo, "%d", &(calcado.codigo));
					fgetc(arquivo);//REMOVE O PRIMEIRO ESPAÇO
					calcado.tipo = ler_string_arquivo(arquivo);
					calcado.marca = ler_string_arquivo(arquivo);
					fscanf(arquivo, "%d", &(calcado.tamanho));
					fgetc(arquivo);//REMOVE O PRIMEIRO ESPAÇO
					fgetpos(arquivo, &posicao);
					//fscanf(arquivo, "%d", &(calcado.quantidade));
					string = ler_string_arquivo(arquivo);
					fscanf(arquivo, "%f", &(calcado.preco));

					fim_do_arquivo = feof(arquivo);
					if(codigo == calcado.codigo){
				        fsetpos(arquivo, &posicao);

				        string = transforma_numero_em_string_com_zeros(string, calcado_busca->quantidade);
				        
						fprintf(arquivo, "%s", string);
						fprintf(arquivo, " %.2f", calcado_busca->preco);

						if(!fim_do_arquivo)
							fprintf(arquivo, "\n");

						free(string);
					}
				}while(codigo != calcado.codigo);

				fclose(arquivo);
			}else
				printf("Calcado nao encontrado\n");
		}else if(opcao == 2){
			printf("Codigo: ");
			scanf("%d", &codigo);

			calcado_busca = buscar_calcado(Raiz, codigo, 0);

			if(calcado_busca){
				printf("Quantidade: ");
				scanf("%d", &quantidade);

				if(quantidade <= calcado_busca->quantidade)
					calcado_busca->quantidade -= quantidade;
				else
					printf("Quantidade de venda maior do que a quantidade de calcados no estoque\nOperacao cancelada\n");
				
				// ATUALIZAR TXT (SUBTRAIR)
				arquivo = fopen("calcados.txt", "r+");

				
				do{
					fscanf(arquivo, "%d", &(calcado.codigo));
					fgetc(arquivo);//REMOVE O PRIMEIRO ESPAÇO
					calcado.tipo = ler_string_arquivo(arquivo);
					calcado.marca = ler_string_arquivo(arquivo);
					fscanf(arquivo, "%d", &(calcado.tamanho));
					fgetc(arquivo);//REMOVE O PRIMEIRO ESPAÇO
					fgetpos(arquivo, &posicao);
					//fscanf(arquivo, "%d", &(calcado.quantidade));
					string = ler_string_arquivo(arquivo);
					fscanf(arquivo, "%f", &(calcado.preco));

					fim_do_arquivo = feof(arquivo);
					if(codigo == calcado.codigo){
				        fsetpos(arquivo, &posicao);

				        string = transforma_numero_em_string_com_zeros(string, calcado_busca->quantidade);
				        
						fprintf(arquivo, "%s", string);
						fprintf(arquivo, " %.2f", calcado_busca->preco);

						if(!fim_do_arquivo)
							fprintf(arquivo, "\n");

						free(string);
					}
				}while(codigo != calcado.codigo);

				fclose(arquivo);
			}else
				printf("Calcado nao encontrado\n");
		}else if(opcao == 3){
			calcado.posicao = ultima_posicao(Raiz) + 1;
	
			printf("Codigo: ");
			scanf("%d", &(calcado.codigo));

			if(!buscar_calcado(Raiz, calcado.codigo, 0)){
				printf("Tipo: ");
				calcado.tipo = ler_string();

				printf("Marca: ");
				calcado.marca = ler_string();

				printf("Tamanho: ");
				scanf("%d", &(calcado.tamanho));

				printf("Quantidade: ");
				scanf("%d", &(calcado.quantidade));

				printf("Preco: ");	
				scanf("%f", &(calcado.preco));

				insereArv23(NULL, &Raiz, calcado, &sobe);

				arquivo = fopen("calcados.txt", "a");

				fprintf(arquivo, "\n%d ", calcado.codigo);
				fprintf(arquivo, "%s ", calcado.tipo);
				fprintf(arquivo, "%s ", calcado.marca);
				fprintf(arquivo, "%d ", calcado.tamanho);
				fprintf(arquivo, "%d ", calcado.quantidade);
				fprintf(arquivo, "%.2f", calcado.preco);

				fclose(arquivo);
			}else{
				printf("Falha ao criar calcado. Codigo repetido\n");
			}
		}else if(opcao == 4){
			printf("Codigo: ");
			scanf("%d", &codigo);

			calcado_busca = buscar_calcado(Raiz, codigo, 0);
			if(calcado_busca != NULL)
				print_calcado(*calcado_busca);
		}else if(opcao == 5){
			in_ordem(Raiz);
		}
	}

	tempo_de_busca = clock();

	calcado_busca = buscar_calcado(Raiz, 21111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 16111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11811, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11311, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21112, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21117, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21311, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11119, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21119, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 31111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11114, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11112, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 24511, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 61111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21116, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 14111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 71111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 51111, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21211, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11711, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11151, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11116, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 11113, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21191, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21411, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21191, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21181, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21171, 1);
	printf("\n");
	calcado_busca = buscar_calcado(Raiz, 21161, 1);
	printf("\n");

	tempo_de_busca = clock() - tempo_de_busca;

	printf("\nTEMPO DE BUSCA %f\n", (float)tempo_de_busca/CLOCKS_PER_SEC);

	desalocar_arvore(Raiz);

	return 0;
}