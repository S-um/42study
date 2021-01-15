
#include <stdio.h>
#include <stdlib.h>

char *solution(int numbers[], size_t numbers_len);
int compare(const void *a, const void *b);

int main(void)
{
	int len;
	scanf("%d", &len);
	int *nums = (int*)malloc(sizeof(int) * len);
	int i = 0;
	while(i < len) {
		scanf("%d", nums+i);
		i++;
	}
	char *temp = solution(nums, len);
	printf("%s\n", temp);

	free(temp);
	free(nums);

	return 0;
}

char *solution(int numbers[], size_t numbers_len)
{
	int temp = (int)numbers_len - 1, i, tens, answerLen = 1;
	while(temp + 1) {
		tens = 10;
		i = 1;
		while(numbers[temp]/tens) {
			tens *= 10;
			i++;
		}
		answerLen += i;
		temp--;
	}
	char *answer = (char*)calloc(answerLen, 1);

	qsort(numbers, numbers_len, sizeof(int), compare);


	answerLen -= 2;
	for(int i = numbers_len - 1; i >= 0; --i) {
		temp = numbers[i];
		do {
			answer[answerLen] = temp%10 + '0';
			temp /= 10;
			--answerLen;
		} while(temp);
	}

	return answer;
}

int compare(const void *a, const void*b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	int num1_len = 10;
	int num2_len = 10;
	while(num1/10) {
		num1 /= 10;
		num1_len*=10;
	}
	while(num2/10) {
		num2 /= 10;
		num2_len*=10;
	}

	if(num1 < num2) return 1;
	else if(num1 > num2)return -1;

	num1 = *(int*)a;
	num2 = *(int*)b;
	int temp1 = num2_len*num1 + num2;
	int temp2 = num1 + num1_len*num2;

	if(temp1 < temp2) return 1;
	else if(temp1 > temp2) return -1;


	return 0;
}
