
#include <stdio.h>

int sum(int a, int b);
int sum_(int a, int b);

int main(void)
{
	int a, b;
	scanf("%d %d",&a,&b);
	printf("sum : %d\n",sum(a,b));
	printf("sum_ : %d\n",sum_(a,b));
}

int sum(int a, int b)
{
	int carry;
	while(b)
	{
		carry = a & b;
		a ^= b;
		b = carry<<1;
	}
	return a;
}

int sum_(int a, int b)
{
	return b ? sum_(a^b,(a&b)<<1) : a;
}
