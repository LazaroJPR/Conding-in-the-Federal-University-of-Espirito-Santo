#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.c"

Grafo *criaGrafo (int v){
	Grafo *G = (Grafo*)malloc(sizeof(Grafo));
	G->V = v;
	G->E = 0;
	G->adj = (Vertice*)calloc(v, sizeof(Vertice));
	return G;
}

Vertice *novoVertice(int x){
    Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
    if(!novo) printf("ERRO\n"); exit(1);
    novo->no = x;
    novo->prox = NULL;
    return novo;
}

void insereAresta(Grafo *G, int v, int w){
    if(v != w){
        Vertice *p = G->adj[v].prox;
        while(p != NULL){
            if(p->no == w) break;
            p = p->prox;
        }
        if(p == NULL){
            Vertice *novo = novoVertice(w);
            novo->prox = G->adj[v].prox;
            G->adj[v].prox = novo;
            G->E++;
        }

        p = G->adj[w].prox;
        while(p != NULL){
            if(p->no == v) break;
            p = p->prox;
        }
        if(p == NULL){
            Vertice *novo = novoVertice(v);
            novo->prox = G->adj[w].prox;
            G->adj[w].prox = novo;
            G->E++;
        }
    }
}

void removeAresta(Grafo *G, int v, int w){
    if(G->adj[v].prox != NULL){
        Vertice *aux = G->adj[v].prox;
        Vertice *preaux = &(G->adj[v]);

        while(aux != NULL){
            if(aux->no == w) break;
            preaux = aux;
            aux = aux->prox;
        }
        if(aux != NULL){
            G->E--;
            preaux->prox = aux->prox;
            free(aux);
        }
    }
    if(G->adj[w].prox != NULL){
        Vertice *aux = G->adj[v].prox;
        Vertice *preaux = &(G->adj[v]);

        while(aux != NULL){
            if(aux->no == w) break;
            preaux = aux;
            aux = aux->prox;
        }
        if(aux != NULL){
            G->E--;
            preaux->prox = aux->prox;
            free(aux);
        }
    }
}

void imprimeGrafo(Grafo *G){
    int v;
    Vertice *w;
    for(v = 0; v < G->V; v++){
        printf("%2d:", v);
        w = G->adj[v].prox;

        while(w != NULL){
            printf(" %2d", w->no);
            w = w->prox;
        }
        printf("\n");
    }
}

void percursoEmLargura(Grafo *G){
    fila *filaV;
    Vertice *r, *w;
    int alc[G->V];
    int i, v, ac;

    for(i = 0; i < G->V; i++) alc[i] = 0;

    r = &G->adj[0];
    filaV = criarFila();
    enfileirar(filaV, 0);
    alc[0] = ac = 1;

    while(filaVazia(filaV) == 0){
        v = desenfileirar(filaV);

        if(G->adj[v].prox != NULL){
            w = G->adj[v].prox;
            while(w->prox != NULL){
                if(alc[w->no] == 0){
                    enfileirar(filaV, w->no);
                    alc[w->no] = ac = ac++;
                    //Adicionar conjunto de aresta v,w
                }
                if(alc[v] < alc[w->no]){
                    //Aresta V W foi explorada
                }
                w = w->prox;
            }
            //Vertice V foi explorado
            v = desenfileirar(filaV);
        }
        else printf("\n Grafo possui somente um vertice!");
    }
}

bool bipartido(Grafo *G){
    fila *filaV;
    Vertice *r, *w;
    int alc[G->V], niv[G->V];
    int i, v, ac;

    for(i = 0; i < G->V; i++) alc[i] = 0;

    r = &G->adj[0];
    filaV = criarFila();
    enfileirar(filaV, 0);
    alc[0] = ac = 1;
    niv[0] = 1;

    while(filaVazia(filaV) == 0){
        v = desenfileirar(filaV);

        if(G->adj[v].prox != NULL){
            w = G->adj[v].prox;
            while(w->prox != NULL){
                if(alc[w->no] == 0){
                    enfileirar(filaV, w->no);
                    alc[w->no] = ac = ac++;
                    niv[w->no] = niv[v] + 1;
                }
                if(alc[v] < alc[w->no]){
                    if(niv[v] == niv[w->no]) return false;
                    //Aresta V W foi explorada
                }
                w = w->prox;
            }
            //Vertice V foi explorado
            v = desenfileirar(filaV);
        }
        else printf("\n Grafo possui somente um vertice!");
    }
    return true;
}
