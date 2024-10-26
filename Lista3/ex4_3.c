#include <stdio.h>

void printMatriz(int matriz[20][20], int n, int m){
    printf("\nMATRIZ:");
    printf("\n");
    for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%d ", matriz[i][j]);
            }

            printf("\n");
        }
}

int verificarRaioSete(int matriz[20][20], int n, int m, int posicaoForte[2], int raio){
    int areaVerificacao = 1;
    if(raio < 1)
        return 0;

    for(int mr = 1; mr <= raio; mr++)
        areaVerificacao += 2;

    if(posicaoForte[0]+raio > n || posicaoForte[0]-raio < 0 ||
    posicaoForte[1]+raio > m || posicaoForte[1]-raio < 0){
        return 2;
    }

    int xInicial = posicaoForte[0]-((areaVerificacao-1)/2);
    int yInicial = posicaoForte[1]-((areaVerificacao-1)/2);
    int cercado = 1;
    for(int i = 0; i < areaVerificacao; i++){
        for(int j = 0; j < areaVerificacao; j++){
            if(xInicial+i != posicaoForte[0] && yInicial+j != posicaoForte[1]){
                if(matriz[xInicial+i][yInicial+j] != 7){
                    cercado = 0;
                    break;
                }
            }
            if(cercado == 0){
                break;
            }
        }
        if(cercado == 0){
            break;
        }
    }
    return cercado;

}

int main(){
        int matriz[20][20];
        int n, m;

        printf("Digite a quantidade de Linhas:\n");
        scanf("%d", &n);

        printf("Digite a quantidade de Colunas:\n");
        scanf("%d", &m);

        if((m > 20 || m < 1) || (n > 20 || n < 1)){
            printf("Matriz deve ter duas dimensões entre 1 e 20 para linhas e colunas.");
            return 0;
        }

        printf("Inicialização da MATRIZ:\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("\n MATRIZ - Digite o valor da posição {%d, %d}:", i+1, j+1);
                scanf("%d", &matriz[i][j]);
            }
        }

        printMatriz(matriz, n, m);

        //Procurando por 42 (Sinal forte)
        int encontrados = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matriz[i][j] == 42){
                    int currentCoord[2];
                    currentCoord[0]= i;
                    currentCoord[1]= j;
                    int raios = verificarRaioSete(matriz, n, m, currentCoord, 1);
                    if(raios == 1){
                        encontrados++;
                        printf("\n________________________\n");
                        printf("|         %dº           |\n", encontrados);
                        printf("|   Sabre Encontrado!  |\n");
                        printf("|                      |\n");
                        printf("|    - Coordenadas:    |\n");
                        printf("|        X: %d          |\n", i+1);
                        printf("|        Y: %d          |\n", j+1);
                        printf("|                      |\n");
                        printf("|                      |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|         |||          |\n");
                        printf("|      =========       |\n");
                        printf("|     ||       ||      |\n");
                        printf("|     ||  o o  ||      |\n");
                        printf("|     ||-------||      |\n");
                        printf("|     ||       ||      |\n");
                        printf("|     ||   o   ||      |\n");
                        printf("|     ||_______||      |\n");
                        printf("|     |_________|      |\n");
                        printf("|______________________|\n");
                    } else if(raios == 2){
                        printf("\n| ATENÇÃO: RAIO DE BUSCA DESREGULADO! |\n");
                    }
                }
            }
        }

        if(encontrados == 0){
            printf("\n| REPORT: NENHUM SABRE DE LUZ FOI ENCONTRADO NESSA ÁREA! |\n");
        }

        return 0;
}
