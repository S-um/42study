

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(const char * s);

int main(void)
{
	char s[30] = "hello world this is me";
	char *ans = solution(s);
	printf("%s\n", ans);
	free(ans);


	return 0;
}

char *solution(const char * s)
{
	int lower = 'a' - 'A';
	int upper = 'A' - 'a';
	size_t s_len = strlen(s);
	char *answer = (char *)malloc(s_len + 1);

	for(int j = 0; j < s_len; ++j) {
		answer[j] = s[j];
	}
	answer[s_len] = 0;
	int i = 0, cnt = 0;

	while(s[i]) {
		if(' ' == s[i]) {
			i++;
			cnt = 0;
			continue;
		}

		if(0 == cnt%2) {
			if(answer[i] >= 'a') {
				answer[i] += upper;
			}
		} else {
			if(answer[i] < 'a')
				answer[i] += lower;
		}
		i++;
		cnt++;
	}
	return answer;
}
