
#include <stdio.h>

int main(void)
{
	unsigned int a = 3;
	if(a>(unsigned int)-1)
		printf("working\n");
	else
		printf("error\n");
}
