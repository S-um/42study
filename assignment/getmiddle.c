
#include <stdio.h>


int median(int a, int b, int c)
{
	if(a>=b) {
		if(b>=c) {
			printf("2times\n");
			return b;
		}
		else if (a <= c) {
			printf("3times\n");
			return a;
		}
		else {
			printf("3times\n");
			return c;
		}
	} else {
		if(c <= a) {
			printf("2times\n");
			return a;
		}
		else if (b <= c) {
			printf("3times\n");
			return b;
		}
		else {
			printf("3times\n");
			return c;
		}
	}
}

int main(void)
{
	int a, b, c;

	printf("세 정수의 중앙 값을 구합니다.\n");
	printf("a : "); scanf("%d", &a);
	printf("b : "); scanf("%d", &b);
	printf("c : "); scanf("%d", &c);

	printf("중앙 값은 %d입니다.\n", median(a, b, c));

	return 0;
}
