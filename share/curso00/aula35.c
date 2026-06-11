#include <stdio.h>
#include <stdlib.h>

int main(void){
        int     fatorial(int x);
        int     numero, resultado;
        double  d_fatorial(int x);
        double  resultado_d;

        printf("Digite um numero inteiro:\n");
        if (scanf("%i", &numero) != 1) {
                printf("Erro ao ler o numero.\n");
                return 1;
        }
        
        // Se for maior que 12, usa a função double para não estourar
        if (numero > 12) {
                resultado_d = d_fatorial(numero);
                printf("O fatorial = %g\n", resultado_d); // %g exibe em notação científica (ex: 9.33263e+157)
        } else {
                // Se for até 12, calcula e exibe como inteiro normal
                resultado = fatorial(numero);
                printf("O fatorial = %i\n", resultado);
        }
        
        return 0;
}

// Sua função recursiva para números pequenos
int fatorial (int x) {
        int resultado;

        if( x == 0 ) {
                resultado = 1;
        } else {
                resultado = x * fatorial(x - 1);
        }
        return resultado;
}

// Sua função iterativa para números gigantes
double d_fatorial(int n) {
        double fat = 1.0;
        for (int i = 1; i <= n; i++) {
                fat *= i;
        }
        return fat;
}

