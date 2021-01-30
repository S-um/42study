
#include <stdio.h>
#include <stdlib.h>

int **powArr(int **arr, int len, long long pow);
int **multiArr(int **arr1, int **arr2, int len);

int main(void)
{
	int len, i, j;
	long long pow;
	scanf("%d %lld", &len, &pow);
	int **arr = (int**)malloc(len*sizeof(int*));
	int **answer;

	i = 0;
	while(i<len) {
		arr[i] = (int*)malloc(len*sizeof(int));
		j = 0;
		while(j<len)
			scanf("%d",arr[i]+(j++));
		++i;
	}

	answer = powArr(arr,len,pow);
	i = 0;
	while(i<len) {
		j = 0;
		while(j<len)
			printf("%d ",answer[i][j++]);
		printf("\n");
		++i;
	}


	i = 0;
	while(i<len) {
		free(answer[i]);
		free(arr[i]);
		++i;
	}
	free(answer);
	free(arr);
}

int **powArr(int **arr, int len, long long pow)
{
	int **answer;
	int i;
	if(1 == pow) {
		answer = (int**)malloc(len*sizeof(int*));
		i = 0;
		while(i<len)
			answer[i++] = (int*)malloc(len*sizeof(int));
		int j;
		i = 0;
		while(i<len) {
			j = 0;
			while(j<len) {
				answer[i][j] = arr[i][j] % 1000;
				++j;
			}
			++i;
		}
		return answer;
	}

	int **temp;
	int **temp2;

	temp = powArr(arr,len,pow/2);
	if(pow%2) {
		temp2 = multiArr(temp,temp,len);
		answer = multiArr(temp2,arr,len);
		i = 0;
		while(i<len)
			free(temp2[i++]);
		free(temp2);
	} else {
		answer = multiArr(temp,temp,len);
	}

	i = 0;
	while(i<len)
		free(temp[i++]);
	free(temp);

	return answer;
}

int **multiArr(int **arr1, int **arr2, int len)
{
	int i, j, m, temp;
	int **multi = (int**)malloc(len*sizeof(int*));

	i = 0;
	while(i<len)
		multi[i++] = (int*)malloc(len*sizeof(int));

	i = 0;
	while(i<len) {
		j = 0;
		while(j<len) {
			m = 0;
			temp = 0;
			while(m<len) {
				temp = (temp + (arr1[i][m] * arr2[m][j])) % 1000;
				++m;
			}
			multi[i][j] = temp;
			++j;
		}
		++i;
	}

	return multi;
}
