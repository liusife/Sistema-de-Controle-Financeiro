#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despesas_acoes.h"
#include "utils.h"

char d_desc[50] = "Nenhuma";
float d_valor = 0.0;

void registrardespesa() {
    limparTela();
    printf("--- REGISTRAR DESPESA ---\n");
    printf("Descricao: ");
    fgets(d_desc, sizeof(d_desc), stdin);
    removerQuebraLinha(d_desc);

    printf("Valor: ");
    scanf("%f", &d_valor);
    limparBuffer();

    printf("\nDespesa salva com sucesso!\n");
    pausar();
}

void visualizardespesa() {
    limparTela();
    printf("--- SUAS DESPESAS ---\n");
    printf("Descricao: %s | Valor: R$ %.2f\n", d_desc, d_valor);
    printf("---------------------\n");
    pausar();
}

void editardespesa() {
    limparTela();
    printf("--- EDITAR DESPESA ---\n");
    printf("Nova Descricao: ");
    fgets(d_desc, sizeof(d_desc), stdin);
    removerQuebraLinha(d_desc);

    printf("Novo Valor: ");
    scanf("%f", &d_valor);
    limparBuffer();

    printf("\nAlteracao concluida!\n");
    pausar();
}

void excluirdespesa() {
    limparTela();
    d_valor = 0.0;
    strcpy(d_desc, "Excluido");
    printf("Despesa apagada!\n");
    pausar();
}