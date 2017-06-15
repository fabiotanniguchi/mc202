#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	Fabio Takahashi Tanniguchi - RA 145980

	MC202 - Estruturas de Dados
	2013 - 2o semestre

	Lab 02 - Hidato
*/


void limpaPosicoes(int **posicao, int *andouX, int *andouY, int xAtual, int yAtual, int qtoAndou, int n){
	int i;

	for(i = qtoAndou - 1; i >= 0 && andouX[i] != xAtual && andouY[i] != yAtual; i--){
		if(andouX[i] != -1 && andouY[i] != -1){
			posicao[andouX[i]][andouY[i]] = 0;
		}
	}
}


void caminho(int **posicao, int iInit, int jInit, int *nSolucoes, int atual, int n, int **solucao, int *andouX, int *andouY, int *qtoAndou){
	int i,j;
	int qtoAndouAntes = *qtoAndou;
	int achouVizinho = 0;

	if(posicao[iInit][jInit] != 0 && posicao[iInit][jInit] != atual)
		return;
	else{

		if(posicao[iInit][jInit] != atual){
			posicao[iInit][jInit] = atual;
			andouX[*qtoAndou] = iInit;
			andouY[*qtoAndou] = jInit;
		}
		else{
			andouX[*qtoAndou] = -1;
			andouY[*qtoAndou] = -1;
		}

		*qtoAndou = *qtoAndou + 1;

		if(atual == n){ // item colocado no hidato eh o ultimo => achamos solucao
			for(i = 0; i < sqrt(n); i++){
				for(j = 0; j < sqrt(n); j++){
					solucao[i][j] = posicao[i][j];
				}
			}

			*nSolucoes = *nSolucoes + 1;
		} else {
			// procurando vizinho que seja atual+1
		
			if(iInit != 0){
				if(jInit != 0){
					if(posicao[iInit-1][jInit-1] == atual + 1 && !achouVizinho){
						achouVizinho = 1;
						caminho(posicao, iInit-1, jInit-1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}
				}

				if(posicao[iInit-1][jInit] == atual + 1 && !achouVizinho){
					achouVizinho = 1;
					caminho(posicao, iInit-1, jInit, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
					limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
				}

				if(jInit != sqrt(n) - 1){
					if(posicao[iInit-1][jInit+1] == atual + 1 && !achouVizinho){
						achouVizinho = 1;
						caminho(posicao, iInit-1, jInit+1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}
				}
			}

			if(jInit != 0){
				if(posicao[iInit][jInit-1] == atual + 1 && !achouVizinho){
					achouVizinho = 1;
					caminho(posicao, iInit, jInit-1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
					limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
				}
			}

			if(jInit != sqrt(n)-1){
				if(posicao[iInit][jInit+1] == atual + 1 && !achouVizinho){
					achouVizinho = 1;
					caminho(posicao, iInit, jInit+1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
					limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
				}
			}

			if(iInit != sqrt(n) - 1){
				if(jInit != 0){
					if(posicao[iInit+1][jInit-1] == atual + 1 && !achouVizinho){
						achouVizinho = 1;
						caminho(posicao, iInit+1, jInit-1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}
				}

				if(posicao[iInit+1][jInit] == atual + 1 && !achouVizinho){
					achouVizinho = 1;
					caminho(posicao, iInit+1, jInit, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
					limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
				}

				if(jInit != sqrt(n) - 1){
					if(posicao[iInit+1][jInit+1] == atual + 1 && !achouVizinho){
						achouVizinho = 1;
						caminho(posicao, iInit+1, jInit+1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}
				}
			}

			if(!achouVizinho){ // nao achou vizinho com atual+1, logo vamos procurar 0
				//andouX[*qtoAndou] = iInit;
				//andouY[*qtoAndou] = jInit;
				//*qtoAndou = *qtoAndou + 1;

				if(iInit != 0){
					if(jInit != 0){
						if(posicao[iInit-1][jInit-1] == 0){
							caminho(posicao, iInit-1, jInit-1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
							// apos cada procura de solucao, limpar o trajeto feito nela
							limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
						}
					}

					if(posicao[iInit-1][jInit] == 0){
						caminho(posicao, iInit-1, jInit, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}

					if(jInit != sqrt(n) - 1){
						if(posicao[iInit-1][jInit+1] == 0){
							caminho(posicao, iInit-1, jInit+1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
							limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
						}
					}
				}

				if(jInit != 0){
					if(posicao[iInit][jInit-1] == 0){
						caminho(posicao, iInit, jInit-1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}
				}

				if(jInit != sqrt(n)-1){
					if(posicao[iInit][jInit+1] == 0){
						caminho(posicao, iInit, jInit+1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}
				}

				if(iInit != sqrt(n) - 1){
					if(jInit != 0){
						if(posicao[iInit+1][jInit-1] == 0){
							caminho(posicao, iInit+1, jInit-1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
							limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
						}
					}

					if(posicao[iInit+1][jInit] == 0){
						caminho(posicao, iInit+1, jInit, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
						limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
					}

					if(jInit != sqrt(n) - 1){
						if(posicao[iInit+1][jInit+1] == 0){
							caminho(posicao, iInit+1, jInit+1, nSolucoes, atual+1, n, solucao, andouX, andouY, qtoAndou);
							limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
						}
					}
				}
			}
			//limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
			*qtoAndou = qtoAndouAntes;
		}
		//limpaPosicoes(posicao, andouX, andouY, iInit, jInit,*qtoAndou, sqrt(n));
		*qtoAndou = qtoAndouAntes;
	}
}


// recebe a matriz inicial e retorna o num de solucoes
int hidato(int **posicao, int n){
	int nSolucoes = 0;
	int achouPosInit = 0;
	int i,j;
	int iInit = -1, jInit = -1;
	int **solucao;
	int continua = 1;
	int qtoAndou = 0;
	int *andouX, *andouY; // vetores com posicoes X e Y andadas

	solucao = calloc(n, sizeof(int*));

	andouX = (int*)malloc(n * n * sizeof(int));
	andouY = (int*)malloc(n * n * sizeof(int));

	if(solucao != NULL && andouX != NULL && andouY != NULL){ // memoria alocada sem problemas

		for(i=0; i<n; i++){
			solucao[i] = calloc(n, sizeof(int));

			if(solucao[i] == NULL) // nao pode seguir em frente, problema de alocacao
				continua = 0;
		}

		if(continua){

			// procurando posicao inicial do hidato
			for(i = 0; (i < n && !achouPosInit); i++){
				for(j = 0; (j < n && !achouPosInit); j++){
					if(posicao[i][j] == 1){
						achouPosInit = 1;
						iInit = i;
						jInit = j;
					}
				}
			}

			caminho(posicao, iInit, jInit, &nSolucoes, 1, n*n, solucao, andouX, andouY, &qtoAndou);

			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					posicao[i][j] = solucao[i][j];
				}
			}
		}
	}

	return nSolucoes;
}


// na main ocorrem operacoes de input e output
int main(){
	int n = 0, i, j, nSolucoes, continua = 1;
	int **posicao;

	scanf("%d",&n);

	posicao = calloc(n, sizeof(int*));

	if(posicao != NULL){ // memoria alocada sem problemas

		for(i=0; i<n; i++){
			posicao[i] = calloc(n, sizeof(int));

			if(posicao[i] == NULL) // nao pode seguir em frente, problema de alocacao
				continua = 0;
		}

		if(continua){
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++){
					scanf("%d", &posicao[i][j]);
				}

			nSolucoes = hidato(posicao, n);

			if(nSolucoes == 0){
				printf("Problema insoluvel.\n");
			}else{
				if(nSolucoes > 1)
					printf("O problema possui %d solucoes.\n", nSolucoes);
				else{
					printf("Solucao unica do problema:\n");
					// imprimindo matriz do hidato
					for(i = 0; i < n; i++){
						for(j = 0; j < n; j++){
							if(j == n - 1)
								printf("%d\n", posicao[i][j]);
							else
								printf("%d ", posicao[i][j]);
						}
					}
				}
			}
		}

		for(i=0; i<n; i++){
			free(posicao[i]);
		}
		free(posicao);
	}

	return 0;
}

