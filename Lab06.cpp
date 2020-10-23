#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

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
	printf("+");
}

void check_bl()
{
	setcolor(3,0);
	gotoxy(75,3);
	printf("Bullet 1 : %d" , !shoot[0]);
	gotoxy(75,4);
	printf("Bullet 2 : %d" , !shoot[1]);
	gotoxy(75,5);
	printf("Bullet 3 : %d" , !shoot[2]);
	gotoxy(75,6);
	printf("Bullet 4 : %d" , !shoot[3]);
	gotoxy(75,7);
	printf("Bullet 5 : %d" , !shoot[4]);
}

void erase_bl(int x, int y)
{
	gotoxy(x,y);
	setcolor(0,0);
	printf(" ");
}

void draw_enermy(int x, int y)
{
	int randcolor_enermy;
	randcolor_enermy = (rand() % 5)+10;
	gotoxy(x,y);
	setcolor(randcolor_enermy,0);
	printf("O");
}

void erasething(int x, int y)
{
	gotoxy(x,y);
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

char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = {x,y}; DWORD num_read;
	if(
	!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )

	return '\0';
	else
	return buf[0];
}
//-----------------------------------------------------------//
int main()
{
	srand(time (NULL));
	setcursor(0);
	char ch='.';
	int x=40,y=25,bsx[5],bsy[5],state=0;
	int i,x_enm,y_enm,rand_enm=0,enmcount=0,col=0;
	unsigned long long int score = 0;
	draw_ship(x,y);
	
	do {
		while (enmcount<20) {
				while (rand_enm < 10 || rand_enm > 70) {
					rand_enm = rand() % 100;					
				}
				x_enm = rand_enm; rand_enm = 0;
				while (rand_enm < 2 || rand_enm > 5) {
					rand_enm = (rand() % 5);
				}	
				y_enm = rand_enm;
				draw_enermy(x_enm, y_enm);
				enmcount++;
		}
		col++;
		if (col > 2)col = 0;
		gotoxy(75, 1);
		setcolor(col+10, 0);
		printf("Score : %d", score);
	
		if (_kbhit())
		{
			ch=getch();
			if(ch=='a') {state = 1;}
			if(ch=='d') {state = 2;}
			if(ch=='s') {state = 0;}
			if(ch==' '){
				for(i=0;i<5;i++)
				{
					if(shoot[i]==0)
					{
						bsx[i]=x+3;
						bsy[i]=y-1;
						shoot[i]=1;
						Beep(700,80);
						break;
					}
				}
			}
			fflush(stdin);
		}
		if(state==1 && x>0){erase_ship(x,y);draw_ship(--x,y);}
		if(state==2 && x<70){erase_ship(x,y);draw_ship(++x,y);}
		if(state==0){erase_ship(x,y);draw_ship(x,y);}
		for(int i=0;i<5;i++)
		{
			if(shoot[i]==1)
			{
				erase_bl(bsx[i],bsy[i]);
				if(bsy[i]>0){draw_bl(bsx[i],--bsy[i]);}
				else{shoot[i]=0;}
				if (cursor(bsx[i]+3, bsy[i]-1) == 'O') {
						int randomX;
						randomX = (rand()%9)+1;
						setcolor(randomX, 0);
						shoot[i] = 0;
						gotoxy(bsx[i]+3, bsy[i]-1);
						printf("$");
						Beep(200, 75);
						gotoxy(bsx[i]+3, bsy[i]-1);
						setcolor(0, 0);
						printf(" ");
						
						erasething(bsx[i]+3, bsy[i]);
						erasething(bsx[i], bsy[i]-1);
						erase_bl(bsx[i], bsy[i]);
						score++;
						enmcount--;
						bsy[i] = 0;
				}
				
			}
		}
		check_bl();
		Sleep(150);
	} while (ch!='x');
	return 0;
}
