
#include <stdio.h>

long long solution(int a, int b);
void sort(int *a, int *b);

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%lld\n", solution(a, b));

}

long long solution(int a, int b)
{
	if(a == b) return (long long)a;

	long long answer = 0;

	sort(&a, &b);
	for(int i = a; i <= b; ++i) {
		answer += i;
	}
	return answer;
}

void sort(int *a, int *b)
{
	if(*a < *b) return;
	
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}
