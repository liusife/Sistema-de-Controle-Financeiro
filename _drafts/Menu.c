#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
void esconderCursor();
void linhaCol(int lin, int col);
void textColor(int letras, int fundo);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[3][40]);

enum{BLACK,
	 BLUE,
	 CYAN,
	 RED,
	 MAGENTA,
	 BROWN,
	 LIGHTGRAY,
	 DARKGRAY,
	 LIGHTBLUE,
	 LIGHTGREEN,
	 LIGHTCYAN,
	 LIGHTRED,
	 LIGHTMAGENTA,
	 YELLOW,
	 WHITE
};

enum{_BLACK=0,
	 _BLUE=16,
	 _GREEN=32,
	 _CYAN=48,
	 _RED=64,
	 _MAGENTA=80,
	 _BROWN=96,
	 _LIGHTGRAY=112,
	 _DARKGRAY=128,
	 _LIGHTBLUE=144,
	 _LIGHTGREEN=160,
	 _LIGHTCYAN=176,
	 _LIGHTRED=192,
	 _LIGHTMAGENTA=208,
	 _YELLOW=224,
	 _WHITE=240
};

void esconderCursor(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(h, &info);
}

void linhaCol(int lin, int col){
	COORD pos;
	pos.X = col - 1;
	pos.Y = lin - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textColor(int letras, int fundo){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),letras+fundo);
}

void box(int lin1, int col1, int lin2, int col2){
	int i,j,tamlin,tamcol;
	
	tamlin=lin2-lin1;
	tamcol=col2-col1;
	
	for(i=col1;i<=col2;i++){
	linhaCol(lin1,i);
	printf("%c",196);
	linhaCol(lin2,i);
	printf("%c",196);
	}

	for(i=lin1;i<=lin2;i++){
	    linhaCol(i,col1);
		printf("%c",179);
		linhaCol(i,col2);
		printf("%c",179);
	}

	for(i=lin1+1;i<lin2;i++){
		for(j=col1+1;j<col2;j++){
			linhaCol(i,j);printf(" ");
		}
	}
	
linhaCol(lin1,col1);
printf("%c",218);
linhaCol(lin1,col2);
printf("%c",191);
linhaCol(lin2,col1);
printf("%c",192);
linhaCol(lin2,col2);
printf("%c",217);
}

int menu(int lin1, int col1, int qtd, char lista[3][40]){
	int opc=1; 
	int lin2,col2,linha,i,tamMaxitem,tecla;
	
	tamMaxitem = strlen(lista[0]);
	
	for(i=1;i<qtd;i++){
		if(strlen(lista[i])>tamMaxitem){
			tamMaxitem = strlen(lista[i]);
		}
	}
	
	lin2 = lin1+(qtd*2+2);
	col2 = col1+tamMaxitem+4;
	
	textColor(WHITE,_BLUE);
	setlocale(LC_ALL,"C");
	box(lin1,col1,lin2,col2);
	setlocale(LC_ALL,"Portuguese");
	
	while(1){
		linha=lin1+2;
		for(i=0;i<qtd;i++){
			if(i+1==opc)textColor(BLACK,_LIGHTGREEN);
			else textColor(WHITE,_BLUE);
			
			linhaCol(linha,col1+2);
		printf("%s",lista[i]);
		linha+=2;
			}
			
			tecla=getch();
			
			if(tecla==27){
				return 0;
			}
			
			if(tecla == 224 || tecla == 0){
				tecla=getch();
				
			if(tecla == 72){
				if(opc>1)opc--;
			}else if(tecla == 80){
				if(opc<qtd)opc++;
		}
			}
			else if(tecla == 13){
		return opc;
		}
	}
}

int main(){
	esconderCursor();
	int opc;
	char lista[3][40]={"Registro","Login","Sair"};
	setlocale(LC_ALL,"Portuguese");
	
	while(1){
		opc = menu(10,10,3,lista);
		if(opc==0){
			break;
		}
		linhaCol(1,1);
		textColor(WHITE,_RED);
		printf("\nVocê escolheu a opção: %d", opc);
	}
	textColor(WHITE,_BLACK);
	linhaCol(24,1);
	printf(" ");
	return 0;
}