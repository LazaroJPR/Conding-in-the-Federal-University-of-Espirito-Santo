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
#include "DList.h"

DList *createDList(){
    DList *ptr;
    if(ptr=(DList *)malloc(sizeof(DList))){
        ptr->size=0;
        ptr->first=NULL;
        return ptr;
    }
    return NULL;
}

Node *createNode(){
    Node *ptr;
    if(ptr=(Node *)malloc(sizeof(Node))){
        ptr->next=ptr->prev=NULL;
        ptr->info=NULL;
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

void freeDList(DList *lst){
    Node *ptr;
    if (!lst) return;
    while(lst->first){
        ptr=lst->first->next;
        free(lst->first->info);
        free(lst->first);
        lst->first=ptr;
    }
    free(lst);
}

bool isEmptyDList(DList * lst){
    return (!lst || lst->size==0);
}

void printDList(DList *lst) {
    Node *ptr;

    if(isEmptyDList(lst)) return;
    printf("\n[ ");
    ptr=lst->first;

    //inicia do primeiro elemento da Lista Dupla
    while(ptr != NULL){
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

int lengthDList(DList *lst){
	if (!lst) return -1;
	return lst->size;
}

Info* findDList(DList *lst, Info *inf) {
	Node *ptr;

    if(isEmptyDList(lst)) return NULL;
	ptr=lst->first;

    while(ptr->info->value!=inf->value) {
      if(ptr->next == NULL) return NULL;
      else ptr=ptr->next;
   }
   return ptr->info;
}

int posDList(DList *lst, Info *inf){
	int pos;
	Node *ptr;
	if (isEmptyDList(lst)) return 0;
	pos=1;
	ptr=lst->first;
	while(ptr!=NULL){
		if(ptr->info->value==inf->value)return pos;
		pos++;
		ptr=ptr->next;
	}
	return 0;
}

int isInDList(DList *lst, Info *inf){
	return posDList(lst,inf);
}

bool insertFirstDList(DList *lst, Info *inf){
    Node *ptr;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=lst->first;
    ptr->prev=NULL;
    if(!isEmptyDList(lst)) lst->first->prev=ptr;
    lst->first=ptr;
    lst->size++;
    return true;
}

bool insertLastDList(DList *lst, Info *inf){
    Node *ptr, *aux;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;

    if(lst->first==NULL) lst->first=ptr;
    else{
		aux=lst->first;
		while(aux->next!=NULL) aux=aux->next;
		aux->next=ptr;
		ptr->prev=aux;
	}
	lst->size++;
    return true;
}

bool insertPositionDList(DList *lst, Info *inf,int pos){
    Node *ptr, *aux;
    int i;
    if(!lst || !(aux=createNode())) return false;
    aux->info=inf;
    
    if(lst->first==NULL) lst->first=aux;
    else{
		ptr=lst->first;
		for(i=1; i<pos && ptr->next!=NULL; i++, ptr=ptr->next);
		if(i<pos){
			ptr->next=aux;
			aux->prev=ptr;
		}
		else{
			if(ptr->prev!=NULL){
				ptr->prev->next=aux;
				aux->prev=ptr->prev;
			}
			else lst->first=aux;
			aux->next=ptr;
			ptr->prev=aux;
		}
	}
	lst->size++;
    return true;
}

Info *deleteFirstDList(DList *lst) {
  Node *ptr;
  Info *inf;
  if (isEmptyDList(lst)) return NULL;
  ptr=lst->first;
  lst->first=ptr->next;
  if(lst->first!=NULL) lst->first->prev=NULL;
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

Info *deleteLastDList(DList *lst) {
  Node *ptr,*pptr;
  Info *inf;
  if (isEmptyDList(lst)) return NULL;
  ptr=lst->first;

  if(lst->size==1)lst->first=ptr->next;
  else{
  	pptr=ptr;
  	ptr=ptr->next;
  	while(ptr->next!=NULL){
  		pptr=ptr;
  		ptr=ptr->next;
	}
	pptr->next=ptr->next;
  }
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

Info* deletePositionDList(DList *lst, int pos){
	Node *ptr;
	Info *inf;
	int i;

	if (isEmptyDList(lst) || pos>lst->size || pos<=0){
		printf("\nImpossivel retirar elemento!\n");
		return NULL;
	}
	ptr=lst->first;
	for(i=1; i<pos;i++, ptr=ptr->next);
	if(ptr->prev!=NULL) ptr->prev->next=ptr->next;
	else lst->first=ptr->next;
	if(ptr->next!=NULL) ptr->next->prev=ptr->prev;
	inf=ptr->info;
	free(ptr);
	lst->size--;
	return inf;
}

Info* deleteInfoDList(DList *lst, Info *inf) {
	Node *ptr, *pptr;
	Info *auxInf;
	if (isEmptyDList(lst)) return NULL;

	ptr=lst->first;	
	while(ptr!=NULL && ptr->info->value != auxInf->value) ptr = ptr->next;

	if(ptr==NULL) return NULL;
	if(ptr->prev!=NULL) ptr->prev->next=ptr->next;
	else lst->first=ptr->next;
	if(ptr->next!=NULL)ptr->next->prev=ptr->prev;
	auxInf=ptr->info;
	free(ptr);
	lst->size--;
	return auxInf;
}

void reverseDList(DList *lst) {
   Node *prev=NULL, *current, *next;
   
   if (isEmptyDList(lst)|| lst->size==1) return;
   current=lst->first;
   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      current->prev=next;
      prev = current;
      current = next;
    }
	lst->first=prev;
}

void sortDList(DList *lst) {
   int i, j, k;
   Info *tempInfo;
   Node *current;
   Node *next;

	k = lst->size;
	if (isEmptyDList(lst)) return;

	for ( i = 0 ; i < (lst->size-1); i++, k-- ){
      current = lst->first;
      next=lst->first->next;
      for ( j = 1 ; j < k ; j++ ){
         if ( current->info->value> next->info->value ) {
            tempInfo = current->info;
            current->info = next->info;
            next->info = tempInfo;
         }
         current = current->next;
         next = next->next;
      }
   }
}


