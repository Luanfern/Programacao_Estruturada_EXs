#include <stdio.h>

void printMatriz(int matriz[101][101], int n, int m){
    printf("\nMATRIZ:");
    printf("\n");
    for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%d ", matriz[i][j]);
            }

            printf("\n");
        }
}

int main(){
        int matriz[101][101];
        int n, r, c, cp;

        printf("Digite a ordem da matriz quadrada (entre 1 e 100):\n");
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matriz[i][j] = 0;
            }
        }

        if(n%2 == 0){
            c = n / 2;
            cp = c+1; 
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    matriz[c+i-1][c+j-1] = c;
                    //printf("%d, %d\n", c+i-1, c+j-1);
                }
            }
        } else {
            c = ((n-1) / 2)+1;
            cp = c;
            matriz[c-1][cp-1] = c;
            //printf("%d, %d\n", c-1, cp-1);
        }

        int nmmi = c-2;
        int nmma = cp;
        for(int k = c-1; k > 0; k--){
            for(int i = nmmi; i <= nmma; i++){
                for(int j = nmmi; j <= nmma; j++){
                    if(matriz[i][j] == 0){
                        //printf("%d, %d: %d\n", i, j, k);
                        matriz[i][j] = k;
                    }
                }
            }
            nmmi--;
            nmma++;
        }

        printf("MATRIZ:\n");
        printMatriz(matriz, n, n);

        return 0;
}
