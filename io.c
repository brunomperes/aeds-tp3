/*
 ============================================================================
 TRABALHO PR�TICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 IO.C - Realiza a comunica��o do programa com o ambiente, lendo o arquivo de entrada, armazenando as informa��es lidas na mem�ria e escrevendo os resultados nos arquivos de sa�da.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //getopt()
#include <string.h>
#include <stdbool.h>

#include "io.h"
#include "boolexp.h"

#define TAMMAXNOMEARQ 256
#define SIM 1
#define NAO 0

//Limpa o conte�do de um arquivo
void LimpaArquivo(char *NomeArqSaida) {
    FILE * ArqSaida = fopen (NomeArqSaida,"w");
    fclose (ArqSaida);
}

//Preenche os par�metros para execu��o do programa e verifica se os par�metros necess�rios foram passados ao programa
void checaEntrada(int argc, char **argv, char *NomeArqEntrada, char *NomeArqSaida, int *Analise) {

    int opcao, checkInput=0, checkOutput=0;

    *Analise = 0;

    char *temp1 = NULL;
    char *temp2 = NULL;

    strncpy(NomeArqEntrada, " ", 2);
    strncpy(NomeArqSaida, " ", 2);

    while( (opcao = getopt(argc, argv, "i:o:a")) != -1 ) {
        switch( opcao ) {
        case 'i':
            checkInput=1 ;
            temp1 = optarg ;
            break ;
        case 'o':
            checkOutput=1 ;
            temp2 = optarg ;
            break ;
        case 'a':
            *Analise=1;
            break ;
        case '?':
            break ;
        }
    }

    //Verifica se os par�metros necess�rios foram preenchidos
    if (checkInput == 0 || checkOutput == 0 || NomeArqEntrada == NULL || NomeArqSaida == NULL) {
        puts ("\n[ERRO] Verifique se os par�metros de nome de arquivo de entrada e de sa�da foram passados corretamente!\n");
        exit(1);
    }

    strncpy(NomeArqEntrada, temp1, TAMMAXNOMEARQ);
    strncpy(NomeArqSaida, temp2, TAMMAXNOMEARQ);
}

//L� a quantidade de inst�ncias de um arquivo j� aberto
int LeInstancias(FILE *ArqEntrada) {
    int x;
    fscanf(ArqEntrada, "%d", &x);
    fgetc(ArqEntrada); //Move o cursor para o in�cio da pr�xima linha
    return x;
}

//L� uma express�o e retorna um ponteiro para o vetor que cont�m a express�o booleana
BoolExp* LeituraExpressao(FILE* ArqEntrada) {

    int i=0, j=0;
    char linha[(6*50)+1];
    char *elemento[50]; //Matriz contendo as palavras lidas
    char *aux;
    BoolExp *exp;

    //Pega a linha que cont�m a express�o
    fgets(linha, sizeof(linha), ArqEntrada);

    //Separa a express�o em um vetor de strings de tamanho i
    aux = strtok (linha," ,");
    while (aux != NULL) {
        elemento[i] = (char*)malloc(strlen(aux) + 1);
        if (elemento[i])
            strncpy(elemento[i], aux, strlen(aux));
        i++;
        aux = strtok (NULL," ,");
    }

    exp = (BoolExp*) malloc((i+1)*sizeof(BoolExp));
    if (exp == NULL) exit(1);

    for (j=0; j<i; j++) {
        //Copia o primeiro caracter das strings para a express�o 'exp'
        if (elemento[j][0] == 'n') { //Caso de ser nand ou not
            if (elemento[j][1] == 'a') { //nand
                exp[j] = 'n';
            } else {
                exp[j] = 'N'; //not
            }
        } else {
            exp[j] = elemento[j][0];
        }
        if (j+1 == i) {
            exp[j+1] = '\0';
            break;
        }
    }

    for (j=0; j<i; j++)
        free(elemento[j]);
    return exp;
}

//Escreve no arquivo de sa�da o resultado da contagem de parentiza��o
void EscreveResultado(FILE *ArqSaida, int QntTrue) {
    fprintf(ArqSaida, "%u\n", QntTrue);
}

void EscreveResultadoAnalise(FILE *ArqAnalise, int QntTrue) {
    fprintf(ArqAnalise, "%u\t", QntTrue);
}

//Escreve um int num arquivo j� aberto como escrita
void EscreveInt(FILE* ArqAnaliseRes, int qntmem) {
    fprintf(ArqAnaliseRes, "%d\t", qntmem);
}

//Escreve o tempo de execu��o do programa num arquivo j� aberto
void EscreveTempoExec(FILE *ArqAnaliseRes, double tempogasto) {
    fprintf(ArqAnaliseRes, "&%lf\t", tempogasto);
    fprintf(ArqAnaliseRes, "\\\\ \\hline\n");
}
