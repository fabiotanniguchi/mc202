#include<stdio.h>
#include<stdlib.h>

/*
	Fabio Takahashi Tanniguchi - RA 145980

	MC202 - Estruturas de Dados
	2013 - 2o semestre

	Lab 04 - Jogo de Paciencia
*/

typedef struct Carta {
	int numero;
	char naipe; // o (naipe 1), e (naipe 2), c (naipe 3), p (naipe 4)
	struct Carta* prox;
} Carta;


// pilhas
Carta* p2 = NULL;
Carta* p3 = NULL;
Carta* p4 = NULL;
Carta* p5 = NULL;
Carta* p6 = NULL;
Carta* p7 = NULL;

Carta* atual1 = NULL;
Carta* atual2 = NULL;
Carta* atual3 = NULL;
Carta* atual4 = NULL;
Carta* atual5 = NULL;
Carta* atual6 = NULL;
Carta* atual7 = NULL;

// naipes
Carta* n1 = NULL;
Carta* n2 = NULL;
Carta* n3 = NULL;
Carta* n4 = NULL;

// fuco -> fila
Carta* fuco = NULL;

// filas
Carta* f1 = NULL;
Carta* f2 = NULL;
Carta* f3 = NULL;
Carta* f4 = NULL;
Carta* f5 = NULL;
Carta* f6 = NULL;
Carta* f7 = NULL;


Carta* novaCarta(int numero, char naipe, Carta* prox){
	Carta* novo = (Carta*) malloc (sizeof(Carta));

	if(novo != NULL){
		novo->numero = numero;
		novo->naipe = naipe;
		novo->prox = prox;

		return novo;
	}
	exit(EXIT_FAILURE); // caso nao tenha sido alocada memoria
}


void lePilha(Carta* pilha, int nCartas){
	Carta* prox = NULL;
	int i, numero;
	char naipe;

	for(i = 0; i < nCartas; i++){
		scanf("%d %c",&numero,&naipe); // le dados da carta a ser colocada na pilha

		pilha = novaCarta(numero, naipe, prox); // cabeca da pilha passa a ser a nova carta, encadeando o restante da lista no apontador de proximo elemento

		prox = pilha;
	}
}


void leFila(Carta* pilha, int nCartas){
	Carta* atual = pilha;
	Carta* nova = NULL;
	int i, numero;
	char naipe;

	scanf("%d %c",&numero,&naipe);

	atual = novaCarta(numero, naipe, NULL);

	for(i = 1; i < nCartas; i++){
		scanf("%d %c",&numero,&naipe); // le dados da carta a ser colocada na pilha

		nova = novaCarta(numero, naipe, NULL); // cabeca da pilha passa a ser a nova carta, encadeando o restante da lista no apontador de proximo elemento

		atual->prox = nova;

		atual = atual->prox;
	}
}


void libera(Carta* pilha){
	// elementos sao liberados de forma recursiva
	if(pilha != NULL){
		libera(pilha->prox);
		free(pilha);
	}
}


// se alguma fila estiver vazia, entao desempilhamos
// um elemento da pilha correspondente caso ainda tenha
// carta
int abreCarta(){
	int result = 0;

	if(f2 == NULL){
		if(p2 != NULL){
			result = 1;
			f2 = p2;
			p2 = p2->prox;
			f2->prox = NULL;
		}
	}

	if(f3 == NULL){
		if(p3 != NULL){
			result = 1;
			f3 = p3;
			p3 = p3->prox;
			f3->prox = NULL;
		}
	}

	if(f4 == NULL){
		if(p4 != NULL){
			result = 1;
			f4 = p4;
			p4 = p4->prox;
			f4->prox = NULL;
		}
	}

	if(f5 == NULL){
		if(p5 != NULL){
			result = 1;
			f5 = p5;
			p5 = p5->prox;
			f5->prox = NULL;
		}
	}

	if(f6 == NULL){
		if(p6 != NULL){
			result = 1;
			f6 = p6;
			p6 = p6->prox;
			f6->prox = NULL;
		}
	}

	if(f7 == NULL){
		if(p7 != NULL){
			result = 1;
			f7 = p7;
			p7 = p7->prox;
			f7->prox = NULL;
		}
	}

	return result;
}


// tenta descartar a primeira carta da estrutura passada por parametro
int tentaDescarte(Carta* fuco){
	int result = 0;
	Carta* aux = NULL;

	// tenta descartar do fuco
	if(fuco != NULL){
		switch(fuco->naipe){
			case 'o': // naipe 1
				if(n1 == NULL){ // entao ve se eh as
					if(fuco->numero == 1){
						n1 = fuco;
						fuco = n1->prox;
						n1->prox = NULL;
						result = 1;
					}
				}else{ // existe carta no descarte, tenta colocar a carta da lista
					if(fuco->numero == n1->numero + 1){
						aux = fuco;
						fuco = fuco->prox;
						aux->prox = n1;
						n1 = aux;
						result = 1;
					}
				}
				break;
			case 'e': // naipe 2
				if(n2 == NULL){ // entao ve se eh as
					if(fuco->numero == 1){
						n2 = fuco;
						fuco = n2->prox;
						n2->prox = NULL;
					}
				}else{ // existe carta no descarte, tenta colocar a carta da lista
					if(fuco->numero == n2->numero + 1){
						aux = fuco;
						fuco = fuco->prox;
						aux->prox = n2;
						n2 = aux;
						result = 1;
					}
				}
				break;
			case 'c': // naipe 3
				if(n3 == NULL){ // entao ve se eh as
					if(fuco->numero == 1){
						n3 = fuco;
						fuco = n3->prox;
						n3->prox = NULL;
					}
				}else{ // existe carta no descarte, tenta colocar a carta da lista
					if(fuco->numero == n3->numero + 1){
						aux = fuco;
						fuco = fuco->prox;
						aux->prox = n3;
						n3 = aux;
						result = 1;
					}
				}
				break;
			case 'p': // naipe 4
				if(n4 == NULL){ // entao ve se eh as
					if(fuco->numero == 1){
						n4 = fuco;
						fuco = n4->prox;
						n4->prox = NULL;
					}
				}else{ // existe carta no descarte, tenta colocar a carta da lista
					if(fuco->numero == n4->numero + 1){
						aux = fuco;
						fuco = fuco->prox;
						aux->prox = n4;
						n4 = aux;
						result = 1;
					}
				}
				break;
		}
	}

	return result;
}


// tenta descartar uma carta
int descarte(){
	int result = 0;

	if(tentaDescarte(fuco)){
		result = 1;
	}

	if(tentaDescarte(f1)){
		result = 1;
	}

	if(tentaDescarte(f2)){
		result = 1;
	}

	if(tentaDescarte(f3)){
		result = 1;
	}

	if(tentaDescarte(f4)){
		result = 1;
	}

	if(tentaDescarte(f5)){
		result = 1;
	}

	if(tentaDescarte(f6)){
		result = 1;
	}

	if(tentaDescarte(f7)){
		result = 1;
	}

	return result;
}


// funcao principal do jogo
// retorna ao final 1 se o jogo acabou
// retorna 0 se o jogo travou
int movimentacao(){
	int movimentou = 0;

	// 1. verificar se pode abrir alguma carta para as filas
	if(abreCarta()){
		movimentou = 1;
	}

	// 2. tentar descartar alguma carta nas listas fx e no fuco
	if(descarte()){
		movimentou = 1;
	}

	// 3. abrir o fuco e tentar posicionar essa carta no descarte ou nas listas fx

	if(!movimentou){
		// 4. tentar movimentar as filas entre si
	}

	if(movimentou){
		return movimentacao(); // tenta outro movimento
	}

	// senao retorna se o jogo acabou ou nao
	if(p2 == NULL &&
		p3 == NULL &&
		p4 == NULL &&
		p5 == NULL &&
		p6 == NULL &&
		p7 == NULL &&
		f1 == NULL &&
		f2 == NULL &&
		f3 == NULL &&
		f4 == NULL &&
		f5 == NULL &&
		f6 == NULL &&
		f7 == NULL) // todas as cartas foram para o descarte
		return 1; // jogo acabou
	return 0; // jogo travou
}


int main(){
	lePilha(f1,1);
	lePilha(p2,2);
	lePilha(p3,3);
	lePilha(p4,4);
	lePilha(p5,5);
	lePilha(p6,6);
	lePilha(p7,7);

	leFila(fuco,24);

	if(movimentacao()){ // jogo
		printf("O jogo acabou com sucesso\n");
	}else{
		//printf("Monte: %d\nDescarte: %d\n, x, y");
	}

	// liberando as listas da memoria
	libera(f1);
	libera(f2);
	libera(f3);
	libera(f4);
	libera(f5);
	libera(f6);
	libera(f7);

	libera(p2);
	libera(p3);
	libera(p4);
	libera(p5);
	libera(p6);
	libera(p7);

	libera(fuco);

	libera(n1);
	libera(n2);
	libera(n3);
	libera(n4);

	return 0;
}

