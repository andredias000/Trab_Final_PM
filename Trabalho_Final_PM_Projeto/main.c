#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showStock(){
    char id;
    char type[8];
    double price;

    FILE *fp;
    fp = fopen("stock.txt", "r");
    if(fp == NULL){
        printf("Ficheiro Vazio.\n");
    }
    while(fscanf(fp, "%c %s %lf\n", &id, &type, &price)!=EOF){
        printf("%c  %s  %lf\n", id, type, price);
    }
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
        getchar();
        case '1':
            showStock();
    }
}


int main()
{

    menu();
}
