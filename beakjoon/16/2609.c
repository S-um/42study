
#include <stdio.h>

void printfacmul(int a, int b);

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printfacmul(a,b);

	return 0;
}

void printfacmul(int a, int b)
{
	int i = 1,min, factor = 1, a1 = a, b1 = b;

	if(a<=b)
		min = a;
	else
		min = b;

	while(i<=min) {
		if(!(a%i) && !(b%i)) {
			factor = i;
			a1 = a/i;
			b1 = b/i;
		}
		++i;
	}
	printf("%d\n%d\n",factor,factor*a1*b1);
	return;
}
