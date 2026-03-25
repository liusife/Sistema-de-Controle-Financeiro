#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int registro()
{
	system("cls");
	char nomecom[50], senha[100], senhacom[100];
	int nu, cpf, x;
	
	x = 10;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o seu nome completo: \n");
	fgets(nomecom, sizeof(nomecom), stdin);
	printf("Verifique se seu nome está correto: %s \n", nomecom);
	printf("1- Sim\n");
	printf("2- Não\n");
	scanf("%d", &nu);
	getchar();
	
	if(nu == 2){
		system("cls");
		registro();
	}
	printf("Digite o seu CPF: \n");
	scanf("%d", &cpf);
	getchar();
	
	while(x != 0)
	{
		printf("Crie uma senha: \n");
		scanf("%s", &senha);
		getchar();
		printf("Confirme a sua senha: \n");
		scanf("%s", &senhacom);
		getchar();
		
		if(senhacom == senha){
			printf("Usuário registrado com sucesso!\n");
			x = 0;
		}else{
		printf("Senha incorreta! Tente novamente.\n");
		system("pause");
		system("cls");
		}
}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int n;
		
	do{
		system("cls");
		
	printf("=====MENU=====\n");
	printf("1- Cadastro\n");
	printf("2- Login\n");
	printf("3- Sair\n");
	scanf("%d", &n);
	getchar();
		
	switch(n)
	{
	case 1:
		registro();
		break;
	case 2:
		printf("Você selecionou a opção: %d \n", n);
		system("pause");
		break;
	case 3:
		printf("\nSaindo...");
		break;
	default:
		printf("\nOpção inválida!\n");
		system("pause");
		break;
		}
	} while(n != 3);
	
	return 0;
}