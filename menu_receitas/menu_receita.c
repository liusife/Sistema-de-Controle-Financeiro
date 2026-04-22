#include <stdio.h>
#include <stdlib.h>
#include "receitas_opcoes.h"
#include "receitas_menu.h"
#include "util_geral.h"


void menuReceitas(void)
{
    int opcao;
    
    do
    {
        limparTela();
    printf("==========================\n");
    printf("   Controle de Receitas   \n");
    printf("==========================\n");
    printf("1 - Adicionar Receitas\n");
    printf("2 - Visualizar Receitas\n");
    printf("3 - Editar Receitas\n");
    printf("4 - Excluir Receitas\n");
    printf("5 - Sair\n");
    printf("==========================\n");
    printf("Escolha uma das opções:");

    if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            continue;
        }
    limparBuffer();

    switch(opcao)
        {
            case 1:
                system("cls");
                adicionarReceitas();
                break; 
                
            case 2:
                system("cls");
                visualizarReceitas();
                break;

            case 3:
                system("cls");
                editarReceitas();
                break;

             case 4:
                system("cls");
                excluirReceitas();
                break;

            case 5:
                printf("\nTem certeza que deseja sair? (1-Sim / 2-Nao): ");
                int confirm;
                scanf("%d", &confirm);
                limparBuffer();
                if(confirm == 1)
                {
                    printf("\n Voltando...\n");
                }
                else
                {
                opcao = 0;
                }
                break;

            default:
                printf("\nOpcao invalida! Digite um numero entre 1 e 5.\n");
                pausar();
            } 
        if (opcao != 5)
        {
            printf("\n");
            system("pause");
            system("cls");
        }
    } while(opcao != 5);

}