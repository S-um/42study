
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

void print_postorder(int *arr, int arr_len, int last_num);

int main(void)
{
	int *arr;
	int input;
	int arr_len;

	arr = (int*)malloc(10001*sizeof(int));
	arr_len = 1;
	while(scanf("%d",&input) != EOF)
		arr[arr_len++] = input;
	--arr_len;
	arr[0] = 1;
	print_postorder(arr,arr_len,MAX);
	free(arr);
}

void print_postorder(int *arr, int arr_len, int last_num)
{
	int cur_num;
	if(arr[0]>arr_len || arr[arr[0]] > last_num)
		return;
	cur_num = arr[arr[0]];
	++arr[0];
	print_postorder(arr,arr_len,cur_num);
	print_postorder(arr,arr_len,last_num);
	printf("%d\n",cur_num);
}
