
#include <stdio.h>
#include <stdlib.h>

void push_min_q(int *min_q, int num);
void push_max_q(int *max_q, int num);
int set_q(int *min_q, int *max_q);
void clean_min_q(int *min_q, int index);
void clean_max_q(int *max_q, int index);

void print(int *q)
{
	int i;
	int two;
	int jump;
	i = 1;
	two = 2;
	jump = 1;
	while(i<q[0])
	{
		printf("%d ",q[i]);
		if(i == jump)
		{
			printf("\n");
			jump += two;
			two *= 2;
		}
		++i;
	}
	printf("\n");
}

int main(void)
{
	int arr_len;
	int input;
	int *min_q;
	int *max_q;
	int i;

	scanf("%d",&arr_len);
	min_q = (int*)malloc(arr_len*sizeof(int));
	max_q = (int*)malloc(arr_len*sizeof(int));
	min_q[0] = 1;
	max_q[0] = 2;

	scanf("%d",&input);
	max_q[1] = input;
	printf("%d\n",input);

	i = 1;
	while(i<arr_len)
	{
		scanf("%d",&input);

		if(min_q[0] == max_q[0])
			push_max_q(max_q,input);
		else
			push_min_q(min_q,input);

		while(set_q(min_q,max_q))
		{
			clean_min_q(min_q,1);
			clean_max_q(max_q,1);
		}
		printf("%d\n",max_q[1]);
		++i;
	}
	free(min_q);
	free(max_q);
}

void push_min_q(int *min_q, int num)
{
	int index;
	int temp;
	index = min_q[0];
	min_q[min_q[0]] = num;
	++min_q[0];
	while(index>1)
	{
		if(min_q[index/2]>min_q[index])
		{
			temp = min_q[index];
			min_q[index] = min_q[index/2];
			min_q[index/2] = temp;
			index /= 2;
		}
		else
		{
			clean_min_q(min_q,index);
			break;
		}
	}
	clean_min_q(min_q,index);
}

void push_max_q(int *max_q, int num)
{
	int index;
	int temp;
	index = max_q[0];
	max_q[max_q[0]] = num;
	++max_q[0];
	while(index>1)
	{
		if(max_q[index/2]<max_q[index])
		{
			temp = max_q[index];
			max_q[index] = max_q[index/2];
			max_q[index/2] = temp;
			index /= 2;
		}
		else
		{
			clean_max_q(max_q,index);
			break;
		}
	}
	clean_max_q(max_q,index);
}

int set_q(int *min_q, int *max_q)
{
	int temp;
	if(min_q[1]<max_q[1])
	{
		temp = min_q[1];
		min_q[1] = max_q[1];
		max_q[1] = temp;
		return 1;
	}
	return 0;
}

void clean_min_q(int *min_q, int index)
{
	int temp;
	int select;
	while(index*2+1<min_q[0])
	{
		select = min_q[index*2]>min_q[index*2+1];
		if(min_q[index*2+select]<min_q[index])
		{
			temp = min_q[index];
			min_q[index] = min_q[index*2+select];
			min_q[index*2+select] = temp;
			index = index*2+select;
		}
		else
			break;
	}
	if(index*2+1 == min_q[0] && min_q[index*2]<min_q[index])
	{
		temp = min_q[index];
		min_q[index] = min_q[index*2];
		min_q[index*2] = temp;
	}
}

void clean_max_q(int *max_q,int index)
{
	int temp;
	int select;
	while(index*2+1<max_q[0])
	{
		select = max_q[index*2]<max_q[index*2+1];
		if(max_q[index*2+select]>max_q[index])
		{
			temp = max_q[index];
			max_q[index] = max_q[index*2+select];
			max_q[index*2+select] = temp;
			index = index*2+select;
		}
		else
			break;
	}
	if(index*2+1 == max_q[0] && max_q[index*2]>max_q[index])
	{
		temp = max_q[index];
		max_q[index] = max_q[index*2];
		max_q[index*2] = temp;
	}
}
