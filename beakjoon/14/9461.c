
#include <stdio.h>

long long wave(int n);

int main(void)
{
	int n;
	int num;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &num);
		printf("%lld\n", wave(num));
	}
}

long long wave(int n)
{
	switch(n) {
		case 1: case 2: case 3:
			return 1;
		case 4: case 5:
			return 2;
	}
	long long bbbbb = 1, bbbb = 1, bbb = 1, bb = 2, b = 2, answer;
	n -= 5;
	while(n) {
		answer = bbbbb + b;
		bbbbb = bbbb;
		bbbb = bbb;
		bbb = bb;
		bb = b;
		b = answer;
		--n;
	}
	
	return answer;
}
