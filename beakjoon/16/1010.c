
#include <stdio.h>
#include <stdlib.h>

int bino(int n, int k);
int bino_i(int n, int k, int **db);

int main(void)
{
	int n,k;
	int cnt, i;
	scanf("%d", &cnt);
	i = 0;
	while(i<cnt) {
		scanf("%d %d", &k, &n);
		printf("%d\n", bino(n,k));
		++i;
	}

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
