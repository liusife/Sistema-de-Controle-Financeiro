#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int valemail()
{
    int nu;
    char email[50];
	
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o seu email: \n\n");
	fgets(email, sizeof(email), stdin);
	printf("\nVerifique se seu email está correto: %s \n", email);
	printf("1- Sim\n");
	printf("2- Não\n");
	printf("\nR: ");
	scanf("%d", &nu);
	getchar();
	system("cls");
	
	if(nu == 2){
		system("cls");
		valemail();
	}
	
	return 0;
}

int valcpf()
{
    int nu, cpf;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o seu CPF: \n\n");
	scanf("%d", &cpf);
	printf("\nVerifique se seu CPF está correto: %d \n", cpf);
	printf("1- Sim\n");
	printf("2- Não\n");
	printf("\nR: ");
	scanf("%d", &nu);
	getchar();
	system("cls");
	
	if(nu == 2){
		system("cls");
		valcpf();
	}
	
	return 0;
}

int registro()
{
	system("cls");
	char nomecom[50], senha[100], senhacom[100];
	int nu, x;
	
	x = 10;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o seu nome completo: \n\n");
	fgets(nomecom, sizeof(nomecom), stdin);
	printf("\nVerifique se seu nome está correto: %s \n", nomecom);
	printf("1- Sim\n");
	printf("2- Não\n");
	printf("\nR: ");
	scanf("%d", &nu);
	getchar();
	system("cls");
	
	if(nu == 2){
		system("cls");
		registro();
	}
	
	valemail();
	
	valcpf();
	
	while(x != 0)
	{
		printf("Crie uma senha: ");
		scanf("%s", senha);
		getchar();
		printf("Confirme a sua senha: ");
		scanf("%s", senhacom);
		getchar();
		
		if(strcmp(senhacom, senha) == 0){
			system("cls");
			printf("Usuário registrado com sucesso!\n");
			system("pause");
			system("cls");
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
	printf("1- CADASTRO\n");
	printf("2- LOGIN\n");
	printf("3- SAIR\n");
	printf("\nDigite a opção desejada: ");
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