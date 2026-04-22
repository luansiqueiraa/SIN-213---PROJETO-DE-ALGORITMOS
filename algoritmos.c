#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort
double insertion(int *array, int n){
    int i, x, temp;
    clock_t start = clock();
    for (i = 1; i < n; i++){
        temp = array[i];
        x = i - 1;
        while (x >= 0 && array[x] > temp){
            array[x + 1] = array[x];
            x = x - 1;
        }
        array[x + 1] = temp;
    }
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Selection Sort
double selection(int *array, int n){
    int i, j, minIndex, temp;
    clock_t start = clock();
    for (i = 0; i < n - 1; i++){
        minIndex = i;
        for (j = i + 1; j < n; j++){
            if (array[j] < array[minIndex]){
                minIndex = j;
            }
        }
        
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Bubble Sort
double bubble(int *array, int n) {
    int i, j, temp;
    clock_t start = clock();
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Shell Sort
double shell(int *array, int n){
    int i, gap, temp, j;
    clock_t start = clock();
    for (gap = n / 2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++) {
            temp = array[i];
            
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }
            
            array[j] = temp;
        }
    }
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Merge Sort
void divide_array(int *array, int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int *arrayL = malloc(n1 * sizeof(int));
    int *arrayR = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        arrayL[i] = array[esq + i];
    for (j = 0; j < n2; j++)
        arrayR[j] = array[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2) {
        if (arrayL[i] <= arrayR[j]) {
            array[k] = arrayL[i];
            i++;
        } else {
            array[k] = arrayR[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = arrayL[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = arrayR[j];
        j++;
        k++;
    }

    free(arrayL);
    free(arrayR);
}

void mergearray(int *array, int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergearray(array, esq, meio);
        mergearray(array, meio + 1, dir);

        divide_array(array, esq, meio, dir);
    }
}

double merge(int *array, int n) {
    clock_t start = clock();
    mergearray(array, 0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Quick Sort
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Pivô como o primeiro elemento
int partition_v1(int vet[], int baixo, int dir){
    int pivot = vet[baixo];
    int j, temp, i = baixo;
    
    for(j = baixo + 1; j <= dir; j++){
        if(vet[j] < pivot){
            i++;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp; 
        }
    }
    temp = vet[i];
    vet[i] = vet[baixo];
    vet[baixo] = temp;
    return i;
}

void aux_v1(int vet[], int baixo, int dir){
    if (baixo < dir){
        int pivo = partition_v1(vet, baixo, dir);
        aux_v1(vet, baixo, pivo -1);
        aux_v1(vet, pivo + 1, dir);
    }
}

// Pivô como o valor do meio
int partition_v2(int vet[], int baixo, int dir) {
    int meio = baixo + (dir - baixo) / 2;
    troca(&vet[baixo], &vet[meio]);
    int pivot = vet[baixo];
    int j, i = baixo;

    for (j = baixo + 1; j <= dir; j++) {
        if (vet[j] < pivot) {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i], &vet[baixo]);
    return i;
}

void aux_v2(int vet[], int baixo, int dir) {
    if (baixo < dir) {
        int pivo = partition_v2(vet, baixo, dir);
        aux_v2(vet, baixo, pivo - 1);
        aux_v2(vet, pivo + 1, dir);
    }
}

// Versão 3: Pivô aleatório
int partition_v3(int vet[], int baixo, int dir) {
    int random_pivot = baixo + rand() % (dir - baixo + 1);
    troca(&vet[baixo], &vet[random_pivot]);
    int pivot = vet[baixo];
    int j, i = baixo;

    for (j = baixo + 1; j <= dir; j++) {
        if (vet[j] < pivot) {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i], &vet[baixo]);
    return i;
}

void aux_v3(int vet[], int baixo, int dir) {
    if (baixo < dir) {
        int pivo = partition_v3(vet, baixo, dir);
        aux_v3(vet, baixo, pivo - 1);
        aux_v3(vet, pivo + 1, dir);
    }
}

double quick_v1(int vet[], int baixo, int dir){
    clock_t start = clock();    
    aux_v1(vet, baixo, dir);    
    clock_t end = clock();  
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double quick_v2(int vet[], int baixo, int dir) {
    clock_t start = clock(); 
    aux_v2(vet, baixo, dir);
    clock_t end = clock();  
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double quick_v3(int vet[], int baixo, int dir) {
    clock_t start = clock(); 
    aux_v3(vet, baixo, dir);
    clock_t end = clock();  
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Heap Sort
void min_heapify(int *array, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] < array[smallest]) {
        smallest = left;
    }

    if (right < n && array[right] < array[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
        min_heapify(array, n, smallest);
    }
}

void build_min_heap(int *array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(array, n, i);
    }
}

double heap(int *array, int n) { 
    clock_t start = clock();
    build_min_heap(array, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        min_heapify(array, i, 0);
    }
    for (int i = 0; i < n / 2; i++) {
        int temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}