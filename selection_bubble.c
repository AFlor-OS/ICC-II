#include <stdio.h>
#include <string.h>

void bolha(int a[], int n){
    int temp;
    int cont;
    for(int i = n-1; i>=1; i= cont){
        cont = 0;
        for(int j = 0; j<i; j++){
            printf("C %d %d\n", j, j+1);
            if(a[j]>a[j+1]){
                printf("T %d %d\n", j, j+1);
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                cont = j;
            }
            
        }
    }
    //return a[n];
}

void selecao(int a[], int n){
    for(int i=0; i<n-1; i++){
        int m=i;
        for(int j=i+1; j<n ; j++){
            printf("C %d %d\n", m, j);
            if(a[j]<a[m]){
                m=j; 
            }       
        }
        if(m!=i){
            printf("T %d %d\n", i, m);
        }
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
    //return a[n];
}

int main(){
    char nome[10];
    int tam;

    scanf("%s", nome);
    scanf("%d", &tam);


    int vet[tam];

    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }

    if(strcmp(nome, "bolha")== 0){
        bolha(vet, tam);
    }
    if(strcmp(nome, "selecao")== 0){
        selecao(vet, tam);
    }

    
    for(int i=0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
    

    return 0;

}
