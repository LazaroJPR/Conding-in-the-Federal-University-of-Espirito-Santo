/*
    Trabalho Prático 1 – Skip List – Estruturas de Dados
    Professor: Roney Pignaton da Silva
    Aluno: Lázaro José Pedrosa dos Reis
    2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

skiplist *createlist(){
    FILE *retorno;                                              //Arquivo para o retorno em .txt
    retorno = fopen("saida.txt","w");                           //Abrindo o arquivo saida.txt
    skiplist *skpl;                                             //Criando um ponteiro para a cabeca da skiplist
    int i;                                                      //Auxiliar
    if(skpl=(skiplist*)malloc(sizeof(skiplist))){                //Mallocando espaço pra struct
        for(i = 0; i <= MAXNIVEIS; i++) skpl->first[i] = NULL;  //For para igualar todos os ponteiros do vetor para NULL
        fprintf(retorno,"true\n");                              //Retorno no arquivo .txt
        return skpl;                                            //Se tudo ocorreu certo, retorna a cabeça da skiplist
    }
    fprintf(retorno,"false\n");                                 //Se nao ocorreu, retorna false no arquivo .txt
    fclose(retorno);
    return NULL;                                                //Retorna NULL
}

node *createnode(int value, int h){
    FILE *retorno;
    retorno = fopen("saida.txt","w");
    node *skpn;
    int i;

    if(skpn=(node*)malloc(sizeof(node))){
        skpn->key = value;                          //Iguala a chave do nó com o valor dado
        skpn->h = h;                                //Iguala a hierarquia do nó com o valor dado
        for(i=0; i<=h; i++) skpn->next[i] = NULL;   //Aponta para NULL todos os ponteiros do vetor do nó
        fprintf(retorno,"true\n");
        return skpn;
    }
    fprintf(retorno,"false\n");
    fclose(retorno);
    return NULL;
}

int isEmptyList(skiplist *skpl){
    FILE *retorno;
    retorno = fopen("saida.txt","w");
    if(skpl->first[0] == NULL){          //Se o primeiro nó da hierarquia 0 for igual a NULL, retorna true
            fprintf(retorno,"true\n");
            return 1;
        }
    else{
        fprintf(retorno,"false\n");
        fclose(retorno);
        return 0;
    }
}

int searchList(int value, skiplist *skpl, node *ListaH, int imprimir){
    node *x;                                                                            //Nó auxiliar
    int h;
    FILE *retorno;

    if (imprimir == 1) retorno = fopen("searchList.txt","w");                           //Se o valor de imprimir for 1, ele irá escrever todos os dados desta funçao no arquivo searchList.txt
    if(!skpl || !ListaH){                                                               //Se a cabeça ou a lista nao existir, já retorna
            if (imprimir == 1) fprintf(retorno,"false\n");
            return 0;
        }

    x = skpl->first[MAXNIVEIS];                                                         //O ponteiro auxiliar se iguala ao primeiro ponteiro da cabeça na maior hierarquia disponivel
    for(h = MAXNIVEIS; h >= 0; h--){                                                    //For para ir diminuindo a hierarquia até o 0
        if(x == NULL){                                                                  //Se o ponteiro é NULL, é igualado no nó ListaH na mesma hierarquia, isso serve para auxiliar as funcoes de inserir e remover
            ListaH->next[h] = NULL;
            if(imprimir == 1) fprintf(retorno,"NULL\n");
        }
        else{                                                                           //Se nao, o auxiliar vai andar pro próximo até encontrar um próximo valor maior que o desejado ou quando o próximo for NULL
            while ((x->next[h]->key < value) && (x->next[h] != NULL)) x = x->next[h];
            ListaH->next[h] = x;                                                        //Iguala o auxiliar encontrado no nó ListaH na mesma hierarquia
            if(imprimir == 1) fprintf(retorno,"%d %d\n",ListaH->next[h]->key,h);        //Imprime no arquivo searchlist.txt a cahve e a hierarquia
        }
    }

    if(x == NULL){                                                                      //Se não achou nenhum nó maior que o informado e o nó em que o auxiliar parou for NULL, é retornado 0
            if (imprimir == 1) fprintf(retorno,"false\n");
            return 0;
        }
    if (x->key == value){                                                               //Se encontrou o valor desejado, é retornado o valor 1 e informado no arquivo .txt
        if(imprimir == 1){
                fprintf(retorno,"%d %d\n",x->key,h);
                fprintf(retorno,"true\n");
            }
        return 1;
    }

    if (imprimir == 1) fprintf(retorno,"false\n");
    fclose(retorno);
    return 0;
}

int Insere(node *x, int h, skiplist *skpl){
    FILE *retorno;
    retorno = fopen("saida.txt","w");

    if(!skpl){
        fprintf(retorno,"false\n");
        return 0;
    }
    int i;
    node *ListaH = createnode(0,MAXNIVEIS);
    if((searchList(x->key,skpl,ListaH,0)) == 1){            //Utiliza a funcao searchlist para verificar se valor que deseja inserir já existe e obter a ListaH com os nós anteriores ao que o nó desejado deverá ser inserido
            fprintf(retorno,"false\n");
            return 0;
        }

    for(i=h; i >= 0; i--){                                  //For que vai da hierarquia informada até o 0
        if(ListaH->next[i] != NULL){                        //Se não for o primeiro nó a ser inserido, utiliza-se a ListaH e se faz os devidos apontamentos para a inserção do novo nó
            x->next[i] = ListaH->next[i];
            ListaH->next[i] = x->next[i];
            x->h = h;
        }
        else{                                               //Se for o primeiro nó, simplesmente se insere pela cabeça e aponta o next para NULL
                skpl->first[i] = x;
                x->next[i] = NULL;
            }
    }
    fprintf(retorno,"true\n");
    fclose(retorno);
    return 1;
}

int removeList(int value, skiplist *skpl){
    FILE *retorno;
    retorno = fopen("saida.txt","w");

    if(!skpl){
            fprintf(retorno,"false\n");
            return 0;
        }
    int i,auxh;
    node *ListaH = createnode(0,MAXNIVEIS), *aux;

    if((searchList(value,skpl,ListaH,0)) == 0){                 //Faz a procura do valor a se removido na skiplist utilizando a funcao searchlist e ainda usa a ListaH para auxiliar nos apontamentos caso ocorra a remoção
            fprintf(retorno,"false\n");                         //Se o valor nao for encontrado na skiplist, simplesmente retorna 0 e false no arquivo .txt
            return 0;
        }
    aux = ListaH->next[0]->next[0];                             //Com o nó encontrado, apontamos no nó auxiliar para o próximo do próximo da ListaH 
    auxh = aux->h;                                              //Obtemos a hierarquia do nó a ser 
    
    for(i = 0; i == auxh; i++)  ListaH->next[i] = aux->next[i]; //Com o for indo da hierarquia desejada até o 0, apontamos o no anterior ao nó a ser removido para o proximo no do que sera removido
    free(aux);                                                  //Damos free no nó que era pra ser removido
    fprintf(retorno,"true\n");
    fclose(retorno);                                            //Retorna true no arquivo .txt e 1 na funcao
    return 1;
}

void printListH(skiplist *skpl, int h){
    FILE *retorno;
    retorno = fopen("saida.txt","w");
    
    if(!skpl){
        fprintf(retorno,"false\n");
        return;
    }
    node *aux;
    aux = skpl->first[h];                       //Aponta pro primeiro nó da hierarquia desejada
    if(aux == NULL){
            fprintf(retorno,"false\n");         //Se o primeiro nó for null, se retorna false no arquivo .txt
            return;
        }
    while(aux != NULL){                         //Vai avançando e printando os nós até chegar no NULL
        fprintf(retorno,"%d %d\n",aux->key,h);
        aux = aux->next[h];
    }
    fprintf(retorno,"true\n");
    fclose(retorno);
    return;
}

void printList(skiplist *skpl){
    FILE *retorno;
    retorno = fopen("saida.txt","w");
    
    if(!skpl){
        fprintf(retorno,"false\n");
        return;
    }
    int i;
    node *aux;
    for(i = MAXNIVEIS; i >= 0; i--){                        //For que passa por todas as hierarquias
        aux = skpl->first[i];                               //Auxiliar que aponta para o primeiro de cada hierarquia
        if(aux != NULL){
            while(aux != NULL){                             //Printa no arquivo .txt os valores dos nós
                fprintf(retorno,"%d %d\n",aux[i].key,i);    
                aux = aux->next[i];
            }
        }
        else fprintf(retorno,"NULL %d\n",i);    	    	//Se o nó for NULL, printa NULL no arquivo  .txt
    }
    fprintf(retorno,"true\n");
    fclose(retorno);
    return;
}
