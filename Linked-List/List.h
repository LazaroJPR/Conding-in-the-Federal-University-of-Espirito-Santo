/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#ifndef __LIST_H__
#define __LIST_H__

// Definição da Estrutura de Dados Lista Ligada

typedef struct{
	int value;
}Info;

typedef struct tnode{
	struct tnode *next;
	Info *info;
}Node;

typedef struct{
	int size;
	Node *first;
}List;

//Função que aloca memória para uma lista
List *createList();

//Função que aloca memória para um nó
Node *createNode();

//Função que aloca memória para um elemento de informação info
Info *createInfo(int i);

//Função que libera todo o espaço de memória usado por uma lista
void freeList(List *lst);

//Função que verifica se uma lista está vazia
bool isEmptyList(List * lst);

//Função que imprime o conteúdo de uma lista
void printList(List *lst);

//Função que verifica o tamanho de uma lista
int length(List *lst);

//Função que encontra um elemento na lista
Info* find(List *lst, Info *inf);

//Função que encontra a posição de um elemento na lista
int posList(List *lst, Info *inf);

//Função que verifica se um elemento está presente na lista
int isInList(List *lst, Info *inf);

//Função que insere um elemento na primeira posição da lista
bool insertFirst(List *lst, Info *inf);

//Função que insere um elemento da última posição da lista
bool insertLast(List *lst, Info *inf);

//Função que deleta o elemento ad primeira posição da lista
Info *deleteFirst(List *lst);

//Função que deleta um elemento da lista
Info *deleteInfo(List *lst, Info *inf);

//Função que deleta o elemento de uma posição específica da lista
Info* deletePosition(List *lst, int pos);

//Função que inverte uma lista
void reverseList(List *lst);

//Função que ordena em orde crescente uma lista
void sortList(List *lst);

//Função que deleta o elemento da primeira posição da lista
Info *deleteLast(List *lst);

#endif // __LIST_H__
