#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define texto "Opção inválida. Escolha uma das opções abaixo:"

    //=============== protótipos ======
    int menutransacoes();
    int escolhadousuario();

    //=============== struct ===========

    struct credito {
        float valor;
        int parcelas,tipo; // 1- entrada | 2-saida
        char descricao[65];
    };

    // =============== main =============
    int main(){

        struct credito emissao1;
        int opcao, escolha1, emissao, volta;

            setlocale(LC_ALL,"Portuguese");

            do {
                 opcao = menutransacoes();

                 switch (opcao)  
                 {
                 case 1:  //emissao

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

                            printf(" A emissão é: [1] Entrada ou [2] saída");
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
                            printf("Voltando para o menu inicial...");
                            system("pause");
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

                            printf(" A emissão é: [1] Entrada ou [2] saída");
                            scanf("%d",&emissao1.tipo);

                        
                        default: 
                        printf("%s", texto);
                            break;
                        }

                    }



                    break;
                 
                 default:
                    break;
                 }


            } while (opcao != 0);

            return 0;

    }

    //============ Função transação ============
    int menutransacoes(){


        int escolha; 

    printf("\n------- TRANSACOES -------\n");
    printf("[1] Registrar transação\n");
    printf("[2] Listar transações\n");
    printf("[3] Editar transação\n");
    printf("[4] Excluir transação\n");
    printf("[0] Sair\n");
    printf("Escolha: ");

    scanf("%d", &escolha);

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

    
