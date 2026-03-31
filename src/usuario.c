#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

char nomecom[50], senha[100];
int cpf;

int valemail()
{
    int nu;
    char email[50];

    do
    {
        printf("Digite o seu email: \n\n");
        fgets(email, sizeof(email), stdin);

        if(strchr(email, '@') == NULL)
        {
            printf("\nEmail invalido!\n\n");
            continue;
        }

        printf("\nVerifique se seu email esta correto: %s \n", email);
        printf("1- Sim\n2- Nao\nR: ");
        scanf("%d", &nu);
        getchar();
        system("cls");

    } while(nu != 1);

    return 0;
}

int valcpf()
{
    int nu;

    do
    {
        printf("Digite o seu CPF: \n\n");

        if(scanf("%d", &cpf) != 1)
        {
            printf("\nCPF invalido!\n");
            while(getchar() != '\n');
            continue;
        }

        getchar();

        if(cpf <= 0)
        {
            printf("\nCPF invalido!\n");
            continue;
        }

        printf("\nVerifique se seu CPF esta correto: %d \n", cpf);
        printf("1- Sim\n2- Nao\nR: ");
        scanf("%d", &nu);
        getchar();
        system("cls");

    } while(nu != 1);

    return 0;
}

int registro()
{
    system("cls");
    char senhacom[100];
    int nu;

    do
    {
        printf("Digite o seu nome completo: \n\n");
        fgets(nomecom, sizeof(nomecom), stdin);

        if(strlen(nomecom) <= 1)
        {
            printf("\nNome invalido!\n\n");
            continue;
        }

        printf("\nVerifique se seu nome esta correto: %s \n", nomecom);
        printf("1- Sim\n2- Nao\nR: ");
        scanf("%d", &nu);
        getchar();
        system("cls");

    } while(nu != 1);

    valemail();
    valcpf();

    while(1)
    {
        printf("Crie uma senha: ");
        fgets(senha, sizeof(senha), stdin);

        if(strlen(senha) <= 1)
        {
            printf("Senha invalida!\n");
            continue;
        }

        printf("Confirme a sua senha: ");
        fgets(senhacom, sizeof(senhacom), stdin);

        if(strcmp(senhacom, senha) == 0)
        {
            system("cls");
            printf("Usuario cadastrado com sucesso!\n");
            system("pause");
            break;
        }
        else
        {
            printf("Senha incorreta! Tente novamente.\n");
            system("pause");
            system("cls");
        }
    }

    return 0;
}

int login()
{
    char senhalogin[100];
    int cpflogin;

    system("cls");

    while(1)
    {
        printf("Digite o seu CPF: \n\n");

        if(scanf("%d", &cpflogin) != 1)
        {
            printf("\nCPF invalido!\n");
            while(getchar() != '\n');
            continue;
        }

        getchar();

        if(cpflogin == cpf)
        {
            printf("Digite a sua senha: ");
            fgets(senhalogin, sizeof(senhalogin), stdin);

            if(strcmp(senhalogin, senha) == 0)
            {
                system("cls");
                printf("Logado com sucesso!\n");
                system("pause");
                break;
            }
            else
            {
                printf("Senha invalida!\n");
            }
        }
        else
        {
            printf("CPF invalido!\n");
        }

        system("pause");
        system("cls");
    }

    return 0;
}