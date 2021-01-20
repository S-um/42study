
#include <stdio.h>
#include <stdlib.h>

int backpack(int **pack, int pack_count, int max);
int getbigger(int i, int j);

int main(void)
{
	int pack_count, max, i;
	scanf("%d %d", &pack_count, &max);
	int **pack = (int**)malloc(pack_count * sizeof(int*));
	i = 0;
	while(i<pack_count) {
		pack[i] = (int*)malloc(2 * sizeof(int));
		scanf("%d %d", pack[i], pack[i]+1);
		++i;
	}
	printf("%d\n", backpack(pack, pack_count, max));

	return 0;
}

int backpack(int **pack, int pack_count, int max)
{
	int answer = 0, i, j;
	int **dp = (int**)malloc(pack_count*sizeof(int*));
	i = 0;
	while(i<pack_count)
		dp[i++] = (int*)calloc(max+1,sizeof(int));

	j = 0;
	while(j<=max) {
		dp[0][j] = pack[0][1] * (j>=pack[0][0]);
		++j;
	}

	i = 1;
	while(i<pack_count) {
		j = 0;
		while(j<=max) {
			if(j>=pack[i][0])
				dp[i][j] = getbigger(dp[i-1][j],dp[i-1][j-pack[i][0]]+pack[i][1]);
			else
				dp[i][j] = dp[i-1][j];
			++j;
		}
		++i;
	}

	answer = dp[pack_count-1][max];
	i = 0;
	while(i<pack_count)
		free(dp[i++]);
	free(dp);
	return answer;
}


int getbigger(int i, int j)
{
	if(i>=j) return i;
	return j;
}
