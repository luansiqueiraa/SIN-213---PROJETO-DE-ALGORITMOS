#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "funcoes.c"
#include "algoritmos.c"
#include "arquivos.c"

void menu() {
    int opcao, opcaoquick, tipo, tam;
    int *array;
    double tempo;

        printf("Menu: \n");
        printf("1 - Insertion Sort \n");
        printf("2 - Selection Sort \n");
        printf("3 - Bubble Sort \n");
        printf("4 - Shell Sort \n");
        printf("5 - Merge Sort \n");
        printf("6 - Quick Sort \n");
        printf("7 - Heap Sort \n");
        printf("0 - Sair do Programa \n");
        printf("Escolha uma opcao: ");
        printf("\n");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 0){
            printf("Voce Saiu!\n");
            exit(0);
        }

        if (opcao < 1 || opcao > 7){
            printf("Erro: Opcao invalida! Escolha entre 0 e 7.\n");
            exit(0);
        }

        switch (opcao){
            case 1:
                printf("==========  Insertion Sort  ==========\n");
                break;
            case 2:
                printf("==========  Selection Sort  ==========\n");
                break;
            case 3:
                printf("==========   Bubble Sort    ==========\n");
                break;
            case 4:
                printf("===========   Shell Sort   ===========\n");
                break;
            case 5:
                printf("===========   Merge Sort   ===========\n");
                break;
            case 7:
                printf("===========    Heap Sort   ===========\n");
                break;
        }

        if (opcao == 6){
            printf("===========  Escolha a versao  ===========\n");
            printf("=======                            =======\n");
            printf("=======     1 - Quick Sort_V1      =======\n");
            printf("=======     2 - Quick Sort_V2      =======\n");
            printf("=======     3 - Quick Sort_V3      =======\n");
            printf("=======                            =======\n");
            printf("==========================================\n");
            printf("Versao: ");
            scanf("%d", &opcaoquick);
            printf("\n");
        }

        switch (opcaoquick){
            case 1:
                printf("==========  Quick Sort_V1  ===========\n");
                break;
            case 2:
                printf("==========  Quick Sort_V2  ===========\n");
                break;
            case 3:
                printf("==========  Quick Sort_V3  ===========\n");
                break;
        }

        printf("=====                            =====\n");
        printf("=====       1 - Random           =====\n");
        printf("=====       2 - Crescente        =====\n");
        printf("=====       3 - Decrescente      =====\n");
        printf("=====                            =====\n");
        printf("======================================\n");
        printf("Escolha o tipo de ordenacao: ");
        scanf("%d", &tipo);

        if (tipo < 1 || tipo > 3){
            printf("Erro: Opcao de ordenacao invalida! Escolha entre 1 e 3.\n");
            exit(0);
        }

        printf("Escolha o tamanho do array (10, 100, 1000, 10000, 100000, 1000000): ");
        scanf("%d", &tam);

        switch (tipo){
            case 1: 
                array = array_aleatorio(tam);
                break;
            case 2:
                array = crescente(tam);
                break;
            case 3:
                array = decrescente(tam);
                break;
        }

        salvarEmArquivo(array, tam, tipo);

        switch (opcao){
            case 1:
                tempo = insertion(array, tam);
                break;
            case 2:
                tempo = selection(array, tam);
                break;
            case 3:
                tempo = bubble(array, tam);
                break;
            case 4:
                tempo = shell(array, tam);
                break;
            case 5:
                tempo = merge(array, tam);
                break;
            case 7:
                tempo = heap(array, tam);
                break;
        }

        switch(opcaoquick){
            case 1:
                tempo = quick_v1(array, 0, tam - 1);
                break;
            case 2:
                tempo = quick_v2(array, 0, tam - 1);
                break;
            case 3:
                tempo = quick_v3(array, 0, tam - 1);
                break;
        }

        salvarOrdenadoEmArquivo(array, tam, tipo);
        salvarTempoEmArquivo(tempo, tam, tipo);

        free(array);
    }

int main() {
    srand(time(NULL));
    menu();
    return 0;
}
