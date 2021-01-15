
#include <stdio.h>
#include <stdlib.h>

int solution(int n) {
	int answer = 0;

	while(n) {
		answer *= 3;
		answer += n % 3;
		n /= 3;
	}

	return answer;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", solution(n));

	return 0;
}
