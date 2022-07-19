/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

typedef struct t_celula{
    struct t_celula *direita, *abaixo;
    int linha, coluna;
    double valor;
}Celula;

typedef struct{
    int i, j;
    Celula *inicio, *fimLinha, *fimColuna;
}Matriz;

//Funcao que cria a matriz
Matriz *CriarMatriz(int i, int j);

//Funcao que cria a cabeca principal
int IniciaCabecas(Matriz *A);

//Funcao que cria as cabecas da linha
int InsereCabecaLinha(Matriz *A);

//Funcao que cria as cabecas da coluna
int InsereCabecaColuna(Matriz *A);

//Funcao que apaga a matriz
int ApagaMatriz(Matriz *A);

//Funcao que imprime a matriz
void ImprimeMatriz(Matriz *A);

//Funcao que insere um valor numa determinada posicao || i = Linha || j = Coluna
void Insere(int i, int j, double valor, Matriz *A);

//Funcao que soma a matriz
Matriz *SomaMatriz(Matriz *A, Matriz *B);

//Fucao que multiplica a matriz
Matriz *MultiplicaMatriz(Matriz *A, Matriz *B);

//Funcao que retorna o valor de um determinada posicao
double ObtemElementoPeloIndice(Matriz *A, int i, int j);

//Funcao que le um arquivo e retorna a matriz
Matriz *LeMatriz(char *nome);