
#include <stdio.h>
#include <stdlib.h>

void maxPush(int *maxq, int num, int index);
void minPush(int *minq, int num, int index);
void maxSort(int *maxq, int index);
void minSort(int *minq, int index);
int setQ(int *maxq, int *minq);

int main(void)
{
	int n, index, i, num, temp, flipflop;
	scanf("%d", &n);
	int *maxq = (int*)calloc(n,sizeof(int));
	int *minq= (int*)calloc(n,sizeof(int));

	i = 1;
	index = 1;
	flipflop = 0;
	scanf("%d",&num);
	maxPush(maxq,num,index);
	printf("%d\n",num);

	while(i<n) {
		scanf("%d", &num);
		if(flipflop) {
			maxPush(maxq,num,index);
			if(setQ(maxq,minq))
				minSort(minq,index-1);
			flipflop = 0;
		}else{
			minPush(minq,num,index);
			if(setQ(maxq,minq))
				maxSort(maxq,index);
			++index;
			flipflop = 1;
		}
		printf("%d\n",maxq[1]);
		++i;
	}

	free(maxq);
	free(minq);
}

void maxPush(int *maxq, int num, int index)
{
	int temp;
	maxq[index] = num;
	while(index>1) {
		if(maxq[index]>maxq[index/2]) {
			temp = maxq[index/2];
			maxq[index/2] = maxq[index];
			maxq[index] = temp;
			index /= 2;
		}else
			break;
	}
}

void minPush(int *minq, int num, int index)
{
	int temp;
	minq[index] = num;
	while(index>1) {
		if(minq[index]<minq[index/2]) {
			temp = minq[index];
			minq[index] = minq[index/2];
			minq[index/2] = temp;
			index /= 2;
		}else
			break;
	}
}

void maxSort(int *maxq, int index)
{
	int i, temp;

	i = 1;
	while(i*2<=index) {
		if((i*2+1<=index && maxq[i*2]>=maxq[i*2+1]) || i*2+1>index || !maxq[i*2+1]) {
			if(maxq[i*2]>maxq[i]) {
				temp = maxq[i];
				maxq[i] = maxq[i*2];
				maxq[i*2] = temp;
				i *= 2;
			}else
				break;
		}else{
			if(maxq[i*2+1]>maxq[i]) {
				temp = maxq[i];
				maxq[i] = maxq[i*2+1];
				maxq[i*2+1] = temp;
				i = i*2+1;
			}else
				break;
		}
	}
}

void minSort(int *minq, int index)
{
	int i, temp;

	i = 1;
	while(i*2<=index) {
		if((i*2+1<=index && minq[i*2]<=minq[i*2+1]) || i*2+1>index || !minq[i*2+1]) {
			if(minq[i*2]<minq[i]){
				temp = minq[i];
				minq[i] = minq[i*2];
				minq[i*2] = temp;
				i *= 2;
			}else
				break;
		}else{
			if(minq[i*2+1]<minq[i]) {
				temp = minq[i];
				minq[i] = minq[i*2+1];
				minq[i*2+1] = temp;
				i = i*2+1;
			}else
				break;
		}
	}
}

int setQ(int *maxq, int *minq)
{
	if(maxq[1]>minq[1]) {
		int temp;
		temp = maxq[1];
		maxq[1] = minq[1];
		minq[1] = temp;
		return 1;
	}
	return 0;
}
