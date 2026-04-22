#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "despesas_acoes.h"
#include "utils.h"

void menudespesas()
{
    int n;
    do
    {
        limparTela();
        printf("--- CONTROLE DE DESPESAS ---\n");
        printf("1- Adicionar Despesa\n");
        printf("2- Visualizar Despesas\n");
        printf("3- Editar Despesa\n");
        printf("4- Excluir Despesa\n");
        printf("5- Retornar ao Menu Principal\n");
        printf("Escolha: ");

        if (scanf("%d", &n) != 1)
        {
            limparBuffer();
            continue;
        }
        limparBuffer();

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
            pausar();
            break;
        default:
            printf("Opcao invalida!");
            pausar();
        }
    } while (n != 5);
}