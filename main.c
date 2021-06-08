#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * Exemplo de programa em C para leitura de arquivo com delimitadores
 * e campos numéricos e textuais usando buffer.
 * Esse programa faz a leitura de uma linha de cada vez do arquivo
 * armazenando cada campo em uma variável, exibindo os dados lidos na 
 * tela no formato de uma tabela e, ao final, 
 * calcula e exibe a media de todas as notas.
 */

#define MAX_TAM 100

int main(){
    float notas=0, media=0, nota1, nota2;
    char buf[MAX_TAM];
    int num;
    char *nome;

    FILE *arq;
    arq = fopen("alunos.txt", "r");

    if (arq==NULL){
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    printf("\nMatricula\t Nome \t\t\t Nota 1\t\t Nota 2 \t");

    fgets(buf,MAX_TAM,arq);
    while(!feof(arq)){
        num = atoi(strtok(buf, ","));
        nome = strtok(NULL,",");
        nota1 = atof(strtok(NULL,","));
        nota2 = atof(strtok(NULL,","));
        printf("\n%d \t\t%s \t%4.1f \t\t%4.1f", num, nome, nota1, nota2);
        notas = notas + 2;
        media = media + nota1 + nota2;
        fgets(buf,MAX_TAM,arq);
    }
    printf("\nMedia = %f\n", media/notas);

    fclose(arq);

    return 0;
}