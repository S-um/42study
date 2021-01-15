
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *solution(const char *number, int k);

int main(void)
{
	char num[30] = {0,};
	int k;

	scanf("%s", num);
	scanf("%d", &k);
	char *temp = solution(num,k);
	printf("%s\n", temp);

	free(temp);

	return 0;
}

char *solution(const char *number, int k)
{
	int numLen = strlen(number);
	int block = k + 1, scan, biggestNum, biggestNumIndex = -1, putAnswer = 0;
	char *answer = (char*)calloc(numLen-k+1, 1);

	while(block <= numLen) {
		scan = biggestNumIndex + 1;
		biggestNum = 0;
		while(scan < block) {
			if(number[scan] > biggestNum) {
				biggestNum = number[scan];
				biggestNumIndex = scan;
			}
			scan++;
		}
		answer[putAnswer++] = biggestNum;
		block++;
	}

	return answer;
}
