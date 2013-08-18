/*
 ============================================================================
 TRABALHO PRÁTICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 HEURISTICA.C - Define o funcionamento da função principal de programa.
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> //Tipo bool em C
#include <string.h> //strlen()

#include "heuristica.h"
#include "io.h"

//Mostra o conteúdo de uma matriz de memória
void MostraMemoria(TipoMemoria **memoria, int tam) {
    int i, j;
    for (i=0; i<tam; i++) {
        for (j=0; j<tam; j++) {
            printf ("%llu ", memoria[i][j]);
        }
        printf ("\n");
    }
}

//Verifica se nenhuma das matrizes (T[][] e F[][]) não foi alterada na posição [i][j]
_Bool NaoCalculou(TipoMemoria **T, TipoMemoria **F, int i, int j) {
    return ((T[i][j] == 0) && (F[i][j] == 0));
}

//Atribui valores à matriz de verdadeiros e falsos de acordo com o valor da variável
void ArmazenaValorDaVariavel(TipoMemoria **T, TipoMemoria **F, int i, int variable) {
    if (variable == 'T') {
        T[i][i] = 1;
    } else {
        F[i][i] = 1;
    }
}

void AvaliaExpressao(BoolExp operator, TipoMemoria **T, TipoMemoria **F, int i, int j, int k) {

    int esquerda, direita, totalTrues, totalFalses,trues1, trues2, falses1, falses2;

    switch(operator) {

    case 'a':
        esquerda = T[i][k-1] + F[i][k-1];     // T(esq) + F(esq)
        direita = T[k+1][j] + F[k+1][j];      // T(dir) + F(dir)
        totalTrues = T[i][k-1] * T[k+1][j];   // T(esq) * T(dir)

        T[i][j] += totalTrues;
        F[i][j] += (esquerda * direita) - totalTrues;
        break;

    case 'o':
        esquerda = T[i][k-1] + F[i][k-1];	    // T(esq) + F(esq)
        direita = T[k+1][j] + F[k+1][j];	    // T(dir) + F(dir)
        totalFalses = F[i][k-1] * F[k+1][j];    // F(esq) * F(dir)

        T[i][j] += (esquerda * direita) - totalFalses;
        F[i][j] += totalFalses;
        break;

    case 'x':
        trues1 = T[i][k-1] * F[k+1][j];	    // T(esq) * F(dir)
        trues2 = F[i][k-1] * T[k+1][j];	    // F(esq) * T(dir)
        falses1 = T[i][k-1] * T[k+1][j];	// T(esq) * T(dir)
        falses2 = F[i][k-1] * F[k+1][j];    // F(esq) * F(dir)

        T[i][j] += trues1 + trues2;
        F[i][j] += falses1 + falses2;
        break;

    case 'n': //NAND
        T[i][j] += F[k+1][j];   // F(dir)
        F[i][j] += T[k+1][j];   // T(dir)
        break;

    case 'i': //IMP
        esquerda = T[i][k-1] + F[i][k-1];	   // T(esq) + F(esq)
        direita = T[k+1][j] + F[k+1][j];	   // T(dir) + F(dir)
        totalFalses = T[i][k-1] * T[k+1][j];   // T(esq) * T(dir)

        T[i][j] += (esquerda * direita) - totalFalses;
        F[i][j] += totalFalses;
        break;

    case 'e': //EQV
        trues1 = T[i][k-1] * T[k+1][j];	   // T(esq) * T(dir)
        trues2 = F[i][k-1] * F[k+1][j];    // F(esq) * F(dir)
        falses1 = T[i][k-1] * F[k+1][j];   // T(esq) * F(dir)
        falses2 = F[i][k-1] * T[k+1][j];   // F(esq) * T(dir)

        T[i][j] += trues1 + trues2;
        F[i][j] += falses1 + falses2;
        break;

    case 'N': //NOT
        T[i][j] += F[k+1][j];   // F(dir)
        F[i][j] += T[k+1][j];   // T(dir)
        break;
    }
}

//Função recursiva que realiza a contagem
void ContaParentizacao(int i, int j, TipoMemoria **T, TipoMemoria **F, BoolExp exp[]) {
    int k;

    // Caso base: parênteses esquerdo e direito na variável i da expressão.
    if (i == j) {
        ArmazenaValorDaVariavel(T, F, i, exp[i]);
    }

    else {
        //Caso seja um operador
        for (k = i; k < j; k++) {
            if (isOP(exp[k]) || isNOT(exp[k])) {
                if (!isNOT(exp[k])) {
                    if (NaoCalculou(T, F, i, k-1)) {
                        //parte esquerda da sub-expressão.
                        ContaParentizacao(i, k-1, T, F, exp);
                    }
                }
                if (NaoCalculou(T, F, k+1, j)) {
                    //Parte direita da sub-expressão.
                    ContaParentizacao(k+1, j, T, F, exp);
                }
                //De acordo com o operador k entre o lado esquerdo e direito, calcula a quantidade de True entre os dois lados da expressão
                AvaliaExpressao(exp[k], T, F, i, j, k);
            }
        }
    }
}

//Função principal para solucionar o problema
TipoMemoria ContaParentizacaoTrue(FILE* ArqAnalise, BoolExp *exp) {

    int i;
    TipoMemoria **T;
    TipoMemoria **F;
    TipoMemoria resultado;
    int tam = TamanhoExp(exp);

    //Cria o vetor de memória para armazenar os valores já calculados
    T = (TipoMemoria**)malloc ( sizeof (TipoMemoria) * tam +1);
    for ( i=0; i < tam+1; i++ ) {
        T[i] = calloc(tam, sizeof(TipoMemoria)); //Aloca atribuindo valor 0 nas posições
    }
    F = (TipoMemoria**)malloc ( sizeof (TipoMemoria) * tam +1);
    for ( i=0; i < tam+1; i++ ) {
        F[i] = calloc(tam, sizeof(TipoMemoria)); //Aloca atribuindo valor 0 nas posições
    }

    ContaParentizacao(0, tam-1, T, F, exp);

    resultado = T[0][tam-1];

    TipoMemoria qntmem = sizeof(TipoMemoria)*2*tam*tam; //2 matrizes de tam*tam elementos de tipo TipoMemoria

    EscreveInt(ArqAnalise, qntmem);

    EscreveResultadoAnalise(ArqAnalise, resultado);

    //Libera a memória alocada para as matrizes de memória
    for ( i=0; i < tam; i++ ) {
        free(T[i]);
        free(F[i]);
    }
    free(T);
    free(F);

    return resultado;
}
