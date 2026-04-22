#ifndef DESPESAS_ACOES_H
#define DESPESAS_ACOES_H

typedef struct
{
    int id;
    char cpf_usuario[12];
    char descricao[50];
    float valor;
} Despesa;


void registrardespesa();
void visualizardespesa();
void editardespesa();
void excluirdespesa();

#endif