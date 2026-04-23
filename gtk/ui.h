#ifndef UI_H
#define UI_H

void ui_limpar_tela(void);
void ui_pausar(void);
void ui_limpar_buffer(void);
void ui_remover_quebra_linha(char *str);
void ui_text_color(int letras, int fundo);
void ui_box(int lin1, int col1, int lin2, int col2);
int ui_menu(int lin1, int col1, int qtd, char lista[][40]);

#endif