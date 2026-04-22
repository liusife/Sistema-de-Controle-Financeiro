#ifndef USUARIO_H
#define USUARIO_H

typedef struct
{
    char nome[50];
    char email[50];
    char cpf[12];
    char senha[100];
} Usuario;

extern Usuario userLogado;

int registro();
int login();

#endif