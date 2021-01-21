
#include <stdio.h>
#include <stdlib.h>

int bino(int n, int k);
int bino_i(int n, int k, int **db);

int main(void)
{
	int n,k;
	scanf("%d %d", &n, &k);
	printf("%d\n", bino(n,k));

	return 0;
}

int bino(int n, int k)
{
	int **db = (int**)malloc((n+1)*sizeof(int*));
	int i = 0;
	while(i<=n) {
		db[i] = (int*)calloc(i+1,sizeof(int));
		++i;
	}
	int answer = bino_i(n,k,db);
	int j;
	i = 0;
	while(i<=n) {
		j = 0;
		while(j<=i) {
			printf("%d ", db[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	i = 0;
	while(i<=n) {
		free(db[i]);
		++i;
	}
	free(db);
	return answer;
}

int bino_i(int n, int k, int **db)
{
	if(db[n][k])
		return db[n][k];
	if(k == 0 || n == k) {
		db[n][k] = 1;
		return 1;
	}
	db[n][k] = bino_i(n-1,k-1,db) + bino_i(n-1,k,db);
	return db[n][k];
}
