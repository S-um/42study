
#include <stdio.h>

int solution(const char* s);

int main(void)
{
	char s[100000];
	scanf("%s", s);
	printf("%d\n", solution(s));
	return 0;
}

int solution(const char* s)
{
	int answer = 0, index = 0, len = 0, pali, i, j;
	while(s[++len]);

	if(1 == len) return 1;
	if(2 == len) {
		if(s[0] == s[1]) return 2;
		return 1;
	}

	i = 0;
	while(s[i+2]) {
		if(s[i] == s[i+1]) {
			pali = 2;
			j = 1;
			while((i-j)>=0&&s[i+j+1]) {
				if(s[i-j] != s[i+j+1]) break;
				pali+=2;
				j++;
			}
		}
		if(pali>answer) answer = pali;
		if(s[i] == s[i+2]) {
			pali = 3;
			j = 1;
			while((i-j)>=0&&s[i+j+2]) {
				if(s[i-j] != s[i+j+2]) break;
				pali+=2;
				j++;
			}
		}
		if(pali>answer) answer = pali;
		++i;
	}
	return answer;
}
