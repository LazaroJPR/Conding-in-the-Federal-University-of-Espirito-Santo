/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *createStack(){
    Stack *ptr;
    if(ptr=(Stack *)malloc(sizeof(Stack))){
        ptr->size=0;
        ptr->first=NULL;
        return ptr;
    }
    return NULL;
}

Node *createNode(){
    Node *ptr;
    if(ptr=(Node *)malloc(sizeof(Node))){
        ptr->info=NULL;
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}

Info *createInfo(int i){
    Info *ptr;
    if(ptr=(Info *)malloc(sizeof(Info))){
        ptr->value=i;
        return ptr;
    }
    return NULL;
}

void freeStack(Stack *stack){
    Node *ptr;
    if (!stack) return;
    while(stack->first){
        ptr=stack->first->next;
        free(stack->first->info);
        free(stack->first);
        stack->first=ptr;
    }
    free(stack);
}

bool isEmptyStack(Stack * stack){
    return (!stack || stack->size==0);
}

void printStack(Stack *stack){
    Node *ptr;

    if(isEmptyStack(stack)) return;
    printf("\n TOP[ ");
    ptr=stack->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL){
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]BOTTOM");
}

int lengthStack(Stack *stack){
	if (!stack) return -1;
	return stack->size;
}

bool push(Stack *stack, Info *inf){
	Node *ptr;
    if(!stack || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=stack->first;
    stack->first=ptr;
    stack->size++;
    return true;
}

Info *pop(Stack *stack){
	Node *ptr;
  	Info *inf;
	if (isEmptyStack(stack)) return NULL;
	ptr=stack->first;
	stack->first=ptr->next;
  	inf=ptr->info;
  	free(ptr);
  	stack->size--;
  	return inf;
}

