#include "grafo.h"

int **alocaMatrizAdj(int r, int c, int val){
	int i,j;
	int **m = malloc(r* sizeof(int*));
	for(i = 0; i < r; i++)
    	m[i] = malloc(C* sizeof(int));
	for(i = 0; i < r; i++)
    	for(j=0; j<c; j++)
        	m[i][j] = val;
	return m;
}

Grafo *criaGrafo (int v){
	Grafo *G = malloc(sizeof(Grafo));
	G->V = v;
	G->E = 0;
	G->ajd = alocaMatrizAdj(v, v, 0);
	return G;
}

void insereAresta(Grafo *G, int v, int w){
	if(v != w && G->adj[v][w] == 0){
    	G->adj[v][w] = 1;
    	G->adj[w][v] = 1;
    	G->E++;
	}
}

void removeAresta(Grafo *G, int v, int w){
	if(v != w && G->adj[v][w] == 1){
    	G->E--;
    	G->adj[v][w] = 0;
    	G->adj[w][v] = 0;
	}
}

void imprimeGrafo(Grafo *G){
	int v, w;
	for(v = 0; v < G->V; v++){
    	printf("%2d:", v);
    	for(w = 0; w < G->V; w++)
        	if(G->adj[v][w] == 1) printf(" %2d", w);
    	printf("\n");
	}
}

void imprimeAdjacente(Grafo *G, int v){
	int i;

	for(i = 0; i < G->V; i++){
		if(G->adj[v][i] == 1){
			printf("/nVertices adjacentes: /n");
			printf(" %2d \n", i);
		}
	}
}

void verificaAdjacencia(Grafo *G, int v, int w){
	if(G->adj[v][w] == 1) printf("O vertice %2d e adjacente ao vertice %2d\n", v, w);
}

int grau(Grafo *G, int v){
	int i, grau = 0;

	for(i = 0; i < G->V; i++){
		if(G->adj[v][i] == 1) grau++;
	}
	return grau;
}

void union(int p[], int i, int j){
    p[i] = j;
}

int findSet(int p[], int i){
    while(p[i] >= 0) i = p[i];
    return i;
}

void kruskal(Grafo *G, int peso, int vertices){
    int A[vertices], i, j;

    for(i = 0; i < vertices; i++) A[i] = -1;

    for(i = 0; i < vertices; i++){
        for(j = 0; j < vertices; j++){
            if(G->adj[i][j] != 0){
                if(findSet[A, i] != findSet[A, j]){
                    union(A, i, j);
                }
            }
        }
    }
}