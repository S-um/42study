
#include <stdio.h>

int main(void)
{
	int a;

	if(scanf("%d",&a) == EOF)
		printf("EOF\n");
	else
		printf("%d\n", a);
}
