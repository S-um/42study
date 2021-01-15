
#include <stdio.h>

long long solution(long long n);

int main(void)
{
	long long answer;
	scanf("%lld", &answer);
	answer = solution(answer);
	printf("%lld\n", answer);

	return 0;
}

long long solution(long long n)
{
	long long answer = 0;
	long long square = 1;
	while(1) {
		if(square * square < n) {
			square++;
			continue;
		}
		else if(square * square > n) {
			answer = -1;
			break;
		} else {
			answer = (square + 1) * (square + 1);
			break;
		}
	}

	return answer;
}
