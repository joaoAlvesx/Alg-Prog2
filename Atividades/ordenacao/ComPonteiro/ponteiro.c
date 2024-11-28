#include <stdio.h>
#include <stdlib.h>

void bubleSort(void *v, int n, int tipo, int (*comp)(void *a, void *b)) {

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {

            if (tipo == 1) {

                if (comp((int*)(v) + j, (int*)(v) + j + 1) > 0) {
                    int aux = *((int*)(v) + j);
                    *((int*)(v) + j) = *((int*)(v) + j + 1);
                    *((int*)(v) + j + 1) = aux;
                }

            } else if (tipo == 2) {

                if (comp((float*)(v) + j, (float*)(v) + j + 1) > 0) {
                    float aux = *((float*)(v) + j);
                    *((float*)(v) + j) = *((float*)(v) + j + 1);
                    *((float*)(v) + j + 1) = aux;
                }

            } else if (tipo == 3) {

                if (comp((double*)(v) + j, (double*)(v) + j + 1) > 0) {
                    double aux = *((double*)(v) + j);
                    *((double*)(v) + j) = *((double*)(v) + j + 1);
                    *((double*)(v) + j + 1) = aux;
                }

            }
        };
    };
}

int compInt(void* a, void* b) {
    return *((int*)a) - *((int*)b);
}

int compFloat(void* a, void* b) {
    return *((float*)a) - *((float*)b);
}

int compDouble(void* a, void* b) {
    return *((double*)a) - *((double*)b);
}

int main() {

    void *v;
    int n;
    int tipo = -1;

    printf("informe a quantidade de elemento: ");
    scanf("%d", &n);

    while (tipo != 0) {

        printf("defina o tipo de variavel \n"
        "1 para int\n"
        "2 para float\n"
        "3 para double\n"
        "0 sair\n"
        "opção: ");
        scanf("%d", &tipo);

        if (tipo == 1) {
            
            v = (int*) malloc(sizeof(int) * n);

            for(int i = 0; i < n; i++) {

                printf("\nEntre com %d inteiros: ", n);
                scanf("%d", (int*)(v) + i);

            }

            bubleSort(v, n, 1, compInt);

            printf("\n [");
            for (int i = 0; i < n; i++) 
                printf(" %d ", *((int*)(v) + i));
                
            printf("]\n");

            free(v);

        } else if (tipo == 2) {

            v = (float*) malloc(sizeof(float) * n);

            for(int i = 0; i < n; i++) {

                printf("\nEntre com %d floats: ", n);
                scanf("%f", (float*)(v) + i);

            }

            bubleSort(v, n, 2, compFloat);

            printf("\n [");
            for (int i = 0; i < n; i++) 
                printf(" %.2f ", *((float*)(v) + i));
                
            printf("]\n");

            free(v);

        } else if (tipo == 3) {

            v = (double*) malloc(sizeof(double) * n);

            for(int i = 0; i < n; i++) {

                printf("\nEntre com %d doubles: ", n);
                scanf("%lf", (double*)(v) + i);

            }

            bubleSort(v, n, 3, compDouble);

            printf("\n [");
            for (int i = 0; i < n; i++) 
                printf(" %.2lf ", *((double*)(v) + i));
                
            printf("]\n");

            free(v);

        } 

        printf("\n\n\n");
 
    }

    return 0;

}