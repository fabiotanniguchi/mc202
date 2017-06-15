#include<stdio.h>
#include<stdlib.h>

/*
	Fabio Takahashi Tanniguchi - RA 145980

	MC202 - Estruturas de Dados
	2013 - 2o semestre

	Lab 06 - Satisfabilidade
*/


typedef struct NoArvore {
	char letra;
	char operador;
	struct NoArvore* esq;
	struct NoArvore* dir;
} NoArvore;


NoArvore* fazNo(char letra, char operador, NoArvore* esq, NoArvore* dir){
	NoArvore* novoNo = (NoArvore*) malloc (sizeof(NoArvore));

	if(novoNo == NULL){
		exit(EXIT_FAILURE); // alocacao mal sucedida
	}

	novoNo->letra = letra;
	novoNo->operador = operador;
	novoNo->esq = esq;
	novoNo->dir = dir;

	return novoNo;
}


int ehOperador(char entrada){
	if(entrada == '&'
          || entrada == '|'
          || entrada == '!')
		return 1;

	return 0;
}


int main(){

	NoArvore* raiz = NULL;
	NoArvore* atual = NULL;
	char entrada;

	scanf("%c",entrada);
	raiz = fazNo('', entrada, NULL, NULL);
	atual = raiz;

	// ler percurso pré-ordem
	while(scanf("%c",entrada)){

		if(ehOperador(entrada)){
			atual->
		}
	}

	return 0;
}

