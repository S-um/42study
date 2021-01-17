
#include <stdio.h>

int tile(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", tile(n));

	return 0;
}

int tile(int n)
{
	if(1 == n) return 1;
	if(2 == n) return 2;
	int bb = 1, b = 2, answer;
	n -= 2;
	while(n) {
		answer = (bb + b) % 15746;
		bb = b;
		b = answer;
		--n;
	}
	return answer;
}
