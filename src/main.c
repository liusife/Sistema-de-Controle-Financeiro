#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

int main()
{
    int n;

    do
    {
        system("cls");

        printf("=====MENU=====\n");
        printf("1- CADASTRO\n");
        printf("2- LOGIN\n");
        printf("3- SAIR\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
                registro();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\nSaindo...");
                break;
            default:
                printf("\nOpcao invalida!\n");
                system("pause");
                break;
        }

    } while(n != 3);

    return 0;
}