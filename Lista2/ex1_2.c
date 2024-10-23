#include <stdio.h>

int busca(int valores[], int n, int chave){
        int ret;
        for(int i=0; i < n; i++){
                if(valores[i] == chave){
                        ret = i;
                }
        }
        return ret;
}

int main(){
        int valores[1000];
        int n, chave;

        printf("Digite o tamanho da lista:\n");
        scanf("%d", &n);

        printf("Digite o valor da CHAVE:\n");
        scanf("%d", &chave);

        for(int i = 0; i < n; i++){
                printf("\nDigite o valor %dº da lista:", i+1);
                scanf("%d", &valores[i]);
        }

        printf("\nValor da chave na posição %d da lista.", busca(valores, n, chave));

        return 0;
}