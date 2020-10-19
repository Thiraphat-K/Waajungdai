#include<stdio.h>

void set(char*);

int main()
{
	char y[100];
	char* py = y ;
	scanf("%s", y);
	set(py);
	return 0;
}
void set(char *a)
{
	int x = 0;
	while (*(a+x) != '\0')
	{
		if (*(a+x) != *(a+x+1))
		{
			printf("%c", *(a+x));
		}
		x++;
	}
}
