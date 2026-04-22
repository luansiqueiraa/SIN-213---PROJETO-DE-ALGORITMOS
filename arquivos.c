#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>

void confere_o_Diretorio(const char *caminho){
	if(_mkdir(caminho) == -1){
	}
}

void criarArquivo(const char *caminhoArquivo, const char *conteudo) {
    FILE *arquivo = fopen(caminhoArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s\n", caminhoArquivo);
        return;
    }
    fprintf(arquivo, "%s", conteudo);
    fclose(arquivo);
    printf("Arquivo '%s' criado com sucesso!\n", caminhoArquivo);
}

void salvarEmArquivo(int arr[], int tamanho, int tipoOrdenacao){
    char tipoOrdenacaoStr[20];
    if(tipoOrdenacao == 1){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "random");
    }else if(tipoOrdenacao == 2){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "crescente");
    }else if(tipoOrdenacao == 3){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "decrescente");
    }else{
        printf("Tipo de ordenacao invalido\n");
        return;
    }

    confere_o_Diretorio("Arquivos de Entrada");
    confere_o_Diretorio("Arquivos de Entrada\\Crescente");
    confere_o_Diretorio("Arquivos de Entrada\\Decrescente");
    confere_o_Diretorio("Arquivos de Entrada\\Random");

    char filename[60];
    snprintf(filename, sizeof(filename), "Arquivos de Entrada\\%s\\entrada%s%d.txt", tipoOrdenacaoStr, tipoOrdenacaoStr, tamanho);


    FILE *arquivo = fopen(filename, "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(arquivo, "%d:\n", tamanho);

    int i;
    for(i = 0; i < tamanho; i++){
        fprintf(arquivo, "%d\n", arr[i]);
    }

    fclose(arquivo);
}

void salvarOrdenadoEmArquivo(int arr[], int tamanho, int tipoOrdenacao){
    char tipoOrdenacaoStr[20];
    if(tipoOrdenacao == 1){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "random");
    }else if(tipoOrdenacao == 2){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "crescente");
    }else if(tipoOrdenacao == 3){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "decrescente");
    }else{
        printf("Tipo de ordenacao invalido\n");
        return;
    }

    confere_o_Diretorio("Arquivos de Saida");
    confere_o_Diretorio("Arquivos de Saida\\Crescente");
    confere_o_Diretorio("Arquivos de Saida\\Decrescente");
    confere_o_Diretorio("Arquivos de Saida\\Random");

    char filename[60];
    snprintf(filename, sizeof(filename), "Arquivos de Saida\\%s\\ordenado%s%d.txt", tipoOrdenacaoStr, tipoOrdenacaoStr, tamanho);

    FILE *arquivo = fopen(filename, "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(arquivo, "%d:\n", tamanho);

    int i;
    for(i = 0; i < tamanho; i++){
        fprintf(arquivo, "%d\n", arr[i]);
    }

    fclose(arquivo);
}

void salvarTempoEmArquivo(double tempo, int tamanho, int tipoOrdenacao){
    char tipoOrdenacaoStr[20];
    if(tipoOrdenacao == 1){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "random");
    }else if(tipoOrdenacao == 2){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "crescente");
    }else if(tipoOrdenacao == 3){
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "decrescente");
    }else{
        printf("Tipo de ordenacao invalido\n");
        return;
    }

    confere_o_Diretorio("Arquivos de Tempo");
    confere_o_Diretorio("Arquivos de Tempo\\Crescente");
    confere_o_Diretorio("Arquivos de Tempo\\Decrescente");
    confere_o_Diretorio("Arquivos de Tempo\\Random");


    char filename[60];
    snprintf(filename, sizeof(filename), "Arquivos de Tempo\\%s\\tempo%s%d.txt", tipoOrdenacaoStr, tipoOrdenacaoStr, tamanho);

    FILE *arquivo = fopen(filename, "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(arquivo, "%d:\n", tamanho);

    fprintf(arquivo, "Tempo gasto: %f segundos\n", tempo);

    fclose(arquivo);
}