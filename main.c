#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    FILE *arquivo;
    char nome_arquivo[MAX_LEN];
    char palavra[MAX_LEN];
    char linha[MAX_LEN];
    int numero_linha = 0;
    int numero_ocorrencias = 0;

    // pedir o nome do arquivo ao usuário
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    // abrir o arquivo em modo leitura
    arquivo = fopen(nome_arquivo, "r");

    // verificar se a abertura foi bem-sucedida
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // pedir a palavra a ser pesquisada ao usuário
    printf("Digite a palavra a ser pesquisada: ");
    scanf("%s", palavra);

    // percorrer as linhas do arquivo
    while (fgets(linha, MAX_LEN, arquivo)) {
        numero_linha++;

        // percorrer as palavras da linha
        char *ptr = linha;
        while ((ptr = strstr(ptr, palavra))) {
            // encontrou uma ocorrência da palavra
            numero_ocorrencias++;
            printf("'%s' encontrada na linha %d, coluna %ld\n", palavra, numero_linha, ptr - linha + 1);
            ptr++;
        }
    }

    // exibir a quantidade de ocorrências encontradas
    printf("'%s' ocorreu %d vez(es) no arquivo.\n", palavra, numero_ocorrencias);

    // fechar o arquivo
    fclose(arquivo);

    return 0;
}
