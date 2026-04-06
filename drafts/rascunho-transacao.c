#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define texto "Opção inválida. Escolha uma das opções abaixo:"

    int main()
    {
        setlocale(LC_ALL,"Portuguese");

    int escolha, opc1, tipoemi, parcelas, tipotrans, tipotrans2;
    float trans, vtrans;
    char descricaoc[50], dtrans[50];
    
        printf("------- Transações -------\n");                     //*essa parte pode ser um procedimento*
        printf("[1] Registrar transações \n");
        printf("[2] Visualizar transações \n");
        printf("[3] Editar transações \n");
        printf("[4] Excluir despesas \n");
        scanf("%d",&escolha);
        system("clear");
        

        switch (escolha)
        {
        case 1:
            printf("     Escolha uma das opções abaixo:     \n");
            printf("[1] Selecionar tipo de emissão \n");
            printf("[2] Retornar para transações \n");
            scanf("%d", &opc1);

            switch (opc1)
            {
            case 1:    //tipo de emissão 
                printf("[1] Crédito\n");   
                printf("[2] Débito\n");
                printf("[3] Pix agendado\n");
                printf("[4] Pix, saque/troca\n");
                scanf("%d", &tipoemi);
                system("clear");

                switch (tipoemi)
                {
                case 1:         // adicionar valor da transação e parcelas
                    printf("Adicone o valor da transação: R$");
                    scanf("%f",&trans);
                    printf("Adicione a quantidade de parcelas: ");
                    scanf("%d", &parcelas);
                    printf("Adicionar descrição da transação: ");
                    scanf("%s", descricaoc);
                    printf("     ");
                    printf("     Selecione o tipo de transação:     \n");    // entrada ou saída   //* pprocedimento*\\ 
                    printf("[1] Entrada\n");
                    printf("[2] Saída\n");
                    scanf("%d",&tipotrans);
                    system("clear");

                        if (tipotrans == 1)
                        {
                           //adicionar valor ao saldo(tem q ver como q faz)
                           //mostra saldo atualizado
                        } else {
                            // subtrair valor do saldo (tem q ver isso aqui tbm)
                            //mostrar saldo atualizado
                        }
                        
                    break;

                case 2:                 // ta indo certinho esses 3 aqui
                case 3:
                case 4:
                
                printf("Adicione valor da transação: R$ ");
                scanf("%f", &vtrans);
                printf("Adiconar descrição da transação:");
                scanf("%s", &dtrans);
                printf("      ");
                printf("     Selecione o tipo de transação:     \n");    // entrada ou saída
                printf("[1] Entrada\n");
                printf("[2] Saída\n");
                scanf("%d",&tipotrans2);

                        if (tipotrans2 == 1){
                            // adicionar valor ao saldo
                        } else {
                            //subtrair valor ao saldo
                        }

                break;
                
                default:
                    printf("%s",texto);
                    break;
                }
                break;
            
            default:
                printf("%s\n",texto);
                //colocar menu escolhas de transação
                break;
            }
            break;
        
        default:

        printf("%s\n",texto);
        //menu transações
            break;
        }

        return 0;
    }