/*
 ============================================================================
 TRABALHO PR�TICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 BOOLEXP.H - Define o cabe�alho das fun��es do TAD Express�o Booleana e o tipo de dado do vetor BoolExp.
 ============================================================================
 */

#ifndef BOOLEXP_H_INCLUDED
#define BOOLEXP_H_INCLUDED

//Tipo que armazenar� a express�o booleana
typedef char BoolExp;

//Calcula o tamanho da express�o em O(n)
int TamanhoExp(BoolExp* exp);

//Encontra a pr�xima vari�vel na express�o e retorna a posi��o da vari�vel. Pior caso O(n)
int proxVAR(BoolExp* exp, int pos);

//Encontra o pr�ximo operador da express�o
int proxOP(BoolExp *exp, int pos);

//Retorna se um elemento da express�o � um operador
bool isOP(BoolExp c);

//Retorna se um elemento da express�o � um 'not'
bool isNOT(BoolExp c);

//Retorna se uma elemento da express�o � uma vari�vel ('True' ou 'False')
bool isVAR(BoolExp c);

void ImprimirExpressao(BoolExp* exp);

//Mostra um intervalo da express�o exp
void MostraIntervalo(BoolExp* exp, int inicio, int fim);

#endif // BOOLEXP_H_INCLUDED
