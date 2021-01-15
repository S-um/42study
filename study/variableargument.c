
#include <stdio.h>

void function(int, ...);

int main(void)
{
	int a = 82, b = 49;
	function(2,a,b);

	return 0;
}

void function(int _iCount, ...)
{
	int *iPtr = &_iCount + 1;
	printf("%d \n", *iPtr);
	printf("%d \n", *(iPtr + 1));

	return;
}
