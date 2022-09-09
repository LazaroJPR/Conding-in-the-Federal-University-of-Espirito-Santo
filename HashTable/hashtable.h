/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados I
2019
*/

typedef struct Node AVL;

typedef struct tnode{
	char *info;
   int balance;
	struct tnode *next,*right;
}Node;

typedef struct{
   Node *first;
}Hash;

//Funçõess AVL

/*Realizaçãoo da alocação dinómica de um nó da árvore com as inicializações
de cada elemento da estrutura, sendo necessário o parâmetro da chave genérica desejada*/
AVL *createAVL(void);

/*A busca por um nó em uma árvore na qual a chave desejada é passada como parâmetro, assim como a função callback que será
informada pelo cliente, tendo o objetivo de realizar as comparações entre as chaves de cada nó, retornando o nó correspondente*/
AVL *searchAVL(AVL *avl,Info *inf);

/*Tendo como parâmetros, a árvore na qual será inserida, a chave genérica a ser inserida e a função callback
que será passada no arquivo do cliente para realizar as comparações entre as chaves da árvore, a função abaixo
realiza a inserção numa árvore, respeitando as características da AVL, ou seja, cuidando dos casos de desebalanceamento*/
int insertAVL(AVL **avl,Info *inf);

//Função que auxilia na inserção de uma chave
int auxInsertAVL(AVL** avl, Info *inf, int *growup);

/*De forma análoga, ao passar a árvore na qual deseja-se inserir, a chave genérica desejada e a função callback
que será informada pelo cliente na qual realizará as comparações entre as chaves de cada nó da árvore, a função abaixo
realiza a remoção de uma chave, se existir, numa árvore, respeitando as característcas da AVL, ou seja, cuidando
dos casos de desebalanceamento*/
AVL *deleteAVL(AVL *avl,Info *inf);

//Funções que realizam as devidas rotações na árvore
void LL_RotationAVL(AVL** avl);
void RR_RotationAVL(AVL** avl);
void LR_RotationAVL(AVL** avl);
void RL_RotationAVL(AVL** avl);

/*Impressão de uma árvore AVL com visualização de uma árvore binária, sendo a função de impressão de cada chave informada
pelo cliente, tendo um callback como parâmetro da função*/
void printAVL(AVL *avl);

//Função que auxilia na impreção da árvore
void auxprintAVL(AVL *avl);

//Funções Hash Table

//Função que cria uma hashtable
void createHT(Hash hashtable[],int sizeht);

//Função que calcula o valor hash de uma chave
int functionHT(char *inf,int sizeht);   

//Função que printa a hashtable
void printHT(Hash hashtable[],int sizeht);      

//Função que insere uma chave na hashtable
void insertHT(Hash hashtable[],int sizeht, char *name);  

//Função que deleta uma chave da hashtable
void deleteHT(Hash hashtable[], int sizeht, char *wd);  

//Função que busca uma chave na hashtable
void searchHT(Hash hashtable[], int sizeht, char *word);
