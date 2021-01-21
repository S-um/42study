
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if(a%b)
		return gcd(b, a%b);
	return b;
}

int main(void)
{
	int n, i, temp;
	scanf("%d", &n);
	int *gear = (int*)malloc(n*sizeof(int));
	i = 0;
	while(i<n)
		scanf("%d",gear+(i++));
	i = 1;
	while(i<n) {
		temp = gcd(*gear,gear[i]);
		printf("%d/%d\n", *gear/temp,gear[i]/temp);
		++i;
	}

	return 0;
}
