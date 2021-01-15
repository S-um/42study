
#include <stdio.h>
#include <stdlib.h>

int* solution(int n);
void down(int **arr, int startNum, int y, int x, int n);
void right(int **arr, int startNum, int y, int x, int n);
void up(int **arr, int startNum, int y, int x, int n);

int main(void)
{
	int a;
	scanf("%d", &a);
	int * temp = solution(a);

	for(int i = 0; i < a * (a+1) / 2; i++) printf("%d ", temp[i]);

	free(temp);
	return 0;
}

int* solution(int n)
{
	int *answer = (int *)calloc(n * (n+1) / 2,  sizeof(int));
	int **arr = (int **)malloc(sizeof(int *) * n);
	for(int i = 0; i < n; ++i) {
		arr[i] = (int *)malloc(sizeof(int) * (i + 1));
	}

	down(arr, 1, 0, 0, n);


	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i+1; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	int temp = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i+1; ++j) {
			answer[temp + j] = arr[i][j];
		}
		temp += i+1;
	}


	for(int i = 0; i < n; ++i) {
		free(arr[i]);
	}
	free(arr);

	return answer;
}

void down(int **arr, int startNum, int y, int x, int n)
{
	if(!n) return;
	int temp = n - 1;
	while(n--) {
		arr[y++][x] = startNum++;
	}
	right(arr, startNum, y - 1, x+1, temp);

	return;
}

void right(int **arr, int startNum, int y, int x, int n)
{
	if(!n) return;
	int temp = n - 1;
	while(n--) {
		arr[y][x++] = startNum++;
	}
	up(arr, startNum, y-1, x-2, temp);

	return;
}

void up(int **arr, int startNum, int y, int x, int n)
{
	if(!n) return;
	int temp = n-1;
	while(n--) {
		arr[y--][x--] = startNum++;
	}
	down(arr, startNum, y+2, x+1, temp);

	return;
}
