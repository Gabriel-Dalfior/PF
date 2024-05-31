#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int MR(char matriz[6][5]);


int main(){

    int selecao;
    FILE *file;
    char mapa[25], matriz[6][5];  
    int numero, x=0, cont;

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
                printf("\n");
                srand(time(NULL));
                for(cont=1; cont<=5; cont++){
                    for(x=0; x<=5; x++){
                        numero=rand()%3; //vai mandar numeros aleatorios até 2
                        if(x==5){
                            matriz[x][cont] = '\n';
                            printf("\n");//printf somente para vizualização
                        }
                        else{
                            if(numero==0 || numero==1){
                                matriz[x][cont] = '0';
                                printf("%c ", matriz[x][cont]);//printf somente para vizualização
                            }
                            else if(numero==2){
                                matriz[x][cont] = '1';
                                printf("%c ", matriz[x][cont]);//printf somente para vizualização
                            }
                        }
                    }
                }
                printf("\n----------------------------------\n");
                
                    x=rand()%5;
                    cont=rand()%5;
                    matriz[x][cont] = '7';
                    for(;matriz[x][cont] == '7';){
                        x=rand()%5;
                        cont=rand()%5;
                    }
                    matriz[x][cont] = '9';

                for(cont=1; cont<=5; cont++){
                    for(x=0; x<=5; x++){
                        if(x==5 && cont==5)
                            break;
                        if(x!=5){
                            printf("%c ", matriz[x][cont]);
                        }
                        else
                           printf("%c", matriz[x][cont]); 
                    }
                }

                break;

            case 4:

                break;

            case 5:
                MR(matriz[6][5]);
                fclose(file); // funcao para fechar arquivo .txt
                break;

            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }

    return 0;
}

int MU(char matriz[30]){

}
int MD (char matriz[30]){

}
int MR(char matriz[6][5]){
    int cont;
    int x;
    for(cont=0; cont<=5; cont++){
        for(x=0; x<6; x++){
            if(matriz[x][cont]=='7'){
                printf("\no rato esta na posicao (%i,%i)\n", x, cont);
                break;
            }
        }
    }
    if(x!=5){
        x++;
        matriz[x][cont] = '7';
        x--;
        matriz[x][cont] = '0';
    }
    for(cont=1; cont<=4; cont++){
        for(x=1; x<=5; x++){
            if(x==5){
                printf("\n");
                if(cont==5)
                    break;
            }
            printf("%c ", matriz[x][cont]);
        }
    }
}
int ML(char matriz[30]){

}
int verif(char matriz[30]){

}