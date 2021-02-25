
#include <stdio.h>
#include <stdlib.h>

#define ABS(x) (((x>=0)*2-1)*x)

void push(int *q, int num, int index);
int pop(int *q, int index);
int compare(int x, int y)
{
	if(!y)
		return 0;
	if(ABS(x)>ABS(y))
		return 1;
	else if(ABS(x) == ABS(y) && x>y)
		return 1;
	return 0;
}
void print(int *q, int index)
{
	int i = 1;
	while(i<index)
		printf("%d ",q[i++]);
	printf("\n");
}

int main(void)
{
	int n, i, num, temp, index;
	scanf("%d",&n);
	int *q = (int*)calloc(n+1,sizeof(int));

	i = 0;
	index = 1;
	while(i<n) {
		scanf("%d", &num);
		if(num) {
			push(q,num,index);
			++index;
		}else{
			if(index>1) {
				--index;
				printf("%d\n",pop(q,index));
			}else
				printf("0\n");
		}
		++i;
	}
	free(q);
}

void push(int *q, int num, int index)
{
	int temp;
	q[index] = num;
	while(index>1) {
		if(compare(q[index/2], q[index])) {
			temp = q[index];
			q[index] = q[index/2];
			q[index/2] = temp;
		}else
			break;
		index /= 2;
	}
}

int pop(int *q, int index)
{
	int ret = q[1], i, temp;

	q[1] = q[index];
	q[index] = 0;

	i = 1;
	while(i*2<index) {
		if(compare(q[i*2],q[i*2+1])) {
			if(compare(q[i],q[i*2+1])) {
				temp = q[i];
				q[i] = q[i*2+1];
				q[i*2+1] = temp;
				i = i*2+1;
			}else
				break;
		}else{
			if(compare(q[i],q[i*2])) {
				temp = q[i];
				q[i] = q[i*2];
				q[i*2] = temp;
				i *= 2;
			}else
				break;
		}
	}

	return ret;
}
