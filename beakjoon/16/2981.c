
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	return 0;
}

int gcd(int a, int b)
{
	if(a%b)
		return gcd(b,a%b);
	return b;
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	int *num = (int*)malloc(n*sizeof(int));
	i = 0;
	while(i<n)
		scanf("%d", num+(i++));
	qsort(num,n,sizeof(int),compare);

	int factor = num[1] - num[0];
	i = 2;
	while(i<n) {
		factor = gcd(factor,num[i]-num[i-1]);
		++i;
	}

	i = 2;
	int answer[501];
	int answer_len = 0;
	while(i*i<=factor) {
		if(!(factor%i))
			answer[answer_len++] = i;
		++i;
	}
	i = 0;
	while(i<answer_len) {
		printf("%d ", answer[i]);
		++i;
	}

	i = answer_len -1;
	if(answer[answer_len-1] * answer[answer_len-1] == factor)
		i = answer_len -2;
	while(i>=0)
		printf("%d ", factor/answer[i--]);
	printf("%d\n", factor);
	return 0;
}
