#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define texto "Opção inválida. Escolha uma das opçõees abaixo:"

    //=============== protótipos ======
    int menutransacoes();
    int escolhadousuario();
    void limparTela();
    void returnmenu();

    //=============== struct ===========

    struct credito {
        float valor;
        int parcelas,tipo; // 1- entrada | 2-saida
        char descricao[65];
    };

    // =============== main =============
    int main(){

        struct credito emissao1;
        int opcao, escolha1, escolha2, escolha3, escolha4, emissao, volta;

            setlocale(LC_ALL,"Portuguese");

            do {
                 opcao = menutransacoes();

                 switch (opcao)  
                 {
                 case 1:  //[1] selecioanar tipo de emissao

                    printf("  Escolha uma das opções abaixo: \n ");
                    printf("[1] Selecionar tipo de emissão \n");
                    printf("[2] Voltar para o menu \n");
                    scanf("%d",&escolha1);

                    if (escolha1 == 1){

                        printf("   Selecione o tipo de emissão:   \n");
                        printf("[1] Crédito \n");
                        printf("[2] Débito \n");
                        printf("[3] Pix \n");
                        printf("[4] Pix, saque/troca \n");
                        scanf("%d",&emissao);

                        switch (emissao) //tipo de emissao
                        {
                        case 1:
                            printf(" Adicione o valor transação: R$");
                            scanf("%f", &emissao1.valor); 

                            printf(" Adicione a quantidade de parcelas: ");
                            scanf("%d",&emissao1.parcelas);
                            getchar();

                            printf(" Adicione a descrição da transação: ");
                            fgets(emissao1.descricao, 65, stdin);
                            printf(" \n ");

                            printf(" A emissão é [1] Entrada ou [2] saída ?\n");
                            scanf("%d",&emissao1.tipo);

                            if (emissao1.tipo == 1){

                                //adicionar valor ao saldo
                                //mostrar saldo atualizado

                            } else {

                                //subtrair valor do saldo
                                //mostrar saldo atualizado

                            }

                        volta = escolhadousuario();

                         if (volta == 1){

                            returnmenu();
                            limparTela();
                            continue; // voltar para menutransacoes()

                         } else {
                            opcao = 0;
                         }
                            break;
                        case 2:
                        case 3:
                        case 4:
                         printf(" Adicione o valor transação: R$");
                            scanf("%f", &emissao1.valor); 

                            getchar();

                            printf(" Adicione a descrição da transação: ");
                            fgets(emissao1.descricao, 65, stdin);
                            printf(" \n ");

                            printf(" A emissão é [1] Entrada ou [2] saída");
                            scanf("%d",&emissao1.tipo);
 
                        
                        default: 
                        printf("%s", texto);
                            break;
                        }

                    } else {
                            returnmenu();
                            limparTela();
                            continue; // voltar para menutransacoes()
                           

                    }

                    break;

                    case 2:  //visualizar transações
                    printf("  Escolha uma das opções abaixo: \n ");
                    printf("[1] Exibir lista de transações \n");
                    printf("[2] Voltar para o menu \n");
                    scanf("%d",&escolha2);

                    if (escolha2 == 1){

                        //exibir lista de transações
                        escolhadousuario();

                    } else {

                        returnmenu();
                        limparTela();
                        continue; // voltar para menutransacoes()
                    }

                    break;
                    
                    case 3:

                    printf("  Escolha uma das opções abaixo: \n ");
                    printf("[1] Exibir lista de transações por ID\n");
                    printf("[2] Voltar para o menu \n");
                    scanf("%d",&escolha3);

                    if (escolha2 == 1){

                        //usuario escolhe qual transação vai querer editar
                        //lista atualizada de transações é exibida
                        //opção de editar algum item

                    } else{

                        returnmenu();
                        limparTela();
                        continue;

                    }
                    break; 

                    case 4:

                     printf("  Escolha uma das opções abaixo: \n ");
                    printf("[1] Exibir lista de transações por ID\n");
                    printf("[2] Voltar para o menu \n");
                    scanf("%d",&escolha4);

                    if(escolha4 == 4){
                        //usuário escolhe qual transação quer exluir
                        //outras funionalidade...
                    } else {

                        returnmenu();
                        limparTela();
                        continue;
                    }

                 default:
                    break;
                 }


            } while (opcao != 0);

            return 0;

    }

    //============ Função transação ============
    int menutransacoes(){


        int escolha; 

    printf("\n------- TRANSAÇÕES -------\n");
    printf("[1] Registrar transação\n");
    printf("[2] Listar transações\n");
    printf("[3] Editar transação\n");
    printf("[4] Excluir transação\n");
    printf("[0] Sair\n");
    printf("Escolha: ");

    scanf("%d", &escolha);
    system("pause");
    limparTela();

    return escolha;
    }

    //=============== Função retornar ==============
    int escolhadousuario (){

        int retorno;

        printf(" Você deseja: \n");
        printf("[1] Retornar para o menu de transações");
        printf("[2] Retornar para o menu principal \n");
        scanf("%d",&retorno);

        return retorno;
    }
    //=============== Função Limpar tela =============
    void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

    void returnmenu(){
        
        printf("\nVoltando para o menu inicial...\n");
        system("pause");

    }