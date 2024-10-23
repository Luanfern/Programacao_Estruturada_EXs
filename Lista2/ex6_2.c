#include <stdio.h>

int main(){
        int vA[1000][1000];
        int n, m;

        printf("Digite a quantidade de Linhas::\n");
        scanf("%d", &n);

        printf("Digite o quantidade de Colunas:\n");
        scanf("%d", &m);

        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        printf("\nMATRIZ A - Digite o valor da posição {%d, %d}:", i+1, j+1);
                        scanf("%d", &vA[i][j]);
                }
        }

        int ns = 0;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(vA[i][j] != vA[j][i]){
                                ns = 1;
                                break;
                        }
                }
        }

        if(ns == 0){
                printf("Simetrica");
        } else {
                printf("Nao Simetrica");
        }

        return 0;
}
