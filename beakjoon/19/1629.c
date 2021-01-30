
#include <stdio.h>

long long multi(int a, int b, int c);

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a %= c;
	printf("%lld\n",multi(a,b,c));
}

long long multi(int a, int b, int c)
{
	if(1 == b)
		return a;

	long long temp = multi(a,b/2,c);
	if(b%2) {
		temp = (temp * temp) % c;
		return (temp * a) % c;
	} else {
		return (temp * temp) % c;
	}
}
