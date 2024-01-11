#include <stdio.h>
#include <stdlib.h>

int c_merge;
int t_merge;

void insertion_sort(int *vet, int n)
{
    /* alg vars */
    int i, key, j;
    /* problem vars vars */
    int c, t;
    c =  0;
    t = 0;

    for (i = 1; i < n; i++) {
        key = vet[i];
        t++;
        j = i - 1;

        while (j >= 0 && ++c && (vet[j] > key)) {
            vet[j + 1] = vet[j];
            t++;
            j = j - 1;
        }
        vet[j + 1] = key;
        t++;
    }

    printf("I %d %d %d\n", n, t, c);
}

void merge(int *vet, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = vet[l + i];
        t_merge++;
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = vet[m + 1 + j];
        t_merge++;
    }


    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (++c_merge && L[i] <= R[j]) {
            vet[k] = L[i];
            t_merge++;
            i++;
        }
        else {
            vet[k] = R[j];
            t_merge++;
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        vet[k] = L[i];
        t_merge++;
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        vet[k] = R[j];
        t_merge++;
        j++;
        k++;
    }
}

void mergeSort(int *vet, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(vet, l, m);
        mergeSort(vet, m + 1, r);

        merge(vet, l, m, r);
    }
}


void print_vectors(int total_vet, int *vet_tam, int **vets) {
    // Print vectors
    for (int i = 0; i < total_vet; i++) {
        printf("\nvector %d:\n", i+1);
        for (int j = 0; j < vet_tam[i]; j++){
            printf("%d ", vets[i][j]);
        }
    }
}

int main(){
    int total_vet;
    int **vets, *vet_tam;
    int **vets2;

    scanf("%d", &total_vet);

    // alloc memory
    vets = (int**)malloc(total_vet * sizeof(int*));
    vet_tam = (int*)malloc(total_vet * sizeof(int));
    //copy vector
    vets2 = (int**)malloc(total_vet * sizeof(int*));

    // Define vector sizes and allocate memory for each vector
    for (int i = 0; i < total_vet; i++) {
        scanf("%d", &vet_tam[i]);
        // allocate memory for each vector
        vets[i] = (int*)malloc(vet_tam[i] * sizeof(int));
        // allocate memory for each copy vector
        vets2[i] = (int*)malloc(vet_tam[i] * sizeof(int));
    }

    // Add elements in each vector
    for (int i = 0; i < total_vet; i++) {
        for (int j = 0; j < vet_tam[i]; j++){
            scanf("%d", &vets[i][j]);
            //copy vector
            vets2[i][j] = vets[i][j];
        }
    }

    // sort vectors
    for (int i = 0; i < total_vet; i++) {
        insertion_sort(vets[i], vet_tam[i]);
        // we use global vars to count
        // comparison and swaps
        c_merge = 0; //comparison
        t_merge = 0; // swaps
        mergeSort(vets2[i], 0, vet_tam[i] -1);
        printf("M %d %d %d\n", vet_tam[i], t_merge, c_merge);
    }

    // Print vectors
    //print_vectors(total_vectors, vector_sizes, vectors);

    // freeing
    free(vet_tam);

    for (int i = 0; i < total_vet; i++) {
        free(vets[i]);
        free(vets2[i]);
    }

    free(vets);
    free(vets2);

    return 0;
}
