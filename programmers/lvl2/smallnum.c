
#include <stdio.h>
#include <stdlib.h>

int solution(int A[], size_t A_len, int B[], size_t B_len);
int compare(const void*a,const void*b);

int main(void)
{
	int count; 
	scanf("%d", &count);
	int *a = (int*)malloc(sizeof(int)*count);
	int *b = (int*)malloc(sizeof(int)*count);

	for(int i = 0; i < count; ++i) {
		scanf("%d", a+i);
	}

	for(int i = 0; i < count; ++i) {
		scanf("%d", b+i);
	}

	printf("%d\n", solution(a,count,b,count));
}

int solution(int A[], size_t A_len, int B[], size_t B_len)
{
	qsort(A, A_len, sizeof(int), compare);
	qsort(B, B_len, sizeof(int), compare);

	int sum = 0;
	for(int i = 0; i < A_len; ++i) {
		sum += A[i] * B[B_len - i - 1];
	}
	return sum;
}

int compare(const void*a,const void*b)
{
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	return 0;
}
