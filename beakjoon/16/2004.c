
#include <stdio.h>

long long count(int num, int division)
{
	long long temp = 1;
	long long answer = 0;
	while(num/temp) {
		temp *= division;
		answer += num/temp;
	}
	return answer;
}

int main(void)
{
	int temp, m, n;
	long long two = 0, five = 0;
	scanf("%d %d", &m, &n);

	two = count(m,2) - count(n,2) - count(m-n,2);
	five = count(m,5) - count(n,5) - count(m-n,5);

	if(two <= five)
		printf("%lld\n", two);
	else
		printf("%lld\n", five);

	return 0;
}
