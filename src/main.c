#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "utils.h"

int main()
{
    int n;

    do
    {
        limparTela();

        printf("=====MENU=====\n");
        printf("1- CADASTRO\n");
        printf("2- LOGIN\n");
        printf("3- SAIR\n");
        printf("\nDigite a opcao desejada: ");
        
        if (scanf("%d", &n) != 1) {
            limparBuffer();
            continue;
        }
        limparBuffer();

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
                pausar();
                break;
        }

    } while(n != 3);

    return 0;
}