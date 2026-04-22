#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"
#include "despesas.h"
#include "utils.h"

void menuPrincipal()
{
    int n;

    do
    {
        limparTela();
        printf("===== MENU =====\n");
        printf("1- Gerenciar Despesas\n");
        printf("2- Logout\n");
        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &n) != 1)
        {
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (n)
        {
        case 1:
            menudespesas();
            break;
        case 2:
            printf("\nSaindo da conta...\n");
            pausar();
            break;
        default:
            printf("\nOpcao invalida!\n");
            pausar();
            break;
        }
    } while (n != 2);
}