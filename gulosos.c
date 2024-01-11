


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void combina(char *r01, char*r02, int ovlp, char *rNova);//concatena
void removerR(char **read, int max01, int max02, char *rNova, int N);
//void remove(char **read, int max01, int max02, char *rNova, int N);
int sobreposicao(char *r01, char *r02); //retorna overlap/sobreposicoes entre as reads

int sobreposicao(char *r01, char *r02) {
    int a,b;
    int ovlp = 0; //overlap/sobreposicao
    a = strlen(r01);
    b = strlen(r02);


    if(r01[a - 1] == r02[0] && b == 1) { 
        ovlp = 1;
        return ovlp;
    }

    if (strstr(r01, r02) != NULL) { //r02 está na r01?
        ovlp = b;
        return ovlp;
    }
    //overlap ta na última letra
    if (r01[a - 1] == r02[0] && r01[a - 2] != r02[1]) {
        ovlp = 1;
        return ovlp;
    }
    
    int j = 0;
    for (int i = 0; i < a && j < b; i++) {
        if (r01[i] == r02[j]) {
            ovlp++;
            j++;
        }
        else {  //letra diferente
            i = i - ovlp; 
            ovlp = 0;    
            j = 0;
        }
    }
    return ovlp;
}


void combina(char *r01, char*r02, int ovlp, char *rNova) {
    if (ovlp == 0) { //tem sopreposição,
        strcpy(rNova,r01); 
        strcat(rNova,r02); //concatenando 
    } 
    else if (ovlp == strlen(r02)) { //read2 é subtring da read1 ou sao iguais
        strcpy(rNova, r01);
    }
    else { 
        strcpy(rNova,r01);
        for (int i = ovlp; i < strlen(r02); i++) {
            int t = strlen(rNova);
            rNova[t] = r02[i];
            rNova[t + 1] = '\0';
        }
    }
}
void removerR(char **read, int max01, int max02, char *rNova, int N) {

        for (int i = max01; i < N - 1; i++) {
            strcpy(read[i], read[i + 1]); //remove 
        }
        int k;
        //verificar a posição do max1 
        if (max01 < max02)
            k = 1;      
        else 
            k = 0;

        for (int i = max02 - k; i < N - 2; i++) { //remove 
            strcpy(read[i], read[i + 1]);
        }
        //desloca
        for (int i = N - 2; i >= 1; i--) {
            strcpy(read[i], read[i - 1]);
        }
        strcpy(read[0], rNova);
}


int main() {

    char **read;
    char *rNova;
    int N;
    int max01,max02,ovlpmax = -1;
    int ovlpC;

    rNova = (char *)malloc(200 * sizeof(char ));
    scanf("%d", &N);
    read = (char **)malloc(N * sizeof(char *)); 
    for(int i = 0; i < N; i++) {

        read[i] = malloc(200 * sizeof(char)); 
        scanf("%s", read[i]);
    }
    while (N >= 2) {
         for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    ovlpC = sobreposicao(read[i], read[j]);
                    if (ovlpC > ovlpmax)
                    {
                        ovlpmax = ovlpC;
                        max01 = i;
                        max02 = j;
                    }
                }
            }
        }
    combina(read[max01],read[max02],ovlpmax,rNova);
    if (N > 2) {
        removerR(read,max01,max02,rNova,N);
    }
    N--;
    ovlpmax = -1;
    }
    printf("%s", rNova); 
    for (int i = 0; i < N; i++) {
        free(read[i]);
    }
    free(read);
    return 0;
}
    
