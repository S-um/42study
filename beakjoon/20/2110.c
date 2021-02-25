
#include <stdio.h>
#include <stdlib.h>

int GetMinLen(int N, int C, int *x);
int compare(const void *a, const void *b);

int main(void)
{
	int N, C, i;
	scanf("%d %d",&N,&C);
	int *x = (int*)malloc(N*sizeof(int));

	i = 0;
	while(i<N)
		scanf("%d",x+(i++));

	qsort(x,N,sizeof(int),compare);

	printf("%d\n",GetMinLen(N,C,x));
	free(x);
	
	return 0;
}

int GetMinLen(int N, int C, int *x)
{
	int min,max,mid,i,cnt,lastPos,isAble;
	min = 1;
	max = x[N-1]-x[1]+1;
	mid = (min+max)/2;

	while(min!=mid) {
		i = 0;
		cnt = 0;
		lastPos = -1*mid;
		isAble = 0;
		while(i<N) {
			if(x[i]>=lastPos+mid) {
				lastPos = x[i];
				++cnt;
				if(cnt>=C) {
					isAble = 1;
					break;
				}
			}
			++i;
		}
		if(isAble) {
			min = mid;
			mid = (min+max)/2;
		}else{
			max = mid;
			mid = (min+max)/2;
		}
	}
	return mid;
}

int compare(const void *a, const void *b)
{
	if(*(int*)a>*(int*)b)
		return 1;
	else
		return -1;
}
