
#include <stdio.h>

void printFrac(int num);

int main(void)
{
	int n;
	scanf("%d",&n);
	printFrac(n);

	return 0;
}

void printFrac(int num)
{
	int i = 2;
	while(i<=num) {
		if(num%i == 0) {
			printf("%d\n",i);
			num /= i;
			continue;
		}
		++i;
	}
	return;
}
