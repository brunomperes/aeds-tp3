/*
 ============================================================================
 TRABALHO PRÁTICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 BOOLEXP.H - Define o cabeçalho das funções do TAD Expressão Booleana e o tipo de dado do vetor BoolExp.
 ============================================================================
 */

#ifndef BOOLEXP_H_INCLUDED
#define BOOLEXP_H_INCLUDED

//Tipo que armazenará a expressão booleana
typedef char BoolExp;

//Calcula o tamanho da expressão em O(n)
int TamanhoExp(BoolExp* exp);

//Encontra a próxima variável na expressão e retorna a posição da variável. Pior caso O(n)
int proxVAR(BoolExp* exp, int pos);

//Encontra o próximo operador da expressão
int proxOP(BoolExp *exp, int pos);

//Retorna se um elemento da expressão é um operador
bool isOP(BoolExp c);

//Retorna se um elemento da expressão é um 'not'
bool isNOT(BoolExp c);

//Retorna se uma elemento da expressão é uma variável ('True' ou 'False')
bool isVAR(BoolExp c);

void ImprimirExpressao(BoolExp* exp);

//Mostra um intervalo da expressão exp
void MostraIntervalo(BoolExp* exp, int inicio, int fim);

#endif // BOOLEXP_H_INCLUDED
