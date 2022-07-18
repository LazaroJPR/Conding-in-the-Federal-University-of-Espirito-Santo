/*
Autor: Lázaro José Pedrosa dos Reis
Universidade Federal do Espírito Santo
Estrutura de Dados II
2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.c"

/*Estrutura que será guardada pelos nós da árvore AVL já criada em "avl.c", sendo
a matricula a chave de relevância que será levada em conta para comparações em cada função,
sendo as outras informações, o nome do aluno e sua nota, importantes apenas para o armazenamento*/
typedef struct{
    int matricula;
    float nota;
    char nome[70];
}Aluno;

/*Alocação dinâmica da estrutura acima com inicializa��es para cada chave da estrutura,
retornando o objeto Aluno como resultado*/
Aluno *criaAluno(int mat, float nota, char *nome){
    Aluno *estud = (Aluno *)malloc(sizeof(Aluno));
    if(estud == NULL) return NULL;
    estud->matricula = mat;
    estud->nota = nota;
    strcpy(estud->nome, nome);
    return estud;
}

/*função que será substituída pelo callback, responsável pelas comparações entre as chaves
da árvore e da chave indicada como parâmetro na inserção na árvore de dados, retornando 0
se forem iguais, 1 se a chave da árvore for menor e -1 se a chave da árvore for maior */
int comparaAluno(void *chave, void *arv){
    Aluno *auxChave = (Aluno *)chave;
    Aluno *auxArv = (Aluno *)arv;
    if(auxArv->matricula == auxChave->matricula) return 0;
    else if(auxArv->matricula > auxChave->matricula) return 1;
    else return -1;
}

/*função análoga à acima, tendo praticamente o mesmo intuito de ser substituído pelo callback,
tendo também o objetivo de comparar elementos, porem essa função será utilizada para remover um
elemento ou buscá-lo, pois o usuário só irá informar um elemento para tais utilidades que nesse caso
é considerado a matrícula como chave essencial */
int comparaIntAluno(void *chave, void *arv){
    int *auxChave = (int *)chave;
    Aluno *auxArv = (Aluno *)arv;
    if(auxArv->matricula == (*auxChave)) return 0;
    else if(auxArv->matricula > (*auxChave)) return 1;
    else return -1;
}

/*função de impressão da chave relevante da estrutura Aluno que será substituída pelo callback
da função impressao indicada pelo arquivo "avl.c" */
void impressaoArvore(void *chave){
    Aluno *auxChave = (Aluno *)chave;
    printf("%d\n", auxChave->matricula);
}

/*Impressão correspondente aos dados de um aluno passado inserido na árvore AVL que foi
passado como parametro */
void impressaoAluno(Aluno *estud){
    printf("Nome do aluno: %s \nMatricula: %d \nNota Final: %.2f\n",
           estud->nome, estud->matricula, estud->nota);
}

void menu(){
    printf("---------------------------------------\n");
    printf("1 - Insercao de um aluno\n");
    printf("2 - Remocao de um aluno\n");
    printf("3 - Busca de um aluno\n");
    printf("4 - Impressao das chaves\n");
    printf("5 - Sair\n");
    printf("---------------------------------------\n");
    printf("Insira a opcao correspondente ao que deseja realizar: ");
}

/*função principal que utiliza a função void menu para decidir qual função usar de acordo com a opção escolhida*/
int main(){
    int loop = 0;
    No *root = NULL;
    while(loop != 5){
        menu();
        scanf("%d",&loop);
        printf("\n");
        if(loop == 1){  /*Caso a opção seja a de número 1, a função irá chamar a insertAVL para adicionar uma nova chave */
            int mat;
            float nota;
            char nome[70];
            printf("Sobre o aluno que deseja inserir:\nNome:");
            fgets(nome,70,stdin);
            scanf("%[^\n]s", nome);
            printf("Matricula: ");
            scanf("%d", &mat);
            printf("Nota final: ");
            scanf("%f", &nota);
            printf("\n");
            Aluno *aux = criaAluno(mat, nota, nome);
            if(aux == NULL) printf("Memoria Indisponivel\n\n");
            else root = insertAVL(root, aux, comparaAluno);
            printAVL(root, 2, impressaoArvore);
        }
        else if(loop == 2){ /*Caso a opção seja a de número 2, a função irá chamar a removeNO para deletar o nó desejado e após isso, imprimir a árvore  */
            int mat;
            if(root == NULL)
                printf("Arvore vazia. Insira uma chave inicialmente\n\n");
            else{
                printf("Qual a matricula que deseja remover do banco de dados? ");
                scanf("%d", &mat);
                root = removeNo(root, &mat, comparaIntAluno);
                printf("\n");
                printAVL(root, 2, impressaoArvore);
            }
        }
        else if(loop == 3){ /*Caso a opção seja a de número 3, a função irá chamar a searchAVL para procurar o nó desejado e após isso, imprimir a chave encontrada  */
                int mat;
                printf("Insira a matricula do aluno no qual deseja verificar: ");
                scanf("%d", &mat);
                No *aux = searchAVL(root, &mat, comparaIntAluno);
                printf("\n");
                if(aux == NULL) printf("Tal matricula nao se encontra no sistema. Tente Novamente\n\n");
                else impressaoAluno(aux->chave);
        }
        else if(loop == 4){ /*Caso a opção seja a de número 4, a função irá chamar a printtAVL para imprimir a árvore  */
            printf("\nImpressao da arvore onde o campo a ser impresso e a chave de busca: \n\n");
            printAVL(root, 2, impressaoArvore);
        }
        else if(loop == 5){ /*Caso a opção seja a de número 5, a função irá encerrar o programa*/
            printf("Ate mais");
        }
        else printf("O numero inserido nao corresponde a nenhuma funcao\nTente novamente\n\n");
    }
    return 0;
}

