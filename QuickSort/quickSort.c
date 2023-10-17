#include <stdio.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(int vetor[], int p, int r) {
  int pivot = vetor[r];
  int i = (p - 1);

  for (int j = p; j < r; j++) {
    if (vetor[j] <= pivot) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }

  troca(&vetor[i + 1], &vetor[r]);

  return (i + 1);
}

void quickSort(int vetor[], int p, int r) {
  if (p < r) {
    int pi = particao(vetor, p, r);
    quickSort(vetor, p, pi - 1);
    quickSort(vetor, pi + 1, r);
  }
}

void imprimeVetor(int vetor[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int vetor[] = {8, 7, 2, 1, 0, 9, 6};
  int n = sizeof(vetor) / sizeof(vetor[0]);
  
  printf("Vetor desordenado\n");
  imprimeVetor(vetor, n);
  quickSort(vetor, 0, n - 1);
  
  printf("Vetor ordenado: \n");
  imprimeVetor(vetor, n);
}