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
	struct Carta* ant;
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
		novo->ant = NULL;
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


// tenta movimentar do fuco para alguma das listas fx
int movimentaFuco(){
    int result = 0;
    Carta* aux;

    if(fuco != NULL){
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f1 = fuco;
                fuco = fuco->prox;
                f1->ant = f1;
                f1->prox = f1;
                result=1;
            }
        }else{
            if(fuco->numero == f1->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = fuco;
                fuco = fuco->prox;
                f1->prox = aux;
            }
        }
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f2 = fuco;
                fuco = fuco->prox;
                f2->ant = f2;
                f2->prox = f2;
                result=1;
            }
        }else{
            if(fuco->numero == f2->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = fuco;
                fuco = fuco->prox;
                f2->prox = aux;
            }
        }
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f3 = fuco;
                fuco = fuco->prox;
                f3->ant = f3;
                f3->prox = f3;
                result=1;
            }
        }else{
            if(fuco->numero == f3->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = fuco;
                fuco = fuco->prox;
                f3->prox = aux;
                result=1;
            }
        }
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f4 = fuco;
                fuco = fuco->prox;
                f4->ant = f4;
                f4->prox = f4;
                result=1;
            }
        }else{
            if(fuco->numero == f4->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = fuco;
                fuco = fuco->prox;
                f4->prox = aux;
                result=1;
            }
        }
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f5 = fuco;
                fuco = fuco->prox;
                f5->ant = f5;
                f5->prox = f5;
                result=1;
            }
        }else{
            if(fuco->numero == f5->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = fuco;
                fuco = fuco->prox;
                f5->prox = aux;
                result=1;
            }
        }
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f6 = fuco;
                fuco = fuco->prox;
                f6->ant = f6;
                f6->prox = f6;
                result=1;
            }
        }else{
            if(fuco->numero == f6->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = fuco;
                fuco = fuco->prox;
                f6->prox = aux;
                result=1;
            }
        }
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(fuco->numero == 12){
                f7 = fuco;
                fuco = fuco->prox;
                f7->ant = f7;
                f7->prox = f7;
                result=1;
            }
        }else{
            if(fuco->numero == f7->ant->numero - 1 &&(
		((fuco->naipe=='o' || fuco->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((fuco->naipe=='c' || fuco->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = fuco;
                fuco = fuco->prox;
                f7->prox = aux;
                result=1;
            }
        }
    }

    return result;
}


// tenta movimentar as listas
int movimentaListas(){
    Carta* aux = NULL;
    int result = 0;

    // f1
    if(f1 != NULL){
        // tenta movimentar para f2
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f1->numero == 12){
                f2 = f1;
                f1 = NULL;
	 	result = 1;
            }
        }else{
            if(f1->numero == f2->ant->numero - 1 &&(
		((f1->naipe=='o' || f1->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((f1->naipe=='c' || f1->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = NULL;
                aux->ant = f2->ant;
                aux->ant->prox = f2;
                f2->ant->prox = aux;
                f2->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f3
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f1->numero == 12){
                f3 = f1;
                f1 = NULL;
	 	result = 1;
            }
        }else{
            if(f1->numero == f3->ant->numero - 1 &&(
		((f1->naipe=='o' || f1->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((f1->naipe=='c' || f1->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = NULL;
                aux->ant = f3->ant;
                aux->ant->prox = f3;
                f3->ant->prox = aux;
                f3->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f4
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f1->numero == 12){
                f4 = f1;
                f1 = NULL;
	 	result = 1;
            }
        }else{
            if(f1->numero == f4->ant->numero - 1 &&(
		((f1->naipe=='o' || f1->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((f1->naipe=='c' || f1->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = NULL;
                aux->ant = f4->ant;
                aux->ant->prox = f4;
                f4->ant->prox = aux;
                f4->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f5
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f1->numero == 12){
                f5 = f1;
                f1 = NULL;
	 	result = 1;
            }
        }else{
            if(f1->numero == f5->ant->numero - 1 &&(
		((f1->naipe=='o' || f1->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((f1->naipe=='c' || f1->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = NULL;
                aux->ant = f5->ant;
                aux->ant->prox = f5;
                f5->ant->prox = aux;
                f5->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f6
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f1->numero == 12){
                f6 = f1;
                f1 = NULL;
	 	result = 1;
            }
        }else{
            if(f1->numero == f6->ant->numero - 1 &&(
		((f1->naipe=='o' || f1->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((f1->naipe=='c' || f1->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = NULL;
                aux->ant = f6->ant;
                aux->ant->prox = f6;
                f6->ant->prox = aux;
                f6->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f7
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f1->numero == 12){
                f7 = f1;
                f1 = NULL;
	 	result = 1;
            }
        }else{
            if(f1->numero == f7->ant->numero - 1&&(
		((f1->naipe=='o' || f1->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((f1->naipe=='c' || f1->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f1;
                f1 = NULL;
                aux->ant = f7->ant;
                aux->ant->prox = f7;
                f7->ant->prox = aux;
                f7->ant = aux->ant;
	 	result = 1;
            }
        }
    }

    // f2
    if(f2 != NULL){
        // tenta movimentar para f1
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f2->numero == 12){
                f1 = f2;
                f2 = NULL;
	 	result = 1;
            }
        }else{
            if(f2->numero == f1->ant->numero - 1 &&(
		((f2->naipe=='o' || f2->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((f2->naipe=='c' || f2->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = NULL;
                aux->ant = f1->ant;
                aux->ant->prox = f1;
                f1->ant->prox = aux;
                f1->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f3
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f2->numero == 12){
                f3 = f2;
                f2 = NULL;
	 	result = 1;
            }
        }else{
            if(f2->numero == f3->ant->numero - 1 &&(
		((f2->naipe=='o' || f2->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((f2->naipe=='c' || f2->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = NULL;
                aux->ant = f3->ant;
                aux->ant->prox = f3;
                f3->ant->prox = aux;
                f3->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f4
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f2->numero == 12){
                f4 = f2;
                f2 = NULL;
	 	result = 1;
            }
        }else{
            if(f2->numero == f4->ant->numero - 1 &&(
		((f2->naipe=='o' || f2->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((f2->naipe=='c' || f2->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = NULL;
                aux->ant = f4->ant;
                aux->ant->prox = f4;
                f4->ant->prox = aux;
                f4->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f5
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f2->numero == 12){
                f5 = f2;
                f2 = NULL;
	 	result = 1;
            }
        }else{
            if(f2->numero == f5->ant->numero - 1 &&(
		((f2->naipe=='o' || f2->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((f2->naipe=='c' || f2->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = NULL;
                aux->ant = f5->ant;
                aux->ant->prox = f5;
                f5->ant->prox = aux;
                f5->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f6
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f2->numero == 12){
                f6 = f2;
                f2 = NULL;
	 	result = 1;
            }
        }else{
            if(f2->numero == f6->ant->numero - 1 &&(
		((f2->naipe=='o' || f2->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((f2->naipe=='c' || f2->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = NULL;
                aux->ant = f6->ant;
                aux->ant->prox = f6;
                f6->ant->prox = aux;
                f6->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f7
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f2->numero == 12){
                f7 = f2;
                f2 = NULL;
	 	result = 1;
            }
        }else{
            if(f2->numero == f7->ant->numero - 1 &&(
		((f2->naipe=='o' || f2->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((f2->naipe=='c' || f2->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f2;
                f2 = NULL;
                aux->ant = f7->ant;
                aux->ant->prox = f7;
                f7->ant->prox = aux;
                f7->ant = aux->ant;
	 	result = 1;
            }
        }
    }

    // f3
    if(f3 != NULL){
        // tenta movimentar para f1
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f3->numero == 12){
                f1 = f3;
                f3 = NULL;
	 	result = 1;
            }
        }else{
            if(f3->numero == f1->ant->numero - 1 &&(
		((f3->naipe=='o' || f3->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((f3->naipe=='c' || f3->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = NULL;
                aux->ant = f1->ant;
                aux->ant->prox = f1;
                f1->ant->prox = aux;
                f1->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f2
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f3->numero == 12){
                f2 = f3;
                f3 = NULL;
	 	result = 1;
            }
        }else{
            if(f3->numero == f2->ant->numero - 1 &&(
		((f3->naipe=='o' || f3->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((f3->naipe=='c' || f3->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = NULL;
                aux->ant = f2->ant;
                aux->ant->prox = f2;
                f2->ant->prox = aux;
                f2->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f4
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f3->numero == 12){
                f4 = f3;
                f3 = NULL;
	 	result = 1;
            }
        }else{
            if(f3->numero == f4->ant->numero - 1 &&(
		((f3->naipe=='o' || f3->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((f3->naipe=='c' || f3->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = NULL;
                aux->ant = f4->ant;
                aux->ant->prox = f4;
                f4->ant->prox = aux;
                f4->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f5
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f3->numero == 12){
                f5 = f3;
                f3 = NULL;
	 	result = 1;
            }
        }else{
            if(f3->numero == f5->ant->numero - 1 &&(
		((f3->naipe=='o' || f3->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((f3->naipe=='c' || f3->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = NULL;
                aux->ant = f5->ant;
                aux->ant->prox = f5;
                f5->ant->prox = aux;
                f5->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f6
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f3->numero == 12){
                f6 = f3;
                f3 = NULL;
	 	result = 1;
            }
        }else{
            if(f3->numero == f6->ant->numero - 1 &&(
		((f3->naipe=='o' || f3->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((f3->naipe=='c' || f3->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = NULL;
                aux->ant = f6->ant;
                aux->ant->prox = f6;
                f6->ant->prox = aux;
                f6->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f7
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f3->numero == 12){
                f7 = f3;
                f3 = NULL;
	 	result = 1;
            }
        }else{
            if(f3->numero == f7->ant->numero - 1 &&(
		((f3->naipe=='o' || f3->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((f3->naipe=='c' || f3->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f3;
                f3 = NULL;
                aux->ant = f7->ant;
                aux->ant->prox = f7;
                f7->ant->prox = aux;
                f7->ant = aux->ant;
	 	result = 1;
            }
        }
    }

    // f4
    if(f4 != NULL){
        // tenta movimentar para f1
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f4->numero == 12){
                f1 = f4;
                f4 = NULL;
	 	result = 1;
            }
        }else{
            if(f4->numero == f1->ant->numero - 1 &&(
		((f4->naipe=='o' || f4->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((f4->naipe=='c' || f4->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = NULL;
                aux->ant = f1->ant;
                aux->ant->prox = f1;
                f1->ant->prox = aux;
                f1->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f2
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f4->numero == 12){
                f2 = f4;
                f4 = NULL;
	 	result = 1;
            }
        }else{
            if(f4->numero == f2->ant->numero - 1 &&(
		((f4->naipe=='o' || f4->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((f4->naipe=='c' || f4->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = NULL;
                aux->ant = f2->ant;
                aux->ant->prox = f2;
                f2->ant->prox = aux;
                f2->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f3
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f4->numero == 12){
                f3 = f4;
                f4 = NULL;
	 	result = 1;
            }
        }else{
            if(f4->numero == f3->ant->numero - 1 &&(
		((f4->naipe=='o' || f4->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((f4->naipe=='c' || f4->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = NULL;
                aux->ant = f3->ant;
                aux->ant->prox = f3;
                f3->ant->prox = aux;
                f3->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f5
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f4->numero == 12){
                f5 = f4;
                f4 = NULL;
	 	result = 1;
            }
        }else{
            if(f4->numero == f5->ant->numero - 1 &&(
		((f4->naipe=='o' || f4->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((f4->naipe=='c' || f4->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = NULL;
                aux->ant = f5->ant;
                aux->ant->prox = f5;
                f5->ant->prox = aux;
                f5->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f6
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f4->numero == 12){
                f6 = f4;
                f4 = NULL;
	 	result = 1;
            }
        }else{
            if(f4->numero == f6->ant->numero - 1 &&(
		((f4->naipe=='o' || f4->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((f4->naipe=='c' || f4->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = NULL;
                aux->ant = f6->ant;
                aux->ant->prox = f6;
                f6->ant->prox = aux;
                f6->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f7
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f4->numero == 12){
                f7 = f4;
                f4 = NULL;
	 	result = 1;
            }
        }else{
            if(f4->numero == f7->ant->numero - 1 &&(
		((f4->naipe=='o' || f4->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((f4->naipe=='c' || f4->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f4;
                f4 = NULL;
                aux->ant = f7->ant;
                aux->ant->prox = f7;
                f7->ant->prox = aux;
                f7->ant = aux->ant;
	 	result = 1;
            }
        }
    }

    // f5
    if(f5 != NULL){
        // tenta movimentar para f1
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f5->numero == 12){
                f1 = f5;
                f5 = NULL;
	 	result = 1;
            }
        }else{
            if(f5->numero == f1->ant->numero - 1 &&(
		((f5->naipe=='o' || f5->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((f5->naipe=='c' || f5->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = NULL;
                aux->ant = f1->ant;
                aux->ant->prox = f1;
                f1->ant->prox = aux;
                f1->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f2
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f5->numero == 12){
                f2 = f5;
                f5 = NULL;
	 	result = 1;
            }
        }else{
            if(f5->numero == f2->ant->numero - 1 &&(
		((f5->naipe=='o' || f5->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((f5->naipe=='c' || f5->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = NULL;
                aux->ant = f2->ant;
                aux->ant->prox = f2;
                f2->ant->prox = aux;
                f2->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f3
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f5->numero == 12){
                f3 = f5;
                f5 = NULL;
	 	result = 1;
            }
        }else{
            if(f5->numero == f3->ant->numero - 1 &&(
		((f5->naipe=='o' || f5->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((f5->naipe=='c' || f5->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = NULL;
                aux->ant = f3->ant;
                aux->ant->prox = f3;
                f3->ant->prox = aux;
                f3->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f4
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f5->numero == 12){
                f4 = f5;
                f5 = NULL;
	 	result = 1;
            }
        }else{
            if(f5->numero == f4->ant->numero - 1 &&(
		((f5->naipe=='o' || f5->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((f5->naipe=='c' || f5->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = NULL;
                aux->ant = f4->ant;
                aux->ant->prox = f4;
                f4->ant->prox = aux;
                f4->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f6
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f5->numero == 12){
                f6 = f5;
                f5 = NULL;
	 	result = 1;
            }
        }else{
            if(f5->numero == f6->ant->numero - 1 &&(
		((f5->naipe=='o' || f5->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((f5->naipe=='c' || f5->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = NULL;
                aux->ant = f6->ant;
                aux->ant->prox = f6;
                f6->ant->prox = aux;
                f6->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f7
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f5->numero == 12){
                f7 = f5;
                f5 = NULL;
	 	result = 1;
            }
        }else{
            if(f5->numero == f7->ant->numero - 1 &&(
		((f5->naipe=='o' || f5->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((f5->naipe=='c' || f5->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f5;
                f5 = NULL;
                aux->ant = f7->ant;
                aux->ant->prox = f7;
                f7->ant->prox = aux;
                f7->ant = aux->ant;
	 	result = 1;
            }
        }
    }

    // f6
    if(f6 != NULL){
        // tenta movimentar para f1
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f6->numero == 12){
                f1 = f6;
                f6 = NULL;
	 	result = 1;
            }
        }else{
            if(f6->numero == f1->ant->numero - 1 &&(
		((f6->naipe=='o' || f6->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((f6->naipe=='c' || f6->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = NULL;
                aux->ant = f1->ant;
                aux->ant->prox = f1;
                f1->ant->prox = aux;
                f1->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f2
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f6->numero == 12){
                f2 = f6;
                f6 = NULL;
	 	result = 1;
            }
        }else{
            if(f6->numero == f2->ant->numero - 1 &&(
		((f6->naipe=='o' || f6->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((f6->naipe=='c' || f6->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = NULL;
                aux->ant = f2->ant;
                aux->ant->prox = f2;
                f2->ant->prox = aux;
                f2->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f3
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f6->numero == 12){
                f3 = f6;
                f6 = NULL;
	 	result = 1;
            }
        }else{
            if(f6->numero == f3->ant->numero - 1 &&(
		((f6->naipe=='o' || f6->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((f6->naipe=='c' || f6->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = NULL;
                aux->ant = f3->ant;
                aux->ant->prox = f3;
                f3->ant->prox = aux;
                f3->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f4
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f6->numero == 12){
                f4 = f6;
                f6 = NULL;
	 	result = 1;
            }
        }else{
            if(f6->numero == f4->ant->numero - 1 &&(
		((f6->naipe=='o' || f6->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((f6->naipe=='c' || f6->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = NULL;
                aux->ant = f4->ant;
                aux->ant->prox = f4;
                f4->ant->prox = aux;
                f4->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f5
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f6->numero == 12){
                f5 = f6;
                f6 = NULL;
	 	result = 1;
            }
        }else{
            if(f6->numero == f5->ant->numero - 1 &&(
		((f6->naipe=='o' || f6->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((f6->naipe=='c' || f6->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = NULL;
                aux->ant = f5->ant;
                aux->ant->prox = f5;
                f5->ant->prox = aux;
                f5->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f7
        if(f7 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f6->numero == 12){
                f7 = f6;
                f6 = NULL;
	 	result = 1;
            }
        }else{
            if(f6->numero == f7->ant->numero - 1 &&(
		((f6->naipe=='o' || f6->naipe=='p') && (f7->ant->naipe == 'c' || f7->ant->naipe == 'e')) ||
		((f6->naipe=='c' || f6->naipe=='e') && (f7->ant->naipe == 'o' || f7->ant->naipe == 'p'))
	    )){
                aux = f6;
                f6 = NULL;
                aux->ant = f7->ant;
                aux->ant->prox = f7;
                f7->ant->prox = aux;
                f7->ant = aux->ant;
	 	result = 1;
            }
        }
    }

    // f7
    if(f7 != NULL){
        // tenta movimentar para f1
        if(f1 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f7->numero == 12){
                f1 = f7;
                f7 = NULL;
	 	result = 1;
            }
        }else{
            if(f7->numero == f1->ant->numero - 1 &&(
		((f7->naipe=='o' || f7->naipe=='p') && (f1->ant->naipe == 'c' || f1->ant->naipe == 'e')) ||
		((f7->naipe=='c' || f7->naipe=='e') && (f1->ant->naipe == 'o' || f1->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = NULL;
                aux->ant = f1->ant;
                aux->ant->prox = f1;
                f1->ant->prox = aux;
                f1->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f2
        if(f2 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f7->numero == 12){
                f2 = f7;
                f7 = NULL;
	 	result = 1;
            }
        }else{
            if(f7->numero == f2->ant->numero - 1 &&(
		((f7->naipe=='o' || f7->naipe=='p') && (f2->ant->naipe == 'c' || f2->ant->naipe == 'e')) ||
		((f7->naipe=='c' || f7->naipe=='e') && (f2->ant->naipe == 'o' || f2->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = NULL;
                aux->ant = f2->ant;
                aux->ant->prox = f2;
                f2->ant->prox = aux;
                f2->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f3
        if(f3 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f7->numero == 12){
                f3 = f7;
                f7 = NULL;
	 	result = 1;
            }
        }else{
            if(f7->numero == f3->ant->numero - 1 &&(
		((f7->naipe=='o' || f7->naipe=='p') && (f3->ant->naipe == 'c' || f3->ant->naipe == 'e')) ||
		((f7->naipe=='c' || f7->naipe=='e') && (f3->ant->naipe == 'o' || f3->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = NULL;
                aux->ant = f3->ant;
                aux->ant->prox = f3;
                f3->ant->prox = aux;
                f3->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f4
        if(f4 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f7->numero == 12){
                f4 = f7;
                f7 = NULL;
	 	result = 1;
            }
        }else{
            if(f7->numero == f4->ant->numero - 1 &&(
		((f7->naipe=='o' || f7->naipe=='p') && (f4->ant->naipe == 'c' || f4->ant->naipe == 'e')) ||
		((f7->naipe=='c' || f7->naipe=='e') && (f4->ant->naipe == 'o' || f4->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = NULL;
                aux->ant = f4->ant;
                aux->ant->prox = f4;
                f4->ant->prox = aux;
                f4->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f5
        if(f5 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f7->numero == 12){
                f5 = f7;
                f7 = NULL;
	 	result = 1;
            }
        }else{
            if(f7->numero == f5->ant->numero - 1 &&(
		((f7->naipe=='o' || f7->naipe=='p') && (f5->ant->naipe == 'c' || f5->ant->naipe == 'e')) ||
		((f7->naipe=='c' || f7->naipe=='e') && (f5->ant->naipe == 'o' || f5->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = NULL;
                aux->ant = f5->ant;
                aux->ant->prox = f5;
                f5->ant->prox = aux;
                f5->ant = aux->ant;
	 	result = 1;
            }
        }
        // tenta movimentar para f6
        if(f6 == NULL){ // se nao tem nada na fila so pode colocar o K
            if(f7->numero == 12){
                f6 = f7;
                f7 = NULL;
	 	result = 1;
            }
        }else{
            if(f7->numero == f6->ant->numero - 1 &&(
		((f7->naipe=='o' || f7->naipe=='p') && (f6->ant->naipe == 'c' || f6->ant->naipe == 'e')) ||
		((f7->naipe=='c' || f7->naipe=='e') && (f6->ant->naipe == 'o' || f6->ant->naipe == 'p'))
	    )){
                aux = f7;
                f7 = NULL;
                aux->ant = f6->ant;
                aux->ant->prox = f6;
                f6->ant->prox = aux;
                f6->ant = aux->ant;
	 	result = 1;
            }
        }
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
		if(movimentaFuco()){
			movimentou = 1;
		}
	}

	if(!movimentou){
		if(movimentaListas()){
			movimentou = 1;
		}
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


// imprime estatisticas do fuco e do descarte
void estatsFucoDescarte(){
	int nFuco = 0;
	int nDescarte = 0;
	Carta* percorreFuco = fuco;
	Carta* percorreDescarte = NULL;

	while(percorreFuco->prox != NULL){ // percorrendo fuco
		percorreFuco = percorreFuco->prox;
		nFuco++;
	}

	if(n1 != NULL){
		percorreDescarte = n1; // vamos percorrer o naipe 1

		while(percorreDescarte->prox != NULL && percorreDescarte != n1){
			percorreDescarte = percorreDescarte->prox;
			nDescarte++;
		}
	}

	if(n2 != NULL){
		percorreDescarte = n2; // vamos percorrer o naipe 2

		while(percorreDescarte->prox != NULL && percorreDescarte != n2){
			percorreDescarte = percorreDescarte->prox;
			nDescarte++;
		}
	}

	if(n3 != NULL){
		percorreDescarte = n3; // vamos percorrer o naipe 3

		while(percorreDescarte->prox != NULL && percorreDescarte != n3){
			percorreDescarte = percorreDescarte->prox;
			nDescarte++;
		}
	}

	if(n4 != NULL){
		percorreDescarte = n4; // vamos percorrer o naipe 4

		while(percorreDescarte->prox != NULL && percorreDescarte != n4){
			percorreDescarte = percorreDescarte->prox;
			nDescarte++;
		}
	}

	printf("Monte: %d\nDescarte: %d\n", nFuco, nDescarte);
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
		estatsFucoDescarte();
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
