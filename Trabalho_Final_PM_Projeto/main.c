#include <stdio.h>
#include <stdlib.h>
//fp = fopen("stock.txt", "r");
//while(if scanf(fp, "%c %s %lf", &ld, tipo, &preco)!EOF)

void showStock(){
    fp = fopen8"
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
