#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, fg+bg*16);
}

void draw_ship()
{
	printf(" ^|0|^ ");
}

void erase_ship()
{
	printf("       ");
}

void draw_bl()
{
	printf("^");
}

void erase_bl()
{
	printf("       ");
}

void gotoxy(int x, int y)
{
	COORD xxx = {0,0};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , xxx);
	setcolor(2,4);
	printf("%d %d",x,y);
	
	COORD f = { x-1, y};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , f);
	setcolor(0,0);
	erase_ship();

	COORD h = { x+1, y};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , h);
	setcolor(0,0);
	erase_ship();
	
	COORD c = { x, y };
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
	setcolor(2,4);
	draw_ship();
	
	COORD d = { x+3, y+1};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , d);
	setcolor(0,0);
	erase_bl();
	
	COORD e = { x+3, y-1};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , e);
	setcolor(2,4);
	draw_bl();
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}

int main()
{
	setcursor(0);
	char ch='.';
	int x=40,y=20;
	int i, j;
	int state = 0;
	gotoxy(x,y);
	do {
		if (_kbhit())
		{
			ch=getch();
			if(ch=='a') {state = 1;}
			if(ch=='d' ) {state = 2;}
			if(ch=='s' ) {state = 0;}
			if(ch==' ' ) {state = 3;
			i=x;
			j=y-1;}
			fflush(stdin);
		}
		if(state==1 && x>0){x--;gotoxy(x,y);}
		if(state==2 && x<80){x++;gotoxy(x,y);}
		if(state==0){gotoxy(x,y);}
		if(state==3 && j>0){j--;gotoxy(i,j);}
		Sleep(200);
	} while (ch!='x');
	return 0;
}
