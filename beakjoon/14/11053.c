
#include <stdio.h>
#include <stdlib.h>

int longarr(int *arr, int arr_len);

int main(void)
{
	int arr_len;
	scanf("%d", &arr_len);
	int *arr = (int*)malloc(sizeof(int)*arr_len);
	for(int i = 0; i < arr_len; ++i) scanf("%d", arr+i);

	printf("%d\n", longarr(arr,arr_len));

	free(arr);

	return 0;
}

int longarr(int *arr, int arr_len)
{
	int i, j, temp, answer = 0;
	int *smallcount = (int*)malloc(sizeof(int)*arr_len);
	i = 0;
	while(i<arr_len) {
		smallcount[i] = 1;
		++i;
	}

	i = 0;
	while(i<arr_len) {
		j = 0;
		temp = 0;
		while(j<i) {
			if(temp<smallcount[j] && arr[j]<arr[i]) temp = smallcount[j];
			++j;
		}
		smallcount[i] = temp + 1;
		if(answer<temp+1) answer = temp + 1;
		++i;
	}


	free(smallcount);

	return answer;
}
