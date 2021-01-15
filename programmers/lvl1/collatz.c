
#include <stdio.h>

int solution(int num);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d\n", solution(a));

	return 0;
}

int solution(int num)
{
	int answer = 0;
	long long n = (long long)num;
	while(1 != n) {
		if(0 == n%2) n /= 2;
		else n = n *3 +1;

		answer++;
		if(answer >= 500) return -1;
	}
	return answer;
}
