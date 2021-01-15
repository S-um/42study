
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* s);
void solution_i(char* s, int* answer);

int main(void)
{
	char s[50];
	scanf("%s",s);
	int *answer = solution(s);
	printf("recycle count : %d\nremoved 0 : %d\n", answer[0], answer[1]);
	free(answer);
}

int* solution(const char* s)
{
	int *answer = (int*)malloc(sizeof(int) * 2);
	int slen = strlen(s);
	char *temp = (char*)calloc(slen+1, sizeof(char));
	answer[0] = 0;
	answer[1] = 0;
	
	for(int i = 0; i < slen; ++i) {
		temp[i] = s[i];
	}

	solution_i(temp, answer);

	free(temp);

	return answer;
}

void solution_i(char* s, int* answer)
{
	if(!s[1] || !s[0]) return;

	printf("%s\n", s);
	
	answer[0]++;

	
	int i = 0, count = 0;
	while(s[i]) {
		if(s[i] == '0') answer[1]++;
		else if(s[i] == '1') count++;
		++i;
	}
	
	i = count;
	int binlen = 0;
	while(i) {
		binlen++;
		i /= 2;
	}

	s[binlen] = 0;
	while(count) {
		binlen--;
		if(count%2) s[binlen] = '1';
		else s[binlen] = '0';
		count /= 2;
	}

	solution_i(s, answer);

	
}
