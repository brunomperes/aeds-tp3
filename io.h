/*
 ============================================================================
 TRABALHO PRÁTICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 IO.H - Contém o cabeçalho das funções de entrada e saída.
 ============================================================================
 */

#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#include "boolexp.h"

//Verifica se os parâmetros com o nome do arquivo de entrada e saída foram passados corretamente
//Caso encontre algum erro, finaliza a execução
void checaEntrada(int argc, char **argv, char *NomeArqEntrada, char *NomeArqSaida, int *Analise);

//Limpa o conteúdo de um arquivo
void LimpaArquivo(char *NomeArqSaida);

//Lê a quantidade de instâncias de um arquivo já aberto
int LeInstancias(FILE *ArqEntrada);

//Lê uma expressão e retorna um ponteiro para o vetor que contém a expressão booleana
BoolExp* LeituraExpressao(FILE* ArqEntrada);

//Escreve um int num arquivo já aberto
void EscreveInt(FILE* ArqSaida, int qntmem);

void EscreveTempoExec(FILE* ArqSaida, double tempogasto);

void EscreveResultadoAnalise(FILE *ArqAnalise, int QntTrue);

//Escreve no arquivo de saída o resultado da quantidade calculada
void EscreveResultado(FILE *ArqSaida, int QntTrue);

#endif // IO_H_INCLUDED
