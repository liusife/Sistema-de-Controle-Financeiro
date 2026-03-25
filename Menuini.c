#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int registro()
{
	system("cls");
	char nomecom[50];
	int nu;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o seu nome completo: \n");
	fgets(nomecom, sizeof(nomecom), stdin);
	system("cls");
	printf("Verifique se seu nome está correto: %s \n", nomecom);
	printf("1- Sim\n");
	printf("2- Não\n");
	scanf("%d", &nu);
	getchar();
	
	if(nu == 2){
		registro();
	}
	printf("Usuário registrado!\n");
	system("pause");
	
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