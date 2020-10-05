#include<stdio.h>

int a,b,d;

int swap(int *w, int *z)
{
	d = *w;
	*w = *z;
	*z = d;
}

int main()
{
	scanf("%d %d", &a, &b);
	swap(&a,&b);
	printf("%d %d", a, b);
}
