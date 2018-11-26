#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showStock(){
    int id;
    char type[9];
    double price;
    char input[255];

    FILE *fp;
    fp = fopen("stock.txt", "r");
    if(fp == NULL){
        printf("Ficheiro Nao lido.\n");
    }
    while(fscanf(fp, "%d %s %lf", &id, type, &price)!=EOF){
        printf("%d  %s  %.2lf\n", id, type, price);
    }
    /*while(fgets(input,255,fp) != NULL){
            sscanf(input, "%d %s %.2lf\n", &id, type, &price);
            printf("%d  %s  %.2lf\n", id, type, price);
        //printf("%d  %s  %.2lf\n", id, type, price);
    }*/
    fclose(fp);
}


//Establish menu
void menu(){
    char opcao=' ';

    printf("    ****Factory Admin Menu****\n");
    printf("\n  1 - Show Stock\n");
    printf("  2 - Refill Stock\n");
    printf("  3 - Build Car\n");
    printf("  4 - Factory State\n");
    printf("  5 - Statistics\n");
    printf("  6 - Time Skip\n");
    printf("  E - Exit\n");
    printf("\nOption: ");
    scanf(" %c", &opcao);

    switch(opcao){
        case '1':
            showStock();
    }
}


int main()
{

    menu();
}
