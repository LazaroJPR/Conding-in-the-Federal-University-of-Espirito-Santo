/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "MatrizEsparsa.h"

#define TAM 255

Matriz *CriarMatriz(int i, int j){
    Matriz *A;
	A = (Matriz*)malloc(sizeof(Matriz));
	if (!A || i<=0 || j<=0) return 0;
	A->inicio = NULL;
	A->fimLinha = NULL;
	A->fimColuna = NULL;
	A->i = i;
	A->j = j;

	IniciaCabecas(A);
	return A;
}

int IniciaCabecas(Matriz *A){
    int i=0;

    Celula *cabeca;
    cabeca = (Celula*)malloc(sizeof(Celula));

    if(!cabeca)return 0;

    cabeca->coluna = -1;
    cabeca->linha = -1;

    A->inicio = cabeca;
    A->fimLinha = cabeca;
    A->fimColuna = cabeca;

    for(i = 1; i <= A->j; i++)InsereCabecaColuna(A);
    for(i = 1; i <= A->i; i++)InsereCabecaLinha(A);
    return 1;
}

int InsereCabecaColuna(Matriz *A){
    Celula *cabeca;
    cabeca = (Celula*)malloc(sizeof(Celula));

    if (!cabeca)return 0;

    cabeca->coluna = -1;
    cabeca->linha = 0;

    A->fimColuna->direita = cabeca;
    A->fimColuna = cabeca;

    cabeca->direita = A->inicio;
    cabeca->abaixo = cabeca;
    return 1;
}

int InsereCabecaLinha(Matriz *A){
    Celula *cabeca;
    cabeca = (Celula*)malloc(sizeof(Celula));

    if (!cabeca)return 0;

    cabeca->coluna = 0;
    cabeca->linha = -1;

    A->fimLinha->abaixo = cabeca;
    A->fimLinha = cabeca;

    cabeca->abaixo = A->inicio;
    cabeca->direita = cabeca;

    return 1;
}
void Insere(int i, int j, double valor, Matriz *A){
    int m;
    if (!A || A->i <= 0 || A->j <= 0 || !valor) return;
    if (i>A->i || j>A->j || !valor || i < 1 || j < 1) return;

    Celula *pCelula, *pCelulaColuna, *pCelulaLinha;

    pCelula = (Celula*)malloc(sizeof(Celula));

    if (!pCelula) return;

    pCelula->linha = i;
    pCelula->coluna = j;
    pCelula->valor = valor;

    pCelulaLinha = A->inicio->abaixo;
    pCelulaColuna = A->inicio->direita;

    for(m=0; m<i-1; m++) pCelulaLinha = pCelulaLinha->abaixo;
    m=0;

    while (m<j && pCelulaLinha->direita->linha != -1){
        if (pCelulaLinha->direita->coluna > pCelula->coluna){
            pCelula->direita = pCelulaLinha->direita;
            pCelulaLinha->direita = pCelula;
        }
        else pCelulaLinha = pCelulaLinha->direita;
        m++;
    }
    if (pCelulaLinha->direita->linha == -1){
        pCelula->direita = pCelulaLinha->direita;
        pCelulaLinha->direita = pCelula;
    }

    for (m = 0; m < j-1; m++)pCelulaColuna = pCelulaColuna->direita;
    m=0;

    while(m<i && pCelulaColuna->abaixo->coluna != -1){
        if(pCelulaColuna->abaixo->linha > pCelula->linha){
            pCelula->abaixo = pCelulaColuna->abaixo;
            pCelulaColuna->abaixo = pCelula;
        }
        else pCelulaColuna = pCelulaColuna->abaixo;
        m++;
    }
    if(pCelulaColuna->abaixo->coluna == -1){
        pCelula->abaixo = pCelulaColuna->abaixo;
        pCelulaColuna->abaixo = pCelula;
    }
    return;
}

void ImprimeMatriz(Matriz *A){
    int m, n;
    Celula *pCelula;
    if (!A || !A->i || !A->j)return;

    pCelula = A->inicio->abaixo;
    printf("\n");
    for (m = 1; m <= A->i; m++){
        for (n = 1; n <= A->j; n++){
            if (pCelula->direita->linha == m && pCelula->direita->coluna == n){
                pCelula = pCelula->direita;
                printf("  \t%0.2f   ", pCelula->valor);
            }
            else printf("  \t%0.2f   ", 0.0F);
        }
        printf("\n");
        pCelula = pCelula->direita->abaixo;
    }
    return;
}

int ApagaMatriz(Matriz *A){
    int m = 1;
    int n = 1;
    Celula *pCelula, *aux;

    if (!A || !A->i || !A->j)return 0;
    pCelula = A->inicio->abaixo;
    pCelula = pCelula->direita;

    for (m = 1; m <= A->i; m++){
        for (n = 1; n <= A->j; n++){
            if (pCelula->linha == m && pCelula->coluna == n){
                aux = pCelula;
                pCelula = pCelula->direita;
                free(aux);
            }
        }
        pCelula = pCelula->abaixo->direita;
    }

    pCelula = A->inicio->direita;
    for (m = 0; m < A->j; m++){
        aux = pCelula;
        pCelula = pCelula->direita;
        free(aux);
    }
    pCelula = A->inicio->abaixo;

    for (m = 0; m < A->i; m++){
        aux = pCelula;
        pCelula = pCelula->abaixo;
        free(aux);
    }
    pCelula = A->inicio;

    free(pCelula);
    A->fimColuna = A->fimLinha = A->inicio = NULL;
    A->i = A->j = 0;
    A = NULL;
    return 1;
}

Matriz *SomaMatriz(Matriz *A, Matriz *B){
    int m, n;
    float soma;
    Matriz *matC;
    Celula *pCelulaA, *pCelulaB;

    if (A->i != B->i || A->j != B->j){
        printf("\nMatrizes de Ordem diferente.\n");
        return NULL;
    }
    if (!A || !B || !A->i|| !A->j)return NULL;

    matC = CriarMatriz(A->i, B->j);

    pCelulaA = A->inicio->abaixo;
    pCelulaB = B->inicio->abaixo;

    for (m = 1; m <= A->i; m++){
        for (n = 1; n <= A->j; n++){
            if (n == pCelulaA->direita->coluna && n == pCelulaB->direita->coluna){
                soma = pCelulaA->direita->valor + pCelulaB->direita->valor;
                if (soma) Insere(m,n,soma,matC);
                pCelulaA = pCelulaA->direita;
                pCelulaB = pCelulaB->direita;
            }
            else if (n == pCelulaA->direita->coluna){
                Insere(m,n,pCelulaA->direita->valor, matC);
                pCelulaA = pCelulaA->direita;
            }
            else if (m == pCelulaB->direita->coluna){
                Insere(m, n, pCelulaB->direita->valor, matC);
                pCelulaB = pCelulaB->direita;
            }
        }
        pCelulaA = pCelulaA->direita->abaixo;
        pCelulaB = pCelulaB->direita->abaixo;
    }
    return matC;
}

Matriz *MultiplicaMatriz(Matriz *A, Matriz*B){
    int m=0, n=0, k=0;
    float total;
    Matriz *matC;

    if (A->i != B->j){
        printf("\nNao foi possivel multiplicar as matrizes.\n");
        return NULL;
    }
    if (!A || !B || !A->i || !A->j || !B->i)return NULL;

    matC = CriarMatriz(A->i, B->j);

    for (m = 1; m <= A->i; m++){
        for (n = 1; n <= B->j; n++){
            total = 0;
            for (k = 1; k <= A->j; k++)total += ObtemElementoPeloIndice(A,m,k) * ObtemElementoPeloIndice(B,k,n);
            if (total)Insere(m,n,total,matC);
        }
    }
    return matC;
}

double ObtemElementoPeloIndice(Matriz *A, int i, int j){
    Celula *pCelula;
    int m = 0;
    pCelula = A->inicio->direita;

    for (m = 0; m < j-1; m++)pCelula = pCelula->direita;

    do{
        pCelula = pCelula->abaixo;
        if (pCelula->linha == i)return pCelula->valor;
    }
    while(pCelula->coluna != -1);
    return 0;
}

Matriz *LeMatriz(char *nome){
    Matriz *A;

    char linha[TAM];

    int i=0, j=0;
    int m=0, n=0;
    float valor=0.0;

    FILE *arquivo;

    arquivo = fopen(nome,"r");
    if (!arquivo){
      arquivo = fopen("arquivo.txt","w");
      fprintf(arquivo, "Erro ao abrir arquivo\n");
      fclose(arquivo);
      return NULL;
    }

    fgets(linha, TAM, arquivo);
    sscanf(linha, "%d %d", &i, &j);

    if (i<=0 || j<=0)return 0;

    A = CriarMatriz(i, j);

    while(fgets(linha, TAM, arquivo)){
        sscanf(linha, "%d %d %f", &m, &n, &valor);
        if (valor)Insere(m, n, valor, A);
        }
    fclose(arquivo);
    return A;
}
