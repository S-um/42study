
#include <stdio.h>

int solution(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", solution(n));

	return 0;
}

int solution(int n)
{
	int bb = 0, b = 1, answer, i = 2;
	while(i++ <= n) {
		answer = bb + b;
		bb = b;
		b = answer;
	}

	return answer;
}
