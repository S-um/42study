
#include <stdio.h>
#include <stdlib.h>

int solution(int nums[], size_t nums_len);
void setprimenum(int*arr, int maxnum);

int main(void)
{
	int len;
	scanf("%d", &len);
	int *arr = (int*)malloc(sizeof(int)*len);
	for(int i = 0; i < len; ++i) {
		scanf("%d", arr+i);
	}
	printf("%d\n", solution(arr, len));
	return 0;
}

int solution(int nums[], size_t nums_len)
{
	int *primenum = (int*)malloc(3001 * sizeof(int));
	setprimenum(primenum, 3000);
	int count = 0;
	for(int i = 0; i < nums_len-2; ++i) {
		for(int j = i+1; j < nums_len-1; ++j) {
			for(int m = j+1; m < nums_len; ++m) {
				if(primenum[nums[i]+nums[j]+nums[m]]) ++count;
			}
		}
	}

	free(primenum);
	return count;
}

void setprimenum(int*arr, int maxnum)
{
	for(int i = 2; i <= maxnum; ++i) {
		arr[i] = 1;
	}
	arr[0] = 0;
	arr[1] = 0;

	for(int i = 0; i <= maxnum; ++i) {
		if(arr[i]) {
			for(int j = 2; i*j<=maxnum; ++j) {
				arr[i*j] = 0;
			}
		}
	}
}
