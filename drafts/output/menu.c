#include <stdio.h>
#include <stdlib.h>

int escolha;

void menutransacao();
{
    printf("------- Transações -------\n");
    printf("[1] Registrar transações\n");
    printf("[2] Visualizar transações\n");
    printf("[3] Editar transações\n");
    printf("[4] Excluir despesas\n");

    scanf("%d", &escolha);

    system("cls");
}