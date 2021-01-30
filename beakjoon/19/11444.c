
#include <stdio.h>
#include <stdlib.h>

long long **powArr(long long pow);
long long **multiArr(long long **arr1, long long **arr2);

int main(void)
{
	long long targetNum;
	scanf("%lld",&targetNum);
	long long **pibo = powArr(targetNum);
	printf("%lld\n",pibo[1][0]);
	free(pibo[0]);
	free(pibo[1]);
	free(pibo);
	return 0;
}

long long **powArr(long long pow)
{
	long long **answer;
	if(1 == pow) {
		answer = (long long**)malloc(2*sizeof(long long*));
		answer[0] = (long long*)malloc(2*sizeof(long long));
		answer[1] = (long long*)malloc(2*sizeof(long long));
		answer[0][0] = 1;
		answer[0][1] = 1;
		answer[1][0] = 1;
		answer[1][1] = 0;
		return answer;
	}

	long long **temp = powArr(pow/2);
	long long **temp2;
	if(pow%2) {
		long long **arr = (long long**)malloc(2*sizeof(long long*));
		arr[0] = (long long*)malloc(2*sizeof(long long));
		arr[1] = (long long*)malloc(2*sizeof(long long));
		arr[0][0] = 1;
		arr[0][1] = 1;
		arr[1][0] = 1;
		arr[1][1] = 0;
		temp2 = multiArr(temp,temp);
		answer = multiArr(temp2,arr);
		free(temp2[0]);
		free(temp2[1]);
		free(temp2);
		free(arr[0]);
		free(arr[1]);
		free(arr);
	}else{
		answer = multiArr(temp,temp);
	}
	free(temp[0]);
	free(temp[1]);
	free(temp);
	return answer;
}

long long **multiArr(long long **arr1, long long **arr2)
{
	long long **answer = (long long**)malloc(2*sizeof(long long*));
	answer[0] = (long long*)malloc(2*sizeof(long long));
	answer[1] = (long long*)malloc(2*sizeof(long long));
	answer[0][0] = (arr1[0][0]*arr2[0][0] + arr1[0][1]*arr2[1][0])%1000000007;
	answer[0][1] = (arr1[0][0]*arr2[0][1] + arr1[0][1]*arr2[1][1])%1000000007;
	answer[1][0] = (arr1[1][0]*arr2[0][0] + arr1[1][1]*arr2[1][0])%1000000007;
	answer[1][1] = (arr1[1][0]*arr2[0][1] + arr1[1][1]*arr2[1][1])%1000000007;
	return answer;
}
