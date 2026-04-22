#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despesas_acoes.h"
#include "usuario.h" 
#include "utils.h"

Despesa d_ex; 

void registrardespesa() {
    limparTela();
    printf("--- REGISTRAR DESPESA ---\n");
    
    d_ex.id = 1;

    printf("Descricao: ");
    fgets(d_ex.descricao, sizeof(d_ex.descricao), stdin);
    removerQuebraLinha(d_ex.descricao);

    printf("Valor: ");
    scanf("%f", &d_ex.valor);
    limparBuffer();

    strcpy(d_ex.cpf_usuario, userLogado.cpf);

    printf("\nDespesa salva com sucesso!\n");
    pausar();
}

void visualizardespesa() {
    limparTela();
    printf("--- SUAS DESPESAS ---\n");
    
    if (strlen(d_ex.descricao) == 0) {
        printf("Nenhuma despesa registrada ainda.\n");
    } else {
        printf("ID: %d\n", d_ex.id);
        printf("Descricao: %s\n", d_ex.descricao);
        printf("Valor: R$ %.2f\n", d_ex.valor);
        printf("Dono (CPF): %s\n", d_ex.cpf_usuario);
    }
    printf("---------------------\n");
    pausar();
}

void editardespesa() {
    limparTela();
    if (d_ex.id == 0) {
        printf("Nao ha despesa para editar!\n");
    } else {
        printf("--- EDITAR DESPESA (ID: %d) ---\n", d_ex.id);
        printf("Nova Descricao: ");
        fgets(d_ex.descricao, sizeof(d_ex.descricao), stdin);
        removerQuebraLinha(d_ex.descricao);

        printf("Novo Valor: ");
        scanf("%f", &d_ex.valor);
        limparBuffer();
        printf("\nAlteracao concluida!\n");
    }
    pausar();
}

void excluirdespesa() {
    limparTela();
    
    d_ex.valor = 0.0;
    d_ex.id = 0;
    strcpy(d_ex.descricao, "Excluido");
    memset(d_ex.cpf_usuario, 0, sizeof(d_ex.cpf_usuario));
    
    printf("Despesa apagada com sucesso!\n");
    pausar();
}