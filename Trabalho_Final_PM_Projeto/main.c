#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showStock(){
    int id;
    char type[9];
    double price;
    int totalMateriais[6] = {0};
    double totalPreco = 0;
    char materiais[6][9];

    //Abrir o ficheiro
    FILE *fp;
    fp = fopen("stock.txt", "r");
    if(fp == NULL){         //Verificar se o ficheiro existe
        printf("Ficheiro Nao lido.\n");
    }
    while(fscanf(fp, "%d %s %lf", &id, type, &price)!=EOF){     //Ler o Ficheiro
        printf("%d  %s  %.2lf\n", id, type, price);

        totalMateriais[id-1]++;
        totalPreco += price;
        strcpy(materiais[id-1], type);
    }

    printf("\n");

    for (int i=0; i<6; i++){
        printf("Existem %d materiais de %s\n", totalMateriais[i], materiais[i]);      //Imprimir a soma dos materiais e o respetivo tipo
    }

    printf("\nO valor total do stock e: %.2lf\n\n", totalPreco);
    fclose(fp);

    system(" PAUSE "); // Esperar por input do utilizador
    menu();
}


//Establish menu
void menu(){
    system("@cls||clear"); //Limpar o ecra
    char opcao=' ';

    printf("    ****Menu de Administrador da Fabrica****\n");
    printf("\n  1 - Mostrar Stock\n");
    printf("  2 - Aumentar Stock\n");
    printf("  3 - Construir Carro\n");
    printf("  4 - Estado da Fabrica\n");
    printf("  5 - Estatisticas\n");
    printf("  6 - Passar Tempo\n");
    printf("  S - Sair\n");
    printf("\nOption: ");
    scanf(" %c", &opcao);

    switch(opcao){
        case '1':
            showStock();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case 'S':
            printf("Obrigado por usar o nosso programa :D\n\n");
            system(" PAUSE ");
            exit(1);
            break;
        case 's':
            printf("Obrigado por usar o nosso programa :D\n\n");
            system(" PAUSE ");
            exit(1);
            break;
        default:
            printf("Opcao Invalida.\n");
            system(" PAUSE ");
            menu();
            break;
    }
}


int main()
{

    menu();
}
