#include "transacao_acoes.h"
#include "usuario.h"
#include "utils.h"

static Transacao *transacoes = NULL;
static int total_transacoes = 0;
static int capacidade = 0;
static int proximo_id = 1;

static void garantir_capacidade(int minimo) {
    int nova_capacidade;
    Transacao *novo_array;

    if (minimo > capacidade) {
        nova_capacidade = (minimo * 2);
        novo_array = realloc(transacoes, nova_capacidade * sizeof(Transacao));
        if (novo_array == NULL) {
            printf("Erro de memoria!\n");
            exit(1);
        }
        transacoes = novo_array;
        capacidade = nova_capacidade;
    }
}

void registrar_transacao(void) {
    Transacao t;
    int opcao;

    limparTela();
    printf("--- REGISTRAR TRANSACAO ---\n");

    printf("Tipo de pagamento:\n");
    printf("[1] Credito\n");
    printf("[2] Debito\n");
    printf("[3] Pix\n");
    printf("[4] Pix Saque/Troco\n");
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida!\n");
        pausar();
        return;
    }
    while (getchar() != '\n');

    if (opcao < 1 || opcao > 4) {
        printf("Opcao invalida!\n");
        pausar();
        return;
    }
    t.tipo_pagamento = opcao;

    printf("Valor: R$ ");
    if (scanf("%f", &t.valor) != 1) {
        printf("Entrada invalida!\n");
        pausar();
        return;
    }
    while (getchar() != '\n');

    if (t.tipo_pagamento == 1) {
        printf("Quantidade de parcelas: ");
        if (scanf("%d", &t.parcelas) != 1) {
            printf("Entrada invalida!\n");
            pausar();
            return;
        }
        while (getchar() != '\n');
    } else {
        t.parcelas = 0;
    }

    printf("Descricao: ");
    fgets(t.descricao, sizeof(t.descricao), stdin);
    removerQuebraLinha(t.descricao);

    printf("Tipo de movimentacao:\n");
    printf("[1] Entrada\n");
    printf("[2] Saida\n");
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida!\n");
        pausar();
        return;
    }
    while (getchar() != '\n');

    if (opcao < 1 || opcao > 2) {
        printf("Opcao invalida!\n");
        pausar();
        return;
    }
    t.tipo_movimentacao = opcao;

    garantir_capacidade(total_transacoes + 1);
    t.id = proximo_id++;
    strncpy(t.cpf_usuario, userLogado.cpf, sizeof(t.cpf_usuario) - 1);
    t.cpf_usuario[sizeof(t.cpf_usuario) - 1] = '\0';

    transacoes[total_transacoes++] = t;

    printf("\nTransacao registrada com sucesso!\n");
    printf("ID: %d\n", t.id);
    pausar();
}

void listar_transacoes(void) {
    int i;
    const char *tipo_pagamento[] = {"", "Credito", "Debito", "Pix", "Pix Saque/Troco"};
    const char *tipo_movimentacao[] = {"", "Entrada", "Saida"};

    limparTela();
    printf("--- LISTA DE TRANSACOES ---\n\n");

    if (total_transacoes == 0) {
        printf("Nenhuma transacao registrada.\n");
    } else {
        for (i = 0; i < total_transacoes; i++) {
            if (strcmp(transacoes[i].cpf_usuario, userLogado.cpf) != 0) {
                continue;
            }
            printf("ID: %d\n", transacoes[i].id);
            printf("Tipo: %s | Movimentacao: %s\n",
                   tipo_pagamento[transacoes[i].tipo_pagamento],
                   tipo_movimentacao[transacoes[i].tipo_movimentacao]);
            printf("Valor: R$ %.2f\n", transacoes[i].valor);
            if (transacoes[i].parcelas > 0) {
                printf("Parcelas: %d\n", transacoes[i].parcelas);
            }
            printf("Descricao: %s\n", transacoes[i].descricao);
            printf("---------------------\n");
        }
    }
    pausar();
}

void buscar_transacao_id(int id) {
    int i;
    for (i = 0; i < total_transacoes; i++) {
        if (transacoes[i].id == id &&
            strcmp(transacoes[i].cpf_usuario, userLogado.cpf) == 0) {
            printf("Transacao encontrada: %s\n", transacoes[i].descricao);
            return;
        }
    }
    printf("Transacao nao encontrada.\n");
}

void editar_transacao(void) {
    int id, i, opcao;
    Transacao *t = NULL;

    limparTela();
    printf("--- EDITAR TRANSACAO ---\n\n");

    if (total_transacoes == 0) {
        printf("Nenhuma transacao registrada.\n");
        pausar();
        return;
    }

    listar_transacoes();

    printf("\nDigite o ID da transacao: ");
    if (scanf("%d", &id) != 1) {
        printf("Entrada invalida!\n");
        pausar();
        return;
    }
    while (getchar() != '\n');

    for (i = 0; i < total_transacoes; i++) {
        if (transacoes[i].id == id &&
            strcmp(transacoes[i].cpf_usuario, userLogado.cpf) == 0) {
            t = &transacoes[i];
            break;
        }
    }

    if (t == NULL) {
        printf("Transacao nao encontrada.\n");
        pausar();
        return;
    }

    printf("\nO que deseja editar?\n");
    printf("[1] Valor\n");
    printf("[2] Descricao\n");
    printf("[3] Parcelas (Credito)\n");
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida!\n");
        pausar();
        return;
    }
    while (getchar() != '\n');

    switch (opcao) {
    case 1:
        printf("Novo valor: R$ ");
        if (scanf("%f", &t->valor) != 1) {
            printf("Entrada invalida!\n");
            pausar();
            return;
        }
        while (getchar() != '\n');
        printf("Valor atualizado!\n");
        break;
    case 2:
        printf("Nova descricao: ");
        fgets(t->descricao, sizeof(t->descricao), stdin);
        removerQuebraLinha(t->descricao);
        printf("Descricao atualizada!\n");
        break;
    case 3:
        if (t->tipo_pagamento == 1) {
            printf("Novo numero de parcelas: ");
            if (scanf("%d", &t->parcelas) != 1) {
                printf("Entrada invalida!\n");
                pausar();
                return;
            }
            while (getchar() != '\n');
            printf("Parcelas atualizadas!\n");
        } else {
            printf("Apenas transacoes de Credito possuem parcelas.\n");
        }
        break;
    default:
        printf("Opcao invalida!\n");
    }
    pausar();
}

void excluir_transacao(void) {
    int id, i, confirmado = 0;
    char confirma[10];

    limparTela();
    printf("--- EXCLUIR TRANSACAO ---\n\n");

    if (total_transacoes == 0) {
        printf("Nenhuma transacao registrada.\n");
        pausar();
        return;
    }

    listar_transacoes();

    printf("\nDigite o ID da transacao: ");
    if (scanf("%d", &id) != 1) {
        printf("Entrada invalida!\n");
        pausar();
        return;
    }
    while (getchar() != '\n');

    for (i = 0; i < total_transacoes; i++) {
        if (transacoes[i].id == id &&
            strcmp(transacoes[i].cpf_usuario, userLogado.cpf) == 0) {
            printf("Tem certeza que deseja excluir '%s'? (s/n): ",
                   transacoes[i].descricao);
            fgets(confirma, sizeof(confirma), stdin);
            removerQuebraLinha(confirma);

            if (confirma[0] == 's' || confirma[0] == 'S') {
                for (; i < total_transacoes - 1; i++) {
                    transacoes[i] = transacoes[i + 1];
                }
                total_transacoes--;
                printf("Transacao excluida com sucesso!\n");
                confirmado = 1;
            } else {
                printf("Exclusao cancelada.\n");
            }
            break;
        }
    }

    if (!confirmado) {
        printf("Transacao nao encontrada.\n");
    }
    pausar();
}