#include "ui.h"
#include "../include/utils.h"

void ui_limpar_tela(void) {
    limparTela();
}

void ui_pausar(void) {
    pausar();
}

void ui_limpar_buffer(void) {
    limparBuffer();
}

void ui_remover_quebra_linha(char *str) {
    removerQuebraLinha(str);
}

void ui_text_color(int letras, int fundo) {
}

void ui_box(int lin1, int col1, int lin2, int col2) {
}

int ui_menu(int lin1, int col1, int qtd, char lista[][40]) {
    return 0;
}