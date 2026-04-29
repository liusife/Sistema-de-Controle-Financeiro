#include "db.h"
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static sqlite3 *db = NULL;

static int abrir_banco(void) {
    if (db != NULL) {
        return SQLITE_OK;
    }
    return sqlite3_open(DB_FILE, &db);
}

int db_init(void) {
    char *errmsg = NULL;
    int rc;

    rc = abrir_banco();
    if (rc != SQLITE_OK) {
        printf("Erro ao abrir banco de dados: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    rc = sqlite3_exec(db,
        "CREATE TABLE IF NOT EXISTS usuarios ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT NOT NULL,"
        "email TEXT NOT NULL,"
        "cpf TEXT UNIQUE NOT NULL,"
        "senha TEXT NOT NULL"
        ");",
        NULL, NULL, &errmsg);

    if (rc != SQLITE_OK) {
        printf("Erro ao criar tabela: %s\n", errmsg);
        sqlite3_free(errmsg);
        return rc;
    }

    return SQLITE_OK;
}

int db_close(void) {
    if (db != NULL) {
        sqlite3_close(db);
        db = NULL;
    }
    return SQLITE_OK;
}

int db_salvar_usuario(Usuario *u) {
    char sql[512];
    char *errmsg = NULL;
    int rc;

    if (db == NULL) {
        db_init();
    }

    snprintf(sql, sizeof(sql),
        "INSERT INTO usuarios (nome, email, cpf, senha) VALUES ('%s', '%s', '%s', '%s')",
        u->nome, u->email, u->cpf, u->senha);

    rc = sqlite3_exec(db, sql, NULL, NULL, &errmsg);

    if (rc != SQLITE_OK) {
        printf("Erro ao salvar usuario: %s\n", errmsg);
        sqlite3_free(errmsg);
        return rc;
    }

    return SQLITE_OK;
}

int db_buscar_usuario_por_cpf(const char *cpf, Usuario *u) {
    char sql[512];
    sqlite3_stmt *stmt;
    int rc;

    if (db == NULL) {
        db_init();
    }

    snprintf(sql, sizeof(sql), "SELECT nome, email, cpf, senha FROM usuarios WHERE cpf = '%s';", cpf);

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Erro ao buscar usuario: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        strncpy(u->nome, (const char *)sqlite3_column_text(stmt, 0), sizeof(u->nome) - 1);
        strncpy(u->email, (const char *)sqlite3_column_text(stmt, 1), sizeof(u->email) - 1);
        strncpy(u->cpf, (const char *)sqlite3_column_text(stmt, 2), sizeof(u->cpf) - 1);
        strncpy(u->senha, (const char *)sqlite3_column_text(stmt, 3), sizeof(u->senha) - 1);
        sqlite3_finalize(stmt);
        return SQLITE_OK;
    }

    sqlite3_finalize(stmt);
    return SQLITE_NOTFOUND;
}