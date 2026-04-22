#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receitas_opcoes.h"
#include "receitas_menu.h"
#include "util_geral.h"

#define MAX_RECEITAS 100
#define MAX_DESC 100

typedef struct {

	char descricao[MAX_DESC];
	float valor;
} Receita;

static Receita receitas[MAX_RECEITAS];
static int totalReceitas = 0;

void limparTela(void)
{
	system("cls");
}

void pausar(void)
{
	system("pause");
}

void limparBuffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
void removerQuebraLinha(char *str)
{
	str[strcspn(str, "\n")] = '\0';
}

int main(void)
{
	menuReceitas();
	return 0;
}

void adicionarReceitas(void)
{
	printf("=== ADICIONAR RECEITA ===\n");

	if (totalReceitas >= MAX_RECEITAS)
	{
		printf("Limite de %d receitas atingido.\n", MAX_RECEITAS);
		return;
	}

	printf("Descricao: ");
	fgets(receitas[totalReceitas].descricao, MAX_DESC, stdin);
	removerQuebraLinha(receitas[totalReceitas].descricao);

	printf("Valor: ");
	if (scanf("%f", &receitas[totalReceitas].valor) != 1 || receitas[totalReceitas].valor <= 0)
	{
		printf("Valor invalido!\n");
		limparBuffer();
		return;
	}
	limparBuffer();

	totalReceitas++;
	printf("Receitas adicionada!\n");
}


void visualizarReceitas(void)
{
	printf("=== RECEITAS ===\n\n");

		if (totalReceitas == 0)
	{
		printf("Nenhuma receita logada.\n");
		return;
	}

	float total = 0;
	for (int i = 0; i < totalReceitas; i++)
	{
	    printf("%d. %-30s R$ %.2f\n", i + 1, receitas[i].descricao, receitas[i].valor);
		total += receitas[i].valor;
	}

	printf("\n==============================\n");
	printf("Total: R$ %.2f\n", total);
	printf("Quantidade: %d\n", totalReceitas);
}


void editarReceitas(void)
{
    printf("===== EDITAR RECEITAS =====\n\n");
 
    if (totalReceitas == 0)
    {
        printf("Nenhuma receita logada.\n");
        return;
    }
 
    visualizarReceitas();
    printf("\nNumero da receita a editar: ");
 
    int num;
    if (scanf("%d", &num) != 1 || num < 1 || num > totalReceitas)
    {
        printf("Numero invalido!\n");
        limparBuffer();
        return;
    }
    limparBuffer();
 
    int idx = num - 1;
 
    printf("Descricao atual: %s\n", receitas[idx].descricao);
    printf("Nova descricao: ");
    fgets(receitas[idx].descricao, MAX_DESC, stdin);
    removerQuebraLinha(receitas[idx].descricao);
 
    printf("Valor atual: R$ %.2f\n", receitas[idx].valor);
    printf("Novo valor (R$): ");
    if (scanf("%f", &receitas[idx].valor) != 1 || receitas[idx].valor <= 0)
    {
        printf("Valor invalido!\n");
        limparBuffer();
        return;
    }
    limparBuffer();
 
    printf("Receita editada com sucesso!\n");
}


void excluirReceitas(void)
{
     printf("=== EXCLUIR RECEITA ===\n\n");
 
    if (totalReceitas == 0)
    {
        printf("Nenhuma receita logada.\n");
        return;
    }
 
    printf("1 - Excluir uma receita especifica\n");
    printf("2 - Excluir TODAS as receitas\n");
    printf("Escolha: ");
 
    int escolha;
    if (scanf("%d", &escolha) != 1)
    {
        limparBuffer();
        return;
    }
    limparBuffer();
 
    if (escolha == 2)
    {
        printf("Tem certeza? (1-Sim / 2-Nao): ");
        int confirmar;
        scanf("%d", &confirmar);
        limparBuffer();
        if (confirmar == 1)
        {
            totalReceitas = 0;
            printf("Todas as receitas foram excluidas!\n");
        }
        else
        {
            printf("Cancelado.\n");
        }
        return;
    }
 
    visualizarReceitas();
    printf("\nNumero da receita a excluir: ");
 
    int num;
    if (scanf("%d", &num) != 1 || num < 1 || num > totalReceitas)
    {
        printf("Numero invalido!\n");
        limparBuffer();
        return;
    }
    limparBuffer();
 
    int idx = num - 1;
 
    for (int i = idx; i < totalReceitas - 1; i++)
    {
        receitas[i] = receitas[i + 1];
    }
    totalReceitas--;
 
    printf("Receita excluida com sucesso!\n");
}
