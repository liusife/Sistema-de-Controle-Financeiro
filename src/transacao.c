#include "transacao.h"
#include "transacao_acoes.h"
#include "utils.h"

void menu_transacoes(void) {
    int opcao;

    do {
        limparTela();
        printf("--- TRANSOES ---\n");
        printf("[1] Registrar Transacao\n");
        printf("[2] Listar Transacoes\n");
        printf("[3] Editar Transacao\n");
        printf("[4] Excluir Transacao\n");
        printf("[5] Voltar\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (opcao) {
        case 1:
            registrar_transacao();
            break;
        case 2:
            listar_transacoes();
            break;
        case 3:
            editar_transacao();
            break;
        case 4:
            excluir_transacao();
            break;
        case 5:
            printf("Retornando...\n");
            pausar();
            break;
        default:
            printf("Opcao invalida!\n");
            pausar();
        }
    } while (opcao != 5);
}