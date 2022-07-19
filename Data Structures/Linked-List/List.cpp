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
#include "List.h"

List *createList(){
    List *ptr;
    if(ptr=(List *)malloc(sizeof(List))){
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

void freeList(List *lst){
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

bool isEmptyList(List * lst){
    return (!lst || lst->size==0);
}

void printList(List *lst) {
    Node *ptr;

    if(isEmptyList(lst)) return;
    printf("\n[ ");
    ptr=lst->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL){
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

int lengthList(List *lst){
	if (!lst) return -1;
	return lst->size;
}

Info* findList(List *lst, Info *inf) {
	Node *ptr;
	if(isEmptyList(lst)) return NULL;
	ptr=lst->first;

   while(ptr->info->value!=inf->value) {
      if(ptr->next == NULL) return NULL;
      else ptr=ptr->next;
   }
   return ptr->info;
}

int posList(List *lst, Info *inf){
	int pos;
	Node *ptr;
	if (isEmptyList(lst)) return 0;
	pos=1;
	ptr=lst->first;

	while(ptr!=NULL){
		if(ptr->info->value==inf->value)return pos;
		pos++;
		ptr=ptr->next;
	}
	return 0;
}

int isInList(List *lst, Info *inf){
	return posList(lst,inf);
}

bool insertFirstList(List *lst, Info *inf){
    Node *ptr;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=lst->first;
    lst->first=ptr;
    lst->size++;
    return true;
}

bool insertLastList(List *lst, Info *inf){
    Node *ptr, *aux;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    
    if(lst->first==NULL){
    	lst->first=ptr;
    }
    else{
		aux=lst->first;
		while(aux->next!=NULL) aux=aux->next;
		aux->next=ptr;
	}
	lst->size++;
    return true;
}

Info *deleteFirstList(List *lst) {
  Node *ptr;
  Info *inf;
  if (isEmptyList(lst)) return NULL;
  ptr=lst->first;
  lst->first=ptr->next;
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

Info* deleteInfoList(List *lst, Info *inf) {
	Node *ptr, *pptr;
	Info *auxInf;

	if (isEmptyList(lst)) return NULL;

	ptr=lst->first;
   while(ptr->info->value != auxInf->value) {
      if(ptr->next == NULL) return NULL;
      else {
         pptr = ptr;
         ptr = ptr->next;
      }
   }


   if(ptr == lst->first) lst->first = ptr->next;
   else pptr->next = ptr->next;

	auxInf=ptr->info;
	free(ptr);
	lst->size--;
   return auxInf;
}

Info* deletePositionList(List *lst, int pos){
	Node *pptr,*ptr;
	Info *inf;
	int cont=1;

	if (isEmptyList(lst) || pos>lst->size || pos<=0){
		printf("\nImpossivel retirar elemento!\n");
		return NULL;
	}
	if(pos==1){
		ptr=lst->first;
		lst->first=ptr->next;
	} 
	else{
		pptr=lst->first;
		for(cont=1;cont<pos-1;cont++,pptr=pptr->next);	
		ptr=pptr->next;
		pptr->next=ptr->next;
	}
	inf=ptr->info;
	free(ptr);
	lst->size--;
	return inf;
}

void reverseList(List *lst) {
   Node *prev= NULL;
   Node *current = lst->first;
   Node *next;

   if (isEmptyList(lst)) return;

   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }

   lst->first=prev;
}

void sortList(List *lst) {
   int i, j, k;
   Info *tempInfo;
   Node *current;
   Node *next;

	k = lst->size ;
	if (isEmptyList(lst)) return;

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

Info *deleteLastList(List *lst) {
  Node *ptr,*pptr;
  Info *inf;
  if (isEmptyList(lst)) return NULL;
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

