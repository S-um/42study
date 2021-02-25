
#include <stdio.h>
#include <stdlib.h>

void push(int *q, int num, int index);
int goUpstair(int *q, int index, int lastIndex);
void goDownstair(int *q, int index, int lastIndex);

void print(int *q, int index)
{
	int i, j, two;

	i = 1;
	j = 1;
	two = 2;
	printf("\ntree\n\n");
	while(i<=index) {
		printf("%d ", q[i]);
		if(i == j) {
			printf("\n");
			j += two;
			two *= 2;
		}
		++i;
	}
	printf("\n\n");
}

int main(void)
{
	int n, i, num, index;
	int *q;
	scanf("%d", &n);
	q = (int*)calloc(n+1,sizeof(int));

	i = 0;
	index = 1;
	while(i<n) {
		scanf("%d", &num);
		push(q, num, index);
		++index;
		printf("%d\n", q[1]);
		++i;
		print(q,n);
	}
	free(q);
}

void push(int *q, int num, int index)
{
	q[index] = num;
	int lastIndex = index;
	while(1) {
		if(goUpstair(q,index,lastIndex)) {
			goDownstair(q,index,lastIndex);
			return;
		}else{
			index /= 2;
		}
	}
}

int goUpstair(int *q, int index, int lastIndex)
{
	if(index==1)
		return 1;
	int temp;
	if(index%2) {
		if(q[index]>q[index/2]) {
			temp = q[index];
			q[index] = q[index/2];
			q[index/2] = temp;
		}
	}else{
		if(q[index]<q[index/2]) {
			temp = q[index];
			q[index] = q[index/2];
			q[index/2] = temp;
		}
	}
	while(index*2<lastIndex) {
		if(q[index]>q[index*2]) {
			temp = q[index];
			q[index] = q[index*2];
			q[index*2] = temp;
			index *= 2;
		}else
			break;
	}
	return 0;
}

void goDownstair(int *q, int index, int lastIndex)
{
	if(index*2>lastIndex)
		return;
	int temp;

	if(q[index]>q[index*2]) {
		temp = q[index];
		q[index] = q[index*2];
		q[index*2] = temp;
		goDownstair(q,index*2,lastIndex);
	}else if(index*2+1<lastIndex && q[index]<q[index*2+1]) {
		temp = q[index];
		q[index] = q[index*2+1];
		q[index*2+1] = temp;
		goDownstair(q,index*2+1,lastIndex);
	}
}
