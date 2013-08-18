/*
 ============================================================================
 TRABALHO PR�TICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 IO.H - Cont�m o cabe�alho das fun��es de entrada e sa�da.
 ============================================================================
 */

#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#include "boolexp.h"

//Verifica se os par�metros com o nome do arquivo de entrada e sa�da foram passados corretamente
//Caso encontre algum erro, finaliza a execu��o
void checaEntrada(int argc, char **argv, char *NomeArqEntrada, char *NomeArqSaida, int *Analise);

//Limpa o conte�do de um arquivo
void LimpaArquivo(char *NomeArqSaida);

//L� a quantidade de inst�ncias de um arquivo j� aberto
int LeInstancias(FILE *ArqEntrada);

//L� uma express�o e retorna um ponteiro para o vetor que cont�m a express�o booleana
BoolExp* LeituraExpressao(FILE* ArqEntrada);

//Escreve um int num arquivo j� aberto
void EscreveInt(FILE* ArqSaida, int qntmem);

void EscreveTempoExec(FILE* ArqSaida, double tempogasto);

void EscreveResultadoAnalise(FILE *ArqAnalise, int QntTrue);

//Escreve no arquivo de sa�da o resultado da quantidade calculada
void EscreveResultado(FILE *ArqSaida, int QntTrue);

#endif // IO_H_INCLUDED
