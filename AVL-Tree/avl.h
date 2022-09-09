/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados II
2020
*/

#ifndef AVL_H_
#define AVL_H_

/*Estrutura de um nó de uma árvore AVL, contendo uma chave genérica,
o fator de balanceamento e ponteiros pra um nó a esquerda e a direita*/
typedef struct tno{
   void *chave;
   int bal;
   struct tno *esq, *dir;
}No;

/*Realizaçãoo da alocação dinómica de um nó da árvore com as inicializações
de cada elemento da estrutura, sendo necessário o parâmetro da chave genérica desejada*/
No *criaNo(void *ch);

/*Função auxiliar para o cálculo da altura de uma árvore ou subárvore auxiliar
por recursividade, buscando o maior caminho do nó indicado como parâmetro até a folha mais distante*/
int alturaNo(No *node);

/*Pode-se atualizar o fator de balanceamento após uma inserção ou remoção de um nó pelo cálculo
da diferença da altura da subárvore esquerda pela altura da subárvore direita*/
int atualizaBal(No *node);

/*Função auxiliar que busca e retorna a menor chave de uma árvore indicada pelo parâmetro, ou seja,
busca a folha mais a esquerda da árvore desejada*/
No *menorChave(No *node);

/*Rotação simples a esquerda de um nó da árvore passado como parâmetro, sem realizar as trocas de
de cada fator de balanceamento, sendo isso feito na propria função da inserção ou remoção*/
No *RotacaoEsq(No *node);

/*Rotação simples a direita de um nó da árvore passado como parâmetro, sem realizar as trocas de
de cada fator de balanceamento, sendo isso feito na propria função da inserção ou remoção*/
No *RotacaoDir(No *node);

/*Tendo como parâmetros, a árvore na qual será inserida, a chave genérica a ser inserida e a função callback
que será passada no arquivo do cliente para realizar as comparações entre as chaves da árvore, a função abaixo
realiza a inserção numa árvore, respeitando as características da AVL, ou seja, cuidando dos casos de desebalanceamento*/
No *insertAVL(No *node, void *ch, int (*cb) (void*, void*));

/*De forma análoga, ao passar a árvore na qual deseja-se inserir, a chave genérica desejada e a função callback
que será informada pelo cliente na qual realizará as comparações entre as chaves de cada nó da árvore, a função abaixo
realiza a remoção de uma chave, se existir, numa árvore, respeitando as característcas da AVL, ou seja, cuidando
dos casos de desebalanceamento*/
No *removeNo(No *node, void *ch, int (*cb) (void*, void*));

/*A busca por um nó em uma árvore na qual a chave desejada é passada como parâmetro, assim como a função callback que será
informada pelo cliente, tendo o objetivo de realizar as comparações entre as chaves de cada nó, retornando o nó correspondente*/
No *searchAVL(No *node, void *ch, int (*cb) (void*, void*));

/*Impressão de uma árvore AVL com visualização de uma árvore binária, sendo a função de impressão de cada chave informada
pelo cliente, tendo um callback como parâmetro da função*/
void printAVL(No *node, int nivel, void (*cb) (void*));

#endif // AVL_H_
