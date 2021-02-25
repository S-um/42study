
#include <stdio.h>
#include <stdlib.h>

void push(int *q, int num, int index);
int pop(int *q, int index);

int main(void)
{
	int n, i, num, index;
	scanf("%d", &n);

	int *q = (int*)calloc(n,sizeof(int));
	i = 0;
	index = 1;
	while(i<n) {
		scanf("%d", &num);
		if(num>0) {
			push(q,num, index);
			++index;
		} else {
			if(index>1) {
				--index;
				printf("%d\n",pop(q,index));
			}else{
				printf("0\n");
			}
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
		if(q[index]<q[index/2]) {
			temp = q[index];
			q[index] = q[index/2];
			q[index/2] = temp;
			index /= 2;
		}else{
			break;
		}
	}
}

int pop(int *q, int index)
{
	int ret = q[1], i, temp;
	q[1] = q[index];
	q[index] = 0;
	i = 1;
	while(i*2<index) {
		if(q[i*2]<=q[i*2+1] || !q[i*2+1]) {
			if(q[i]>q[i*2]) {
				temp = q[i];
				q[i] = q[i*2];
				q[i*2] = temp;
				i *= 2;
			}else
				break;
		}else{
			if(q[i]>q[i*2+1]) {
				temp = q[i];
				q[i] = q[i*2+1];
				q[i*2+1] = temp;
				i = i*2+1;
			}else
				break;
		}
	}

	return ret;
}
