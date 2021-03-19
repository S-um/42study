
#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int multi(int a, int b)
{
	return a*b;
}

int div(int a, int b)
{
	return a/b;
}

int main(void)
{
	int (*cal[4])(int,int) = {add,sub,multi,div};
	int i = 0;
	while(i<4)
		printf("%d\n",cal[i++](3,6));
	printf("\n");
}
