
#include <stdio.h>

void checkfactor();

int main(void)
{
	checkfactor();

	return 0;
}

void checkfactor()
{
	int a, b;
	while(1) {
		scanf("%d %d", &a, &b);
		if(a+b) {
			if(!(a%b))
				printf("multiple\n");
			else if(!(b%a))
				printf("factor\n");
			else
				printf("neither\n");
		} else
			break;
	}
	return;
}
