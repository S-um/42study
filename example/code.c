
#include <stdio.h>

int main(void)
{
	char letter;
	printf("letter : ");
	scanf("%c", &letter);
	printf("set key : ");
	char key;
	scanf("%hhd", &key);


	printf("coded letter : %c\n", key ^ letter);


	return 0;
}
