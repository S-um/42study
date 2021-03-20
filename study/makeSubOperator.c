
#include <stdio.h>

int sub(int a, int b);
int sub_(int a, int b);

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("sub : %d\n",sub(a,b));
	printf("sub_ : %d\n",sub_(a,b));
}

int sub(int a, int b)
{
	int carry;
	while(b)
	{
		carry = ~a & b;
		a ^= b;
		b = carry<<1;
	}
	return a;
}

int sub_(int a, int b)
{
	return b ? sub_(a^b,(~a&b)<<1) : a;
}
