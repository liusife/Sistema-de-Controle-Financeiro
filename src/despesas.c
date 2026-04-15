#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"

void menudespesas()
{
    int n;
    do
    {
        system("cls");
        printf("--- CONTROLE DE DESPESAS ---\n");
        printf("1- Adicionar Despesa\n");
        printf("2- Visualizar Despesas\n");
        printf("3- Editar Despesa\n");
        printf("4- Excluir Despesa\n");
        printf("5- Retornar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &n);
        getchar();

        switch (n)
        {
        case 1:
            registrardespesa();
            break;
        case 2:
            visualizardespesa();
            break;
        case 3:
            editardespesa();
            break;
        case 4:
            excluirdespesa();
            break;
        case 5:
            printf("Retornando ao Menu Principal...");
            break;
        default:
            printf("Opcao invalida!");
            system("pause");
        }
    } while (n != 5);
}