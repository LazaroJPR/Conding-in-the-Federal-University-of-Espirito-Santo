/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#ifndef __STACK_H__
#define __STACK_H__

// Definição da Estrutura de Dados PILHA

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
}Stack;

// Definição das assinaturas das funções sobre o TAD PILHA

//Função que aloca memória para uma pilha
Stack *createStack();

//Função que aloca memória para um nó
Node *createNode();

//Função que aloca memória para um elemento de informação info
Info *createInfo(int i);

//Função que libera todo o espaço de memória usado por uma pilha
void freeStack(Stack *stack);

//Função que verifica se uma pilha é vazia
bool isEmptyStack(Stack * stack);

//Função que imprime o conteudo da pilha
void printStack(Stack *stack);

//Função que verifica o tamanho da pilha
int lengthStack(Stack *stack);

//FUnção que insere um elemento da pilha (na primeira posição)
bool push(Stack *stack, Info *inf);

//Função que retira um elemento da pilha (na primeira posição)
Info *pop(Stack *stack);

#endif // __STACK_H__
