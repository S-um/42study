#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* s1 = malloc(sizeof(char) * 31);

	scanf("%s", s1);

	printf("%s\n", s1);
			

	return 0;
}
