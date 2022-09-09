/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__

// Definição da Estrutura de Dados FILA

typedef struct{
	int value;
}Info;

typedef struct tnode{
	struct tnode *next;
	Info *info;
}Node;

typedef struct{
	int size;
	Node *first,*last;
}Queue;

//Função que aloca memória para uma filha
Queue *createQueue();

//Função que aloca memória para um nó
Node *createNode();

//Função que aloca memória para um elemento de informação info
Info *createInfo(int i);

//Função que libera todo o espaço de memória usado por uma fila
void freeQueue(Queue *queue);

//FUnção que verifica se uma fila está vazia
bool isEmptyQueue(Queue * queue);

//Função que imprime o conteúdo da fila
void printQueue(Queue *queue);

//Função que verifica o tamanho da fila
int lengthQueue(Queue *queue);

//Função que insere um elemento da fila
bool insertQueue(Queue *queue, Info *inf);

//Função que retira um elemento da fila (da primeira posição)
Info *removeQueue(Queue *queue);

#endif // __QUEUE_H__
