#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	Fabio Takahashi Tanniguchi - RA 145980

	MC202 - Estruturas de Dados
	2013 - 2o semestre

	Lab 03 - Polinômios Esparsos
*/


/* Estrutura para uma lista circular, duplamente ligada, com sentinela */
typedef struct Elemento {
	int info;
	int linha;
	int coluna;
	struct Elemento * direito;
	struct Elemento * abaixo;
} Elemento;


/* Criando uma lista vazia, com os sentinelas */
Elemento * criar(int m, int n) {

	int i;
	Elemento * superSent = (Elemento *) malloc(sizeof(Elemento));

	if (superSent == NULL) {
		printf("faltou memoria.");
		exit(EXIT_FAILURE);
	}

	superSent->info = -999;	// atributo exclusivo da sentinela
	superSent->coluna = -1;
	superSent->linha = -1;
	superSent->direito = superSent;
	superSent->abaixo = superSent;

	Elemento * atual = superSent;
	for(i = 1; i<=m; i++){
		Elemento * sent = (Elemento *) malloc(sizeof(Elemento));

		if (sent == NULL) {
			printf("faltou memoria.");
			exit(EXIT_FAILURE);
		}

		sent->linha = -1;
		sent->coluna = i;
		sent->info = -999;
		sent->abaixo = sent;

		atual->direito = sent;
		atual = sent;
	}
	atual->direito = superSent;


	atual = superSent;
	for(i = 1; i<=n; i++){
		Elemento * sent = (Elemento *) malloc(sizeof(Elemento));

		if (sent == NULL) {
			printf("faltou memoria.");
			exit(EXIT_FAILURE);
		}

		sent->linha = i;
		sent->coluna = -1;
		sent->info = -999;
		sent->direito = sent;

		atual->abaixo = sent;
		atual = sent;
	}
	atual->abaixo = superSent;

	return superSent;
}


void inserir(Elemento * superSent, int linha, int coluna, int info){
	Elemento * atual = superSent;
	Elemento * novo = (Elemento *) malloc(sizeof(Elemento));

	printf("OI");

	// percorrendo para chegar no elemento que sera acima do novo

	while(atual->coluna != coluna){
		atual = atual->direito;
	}

	atual = atual->abaixo;

	printf("OI");

	while((atual->abaixo)->linha < linha && (atual->abaixo)->linha != -1){
		atual = atual->abaixo;
	}

	novo->abaixo = atual->abaixo;
	atual->abaixo = novo;

	printf("OI");

	// percorrendo para chegar no elemento que sera a esquerda do novo

	while(atual->linha != linha){
		atual = atual->abaixo;
	}

	atual = atual->direito;

	printf("OI");

	while((atual->direito)->coluna < coluna && (atual->direito)->coluna != -1){
		atual = atual->direito;
	}

	novo->direito = atual->direito;
	atual->direito = novo;

	printf("OI");
}


void transposta(Elemento * superSent){
	// percorre ao contrario (colunas e linhas) e imprime resultado

	Elemento * sentSuperior;
	Elemento * lateral;

	sentSuperior = superSent;

	do{
		sentSuperior = sentSuperior -> direito;

		lateral = sentSuperior->abaixo;

		do{
			if(lateral != sentSuperior)
				printf("%d %d %d\n",lateral->coluna,lateral->linha,lateral->info);
		}while(lateral != sentSuperior);
	}while(sentSuperior != superSent);
}


/* Libera toda a memoria ocupada pela lista */
void liberar(Elemento * superSent) {
	// TODO
}


int main(void) {

	Elemento * superSent;
	Elemento * resultado;
	int i, m, n, nElementos, info, linha, coluna;
	char operacao;

	scanf("%c\n",&operacao);

	if(operacao=='t'){
		scanf("%d %d %d",&m,&n,&nElementos);

		superSent = criar(m,n);

		for(i = 0; i < nElementos; i++){
			scanf("%d %d %d",&linha,&coluna,&info);
			inserir(superSent,linha,coluna,info);
		}

		transposta(superSent);
	}else{
		if(operacao=='+'){
			//scanf();
		}else{ // multiplicacao
			//scanf();
		}
	}

	liberar(superSent);

	return EXIT_SUCCESS;
}

