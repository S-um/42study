
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m,k,i,j,print,p;
	scanf("%d %d", &n, &m);
	int **arr1 = (int**)malloc(n*sizeof(int*));
	i = 0;
	while(i<n) {
		arr1[i] = (int*)malloc(m*sizeof(int));
		j = 0;
		while(j<m)
			scanf("%d", arr1[i]+(j++));
		++i;
	}

	scanf("%d %d", &m, &k);
	int **arr2 = (int**)malloc(m*sizeof(int*));
	i = 0;
	while(i<m) {
		arr2[i] = (int*)malloc(k*sizeof(int));
		j = 0;
		while(j<k)
			scanf("%d", arr2[i]+(j++));
		++i;
	}

	i = 0;
	while(i<n) {
		j = 0;
		while(j<k) {
			p = 0;
			print = 0;
			while(p<m) {
				print += arr1[i][p]*arr2[p][j];
				++p;
			}
			printf("%d ",print);
			++j;
		}
		printf("\n");
		++i;
	}
	i = 0;
	while(i<n)
		free(arr1[i++]);
	free(arr1);
	i = 0;
	while(i<m)
		free(arr2[i++]);
	free(arr2);
}
