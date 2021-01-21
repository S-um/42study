
#include <stdio.h>
#include <stdlib.h>

long long savemoney(int *road, int *price, int cnt);

int main(void)
{
	int cnt;
	scanf("%d", &cnt);
	int *road = (int*)malloc((cnt-1)*sizeof(int));
	int *price = (int*)malloc(cnt*sizeof(int));
	int i = 0;
	while(i<cnt-1)
		scanf("%d", road+(i++));
	i = 0;
	while(i<cnt)
		scanf("%d", price+(i++));

	printf("%lld\n", savemoney(road,price,cnt));

	return 0;
}

long long savemoney(int *road, int *price, int cnt)
{
	int i = 0, j;
	long long answer = 0;
	while(i<cnt) {
		j = i+1;
		while(j<cnt && price[j]>=price[i]) {
			answer += road[j-1] * price[i];
			++j;
		}
		answer += road[j-1] * price[i];
		i = j;
	}

	return answer;
}
