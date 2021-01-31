
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *arr = (int*)malloc(6*sizeof(int));
	++arr;
	int i = -1;
	while(i<5) {
		arr[i] = i;
		++i;
	}
	i = -1;
	while(i<5)
		printf("%d ",arr[i++]);
	printf("\n");
	--arr;
	free(arr);
}
