
#include <stdio.h>
#include <stdlib.h>

int easystair(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n",easystair(n));

	return 0;
}

int easystair(int n)
{
	int answer = 0;
	int **num = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; ++i) num[i] = (int*)malloc(sizeof(int)*10);
	for(int i = 1; i < 10; ++i) num[0][i] = 1;
	num[0][0] = 0;
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < 9; ++j) {
			num[i][j] = (num[i-1][j-1] + num[i-1][j+1]) % 1000000000;
		}
		num[i][0] = num[i-1][1];
		num[i][9] = num[i-1][8];
	}
	for(int i = 0; i < 10; ++i) answer = (answer + num[n-1][i])%1000000000;

	return answer;
}
