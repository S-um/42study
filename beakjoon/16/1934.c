
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, a, b, min, factor, a1, b1;
	scanf("%d", &n);
	int i = 0, j;
	while(i<n) {
		scanf("%d %d", &a, &b);
		if(a<=b) min = a;
		else min = b;

		j = 1;
		while(j<=min) {
			if(!(a%j) && !(b%j)) {
				factor = j;
				a1 = a/j;
				b1 = b/j;
			}
			++j;
		}
		printf("%d\n", factor*a1*b1);
		++i;
	}
	return 0;
}
