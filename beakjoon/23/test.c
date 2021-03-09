
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

int A[SIZE];
int key[SIZE];

int BSearch(int arr[], int, int);
int compare(const void *a, const void *b)
{
	if(*(int*)a>*(int*)b)
		return 1;
	return 0;
}

int main(void) {
	int num1, num2;

	scanf("%d", &num1);
	for (int i = 0; i < num1; i++) {
		int ins;
		scanf("%d", &ins);
		A[i] = ins;
	}

	scanf("%d", &num2);
	for (int i = 0; i < num2; i++) {
		int ins;
		scanf("%d", &ins);
		key[i] = ins;
	}

	qsort(A,num1,sizeof(int),compare);


	for (int i = 0; i < num2; i++) {
		printf("%d\n", BSearch(A, key[i], num1));
	}
}

int BSearch(int arr[], int target, int size) {
	int low = 0;
	int high = size - 1;
	int mid = 0;

	while(low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == target) return 1;
		else if (arr[mid] > target) high = mid-1;
		else low = mid+1;
	}
	return 0;
}
