#ifndef GRAFO
#define GRAFO

//Estrutura de um vertice
typedef struct vertice{
    int no;
	struct vertice *prox;
}Vertice;

//Estrutura de um grafo representado por uma lista de adjacencias
typedef struct grafo{
    int V;
    int E;
    Vertice *adj;
}Grafo;

//Funcao que cria o grafo
Grafo *criaGrafo (int v);

//Funcao que cria um vertice
Vertice *novoVertice(int x);

//Funcao que realiza a insercao de uma aresta no grafo
void insereAresta(Grafo *G, int v, int w);

//Funcao que realiza a remocao de uma aresta no grafo
void removeAresta(Grafo *G, int v, int w);

//Funcao que realiza a impressao do grafo
void imprimeGrafo(Grafo *G);

//Funcao que realiza o percurso em largura de um grafo representado por uma lista de adjacenais
//Retornara uma arvore de largura
void percursoEmLargura(Grafo *G);

//Funcao que verifica se um grafo e bipartido
bool bipartido(Grafo *G);

#endif //GRAFO