
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int anslen;
int compare(const void *a, const void *b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
		    
	if(num1 < num2) return -1;
	if(num1 > num2) return 1;
	return 0;
}

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
	    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	int temp, m;
		    
	int* answer = (int*)malloc(sizeof(int) * (((numbers_len * (numbers_len - 1)) / 2) + 1));
	for(int i = 0; i < (((numbers_len * (numbers_len - 1)) / 2) + 1); ++i) {
		answer[i] = -1;
	}
				    
	for(int i = 0; i < numbers_len - 1; ++i) {
		for(int j = i+1; j < numbers_len; ++j) {
			temp = numbers[i] + numbers[j];
			for(m = 0; answer[m] + 1; ++m) {
				if(temp == answer[m]) break;
			}
			if(-1 == answer[m]) answer[m] = temp;
		}
	}

	int len;
	
	for(len = 0; answer[len] + 1; ++len);
	answer = (int *)realloc(answer, sizeof(int) * len);
	
	anslen = len;
	qsort(answer, len, sizeof(int), compare);
	return answer;
}

int main(void)
{
	int len;
	scanf("%d", &len);
	int *a = (int *)malloc(sizeof(int) * len);
	for(int i = 0; i < len; ++i) scanf("%d", &a[i]);

	int *b = solution(a, len);
	for(int i = 0; i < anslen; ++i) printf("%d ", b[i]);
	printf("\n");
	free(b);

	return 0;
}
