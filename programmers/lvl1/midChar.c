
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(const char *s);

int main(void)
{
	char s[100];
	scanf("%s", s);
	char *hi = solution(s);
	printf("%s\n", hi);
	free(hi);
}

char *solution(const char *s)
{
	char *answer = (char *)malloc(3);
	char len = strlen(s);
	if(len % 2) {
		*answer = s[len/2];
		*(answer + 1) = 0;
	}
	else {
		*answer = s[len/2 - 1];
		*(answer + 1) = s[len/2];
		*(answer + 2) = 0;
	}
	return answer;
}
