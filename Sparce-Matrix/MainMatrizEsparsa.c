/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatrizEsparsa.c"

#define TAM 255

void main(){
    int i;
    char A[TAM], B[TAM], C[TAM];
    Matriz *mA, *mB, *mC, *mD, *mS;

    printf("---------------------Trabalho sobre Matriz Esparsa---------------------\n");
    printf("Aluno: Lazaro Jose pedrosa dos Reis\n\n");
    printf("Estrutura de dados I - 2019/01\n");
    printf("\n-------------------Lendo e imprimindo 3 Matrizes-----------------------\n");
    printf("\nInsira o nome do arquivo da matriz A:\n->>");

    fgets(A, TAM, stdin);
    A[strlen(A)-1] = '\0';
    mA = LeMatriz(A);
    printf("\nMatriz A:\n\n");
    ImprimeMatriz(mA);

    printf("\nInsira o nome do arquivo da matriz B:\n->>");
    fgets(B, TAM, stdin);
    B[strlen(B)-1] = '\0';
    mB=LeMatriz(B);
    printf("\nMatriz B:\n\n");
    ImprimeMatriz(mB);

    printf("\nInsira o nome do arquivo da matriz B:\n->>");
    fgets(C, TAM, stdin);
    C[strlen(C)-1] = '\0';
    mC = LeMatriz(C);
    printf("\nMatriz C:\n\n");
    ImprimeMatriz(mC);
    
    printf("\n-------------------------Somando 3 Matrizes------------------------------\n");
    mD=SomaMatriz(mA,mB);
    mS=SomaMatriz(mD,mC);
    printf("\nSoma das matrizes:\n");
    ImprimeMatriz(mS);

    printf("\n----------------------Apagando a Matriz da soma---------------------------\n");
    ApagaMatriz(mD);
    ApagaMatriz(mS);
    printf("\nA matriz foi apagada!\n");

    printf("\n----------------------Multiplicando 3 Matrizes----------------------------\n");
    mD=MultiplicaMatriz(mA,mB);
    mS=MultiplicaMatriz(mC,mD);
    printf("\nMultiplicacao das matrizes:\n");
    ImprimeMatriz(mS);

    printf("\n------------------Apagando a Matriz da multiplicacao----------------------\n");
    ApagaMatriz(mD);
    ApagaMatriz(mS);
    printf("\nA matriz foi apagada!\n");
    printf("\n-------------------------Fim do Trabalho-----------------------------------\n");
}
