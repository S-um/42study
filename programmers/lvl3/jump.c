
#include <stdio.h>
#include <stdlib.h>

long long solution(int n);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%lld\n", solution(a));

	return 0;
}

long long solution(int n)
{
	long long answer;
	long long bb = 1, b = 2;

	if(1 == n) return 1;
	else if(2 == n) return 2;

	n -= 2;
	while(n--) {
		answer = bb+b;
		bb = b;
		b = answer;
	}

	return answer;
}
