#include <stdio.h>
#include <stdlib.h>
int t_shell=0;
int t_quck=0;

void shell(int v[], int n) {
    int gap = 1;

    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;

    while(gap > 0) { 
        for (int i = gap; i < n; i++){
            int x = v[i];
            int j = i - gap;
            t_shell++;
            while(j >= 0 && v[j] > x) {
                t_shell++;
                v[j + gap] = v[j];
                j -= gap;
                t_shell++;
            }
            if (j >= 0) {
                t_shell++;
            }
            v[j + gap] = x;
            t_shell++;                
        }
        gap /= 2;
    }
}


void quick(int v[], int f, int l) {
    if (f >= l) {
        return;
    }

    int m = (l + f)/2;
    int pivot = v[m];
    int i = f;
    int j = l;
    t_quck ++;
   
    while(1) {
        while(v[i] < pivot) {
            i++;
            t_quck ++; 
        }
        t_quck ++;
        while(v[j] > pivot) {
            j--;
            t_quck ++; 
        }
        t_quck ++;
        if (i >= j) {
            break;
        }

        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        i++;
        j--;
        t_quck = t_quck + 3;   
    }
    quick(v, f, j);
    quick(v, j+1, l);
   
    
}


int main (){
    int N;
    scanf("%i", &N);
    int vet[N];
    for (int i = 0; i < N; i++) {
        scanf("%i", &vet[i]);
    }

    int sub_vets[N][N];
    int sub_vetq[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sub_vets[i][j] = vet[j];
            sub_vetq[i][j] = vet[j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        t_shell=0;
        t_quck=0;
        shell(sub_vets[i], i + 1);
        quick(sub_vetq[i], 0, i);
        if (t_quck > t_shell) {
            printf("S");
        }
        else if (t_shell > t_quck) {
            printf("Q");
        }
        else {
            printf("-");
        }
    }
    
}
