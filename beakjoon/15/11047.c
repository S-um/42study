
#include <stdio.h>
#include <stdlib.h>

int coincnt(int *coin, int cnt, int money);

int main(void)
{
	int cnt, money, i;
	scanf("%d %d", &cnt, &money);
	int *coin = (int*)malloc(cnt*sizeof(int));
	i = 0;
	while(i<cnt)
		scanf("%d", coin+(i++));
	printf("%d\n", coincnt(coin,cnt,money));
	free(coin);

	return 0;
}

int coincnt(int *coin, int cnt, int money)
{
	int i, answer = 0;
	money /= coin[0];
	i = 1;
	while(i<cnt) {
		answer += money%(coin[i]/coin[i-1]);
		money /= coin[i]/coin[i-1];
		++i;
	}
	answer += money;
	return answer;
}
