
#include <stdio.h>
#include <stdlib.h>

void addstring(char *s, char *add);
char *solution(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	char *answer = solution(n);
	printf("%s\n", answer);
	free(answer);

	return 0;
}

void addstring(char *s, char *add)
{
	int s_ptr = 0;
	int add_ptr = 0;
	while(s[s_ptr]) s_ptr++;
	while(add[add_ptr]) s[s_ptr++] = add[add_ptr++];
	s[s_ptr] = 0;

	return;
}

char *solution(int n)
{
	char *answer = (char *)malloc(3 * n + 1);
	int i = 0;
	while(i < 3 * n + 1) *(answer + i++) = 0;
	i = 0;
	while(i < n) {
		if(0 == i%2) addstring(answer, "수");
		else addstring(answer,"박");
		i++;
	}
	return answer;
}
