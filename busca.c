

#include <stdio.h>
#include <stdlib.h>

// função de busca binária
int buscaB(int v[], int aux, int n) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (v[meio] == aux) {
            return 1;
        } else if (v[meio] < aux) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return 0;
}

// função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int v[n]; // vetor de inteiros
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int k;
    scanf("%d", &k);

    int b[k]; // vetor de busca
    for (i = 0; i < k; i++) {
        scanf("%d", &b[i]);
    }

    // ordena o vetor v
    qsort(v, n, sizeof(int), comparar);

    for (i = 0; i < k; i++) {
        int aux = b[i];
        int cont = buscaB(v, aux, n);
        printf("%d\n", cont);
    }

    return 0;
}
