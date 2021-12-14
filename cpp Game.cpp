#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console=GetstdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = {' ','+','+',' ',
				   '+','+','+','+',
				   ' ','+','+',' ',			
				   '+','+','+','+',};
int carPos = WIN_WIDTH/2;
int score  = 0;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetconsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;
	
	
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor .bvisible = visible;
	lpCursor .dwSize = size; 
	SetConsoleCursorInfo(console,&lpCursor);	
}
void drawBorder(){
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=0; j=<17; j++){
			gotoxy(0+j,1); cout<<"+-";
			gotoxy(WIN_WIDTH-j,i); cout<<"+-";
		}
	}
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(SCREEN_HEIGHT,i); cout<<"+-";
	}
}
void genEnemy(int ind){
	enemyX[ind] = 17 + rand()%(33);
}

void drawEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]);   cout<<"****";
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<" ** ";
		gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"****";
		gotoxy(enemyX[ind], enemyY[ind]+3); cout<<" ** ";
	} 
}
void eraseEnemy(int ind){
	if( enemyFlag[ind] == true){
		gotoxy(enemyX[ind], enemyY[ind]); cout<<"   ";
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"    ";
		gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"    ";
		gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"    ";
	}
}
void resetEnemy(int ind){
	eraseEnemy(ind);
	enemyY[ind] = 1;
	genEnemy(ind);
}
void drawCar(){
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++{
			gotoxy(j+carPos, i+22); cout<<car[i][j];
		}
	}
}
void eraseCar(){
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++{
			gotoxy(j+carPos, i+22); cout<<" ";
		}
	}
}
int collision(){
	if( enemyY[0]+4 >= 23){
		if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9){
			return 1;
		}
	}
	return 0;
}
void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t----------------------------------"<<endl;
	cout<<"\t\t--------------Game vover----------"<<endl;
	cout<<"\t\t----------------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	}
	
void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);cout<<"Score:  "<<score<<endl; 
}

void instructions(){
	system("cl")
	gotoxy(10,5); cout<<"-----------------------";
	gotoxy(10,6); cout<<"|     Car Game        |";
	gotoxy(10,7); cout<<"-----------------------";
	gotoxy(10,9); cout<<"1. Start Game";
	gotoxy(10,10); cout<<"2. Insturctions";
	gotoxy(10,11); cout<<"3. Quit";
	gotoxy(10,13); cout<<"Seletion option";
	char op = getche();
	
	if( op=='1') play();
	else if( op=='2') instructions();
	else if ( op=='3') exit(0);
}
	
