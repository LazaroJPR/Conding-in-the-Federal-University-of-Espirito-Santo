/*
    Trabalho Prático 1 – Skip List – Estruturas de Dados
    Professor: Roney Pignaton da Silva
    Aluno: Lázaro José Pedrosa dos Reis
    2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "skiplist.c"

int main(){
    int chave, hierarquia;
    char comando;
    FILE *entrada;
    skiplist *skpl;
    skpl = createlist();
    entrada = fopen("entrada.txt","r");                     //Entrada do arquivo .txt

    if (entrada == NULL){
            printf("O arquivo nao pode ser aberto\n");
            return 0;
        }
    while(fscanf(entrada,"%c %d %d \n",&comando, &chave, &hierarquia) != EOF){           //Le o arquivo entrada.txt e faz a devida operacao de acordo com os comandos recebidos
            if(comando = 'I') Insere(createnode(chave,hierarquia),hierarquia,skpl);
            if(comando = 'R') removeList(chave,skpl);
            if(comando = 'B'){
                node *listah;
                listah = createnode(0,MAXNIVEIS);
                searchList(chave,skpl,listah,1);
            }
            if(comando = 'P') printListH(skpl,chave);
            if(comando = 'A') printList(skpl);
        }
    fclose(entrada);
    return 0;
}
