/* CABECALHO
   Programa: Converte expressoes infixas para posfixas e calcula o valor da avaliacao
   Arquivo: stack.h
   Autor: lazaro jose Pedrosa dos Reis 
   2019
*/

//Struct para info
typedef struct{
	float value;
}Info;

//Struct para o no
typedef struct tnode{
	struct tnode *next;
	Info *info;
}Node;

//Struct para a cabeca da pilha
typedef struct{
	int size;
	Node *first;
}Stack;

//Funcao que cria a cabeça da pilha
Stack *createStack();

//Funcao que cria o no
Node *createNode();

//Funcao que cria a info tipo char
Info *createInfo(char i);

//Funcao que cria a info tipo float
Info *createInfofloat(float i);

//Funcao que limpa a pilha
void freeStack(Stack *stack);

//Funcao que verifica se a pilha esta vazia
bool isEmptyStack(Stack * stack);

//Funcao que printa a pilha
void printStack(Stack *stack);

//Funcao que verifica o tamanho da pilha
int lengthStack(Stack *stack);

//Funccao que insere no primeiro lugar da pilha
bool push(Stack *stack, Info *inf);

//Funcao que retira o primeiro no da pilha e retorna a info desse no
Info *pop(Stack *stack);

//Funcao que verifica se o caractere e um operador
int isoperator(char symbol);

//Funcao que retorna a prioridade do operador
int precedence(char symbol);

//Funcao que converte a expressao infixa para posfixa
void InfixToPostfix(Stack *stk, char source[], char target[]);

//Funcao que calcula o valor da avaliacao de uma expressao posfixa
float evaluatePostfixExp(Stack *stc,char exp[]);
