
#include <stdio.h>
#include <stdlib.h>

char *itoa(int n);

int main(void)
{
	int n;
	scanf("%d", &n);

}

char *itoa(int n)
{
	int ten = 1, digit = 0;
	while(n/ten) {
		ten *= 10;
		++digit;
	}

	ten /= 10;
	while(ten) {
		
	}
}
