
#include <stdio.h>

int main()
{
	char a = 64;
	a = a<<1;
	
	printf("%hhd\n", a);
	a = a>>1;
	printf("%hhd\n", a);

	return 0;
}
