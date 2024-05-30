#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int selecao;
    FILE *file;
    char mapa[25], matriz[28];  
    int numero, x=0;

    printf("\nBem vindo ao Encontre o Queijo\n");

    for(selecao=-1;selecao!=0;){
        printf("\n--------menu---------\n");
        printf("\nPrecione a tecla referente a opcao desejada:\n");
        printf("1- Importar mapa\n2- Apresentar mapa\n3- Gerar mapa aleatorio\n4- Verificar viabiliadade do mapa\n5- iniciar o jogo\n0- SAIR\n");
        scanf("%d", &selecao);

        switch(selecao){
            case 0:
                printf("\nSaindo do Programa\n");
                //sleep(1);
                return 0;
            case 1:
                file = fopen("mapa.txt", "r");//arquivo .txt deve estar no mesmo diretorio que o arquivo .c esta sendo compilado
                if(file==NULL){
                    printf("\nO arquivo nao pode ser aberto\n");
                    break;
                }
                break;
            case 2:
                for(;fgets(mapa, 25, file) != NULL;){//fgets age como scanf para pegar a string de .txt
                    printf("\n%s\n", mapa);
                }
                break;

            case 3:
                srand(time(NULL));
                for(int cont=1; cont<=5; cont++){
                    for(; strlen(matriz) <= 25; x++ ){
                        numero=rand()%3; //vai mandar numeros aleatorios até 2
                        if(cont*x%5==0){
                            matriz[x] = '\n';
                            printf("\n");
                        }
                        if(numero==0 || numero==1){
                            matriz[x] = '0';
                            printf("%c ", matriz[x]);
                        }
                        else if(numero==2){
                            matriz[x] = '1';
                            printf("%c ", matriz[x]);
                        }
                    }
                }
                numero=rand()%25;
                matriz[numero] = '7';
                
                numero=rand()%25;
                matriz[numero] = '9';
                
                for(int cont=1; cont<=5; cont++){
                    for(x=1; strlen(matriz) <= 25; x++ ){
                        if(cont*x%5==0){
                            matriz[x] = '\n';
                            printf("\n");
                        }
                            printf("%c ", matriz[x]);
                    }
                }
                break;

            case 4:
                break;

            case 5:
                fclose(file); // funcao para fechar arquivo .txt
                break;

            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }

    return 0;
}

int MU(){

}
int MD (){

}
int MR(){

}
int ML(){

}
int verif(){

}