
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);
char *solution(const char* s);

int main(void)
{
	char s[10];
	scanf("%s", s);
	printf("%s\n", solution(s));

	return 0;
}

int compare(const void *a, const void *b)
{
	if(*(char *)a < *(char *)b) return 1;
	else if(*(char *)a > *(char *)b) return -1;

	return 0;
}

char *solution(const char* s)
{
	size_t slen = strlen(s);
	char *answer = (char *)malloc(sizeof(char) * slen);
	strcpy(answer, s);
	qsort(answer, slen, sizeof(char), compare);
	return answer;
}
