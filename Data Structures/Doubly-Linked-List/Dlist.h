/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#ifndef __DLIST_H__
#define __DLIST_H__

// Definição da Estrutura de Dados Lista Duplamente Ligada

typedef struct{
	int value;
}Info;

typedef struct tnode{
	struct tnode *next, *prev;
	Info *info;
}Node;

typedef struct{
	int size;
	Node *first;
}DList;

//Função que aloca memória para uma lista
DList *createDList();

//Função que aloca memória para um nó
Node *createNode();

//Função que aloca memória para um elemento de informação info
Info *createInfo(int i);

//Função que libera todo o espaço de memória usado por uma lista
void freeDList(DList *lst);

//Função que verifica se uma lista é vazia
bool isEmptyDList(DList * lst);

//FUnção que imprime o conteudo da lista
void printDList(DList *lst);

//Função que verifica o tamanho da lista
int lengthDList(DList *lst);

//Função que encontra um elemento na lista
Info* findDList(DList *lst, Info *inf);

//FUnção que encontra a posição de um elemento na lista
int posDList(DList *lst, Info *inf);

//Função que verifica se um elemento está presente na lista
int isInDList(DList *lst, Info *inf);

//Função que insere um elemento na primeira posição da lista
bool insertFirstDList(DList *lst, Info *inf);

//Função que insere um elemento da última posição da lista
bool insertLastDList(DList *lst, Info *inf);

//Função que insere um elemento de informação em uma posição da lista
bool insertPositionDList(DList *lst, Info *inf,int pos);

//Função que deleta o elemento da primeira posição da lista
Info *deleteFirstDList(DList *lst);

//Função que deleta o elemento da última posição da lista
Info *deleteLastDList(DList *lst);

//Função que deleta o elemento de uma posição específica da lista
Info* deletePositionDList(DList *lst, int pos);

//Função que deleta o elemento da lista
Info* deleteInfoDList(DList *lst, Info *inf);

//Função que inverte a lista
void reverseDList(DList *lst);

//Função que ordena em ordem crescente uma lista
void sortDList(DList *lst);

#endif // __LIST_H__
