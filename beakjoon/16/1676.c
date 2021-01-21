
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, two = 0, five = 0, temp;
	scanf("%d", &n);
	i = 2;
	while(i<=n) {
		temp = i;
		while(0 == temp%2) {
			++two;
			temp /= 2;
		}
		while(0 == temp%5) {
			++five;
			temp /= 5;
		}
		++i;
	}
	if(two<=five)
		printf("%d\n",two);
	else
		printf("%d\n",five);

	return 0;
}
