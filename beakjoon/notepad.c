
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int p[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int *arr[3] = {*p, *(p+1), *(p+2)};
	int (*arr1)[4] = p;
	
	printf("p+1 : %p\narr+1 : %p\narr1+1 : %p\n", p+1, arr+1, arr1+1);
	printf("p[1] : %p\narr[1] : %p\narr1[1] : %p\n",p[1],arr[1],arr1[1]);
}
