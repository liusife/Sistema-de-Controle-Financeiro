#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"

Usuario userLogado;

int valemail()
{
    int nu;

    do
    {
        printf("Digite o seu email: ");
        fgets(userLogado.email, 50, stdin);
        removerQuebraLinha(userLogado.email);

        if (strchr(userLogado.email, '@') == NULL)
        {
            printf("\nEmail invalido!\n\n");
            continue;
        }

        printf("\nVerifique se seu email esta correto: %s \n", userLogado.email);
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
        printf("Digite o seu CPF (11 digitos): \n\n");
        fgets(userLogado.cpf, 12, stdin);
        removerQuebraLinha(userLogado.cpf);
        limparBuffer();

        if (strlen(userLogado.cpf) < 11)
        {
            printf("\nCPF invalido! (Deve ter 11 digitos)\n");
            pausar();
            limparTela();
            continue;
        }

        printf("\nVerifique se seu CPF esta correto: %s \n", userLogado.cpf);
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
        fgets(userLogado.nome, 50, stdin);
        removerQuebraLinha(userLogado.nome);

        if (strlen(userLogado.nome) <= 1)
        {
            printf("\nNome invalido!\n\n");
            continue;
        }

        printf("\nVerifique se seu nome esta correto: %s \n", userLogado.nome);
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
        fgets(userLogado.senha, 100, stdin);
        removerQuebraLinha(userLogado.senha);

        if (strlen(userLogado.senha) <= 1)
        {
            printf("Senha invalida!\n");
            continue;
        }

        printf("Confirme a sua senha: ");
        fgets(senhacom, sizeof(senhacom), stdin);
        removerQuebraLinha(senhacom);

        if (strcmp(senhacom, userLogado.senha) == 0)
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
        limparBuffer();

        if (strcmp(cpflogin, userLogado.cpf) == 0)
        {
            printf("Digite a sua senha: ");
            fgets(senhalogin, sizeof(senhalogin), stdin);
            removerQuebraLinha(senhalogin);

            if (strcmp(senhalogin, userLogado.senha) == 0)
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