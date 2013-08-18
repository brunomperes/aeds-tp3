/*
 ============================================================================
 TRABALHO PRÁTICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 HEURISTICA.H - Define o cabeçalho da principal função de execução do programa e define o tipo de dado que a memória utilizará.
 ============================================================================
 */

#ifndef HEURISTICA_H_INCLUDED
#define HEURISTICA_H_INCLUDED

#include "boolexp.h"

typedef unsigned long long int TipoMemoria;

/*###############################################################################################################################
#   Definição: Conta a quantidade de maneiras de parentizar uma expressão tal que resulte em True
#   Retorno: Quantidade de Trues possíveis
#   Complexidade: O(n³)
################################################################################################################################*/
TipoMemoria ContaParentizacaoTrue(FILE* ArqAnalise, BoolExp* exp);

#endif // HEURISTICA_H_INCLUDED
