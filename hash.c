

#include <stdio.h>
#include <stdlib.h>

int hash(int cap, int key){
    return key % cap;
}

int search(int *table, int cap, int key){
    int pos = hash(cap, key);
    for (int i = pos; i < cap; i++){
        if(table[i] == key){
            return i;
        } else if( i == cap - 1 && pos != 0){
            return -1;
        } else if(i == pos - 1){
            return -1;
        }
    }
    return -1;
}

int insert(int *table, int cap, int key){
    // verifica se ja existe
    int b = search(table, cap, key);
    if (b != -1){
        return -1; // ja existe
    }

    int pos = hash(cap, key);
    for (int i = pos; i < cap; i++) {
        if (table[i] == -1) {
            table[i] = key;
            return 0;
        }
        if (i == cap - 1 && pos != 0) { // caso chegue no final do array, tente a primeira posição
            i = -1;
        }
        if (i == pos - 1) { // Caso de uma volta completa no array e não ache espaço, retorne erro (prevenir loop)
            return -1;
        }
    }
    return -1;
}

int remove_key(int *table, int cap, int key){
    int b = search(table, cap, key);
    if (b == -1) {
        return 0;
    }
    table[b] = -1;
    return 0;
}


int main() {

    // M capacidade da tabela, N número de inserções, D número de remoções, B número de buscas
    int M, N, D, B; 
    scanf("%d", &M);
    int *t;
    t = malloc(M * sizeof(int)); // Aloca espaço para a tabela

    for (int i = 0; i < M; i++) { // Percorre a tabela e declara tudo como 0
        t[i] = -1;
    }

    scanf("%d", &N); // Num de inserções
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        insert(t, M, k);
    }

    scanf("%d", &D); // remoções
    for (int i = 0; i < D; i++) {
        int k;
        scanf("%d", &k);
        remove_key(t, M, k);
    }

    scanf("%d", &B);
    for (int i = 0; i < B; i++) { // buscas
        int k;
        scanf("%d", &k);
        printf("%d ", search(t, M, k));
    }

    free(t);
    return 0;
}

