#include<stdio.h>
#include <stdlib.h>

/*
	Fabio Takahashi Tanniguchi - RA 145980

	MC202 - Estruturas de Dados
	2013 - 2o semestre

	Lab 01 - Tabela de Campeonato
*/

typedef struct {
	int time1;
	int time2;
} Jogo;

int main(){
	int nTimes = 0;
	int i = 0;
	int j = 0;

	scanf("%d\n",&nTimes); // lendo o numero de jogos

	Jogo *jogo = NULL;
	char *time = NULL;
	char temp, temp2;

	if(nTimes < 2 || nTimes > 20){
		if(nTimes < 2) // menos que o minimo
			printf("Erro: Nao ha campeonato com menos de 2 times");
		else // mais times que o maximo permitido
			printf("Erro: Numero maximo de times excedido");
	}else{ // numero de times ok

		jogo = (Jogo*) malloc(nTimes * nTimes * sizeof(Jogo)); // vetor simulando matriz quadrada
		time = (char*) malloc(nTimes * sizeof(char));

		for(i = 0; i < nTimes; i++)
			if(i<nTimes-1)
				scanf("%c ",time+i);
			else
				scanf("%c\n",time+i); // ultimo registro da linha

		for(i = 0; i < nTimes; i++)
			for(j = 0; j < i; j++){
				if(i == nTimes-1 && j == nTimes -2) // ultimo registro de jogo (sem \n)
					scanf("%c %c %d %d", &temp, &temp2, &(jogo[i*nTimes+j].time1), &(jogo[i*nTimes+j].time2));
				else
					scanf("%c %c %d %d\n", &temp, &temp2, &(jogo[i*nTimes+j].time1), &(jogo[i*nTimes+j].time2));
			}

		printf("X");
		for(i = 0; i < nTimes; i++) // imprimindo parte superior da matriz exibida na tela
			printf("|  %c  ", *(time+i) );
		printf("\n");
		
		for(i = 0; i < nTimes; i++){
			printf("%c", *(time+i) ); // imprimindo lateral da matriz exibida na tela

			for(j = 0; j < nTimes; j++){
				if(i == j){
					printf("|  X  ");
				}else{
					if(i<j){ // inverter resultados
						printf("| %d:%d ", jogo[j*nTimes+i].time2, jogo[j*nTimes+i].time1);
					}else{ // resultados normais
						printf("| %d:%d ", jogo[i*nTimes+j].time1, jogo[i*nTimes+j].time2);
					}
				}
			}
			printf("\n");
		}

		free(time);
		free(jogo);
	}

	return 0;
}

