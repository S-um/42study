
#include <stdio.h>
#include <stdlib.h>

int bitonic(int *arr, int arr_len);

int main(void)
{
	int arr_len;
	scanf("%d", &arr_len);
	int *arr = (int*)malloc(sizeof(int)*arr_len);
	for(int i = 0; i < arr_len; ++i) scanf("%d", arr+i);
	printf("%d\n", bitonic(arr,arr_len));
	free(arr);

	return 0;
}

int bitonic(int *arr, int arr_len)
{
	int *left = (int*)malloc(sizeof(int)*arr_len);
	int *right = (int*)malloc(sizeof(int)*arr_len);
	int i, j, templ, tempr, answer;
	i = 0;
	while(i<arr_len) {
		left[i] = 1;
		right[i] = 1;
		++i;
	}

	i = 0;
	while(i<arr_len) {
		j = 0;
		templ = 0;
		tempr = 0;
		while(j<i) {
			if(templ<left[j] && arr[j]<arr[i]) templ = left[j];
			if(tempr<right[arr_len-j-1] && arr[arr_len-j-1]<arr[arr_len-i-1]) tempr = right[arr_len-j-1];
			++j;
		}
		left[i] = templ + 1;
		right[arr_len-i-1] = tempr + 1;
		++i;
	}
	i = 0;
	answer = 1;
	while(i<arr_len) {
		if(answer<left[i]+right[i]-1) answer = left[i] + right[i] - 1;
		++i;
	}

	free(left);
	free(right);

	return answer;
}
