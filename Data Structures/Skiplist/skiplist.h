/*
    Trabalho Prático 1 – Skip List – Estruturas de Dados
    Professor: Roney Pignaton da Silva
    Aluno: Lázaro José Pedrosa dos Reis
    2019
*/

#define MAXNIVEIS 4     //Numero maximo de niveis hierarquicos

typedef struct tnode{                   //TAD do nó da skiplist
    int key;                            //Valor do nó
    int h;                              //Hierarquia do nó
    struct tnode *next[MAXNIVEIS];      //Vetor de ponteiros para os proximos nós
}node;

typedef struct{                 //TAD da cabeca da smkiplist
    node *first[MAXNIVEIS];     //Vetor de ponteios para os primeiros nós da skiplistt
}skiplist;

//Funcao que cria a cabeca da skiplist
skiplist *createlist();                         

//Funcao que cria um nó para a skiplist                            
node *createnode(int value, int h); 

//Funcao que verifica se a cabeca da skiplist está apontando para null
int isEmptyList(skiplist *skpl);                       

//Funcao que procura determinado valor na skiplist
int searchList(int value, skiplist *skpl, node *ListaH, int imprimir);   

//Funcao que insere um nó na skiplist
int Insere(node *x, int h, skiplist *skpl);      

//Funcao que remove determinado valor da skiplist
int removeList(int value, skiplist *skpl);   

//Funcao que imprimi no arquivo txt determinado nivel da skiplist
void printListH(skiplist *skpl, int h);              

//Funcao que imprimi no arquivo txt todos os nós da skiplist
void printList(skiplist *skpl);                                            
