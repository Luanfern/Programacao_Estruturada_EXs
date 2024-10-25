#include <stdio.h>

int sumDiagonalPrincipal(int matriz[1000][1000], int n){
    int sm = 0;
    for(int i = 0; i < n; i++){
        sm += matriz[i][i];
    }
    return sm;
}

int medDiagonalSuperior(int matriz[1000][1000], int n){
    int ret, sm = 0, qtd = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i){
                sm += matriz[i][j];
                qtd++;
            } else {
                continue;
            }
        }
    }
    ret = sm/qtd;
    return ret;
}

int main(){
        int matriz[1000][1000];
        int n;
        char c = 'M';

        printf("Digite o tamanho da matriz quadrada:\n");
        scanf("%d", &n);

        printf("Inicialização da MATRIZ:\n");
       for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("\nMATRIZ - Digite o valor da posição {%d, %d}:", i+1, j+1);
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("\nDigite a acao \n('S' para Soma dos elementos da diagonal Principal; \n'M' para Média dos elementos que estão acima da diagonal superior ):\n");
        //scanf("%c ", &c);

        printf("\nValor de c: %c", c);

        if(c == 'S'){
            printf("\nSoma da Diagonal Principal: %d", sumDiagonalPrincipal(matriz, n));
        } else if(c == 'M'){
            printf("\nMédia dos Elementos que estão acima da Diagonal Superior: %d", medDiagonalSuperior(matriz, n));
        } else {
            printf("\nAcao Incorreta!\n");
        }

        return 0;
}
