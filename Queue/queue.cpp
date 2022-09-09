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
#include "queue.h"

Queue *createQueue(){
    Queue *ptr;
    if(ptr=(Queue *)malloc(sizeof(Queue))){
        ptr->size=0;
        ptr->first=ptr->last=NULL;
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

void freeQueue(Queue *queue){
    Node *ptr;
    if (!queue) return;
    while(queue->first){
        ptr=queue->first->next;
        free(queue->first->info);
        free(queue->first);
        queue->first=ptr;
    }
    free(queue);
}

bool isEmptyQueue(Queue * queue){
    return (!queue || queue->size==0);
}

void printQueue(Queue *queue){
    Node *ptr;

    if(isEmptyQueue(queue)) return;
    printf("\n[ ");
    ptr=queue->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL){
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

int lengthQueue(Queue *queue){
	if (!queue) return -1;
	return queue->size;
}

bool insertQueue(Queue *queue, Info *inf){
    Node *ptr;
    if(!queue || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=NULL;

    if(lengthQueue(queue)==0) queue->first=ptr;
    else queue->last->next=ptr;
	queue->last=ptr;
	queue->size++;
    return true;
}

Info *removeQueue(Queue *queue) {
  Node *ptr;
  Info *inf;
  if (isEmptyQueue(queue)) return NULL;
  ptr=queue->first;
  queue->first=ptr->next;
  inf=ptr->info;
  free(ptr);
  queue->size--;
  return inf;
}


