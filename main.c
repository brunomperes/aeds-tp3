/*
 ============================================================================
 TRABALHO PRÁTICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 MAIN.C - Arquivo principal do programa, contém as chamadas de funções de entrada e saída e chamada de execução da função principal.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "heuristica.h"
#include "io.h"
#include "timerlinux.h"
#include "boolexp.h"

#define SIM 1
#define TAMMAXNOMEARQ 256

int main(int argc, char **argv) {

    //Nomes dos arquivos
    char NomeArqEntrada[TAMMAXNOMEARQ];
    char NomeArqSaida[TAMMAXNOMEARQ];

    //Variáveis para análise do programa
    int Analise;
    char NomeArqAnaliseHeur[] = "Analise.txt";
    stopWatch cronometro;
    double tempogasto;

    //Variáveis para execução
    int j;
    int instancias;
    TipoMemoria QntTrue;

    //Verifica se os parâmetros necessários foram passados para o programa
    checaEntrada(argc, argv, NomeArqEntrada, NomeArqSaida, &Analise);

    FILE *ArqEntrada = fopen(NomeArqEntrada, "r");
    if (ArqEntrada == NULL) {
        printf("\n[ERRO] Problema ao abrir o arquivo de entrada\nVerifique se o arquivo passado como argumento realmente existe\n\n");
        exit(1); //Finaliza o programa com status de erro
    }
    FILE *ArqSaida = fopen (NomeArqSaida,"w");
    FILE *ArqAnalise = fopen (NomeArqAnaliseHeur,"a");

    instancias = LeInstancias(ArqEntrada);

    for (j=0; j<instancias; j++) {
        BoolExp *exp = LeituraExpressao(ArqEntrada);
        EscreveInt(ArqAnalise, TamanhoExp(exp)); //Escreve o tamanho da expressão

        if (Analise == SIM) startTimer(&cronometro);
        QntTrue = ContaParentizacaoTrue(ArqAnalise, exp);
        if (Analise == SIM) stopTimer(&cronometro);
        if (Analise == SIM) tempogasto = getElapsedTime(&cronometro);

        EscreveResultado(ArqSaida, QntTrue);
        if (Analise == SIM) EscreveTempoExec(ArqAnalise, tempogasto);

        free (exp);

    }

    fclose(ArqEntrada);
    fclose(ArqSaida);
    fclose(ArqAnalise);

    return 0;
}
