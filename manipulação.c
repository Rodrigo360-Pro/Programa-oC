#include <stdio.h>

int main (){
    FILE *arquivo; //ponteiro para o arquivo.
    char nome[50];
    int idade;

    //abrindo o arquivo no mod "w" para escrita.
    arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo!\n");
        return 1;
    }

    //coletando dados do usario.
    printf("digite o nome: ");
    if (scanf("%49s", nome) != 1) {
        printf("erro ao ler o nome!\n");
        fclose(arquivo);
        return 1;
    }

    printf("digite a idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("erro ao ler a idade!\n");
        fclose(arquivo);
        return 1;
    }

    //gravando dados no arquivo.
    fprintf(arquivo, "Nome: %s\n idade: %d\n", nome, idade);

    //fechando o arquivo.
    fclose(arquivo);

    //Reabrindo o arquivo no modo "r" para leitura.
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo!\n");
        return 1;
    }

    //lendo os dados do arquivo.
    if (fscanf(arquivo, "Nome: %49s\n idade: %d\n", nome, &idade) != 2) {
        printf("erro ao ler os dados do arquivo!\n");
        fclose(arquivo);
        return 1;
    }

    //exibindo os dados lidos.
    printf("Dados lidos do arquivo:\n");
    printf("Nome: %s\n idade: %d\n", nome, idade);

    //fecahndo o arquivo.
    fclose(arquivo);

    return 0;
}
