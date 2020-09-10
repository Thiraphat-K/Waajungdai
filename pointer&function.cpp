#include<stdio.h>
void myFn(){
	printf("no return");
}
int myIntFn(){
	return 5;
}
const char * checkEven(int x){
	if(x%2 == 0){
		return "Even";
	}
	return "Odd";
}
void intFnPassByRef(int *y){
	*y = *y+5;
	printf("\n%d",*y);
}

int main(){
	int a = 6;
//	myFn();
//	printf("\n%d",myIntFn());
	printf("\n%s",checkEven(a));
	intFnPassByRef(&a);
	printf("\n%d",a);
	return 0;
}
