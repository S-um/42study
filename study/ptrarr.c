
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e;
	int **ppa[5] = {&pa,&pb,&pc,&pd,&pe};
	int **ppb[5] = {&pe,&pd,&pc,&pb,&pa};
	int **(*arr)[] = &ppa;
	int **(**arr1)[] = (int**(**)[])malloc(2 * sizeof(int**(*)[]));
	arr1[0] = &ppa;
	arr1[1] = &ppb;

	int i = 0;
	while(i<5) {
		printf("%d\n", **((*(arr1[0]))[i]));
		++i;
	}

	i = 0;
	while(i<5) {
		printf("%d\n", **((*(arr1[1]))[i]));
		++i;
	}
}
