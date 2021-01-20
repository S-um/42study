
#include <stdio.h>
#include <stdlib.h>

int continuous(int *arr, int arr_len);

int main(void)
{
	int arr_len, i;
	scanf("%d", &arr_len);
	int *arr = (int*)malloc(arr_len*sizeof(int));
	i = 0;
	while(i<arr_len)
		scanf("%d", arr+(i++));
	printf("%d\n", continuous(arr,arr_len));

	return 0;
}

int continuous(int *arr, int arr_len)
{
	int sum = 0, i = 0, answer = -1001;
	while(i<arr_len) {
		sum += arr[i];
		if(sum>answer) answer = sum;
		if(sum<0) sum = 0;
		++i;
	}

	return answer;
}
