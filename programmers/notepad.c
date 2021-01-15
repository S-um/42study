#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num = 10;
	int* numPtr = &num;

	printf("hello%n\n", &num);

	return 0;
}
