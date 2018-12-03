#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int quantity;       //Criação de uma estrutura tendo em vista a facilitação da adição
    char type[9];       //de novos ficherios de stock e adiciona-los com mais facilidade
    double price;
}stockExistente[6];
typedef struct{
    char brand[9];
    char status[11];
    char place;
    unsigned short timeLeft;
    char op[3]; //operação
}car[300];

void build(){

}
void addStock(){
    fflush(stdin); //Limpar Buffer de Input
    FILE *stockFile;
    FILE *additionalFile;

    char adicionarStock[100];
    char linha_novo_stock;

    printf("Por favor introduza o nome do ficheiro incluindo o \".txt\"\n");
    gets(adicionarStock);

    stockFile = fopen(adicionarStock, "r");
    additionalFile = fopen("stock.txt", "rw");

    if(additionalFile == NULL){
        printf("Erro na leitura do ficheiro.\n");
    }
    fclose(additionalFile);
    fclose(stockFile);
}
void showStock(){
    int id;
    char type[9];
    double price;
    double totalPreco = 0;
    stockExistente stock;

    //Abrir o ficheiro
    FILE *fp;
    fp = fopen("stock.txt", "r");
    if(fp == NULL){         //Verificar se o ficheiro existe
        printf("Erro na leitura do ficheiro.\n");
    }
    for (int i=0; i<6; i++){
        stock[i].quantity = 0;
        stock[i].price = 0.0;   //Dar reset a quantidade da estrutura
    }
    while(fscanf(fp, "%d %s %lf", &id, type, &price)!=EOF){     //Ler o Ficheiro
        printf("%d  %s  %.2lf\n", id, type, price);

        strcpy(stock[id-1].type, type);    //copiar o nome do tipo para a estrutura
        stock[id-1].quantity++;    //Adicinar a quantidade de material dependendo do tipo à estrutura
        stock[id-1].price += price;    //Adicionar o preço total à estrutura
    }

    printf("\n");

    for (int i=0; i<6; i++){
        totalPreco += stock[i].price;  //Preço total do stock a apresentar
        printf("Existem %d materiais de %s com um valor de %.2f\n", stock[i].quantity, stock[i].type, stock[i].price);      //Imprimir a soma dos materiais e o respetivo tipo
    }

    printf("\nO valor total do stock e: %.2lf\n\n", totalPreco);
    fclose(fp);

    /*system(" PAUSE "); // Esperar por input do utilizador
    menu();*/
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
            addStock();
            break;
        case '3':
            build();
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
            /*system(" PAUSE ");
            menu();*/
            break;
    }
    system(" PAUSE "); // Esperar por input do utilizador
    menu();
}


int main()
{
    char brand[9], status[11], place, op[3];
    unsigned short timeLeft = 0;

    car cars;
    FILE *fp;
    int i;
    for(i = 0; i<20; i++){
        cars[i].brand;
        cars[i].status;
        cars[i].place = '-';
        cars[i].timeLeft = 0;
        cars[i].op;
        strcpy(cars[i].brand, "\0");
        strcpy(cars[i].status, "Waiting\0");
        strcpy(cars[i].op, "---\0");
    }

    fp = fopen("processing.txt", "r");
    if(fp == NULL){         //Verificar se o ficheiro existe
        printf("Erro na leitura do ficheiro.\n");
    }
    i = 0;

    while(fscanf(fp, "%s %s %c %hu %c%c%c", &cars[i].brand, &cars[i].status, &cars[i].place, &cars[i].timeLeft, &cars[i].op[0], &cars[i].op[1], &cars[i].op[2])!=EOF){     //Ler o Ficheiro
            printf("%s %s %c %hu %s\n", cars[i].brand, cars[i].status, cars[i].place, cars[i].timeLeft, cars[i].op);
            i++;
        }
    fclose(fp);
    system(" PAUSE ");


    menu();
}
