/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"

//Funções AVL
AVL *createAVL(char *word){
    AVL *node;
    if(node=(AVL*)malloc(sizeof(AVl))){
        node->info=(char*)malloc(sizeof(char)*(strlen(inf)+1));
        strcpy(node->info,inf);
        node->left = NULL;
        node->right = NULL;
        node->balance = 0;
        return node;
    }
    return NULL;
}

AVL *searchAVL(AVL *avl,Node *inf){
    if(!avl || !inf) return NULL;
    if(strcmp(avl->info,inf->info) == 0)return avl;
    else if(strcmp(avl->info,inf->info) > 0) return searchAVL(avl->left,inf);
    else return searchAVL(avl->right,inf);
}

int insertAVL(AVL **avl,Node *inf){
    int growup = 0;
    return auxInsertAVL(avl,inf,&growup);
}

int auxInsertAVL(AVL** avl, Node *inf, int *growup){
    if(*avl == NULL){
        *avl = inf;
        *growup = 1;
        return 1;
    } 

    if(strcmp((*avl)->info,inf->info) == 0) return 0;

    if(strcmp((*avl)->info,inf->info) > 0){
        if (auxInsertAVL(&(*avl)->left,inf,growup)){
		    if (*growup){
				switch ((*avl)->balance){
					case 1:
						if ((*avl)->left->balance == 1)
					    	LL_RotationAVL(avl);
					 	else
							LR_RotationAVL(avl);
						*growup = 0;
						break;
					case 0:
						(*avl)->balance=1;
						*growup = 1;
						break;
					case -1:
						(*avl)->balance = 0;
						*growup= 0;
						break;
				}
			}
			return 1;
        }
        else return 0;
    }
    if(strcmp((*avl)->info,inf->info) < 0){
		if(	uxInsertAVL(&(*avl)->right,inf,growup)){
			if(*growup){
				switch ((*avl)->balance){
					case -1:
						if ((*avl)->right->balance == -1)
							RR_RotationAVL(avl);
						else
							RL_RotationAVL(avl);
						*growup = 0;
						break;
					case 1:
						(*avl)->balance = 0;
						*growup = 0;
						break;
					case 0:
						(*avl)->balance = -1;
						*growup = 1;
						break;
				}
			}
			return 1;
		}
		else return 0;
	}
    return 0;
}

void LL_RotationAVL(AVL** avl){
    AVL* b = *avl;
	AVL* a = b->left;
	b->left = a->right;
	a->right = b;
	a->balance = 0;
	b->balance = 0;
	*avl = a;
}

void RR_RotationAVL(AVL** avl){
	AVL* a = *avl;
	AVL* b = a->right;
	a->right = b->left;
	b->left = a;
	a->balance = 0;
	b->balance = 0;
	*avl = b;
}

void LR_RotationAVL(AVL** avl){
	AVL *c = *avl;
	AVL *a = c->left;
	AVL *b = a->right;

	c->left = b->right;
	a->right = b->left;
	b->left = a;
	b->right = c;
	switch(b->balance){
	  case -1:
		a->balance = 0;
		c->balance = 1;
		break;
	  case 0:
		a->balance = 0;
		c->balance = 0;
		break;
	  case +1:
		a->balance = -1;
		c->balance = 0;
		break;
	}
	b->balance = 0;
	*avl = b;
}

void RL_RotationAVL(AVL** avl){
	AVL *a = *avl;
	AVL *c = a->right;
	AVL *b = c->left;

	c->left = b->right;
	a->right = b->left;
	b->left = a;
	b->right = c;
	switch(b->balance){
		case -1:
		a->balance = 0;
		c->balance = 1;
		break;
		case 0:
		a->balance = 0;
		c->balance = 0;
		break;
		case +1:
		a->balance = -1;
		c->balance = 0;
		break;
	}
	b->balance = 0;
	*avl = b;
}

AVL *deleteAVL(AVL *avl,Node *inf){
	if(!avl) return avl;
    if(strcmp((*avl)->info,inf->info) > 0) avl->left = deleteAVL(avl->left, inf);
    else
        if(strcmp((*avl)->info,inf->info) <0) avl->right = deleteAVL(avl->right, inf);
        else{
            AVL *auxAVL = avl;
            if((avl->left) && (avl->right)){
                AVL *parent = avl->right;
                avl = parent->left;
                if(avl){
                    while(avl->left){
                        parent = avl;
                        avl = avl->left;
                    }
                    parent->left = avl->right;
                    avl->right = auxAVL->right;
                }
                else
                    avl = parent;
                    avl->left = auxAVL->left;
            }
            else
                if(avl->left) avl = avl->left;
                else avl = avl->right;
            free(auxAVL);
        }
    return avl;

}

void printAVL(AVL *avl){
    if(!avl) return;
    auxprintAVL(leftAVL(avl));
    printf("\t %s", avl->info);
    auxprintAVL(rightAVL(avl));
}

void auxprintAVL(AVL *avl){
    if(!avl) return;
    auxprintAVL(leftAVL(avl));
    printf("\t %s", avl->value);
    auxprintAVL(rightAVL(avl));
}

//Funções Hash Table

void createHT(Hash hashtable[],int sizeht){
	int i;
    for (i=0; i<sizeht; i++) hashtable[i].first = NULL;
int functionHT(char *inf,int sizeht){
	int i,sum=0;
	for(i=0;i<strlen(inf);i++)	sum+=inf[i];
	return fmod(sum,sizeht);
}

void printHT(Hash hashtable[],int sizeht){
	int i;
	for (i=0; i<sizeht; i++){
		printf("\nIndice: %d ->", i);
		getchar();
		Node *ptr = hashtable[i].first;
        printAVL(ptr);
		printf("\n\n");
		getchar();
	}
}

void insertHT(Hash hashtable[],int sizeht, char *word){
	Node *ptr = createAVL(word);
	int pos = functionHT(word,sizeht);

    if(hashtable[pos].first == NULL) hashtable[pos].first = ptr;
    else insertAVL(hashtable[pos].first,ptr);

	hashtable[pos].size++;
    return;
}

void deleteHT(Hash hashtable[], int sizeht, char *wd){
    int pos = functionHT(wd,sizeht),inf = 0,sup,meio,i,resp;
    sup = hashtable[pos].size-1;
	Node *ptr=hashtable[pos].first,*pptr=hashtable[pos].first;

	if(strcmp(hashtable[pos].first->info,wd)==0){
            hashtable[pos].first = hashtable[pos].first->next;
            free(ptr);
            printf("\nRemovido!");
            return;
        }
    else{
            while(inf<=sup){
                    meio = (inf+sup)/2;
                    if(meio == 0){
                            for(i=1;i<inf;i++) pptr = pptr->next;
                            ptr = pptr->next;
                            pptr->next = ptr->next;
                            free(ptr);
                            printf("\nRemovido!");
                            return;
                        }
                    for(i=1;i < meio;i++) pptr = pptr->next;

                    ptr = pptr->next;
                    resp = strcmp(ptr->info,wd);
                    if(resp == 0){
                            pptr->next = ptr->next;
                            free(ptr);
                            printf("\nRemovido!");
                            return;
                        }
                    if(resp > 0){
                            inf = meio+1;
                            ptr = hashtable[pos].first;
                        }
                    else{
                            sup = meio-1;
                            ptr = hashtable[pos].first;
                        }
                    meio = 0;
                }
                printf("\nNao encontrado!");
        }
}

void searchHT(Hash hashtable[], int sizeht, char *word){
    int pos = functionHT(word,sizeht);
	Node *ptr=hashtable[pos].first, *inf,*aux;

    inf = createAVL(word);
    aux = searchAVL(ptr,inf);
	
    if (!aux) printf("\t %s",aux->info);
    else printf("Palavra nao encontrada!");
}
