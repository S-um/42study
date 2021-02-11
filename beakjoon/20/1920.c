
#include <stdio.h>
#include <stdlib.h>

int findNum(int *arr, int arrLen, int target)
{
	int start = 0, end = arrLen, mid = arrLen/2;
	while(1) {
		if(target == arr[mid])
			return 1;
		else if(start == mid) {
			return 0;
		}
		if(target < arr[mid]) {
			end = mid;
			mid = (start+end)/2;
		}else if(target > arr[mid]){
			start = mid+1;
			mid = (start+end)/2;
		}
	}
}

int compare(const void *a, const void *b)
{
	if(*(int*)a>*(int*)b)
		return 1;
	else if(*(int*)a<*(int*)b)
		return -1;
	return 0;
}

int main(void)
{
	int n,m,i,targetNum;
	scanf("%d",&n);

	int *arr = (int*)malloc(n*sizeof(int));
	i = 0;
	while(i<n) {
		scanf("%d",arr+i);
		++i;
	}
	qsort(arr,n,sizeof(int),compare);
	scanf("%d",&m);
	
	i = 0;
	while(i<m) {
		scanf("%d", &targetNum);
		printf("%d\n",findNum(arr,n,targetNum));
		++i;
	}
	free(arr);
}
