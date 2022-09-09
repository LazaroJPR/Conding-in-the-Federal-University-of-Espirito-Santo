#ifndef GRAFO
#define GRAFO

//Estrutura base do grafo representado por uma matriz de adjacencias
typedef struct grafo{
	int V;
	int E;
	int **adj;
}Grafo;

//Funcao que aloca dinamicamente uma matriz de adjacencias
int **alocaMatrizAdj(int r, int c, int val);

//Funcao que cria o grafo
Grafo *criaGrafo (int V);

//Funcao que realiza a insercao de uma aresta no grafo
void insereAresta(Grafo *G, int v, int w);

//Funcao que realiza a remocao de uma aresta no grafo
void removeAresta(Grafo *G, int v, int w);

//Funcao que realiza a impressao do grafo
void imprimeGrafo(Grafo *G);

//Funcao que imprime todos os vertices adjacentes
void imprimeAdjacente(Grafo *G, int v);

//Funcao que verifica se dois vertices sao adjacentes
void verificaAdjacencia(Grafo *G, int v, int w);

//Funcao que calcula o grau de um vertice
int grau(Grafo *G, int v);

//Funcao que realiza uma uniao de vetores
void union(int p[], int i, int j);

//Funcao que realiza a busca do pai em um vetor
int findSet(int p[], int i);

//Funcao que realiza o algoritmo de kruskal
void kruskal(Grafo *G, int peso, int vertices);

#endif //GRAFO