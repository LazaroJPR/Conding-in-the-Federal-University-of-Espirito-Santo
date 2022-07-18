/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados II
2019
*/

#include "avl.h"
#include <stdlib.h>

No *criaNo(void *ch){
    No *node = (No *)malloc(sizeof(No));
    if(node == NULL) return NULL;
    node->esq = NULL;
    node->dir = NULL;
    node->chave = ch;
    node->bal = 0;
    return node;
}

int alturaNo(No *node){
    if(node == NULL) return 0;
    int nodeEsq, nodeDir;
    nodeEsq = 1 + alturaNo(node->esq);
    nodeDir = 1 + alturaNo(node->dir);
    if(nodeEsq > nodeDir) return nodeEsq;
    else return nodeDir;
}

int atualizaBal(No *node){
    if(node == NULL) return 0;
    int alturaEsq, alturaDir;
    alturaEsq = alturaNo(node->esq);
    alturaDir = alturaNo(node->dir);
    return alturaEsq - alturaDir;
}

No *menorChave(No *node){
    if(node->esq == NULL) return node;
    else return menorChave(node->esq);
}

No *RotacaoEsq(No *node){
    No *pivo = node->dir, *aux = pivo->esq;
    pivo->esq = node;
    node->dir = aux;
    return pivo;
}

No *RotacaoDir(No *node){
    No *pivo = node->esq, *aux = pivo->dir;
    pivo->dir = node;
    node->esq = aux;
    return pivo;

}

No *insertAVL(No *node, void *ch, int (*cb) (void*, void*)){
    if(node == NULL)
        return criaNo(ch);

    int compara = cb(ch, node->chave);
    if(compara == 0) return node;

    else if(compara == 1)
        node->esq = insertAVL(node->esq, ch, cb);

    else
        node->dir = insertAVL(node->dir, ch, cb);

    node->bal = atualizaBal(node);

    if(node->bal > 1){
        int comparaEsq = cb(ch, node->esq->chave);
        if(comparaEsq == 1){
            node->bal = 0;
            node->esq->bal = 0;
            return RotacaoDir(node);
        }
        else{
            No *pivo = node->esq->dir;
            if(pivo->bal == 1) node->bal = -1;
            else node->bal = 0;
            if(pivo->bal == -1) node->esq->bal = 1;
            else node->esq->bal = 0;
            pivo->bal = 0;
            node->esq = RotacaoEsq(node->esq);
            return RotacaoDir(node);
        }
    }

    if(node->bal < -1){
        int comparaDir = cb(ch, node->dir->chave);
        if(comparaDir == 1){
            No *pivo = node->dir->esq;
            if(pivo->bal == 1) node->dir->bal = -1;
            else node->dir->bal = 0;
            if(pivo->bal == -1) node->bal = 1;
            else node->bal = 0;
            pivo->bal = 0;
            node->dir = RotacaoDir(node->dir);
            return RotacaoEsq(node);
        }
        else{
            node->bal = 0;
            node->dir->bal = 0;
            return RotacaoEsq(node);
        }
    }

    return node;
}

No *removeNo(No *node, void *ch, int (*cb) (void*, void*)){
    if(node == NULL) return NULL;
    int compara = cb(ch, node->chave);
    if(compara == 1)
        node->esq = removeNo(node->esq, ch, cb);

    else if(compara == -1)
        node->dir = removeNo(node->dir, ch, cb);

    else{
        No *aux = node;
        if(node->esq == NULL && node->dir == NULL){
            free(aux);
            return NULL;
        }

        else if(node->esq == NULL || node->dir == NULL){
            No *pivo;
            if(node->esq == NULL)
                pivo = node->dir;
            else
                pivo = node->esq;

            free(aux);
            return pivo;
        }
        else{
            aux = menorChave(node->dir);
            node->chave = aux->chave;
            node->dir = removeNo(node->dir, aux->chave, cb);
        }
    }

    if(node == NULL) return NULL;

    node->bal = atualizaBal(node);

    if(node->bal > 1){
        if(node->esq->bal >= 0){
            node->bal = 0;
            node->esq->bal = 0;
            return RotacaoDir(node);
        }
        else{
            No *pivo = node->esq->dir;
            if(pivo->bal == 1) node->bal = -1;
            else node->bal = 0;
            if(pivo->bal == -1) node->esq->bal = 1;
            else node->esq->bal = 0;
            pivo->bal = 0;
            node->esq = RotacaoEsq(node->esq);
            return RotacaoDir(node);
        }
    }

    if(node->bal < -1){
        if(node->dir->bal <= 0){
            node->bal = 0;
            node->dir->bal = 0;
            return RotacaoEsq(node);
        }
        else{
            No *pivo = node->dir->esq;
            if(pivo->bal == 1) node->dir->bal = -1;
            else node->dir->bal = 0;
            if(pivo->bal == -1) node->bal = 1;
            else node->bal = 0;
            pivo->bal = 0;
            node->dir = RotacaoDir(node->dir);
            return RotacaoEsq(node);
        }
    }

    return node;

}

No *searchAVL(No *node, void *ch, int (*cb) (void*, void*)){
    if (node == NULL)
        return NULL;
    int compara = cb(ch, node->chave);
    if (compara == 0)
        return node;
    else if (compara == -1)
        return searchAVL(node->dir, ch, cb);
    else
        return searchAVL(node->esq, ch, cb);
}

void printAVL(No *node, int nivel, void (*cb) (void*)) {
    if (node == NULL) return;
    int i;
    for(i = 0; i < nivel; i++) printf("\t");
    cb(node->chave);
    printAVL(node->esq, nivel-1, cb);
    printAVL(node->dir, nivel+1, cb);
}
