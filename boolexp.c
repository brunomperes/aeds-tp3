/*
 ============================================================================
 TRABALHO PR�TICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 BOOLEXP.C - Define as fun��es do TAD Express�o Booleana.
 ============================================================================
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "boolexp.h"

//Imprime uma express�o
void ImprimirExpressao(BoolExp* exp) {
    int tam = TamanhoExp(exp);
    int i;
    for (i=0; i<tam; i++) {
        printf("%c", exp[i]);
    }
    printf ("\n");
}

//Retorna se uma elemento da express�o � uma vari�vel ('True' ou 'False')
bool isVAR(BoolExp c) {
    if (c == 'T' || c == 'F') return true;
    else return false;
}

//Retorna se um elemento da express�o � um 'not'
bool isNOT(BoolExp c) {
    if (c == 'N') return true;
    else return false;
}

//Retorna se um elemento da express�o � um operador
bool isOP(BoolExp c) {
    if (c == 'a' || c == 'o' || c == 'n' || c == 'i' || c == 'x' || c == 'e')return true;
    return false;
}

//Conta a quantidade de vari�veis da express�o
int QuantVAR(BoolExp* exp) {
    char *p = exp;
    int qntvar;
    while(*p) {
        if (*p == '\n') break;
        if(isVAR(*p)) {
            printf ("op == %c\n", *p);
            qntvar++;
        }
    }
    return qntvar;
}

//Conta a quantidade de NOTs da express�o
int QuantNOT(BoolExp* exp) {
    char *p = exp;
    int qntnot;
    while(*p) {
        if(isNOT(*p)) {
            printf ("not == %c\n", *p);
            qntnot++;
        }
        p++;
    }
    return qntnot;
}

//Conta a quantidade de operadores da express�o
int QuantOP(BoolExp *exp) {
    char *p = exp;
    int qntop;
    while(*p) {
        if (*p == '\n') break;
        if(isOP(*p)) {
            qntop++;
        }
        p++;
    }
    return qntop;
}

//Encontra a pr�xima vari�vel na express�o e retorna a posi��o da vari�vel. Pior caso O(n)
//Retorna -1 caso chegue no final do arquivo mas n�o encontrou nenhuma vari�vel
int proxVAR(BoolExp* exp, int pos) {
    int tam = TamanhoExp(exp);
    while (tam <= pos) {
        if (isVAR(exp[pos])) return pos;
        if (pos == tam) return -1;
        pos++;
    }
    return pos;
}

//Encontra o pr�ximo operador da express�o
//Retorna -1 caso n�o encontre
int proxOP(BoolExp *exp, int pos) {
    int tam = strlen(exp)-1;
    pos++; //Avan�a o cursor para come�ar a busca no pr�ximo caracter
    while (!isOP(exp[pos]) && (pos < tam)) {
        pos++;
    }
    if (isOP(exp[pos])) return pos;
    else return -1;
}

//Calcula o tamanho da express�o em O(n)
int TamanhoExp(BoolExp* exp) {
    return strlen(exp); //N�o conta o '\n'
}

//Mostra um intervalo da express�o exp
void MostraIntervalo(BoolExp* exp, int inicio, int fim) {
    int i;
    for (i=inicio; i<=fim; i++) {
        printf ("%c", exp[i]);
    }
    printf ("\n");
}
