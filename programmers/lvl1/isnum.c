
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *s = (char *)malloc(9);
	scanf("%s", s);
	size_t len = strlen(s);
	for(int i = 0; i < len; ++i) {
		if(s[i] < '0' || s[i] > '9') printf("false\n");
	}
	printf("if there is no false it's true\n");
}
