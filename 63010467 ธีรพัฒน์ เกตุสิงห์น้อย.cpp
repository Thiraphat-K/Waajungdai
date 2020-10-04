#include<stdio.h>
#include<windows.h>
#include<conio.h>

bool shoot[5]={0};

void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, fg+bg*16);
}

void gotoxy(int x, int y)
{
	COORD ce = { x, y };
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , ce);
}

void draw_ship(int x, int y)
{
	gotoxy(x,y);
	setcolor(4,0);
	printf("[|-0-|]");
}

void erase_ship(int x, int y)
{
	gotoxy(x,y);
	setcolor(0,0);
	printf("        ");
}

void draw_bl(int x, int y)
{
	gotoxy(x,y);
	setcolor(3,0);
	printf("^");
}

void check_bl()
{
	setcolor(3,0);
	gotoxy(0,0);
	printf("bullet 1 : %d \nbullet 2 : %d \nbullet 3 : %d \nbullet 4 : %d \nbullet 5 : %d" , !shoot[0], !shoot[1], !shoot[2], !shoot[3], !shoot[4]);
}

void erase_bl(int x, int y)
{
	gotoxy(x,y);
	setcolor(0,0);
	printf(" ");
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
	int x=40,y=25,bsx[5],bsy[5],state=0;
	draw_ship(x,y);
	do {
		if (_kbhit())
		{
			ch=getch();
			if(ch=='a') {state = 1;}
			if(ch=='d') {state = 2;}
			if(ch=='s') {state = 0;}
			if(ch==' '){
				for(int i=0;i<5;i++)
				{
					if(shoot[i]==0)
					{
						bsx[i]=x+3;
						bsy[i]=y-1;
						shoot[i]=1;
						break;
					}
				}
			}
			fflush(stdin);
		}
		if(state==1 && x>0){erase_ship(x,y);draw_ship(--x,y);}
		if(state==2 && x<80){erase_ship(x,y);draw_ship(++x,y);}
		if(state==0){erase_ship(x,y);draw_ship(x,y);}
		for(int i=0;i<5;i++)
		{
			if(shoot[i]==1)
			{
				erase_bl(bsx[i],bsy[i]);
				if(bsy[i]>0){draw_bl(bsx[i],--bsy[i]);}
				else{shoot[i]=0;}
			}
		}
		check_bl();
		Sleep(150);
	} while (ch!='x');
	return 0;
}
