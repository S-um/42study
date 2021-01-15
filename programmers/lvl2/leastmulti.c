
#include <stdio.h>
#include <stdlib.h>

int solution(int arr[], size_t arr_len);
int mxmulti(int a, int b);
int solution_i(int arr[], int start, int end);

int main(void)
{
	int count;
	scanf("%d", &count);
	int *arr = (int*)malloc(sizeof(int) * count);
	for(int i = 0; i < count; ++i) {
		scanf("%d", arr+i);
	}
	printf("%d\n", solution(arr, count));
	free(arr);

	return 0;
}

int solution(int arr[], size_t arr_len)
{
	return solution_i(arr, 0, arr_len-1);
}

int mxmulti(int a, int b)
{
	int temp;
	int atemp = a, btemp = b;

	while(btemp) {
		temp = atemp%btemp;
		atemp = btemp;
		btemp = temp;
	}
	return a*b/atemp;
}

int solution_i(int arr[], int start, int end)
{
	if(start == end) return arr[start];
	int middle = (start + end)/2;
	
	return mxmulti(solution_i(arr,start,middle), solution_i(arr,middle+1,end));
}
