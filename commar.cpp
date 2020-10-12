#include<stdio.h>
#include<string.h>

int main()
{
	char x[30], y[30];
	int a,b;
	printf("input num : ");
	scanf("%s", x);
	a = strlen(x);
	b = a/3;
	if(a%3 == 0)
	{
		b--;
	}
	a+=b;
	int p = strlen(x)-1, s=a-1,num=0;
	while(p>=0)
	{
		if(num%3==0 && num!=0)
			y[s--] = ',';
		y[s--] = x[p--];
		num++;
	}
	y[s]='\0';
	printf("\nresult put , : %s" , y);
}

