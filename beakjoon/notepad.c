
#include <stdio.h>

int main()
{
	char a = -12;
	a = a<<2;
	
	printf("%hhd\n", a);
	a = a>>1;
	printf("%hhd\n", a);

	return 0;
}
