# FICR---Sistema-de-controle-financeiro
Projeto realizado na cadeira de Residência I, no curso de Análise e Desenvolvimento de Sistemas

## Funcionalidades

- Cadastro e Login de usuários
- Adicionar transações (receitas e despesas)
- Listar transações
- Deletar transações por ID
- Calcular saldo total

## Tecnologias

- Linguagem C
- SQLite (persistência de dados)

## Estrutura

```
/src        -> Código fonte
/include    -> Headers (.h)
/db         -> SQLite + banco de dados
/docs       -> Documentação
```

## Compilar

```bash
make
```

Ou manualmente:
```bash
gcc -D_WIN32_WINNT=0x0501 -o main.exe src/main.c src/sistema.c src/usuario.c src/transacao.c src/transacao_acoes.c src/despesas.c src/despesas_acoes.c src/utils.c db/db.c db/sqlite3.c -I include -I db -Wall
```

## Equipe

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/liusife">
        <img src="https://github.com/liusife.png" width="80px;" alt="Luis"/><br>
        <sub><b>Luis Henrique</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/MiguelAR098">
        <img src="https://github.com/MiguelAR098.png" width="80px;" alt="Miguel"/><br>
        <sub><b>Miguel Arcanjo</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/anaa-ramos">
        <img src="https://github.com/anaa-ramos.png" width="80px;" alt="Ana"/><br>
        <sub><b>Ana Vitória</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Donkaua">
        <img src="https://github.com/Donkaua.png" width="80px;" alt="Kauã"/><br>
        <sub><b>Kauã César</b></sub>
      </a>
  </tr>
</table>