
#include <stdio.h>
#include <stdlib.h>

void pibo(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	int *piboarr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; ++i) scanf("%d",piboarr+i);

	for(int i = 0; i < n; ++i) pibo(piboarr[i]);
	free(piboarr);

}

void pibo(int n)
{
	if(1 == n) {
		printf("0 1\n");
		return;
	}else if(0 == n) {
		printf("1 0\n");
		return;
	}
	int bbone = 0, bbzero = 1;
	int bone = 1, bzero = 0;
	int one, zero;
	for(int i = 1; i < n; ++i) {
		one = bbone + bone;
		zero = bbzero + bzero;
		bbzero = bzero;
		bbone = bone;
		bzero = zero;
		bone = one;
	}
	printf("%d %d\n", zero, one);
	return;
}
