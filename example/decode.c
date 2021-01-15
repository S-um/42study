
#include <stdio.h>

int main(void)
{
	char letter, key;

	printf("code : ");
	scanf("%c", &letter);
	printf("set key : ");
	scanf("%hhd", &key);

	printf("decoded letter : %c\n", letter ^ key);
}
