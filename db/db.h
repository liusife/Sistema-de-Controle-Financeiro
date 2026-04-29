#ifndef DB_H
#define DB_H

#define DB_FILE "financeiro.db"

#include "usuario.h"

int db_init(void);
int db_close(void);
int db_salvar_usuario(Usuario *u);
int db_buscar_usuario_por_cpf(const char *cpf, Usuario *u);

#endif