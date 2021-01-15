
#include <stdio.h>
#include <stdlib.h>

void quicksort(int *arr, int length);
void quicksort_i(int *arr, int start, int end);

int main(void)
{
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", arr+i);
	}
	quicksort(arr, n);
	for(int i = 0; i < n; ++i) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}


void quicksort(int *arr, int length)
{
	quicksort_i(arr, 0, length-1);
	return;
}

void quicksort_i(int *arr, int start, int end)
{
	if(start == end) return;
	int pivot = start;
	int left = start+1;
	int right = end;
	int swaptemp;

	while(left <= right) {
		while(left <= right && arr[left] < arr[pivot]) //you can convert sorting system by changing '<' to '>'
			left++;
		while(right >= left && arr[right] > arr[pivot]) //you cna convert sorting system by changing '>' to '<'
			right--;

		if(left > right) {
			swaptemp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = swaptemp;
			quicksort_i(arr, 0 , right-1);
			quicksort_i(arr, right+1, end);
		} else {
			swaptemp = arr[right];
			arr[right] = arr[left];
			arr[left] = swaptemp;
		}
	}
	return;
}
