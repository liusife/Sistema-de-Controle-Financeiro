#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"

char nomecom[50], senha[100], cpf[12];

int valemail()
{
    int nu;
    char email[50];

    do
    {
        printf("Digite o seu email: \n\n");
        fgets(email, sizeof(email), stdin);
        removerQuebraLinha(email);

        if (strchr(email, '@') == NULL)
        {
            printf("\nEmail invalido!\n\n");
            continue;
        }

        printf("\nVerifique se seu email esta correto: %s \n", email);
        printf("1- Sim\n2- Nao\nR: ");
        scanf("%d", &nu);
        limparBuffer();
        limparTela();

    } while (nu != 1);

    return 0;
}

int valcpf()
{
    int nu;

    do
    {
        printf("Digite o seu CPF (apenas numeros): \n\n");
        fgets(cpf, sizeof(cpf), stdin);
        removerQuebraLinha(cpf);

        if (strlen(cpf) < 11)
        {
            printf("\nCPF invalido! (Deve ter 11 digitos)\n");
            pausar();
            limparTela();
            continue;
        }

        printf("\nVerifique se seu CPF esta correto: %s \n", cpf);
        printf("1- Sim\n2- Nao\nR: ");
        scanf("%d", &nu);
        limparBuffer();
        limparTela();

    } while (nu != 1);

    return 0;
}

int registro()
{
    limparTela();
    char senhacom[100];
    int nu;

    do
    {
        printf("Digite o seu nome completo: \n\n");
        fgets(nomecom, sizeof(nomecom), stdin);
        removerQuebraLinha(nomecom);

        if (strlen(nomecom) <= 1)
        {
            printf("\nNome invalido!\n\n");
            continue;
        }

        printf("\nVerifique se seu nome esta correto: %s \n", nomecom);
        printf("1- Sim\n2- Nao\nR: ");
        scanf("%d", &nu);
        limparBuffer();
        limparTela();

    } while (nu != 1);

    valemail();
    valcpf();

    while (1)
    {
        printf("Crie uma senha: ");
        fgets(senha, sizeof(senha), stdin);
        removerQuebraLinha(senha);

        if (strlen(senha) <= 1)
        {
            printf("Senha invalida!\n");
            continue;
        }

        printf("Confirme a sua senha: ");
        fgets(senhacom, sizeof(senhacom), stdin);
        removerQuebraLinha(senhacom);

        if (strcmp(senhacom, senha) == 0)
        {
            limparTela();
            printf("Usuario cadastrado com sucesso!\n");
            pausar();
            break;
        }
        else
        {
            printf("Senha incorreta! Tente novamente.\n");
            pausar();
            limparTela();
        }
    }

    return 0;
}

int login()
{
    char senhalogin[100];
    char cpflogin[12];

    limparTela();

    while (1)
    {
        printf("Digite o seu CPF: \n\n");
        fgets(cpflogin, sizeof(cpflogin), stdin);
        removerQuebraLinha(cpflogin);

        if (strcmp(cpflogin, cpf) == 0)
        {
            printf("Digite a sua senha: ");
            fgets(senhalogin, sizeof(senhalogin), stdin);
            removerQuebraLinha(senhalogin);

            if (strcmp(senhalogin, senha) == 0)
            {
                limparTela();
                printf("Logado com sucesso!\n");
                pausar();
                break;
            }
            else
            {
                printf("Senha invalida!\n");
            }
        }
        else
        {
            printf("CPF nao cadastrado ou incorreto!\n");
        }

        pausar();
        limparTela();
    }

    return 0;
}