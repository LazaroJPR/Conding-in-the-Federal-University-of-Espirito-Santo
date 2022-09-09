#include <stdlib.h>
#include <stdio.h>

#define SIZE 40

typedef struct fila{
  int items[40];
  int inicio;
  int fim;
}fila;

fila* criarFila();
void enfileirar(fila* q, int);
int desenfileirar(fila* q);
int filaVazia(fila* q);

fila* criarFila(){
  fila* q = malloc(sizeof(fila));
  q->inicio = -1;
  q->fim = -1;
  return q;
}

int filaVazia(fila* q){
  if(q->fim == -1) return 1;
  else return 0;
}

void enfileirar(fila* q, int value){
  if (q->fim == SIZE - 1) return;
  else{
    if (q->inicio == -1) q->inicio = 0;
    q->fim++;
    q->items[q->fim] = value;
  }
}

int desenfileirar(fila* q){
  int item;
  if (filaVazia(q)) item = -1;
  else{
    item = q->items[q->inicio];
    q->inicio++;
    if(q->inicio > q->fim)q->inicio = q->fim = -1;
  }
  return item;
}
