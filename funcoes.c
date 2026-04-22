#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* array_aleatorio(int n) {
    int *array = (int*) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    return array;
}

int* crescente(int n) {
    int *array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        return NULL;
    }    
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    
    return array;
}

int* decrescente(int n) {
    int *array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        return NULL;
    }    
    for (int i = 0; i < n; i++) {
        array[i] = n - i - 1;
    }
    
    return array;
}