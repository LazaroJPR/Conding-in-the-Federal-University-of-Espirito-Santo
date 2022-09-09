/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"

//Funções da lista
List *createList(){
    List *ptr;
    if(ptr=(List*)malloc(sizeof(List))){
        ptr->size=0;
        ptr->first=NULL;
        return ptr;
    }
    return NULL;
}
Node *createNode()                    {
    Node *ptr;
    if(ptr=(Node*)malloc(sizeof(Node))){
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

bool isEmptyList(List *lst){
    return(!lst|| lst->size == 0);
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

void printList(List *lst){
    Node *ptr;
    if(isEmptyList(lst)) return;
    printf("\n[ ");
    ptr=lst->first;

    while(ptr != NULL){
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

Info *deleteFirstList(List *lst){
  Node *ptr;
  Info *inf;

  if (!lst) return NULL;
  ptr=lst->first;
  lst->first=ptr->next;
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

Info *deleteLastList(List *lst){
  Node *ptr,*pptr;
  Info *inf;

  if (!lst) return NULL;
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

//Funções da árvore de busca binária
BST *createBST(Info *inf){
    BST *bst;
    if(!inf) return NULL;
    if(bst=(BST*)malloc(sizeof(BST))){
        bst->inf = inf;
        bst->left = bst->right = NULL;
        return bst;
    }
    return NULL;
}

BST *leftBST(BST *bst){
    if(!bst) return NULL;
    return bst->left;
}

BST *rightBST(BST *bst){
    if(!bst) return NULL;
    return bst->right;
}

Info *rootBST(BST *bst){
    if(!bst) return NULL;
    return bst->inf;
}

int isEmptyBST(BST *bst){
    if(!bst) return 1;
    return 0;
}

BST *searchBST(BST *bst,Info *inf){
    if(!bst || !inf) return NULL;
    if(bst->inf->value == inf->value) return bst;
    else if(bst->inf->value > inf->value) return searchBST(leftBST(bst),inf);
    else return searchBST(rightBST(bst),inf);
}

void destroyBST(BST *bst){
    if(!bst) return;
    destroyBST(leftBST(bst));
    destroyBST(rightBST(bst));
    free(bst->inf);
    free(bst);
    return;
}

int heightBST(BST *bst){
    int l,r;
    if(!bst) return 0;
    l=1+heightBST(leftBST(bst));
    r=1+heightBST(rightBST(bst));
    if(r>l) return r;
    return l;
}

void auxPreOrder(BST *bst,List *lst){
    Info *tempinfo;
    tempinfo = bst->inf;
    if(!tempinfo) return;
    insertLastList(lst,tempinfo);
    auxPreOrder(leftBST(bst),lst);
    auxPreOrder(rightBST(bst),lst);
    return;
}

void auxinOrder(BST *bst,List *lst){
    Info *tempinfo;
    tempinfo = bst->inf;
    if(!tempinfo) return;
    auxPreOrder(leftBST(bst),lst);
    insertLastList(lst,tempinfo);
    auxPreOrder(rightBST(bst),lst);
    return;
}

void auxPostOrder(BST *bst,List *lst){
    Info *tempinfo;
    tempinfo = bst->inf;
    if(!tempinfo) return;
    auxPreOrder(leftBST(bst),lst);
    auxPreOrder(rightBST(bst),lst);
    insertLastList(lst,tempinfo);
    return;
}

List *preOrderTraversalBST(BST *bst){
    List *lst=createList();
    Info *tempInfo;
    if(!bst||!lst) return NULL;
    tempInfo = bst->inf;
    if(!tempInfo) return NULL;
    insertLastList(lst,tempInfo);
    auxPreOrder(leftBST(bst),lst);
    auxPreOrder(rightBST(bst),lst);
    return lst;
}

List *inOrderTraversalBST(BST *bst){
    Info *tempInfo;
    List *lst=createList();
    if(!lst||bst) return NULL;
    tempInfo = bst->inf;
    if(!tempInfo) return NULL;
    auxinOrder(leftBST(bst),lst);
    insertLastList(lst,tempInfo);
    auxinOrder(rightBST(bst),lst);
    return lst;
}

List *postOrderTraversalBST(BST *bst){
    List *lst=createList();
    Info *tempInf;
    if(!lst||bst) return NULL;
    tempInf = bst->inf;
    if(!tempInf) return NULL;
    auxPostOrder(leftBST(bst),lst);
    auxPostOrder(rightBST(bst),lst);
    insertLastList(lst,tempInf);
    return lst;
}

List *leftListBST(List *preOrder,List *left){
    List *lst = createList();
    Node *aux;

    if(!lst||!left) return NULL;
    aux = left->first;
    if(aux == NULL) return NULL;

    while (aux->info->value != preOrder->first->info->value || aux != NULL){
        insertLastList(lst,deleteFirstList(left));
        aux = aux->next;
    }

    if(aux->next == NULL) return NULL;
    insertLastList(lst,deleteFirstList(left));
    return lst;
}

List *rightListBST(List *preOrder,List *right) {
    List *lst = createList();
    Node *aux;

    if(!lst||!right) return NULL;
    deleteFirstList(right);
    aux = right->first;
    if(aux == NULL) return NULL;

    while (aux != NULL){
        insertLastList(lst,deleteFirstList(right));
        aux = aux->next;
    }
    return lst;
}

BST *insertBST(BST *bst,Info *inf){
    if(!bst) return createBST(inf);
    if(bst->inf->value > inf->value) bst->left = insertBST(leftBST(bst),inf);
    else bst->right = insertBST(rightBST(bst),inf);
    return bst;
}

BST *findLargestElementBST(BST *bst){
    if(isEmptyBST(bst)||isEmptyBST(rightBST(bst))) return bst;
    else return findLargestElementBST(rightBST(bst));
}

BST *findSmallestElementBST(BST *bst){
    if(isEmptyBST(bst)||isEmptyBST(leftBST(bst))) return bst;
    else return findSmallestElementBST(leftBST(bst));
}

BST *mostRightBST(BST *bst){
    if(!bst) return NULL;
    if(!(rightBST(bst))) return bst;
    else return mostRightBST(rightBST(bst));
}

BST *mostLeftBST(BST *bst){
    if(!bst) return NULL;
    if(!(leftBST(bst))) return bst;
    else return mostLeftBST(leftBST(bst));
}

BST *deleteBST(BST *bst,Info *inf){
    if(!bst) return NULL;
    if(bst->inf->value > inf->value) bst->left = deleteBST(leftBST(bst),inf);
    else if(bst->inf->value < inf->value) bst->right = deleteBST(rightBST(bst),inf);
    else{
        if(bst->left == NULL){
            BST *temp = rightBST(bst);
            free(bst->left);
            free(bst);
            return temp;
        }
        else if(bst->right == NULL){
            BST *temp = leftBST(bst);
            free(bst->inf);
            free(bst);
            return temp;
        }
        BST *temp = findSmallestElementBST(rightBST(bst));
        bst->inf = temp->inf;
        bst->right = deleteBST(rightBST(bst),temp->inf);
    }
    return bst;
}

void printBSTaux(BST *bst){
    if(!bst) return;
    printBSTaux(leftBST(bst));
    printf("%d ",bst->inf->value);
    printBSTaux(rightBST(bst));
    return;
}

void printBST(BST *bst){
    if(!bst) return;
    printBSTaux(leftBST(bst));
    printf("%d ",bst->inf->value);
    printBSTaux(rightBST(bst));
}

int totalExternalNodes(BST *bst){
    if(!bst) return 0;
    else if(!(bst->left) && !(bst->right)) return 1;
    else return(totalExternalNodes(bst->left)+totalExternalNodes(bst->right))
}

int totalInternalNodes(BST *bst){
    if(!bst) return 0;
    else if(!(bst->left) && !(bst->right)) return 0;
    else return(1+(totalInternalNodes(bst->left)+totalInternalNodes(bst->right)))
}

int isOrderedBST(BST *bst){
    if(!bst || !(bst->left) && !(bst->right)) return 1;
    else{
        return (isOrderedBST(bst->left) && isOrderedBST(bst->right) && (!bst->left 
        || ((findLargestElementBST(bst->left))->inf < bst->inf) && (!bst->right 
        || (findSmallestElementBST(bst->right)->inf > bst->right))))
    }

}
