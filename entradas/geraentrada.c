/*
 ============================================================================
 TRABALHO PRÁTICO 3 - Counting Boolean Parenthesization
 Algoritmos e Estruturas de Dados III

 Bruno Maciel Peres
 brunomperes@dcc.ufmg.br

 GERAENTRADA.C - Gera entradas aleatórias entre 1 e 50
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NOT 0
#define VAR 1
#define OP 2

#define AND 0
#define OR 1
#define NAND 2
#define IMP 3
#define XOR 4
#define EQV 5

#define MAX_T 50

void geraVAR(FILE* output){
    int x;
    x = (rand()%2);
    if (x%2 == 0)
        fprintf(output, "True");
    else fprintf(output, "False");
}

void geraOP(FILE* output){
    int op;
    op = rand()%6;
    switch (op) {
    case AND: //AND
        fprintf(output, " and ");
        return;
    case OR: //OR
        fprintf(output, " or ");
        return;
    case NAND: //NAND
        fprintf(output, " nand ");
        return;
    case IMP: //IMP
        fprintf(output, " imp ");
        return;
    case XOR: //XOR
        fprintf(output, " xor ");
        return;
    case EQV: //EQV
        fprintf(output, " eqv ");
        return;
    }
    return;
}

void imprimeNOT(FILE* output){
    fprintf(output, "not ");
}

int main() {
    int instancias, x, j = 1;
    int t=1, tcont=0; //Tamanho da expressão
    int ant=-1; //Operador anterior
    printf("Insira a quantidade de expressoes:\n");
    scanf("%d", &instancias);
    FILE* output = fopen("input.txt", "w");
    fprintf(output, "%d\n", instancias);
    srand ( time(NULL) );
    while(j <= instancias) {
//        t = (rand()%50)+1; //t máximo é 50 e mínimo é 1
        /*Para gerar valores aleatórios comente daqui ######################*/
//        printf("Insira o tamanho da expressao (entre 0 e 50) da instancia %d:\n", j);
//        scanf("%d", &t);
//        while( t < 1 || t > 50) {
//            printf("O tamanho deve ser entre 0 e 50\n Insira novamente:\n");
//            scanf("%d", &t);
//        }
		//if (j%(instancias/MAX_T) == 0) 
		t+=2;
		if (t > 47) t = 47;
        /* Até aqui ########################################################*/
        ant=-1;
        tcont =0;
        while (tcont < t) {
            x = (rand()%3);
            switch (x){
                case (NOT):
                    if (tcont+1 == t) break; //Não pode haver not no final de uma expressão
                    if (ant == VAR) break; //Evitar uma variável com um not sem operador
                    imprimeNOT(output);
                    ant = NOT;
                    tcont++;
                    break;
                case (VAR):
                    if (ant == VAR) break; //Evitar uma variável imediatamente seguida da outra
                    geraVAR(output);
                    tcont++;
                    ant = VAR;
                    break;
                case (OP):
                    if (ant == -1) break; //Não pode haver operador sem variável à esquerda
                    if (ant == NOT) break; //Não pode haver um operador com not à esquera
                    if (ant == VAR){
                        geraOP(output);
                        tcont++;
                        x= rand()%3;
                        while (x < VAR){
                            imprimeNOT(output);
                            x= rand()%3; //Diminuir as chances de repetir um not, pra 33% e não 50%
                            tcont++;
                            if (tcont< t-1) break;
                        }
                        geraVAR(output);
                        tcont++;
                    }
                    else{
                        geraOP(output);
                        tcont++;
                        geraVAR(output);
                        tcont++;
                        break;
                    }
            }
        }
        printf ("tamanho da expressao = %d\n", tcont);
        fprintf(output, "\n");
        j++;
    }
    fclose(output);
    return 0;
}
