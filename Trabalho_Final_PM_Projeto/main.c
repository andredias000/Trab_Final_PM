#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int quantity;       //Cria��o de uma estrutura tendo em vista a facilita��o da adi��o
    char type[9];       //de novos ficherios de stock e adiciona-los com mais facilidade
    double Totalprice;
    double price;
}stockExistente;

typedef struct{
    char brand[9];
    char status[11];
    char place;
    unsigned short timeLeft;
    char op[3]; //opera��o
}car;

typedef struct{
    int id;
    char ops[3];
    int time[3];
    double cost;
    int totalTime;
}station;
/*
Pedir ajuda sobre a estrutura do ficheiro dat
Pedir ajuda sobre o suposto tamanho do ficheiro dat (21bytes por cada estacao estimativa).
*/
void stationsDat(car *cars, int machine[5], station *stations){
    FILE *station;

    station = fopen("stations.dat", "rb");

    fclose(station);
}
void processingTxt(car *cars, int machine[5]){

    FILE *fp;
    int i;
    for(i = 0; i<20; i++){
        cars[i].place = '-';
        cars[i].timeLeft = 0;
        strcpy(cars[i].brand, "\0");
        strcpy(cars[i].status, "Waiting\0");
        strcpy(cars[i].op, "---\0");
    }

    fp = fopen("processing.txt", "r");
    if(fp == NULL){         //Verificar se o ficheiro existe
        printf("Erro na leitura do ficheiro processing.\n");
    }
    i = 0;

    while(fscanf(fp, "%s %s %c %hu %c%c%c", &cars[i].brand, &cars[i].status, &cars[i].place, &cars[i].timeLeft, &cars[i].op[0], &cars[i].op[1], &cars[i].op[2])!=EOF){     //Ler o Ficheiro
            if (cars[i].place != 0){
                machine[cars[i].place - 1] = 1;
            }
            i++;
    }
    fclose(fp);

}

void statistics(){

    printf("\n***State Chart***\n\n\n");
    printf("Processing: ");

    for(int i = 0; i<5; i++){ //VALORES DE TESTE!!
        printf("*");
    }
    printf("\n");

    printf("Waiting:    ");

    for(int i = 0; i<5; i++){   //VALORES DE TESTE!!
        printf("*");
    }
    printf("\n");

    printf("Finished:   ");

    for(int i = 0; i<5; i++){   //VALORES DE TESTE!!
        printf("*");
    }
    printf("\n");

}
void factoryState(){

    printf("Estado Atual das Maquinas:\n\n");
    printf("  1           2           3           4           5");
    printf("\n");
    printf(" ---         ---         ---         ---         ---");
    printf("\n");
    printf("|   |       |   |       |   |       |   |       |   |");
    printf("\n");
    printf(" ---         ---         ---         ---         ---");
    printf("\n");

}

void materialVerification(stockExistente *stock, car *cars, int machine[5]){

    int option = 0;

    printf("Qual o tipo de carro que deseja produzir?\n");
    printf("1 - Renault\n");
    printf("2 - Mercedes\n");
    printf("3 - Honda\n");
    printf("4 - Ford\n");
    printf("5 - Ferrari\n");
    scanf(" %d", &option);

    switch(option){
        case 1:
            if(stock[0].quantity >= 2 && stock[2].quantity >= 1 && stock[3].quantity >= 3){
                printf("Existem materiais suficientes para a construcao do Renault.\n");
                printf("Vai se proceder a remocao dos materiais necessarios a criacao de um Renault (2-Ferro, 1-Vidro, 3-Plastico)\n");
                stock[0].quantity = stock[0].quantity - 2;
                stock[2].quantity--;
                stock[3].quantity = stock[3].quantity - 3;
            }
            else{
                printf("\n\nErro, nao existem materiais suficientes.");
            }
            break;
        case 2:
            if(stock[1].quantity >= 3 && stock[2].quantity >= 2 && stock[5].quantity >= 2){
                printf("Existem materiais suficientes para a construcao do Mercedes.\n");
                printf("Vai se proceder a remocao dos materiais necessarios a criacao de um Mercedes (3-Aluminio, 2-Vidro, 2-Aco)\n");
                stock[1].quantity = stock[1].quantity - 3;
                stock[2].quantity = stock[2].quantity - 2;
                stock[5].quantity = stock[5].quantity - 2;
            }
            else{
                printf("\n\nErro, nao existem materiais suficientes.");
            }
            break;
        case 3:
            if(stock[0].quantity >= 4 && stock[2].quantity >= 1 && stock[3].quantity >= 3 && stock[4].quantity >= 2){
                printf("Existem materiais suficientes para a construcao do Honda.\n");
                printf("Vai se proceder a remocao dos materiais necessarios a criacao de um Honda (4-Ferro, 1-Vidro, 3-Plastico, 2-Borracha)\n");
                stock[0].quantity = stock[0].quantity - 4;
                stock[2].quantity--;
                stock[3].quantity = stock[3].quantity - 3;
                stock[4].quantity = stock[4].quantity - 2;
            }
            else{
                printf("\n\nErro, nao existem materiais suficientes.");
            }
            break;
        case 4:
            if(stock[1].quantity >= 1 && stock[2].quantity >= 2 && stock[3].quantity >= 3 && stock[4].quantity >= 1 && stock[5].quantity >= 3){
                printf("Existem materiais suficientes para a construcao do Ford.\n");
                printf("Vai se proceder a remocao dos materiais necessarios a criacao de um Ford (1-Aluminio, 2-Vidro, 3-Plastico, 1-Borracha, 3-Aco)\n");
                stock[1].quantity--;
                stock[2].quantity = stock[2].quantity - 2;
                stock[3].quantity = stock[3].quantity - 3;
                stock[4].quantity--;
                stock[5].quantity = stock[5].quantity - 3;
            }
            else{
                printf("\n\nErro, nao existem materiais suficientes.");
            }
            break;
        case 5:
            if(stock[0].quantity >= 2 && stock[1].quantity >= 2 && stock[2].quantity >= 3 && stock[5].quantity >= 2){
                printf("Existem materiais suficientes para a construcao do Ferrari.\n");
                printf("Vai se proceder a remocao dos materiais necessarios a criacao de um Ferrari (2-Ferro, 1-Aluminio, 3-Vidro, 2-Aco)\n");
                stock[0].quantity = stock[0].quantity - 2;
                stock[1].quantity = stock[1].quantity - 2;
                stock[2].quantity = stock[2].quantity - 3;
                stock[5].quantity = stock[5].quantity - 2;
            }
            else{
                printf("\n\nErro, nao existem materiais suficientes.");
            }
            break;
    }
}

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
        stock[id-1].quantity++;    //Adicinar a quantidade de material dependendo do tipo � estrutura
        stock[id-1].Totalprice += price;    //Adicionar o pre�o total � estrutura
        stock[id-1].price = price;
    }
    fclose(fp);
}

void showStock(stockExistente *stock){
    double totalPreco = 0;

    for (int i=0; i<6; i++){
        stock[i].Totalprice = stock[i].price*stock[i].quantity;
        totalPreco += stock[i].Totalprice;  //Pre�o total do stock a apresentar
        printf("Existem %d materiais de %s com um valor de %.2f\n", stock[i].quantity, stock[i].type, stock[i].Totalprice);      //Imprimir a soma dos materiais e o respetivo tipo
    }
    printf("\n");
    printf("\nO valor total do stock e: %.2lf\n\n", totalPreco);
}

void initializeStructure(stockExistente *stock){
    for (int i=0; i<6; i++){
        stock[i].quantity = 0;
        stock[i].price = 0.0;
        stock[i].Totalprice = 0.0;   //Dar reset a quantidade da estrutura
    }
}

void writeToStock(stockExistente *stock){
    FILE *estoke;

    estoke = fopen("novoStock.txt", "w");

    for(int i=0; i<6; i++){
        fprintf(estoke, "Existem %d materiais de %s com um valor de %.2f", stock[i].quantity, stock[i].type, stock[i].Totalprice);
        fputs("\n", estoke);
    }

    fclose(estoke);
}

//Establish menu
void menu(stockExistente *stock, car *cars, int machine[5]){
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
            materialVerification(stock, cars, machine);
            break;
        case '4':
            factoryState();
            break;
        case '5':
            statistics();
            break;
        case '6':
            break;
        case 'S':
            printf("Obrigado por usar o nosso programa :D. \nRealizado por Ricardo Monteiro (55541) e Andre Dias (55815)\n\n");
            system(" PAUSE ");
            writeToStock(stock);
            exit(1);
            break;
        case 's':
            printf("Obrigado por usar o nosso programa :D. \nRealizado por Ricardo Monteiro (55541) e Andre Dias (55815)\n\n");
            system(" PAUSE ");
            writeToStock(stock);
            exit(1);
            break;
        default:
            printf("Opcao Invalida.\n");
            break;
    }
    system(" PAUSE "); // Esperar por input do utilizador
    menu(stock, cars, machine);
}


int main()
{
    stockExistente stock[6];
    car cars[300];
    station stations[5];
    /*char brand[9], status[11], place, op[3];
    unsigned short timeLeft = 0;*/
    int machine[5] = {0};

    initializeStructure(stock);     //Zona de inicializa��o do stock
    addStock(stock, "stock.txt");      //Zona de adi��o do add Stock


    stationsDat(cars, machine, stations); //ler o ficheiro binario e colocar numa estrutura
    processingTxt(cars, machine); //por o ficheiro processing numa estrutura
    menu(stock, cars, machine);
}
