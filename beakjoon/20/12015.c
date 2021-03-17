
#include <stdio.h>
#include <stdlib.h>

int lower_bound(int *arr, int arr_len, int target_num);

int main(void)
{
	int arr_len;
	int *arr;
	int *lis;
	int lis_len;
	int lis_index;
	int lis_circuit;
	int i;

	scanf("%d",&arr_len);
	lis = (int*)malloc((arr_len+1)*sizeof(int));
	arr = (int*)malloc(arr_len*sizeof(int));
	i = 0;
	while(i<arr_len)
		scanf("%d",arr+(i++));

	lis[0] = 0;
	lis_index = 0;
	i = 0;
	while(i<arr_len)
	{
		if(lis[lis_index]<arr[i])
		{
			++lis_index;
			lis[lis_index] = arr[i];
		}
		else
		{
			lis[lower_bound(lis,lis_index,arr[i])] = arr[i];
		}
		++i;
	}
	printf("%d\n",lis_index);
	free(arr);
	free(lis);
}

int lower_bound(int *arr, int arr_len, int target_num)
{
	int start, middle, end;
	start = 0;
	end = arr_len+1;
	middle = end/2;

	while(start != middle)
	{
		if(arr[middle]<target_num)
			start = middle;
		else
			end = middle;
		middle = (start+end)/2;
	}
	++middle;
	return middle;
}
