#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int quantity;       //Criação de uma estrutura tendo em vista a facilitação da adição
    char type[9];       //de novos ficherios de stock e adiciona-los com mais facilidade
    double price;
}stockExistente;

void addStock(stockExistente *stock, char fileName[30]){
    int id;
    char type[9];
    double price;

    //Abrir o ficheiro
    FILE *fp;
    fp = fopen(fileName, "r");
    if(fp == NULL){         //Verificar se o ficheiro existe
        printf("Erro na leitura do ficheiro.\n");
    }

    while(fscanf(fp, "%d %s %lf", &id, type, &price)!=EOF){     //Ler o Ficheiro
        strcpy(stock[id-1].type, type);    //copiar o nome do tipo para a estrutura
        stock[id-1].quantity++;    //Adicinar a quantidade de material dependendo do tipo à estrutura
        stock[id-1].price += price;    //Adicionar o preço total à estrutura
    }
    fclose(fp);
}

void showStock(stockExistente *stock){
    double totalPreco = 0;

    for (int i=0; i<6; i++){
        totalPreco += stock[i].price;  //Preço total do stock a apresentar
        printf("Existem %d materiais de %s com um valor de %.2f\n", stock[i].quantity, stock[i].type, stock[i].price);      //Imprimir a soma dos materiais e o respetivo tipo
    }
    printf("\n");
    printf("\nO valor total do stock e: %.2lf\n\n", totalPreco);
}

void initializeStructure(stockExistente *stock){
    for (int i=0; i<6; i++){
        stock[i].quantity = 0;
        stock[i].price = 0.0;   //Dar reset a quantidade da estrutura
    }
}

//Establish menu
void menu(stockExistente *stock){
    system("@cls||clear"); //Limpar o ecra
    char opcao=' ';
    char fileName[30];

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
            showStock(stock);
            break;
        case '2':
            fflush(stdin);
            printf("Por favor introduza o nome do ficheiro que quer adicionar ao stock, incluindo o  .txt:\n");
            gets(fileName);
            addStock(stock, fileName);
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
            printf("Obrigado por usar o nosso programa :D. \nRealizado por Ricardo Monteiro (55541) e Andre Dias (55815)\n\n");
            system(" PAUSE ");
            exit(1);
            break;
        case 's':
            printf("Obrigado por usar o nosso programa :D. \nRealizado por Ricardo Monteiro (55541) e Andre Dias (55815)\n\n");
            system(" PAUSE ");
            exit(1);
            break;
        default:
            printf("Opcao Invalida.\n");
            break;
    }
    system(" PAUSE "); // Esperar por input do utilizador
    menu(stock);
}


int main()
{
    stockExistente stock[6];
    initializeStructure(stock);     //Zona de inicialização do stock
    addStock(stock, "stock.txt");      //Zona de adição do add Stock

    menu(stock);
}
