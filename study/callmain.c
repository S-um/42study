
#include <stdio.h>

int func(int n);

int main(int argc, char *argv[])
{
	printf("main called, agrc : %d\n", argc);
	func(argc);
	return 0;
}

int func(int n)
{
	printf("func called, n : %d\n", n);
	if(3 == n)
		return 0;
	main(n+1,NULL);
	return 0;
}
