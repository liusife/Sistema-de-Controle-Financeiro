#ifndef TRANSACAO_ACOES_H
#define TRANSACAO_ACOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int tipo_pagamento;
    int tipo_movimentacao;
    float valor;
    int parcelas;
    char descricao[100];
    char cpf_usuario[12];
} Transacao;

void registrar_transacao(void);
void listar_transacoes(void);
void buscar_transacao_id(int id);
void editar_transacao(void);
void excluir_transacao(void);

#endif