#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "sistema.h"
#include "utils.h"
#include "db.h"

int main()
{
    int n;

    db_init();

    do
    {
        limparTela();

        printf("===== BEM-VINDO! =====\n");
        printf("1- CADASTRO\n");
        printf("2- LOGIN\n");
        printf("3- SAIR\n");
        printf("\nDigite a opcao desejada: ");

        if (scanf("%d", &n) != 1)
        {
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (n)
        {
        case 1:
            registro();
            break;
        case 2:
            if (login() == 1)
            {
                menuPrincipal();
            }
            break;
        case 3:
            printf("\nVolte sempre!");
            break;
        default:
            printf("\nOpcao invalida!\n");
            pausar();
            break;
        }

    } while (n != 3);

    db_close();
    return 0;
}