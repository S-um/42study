
#include <stdio.h>
#include <stdlib.h>

int cheap(int house, int ***price);
int cheap_i(int house, int ***price, int lastcolor, int curhouse,int cost, int *answer);

int main(void)
{
	int n;
	scanf("%d", &n);
	int ***price = (int***)malloc(sizeof(int**)*n);
	for(int i = 0; i < n; ++i) {
		price[i] = (int**)calloc(sizeof(int*),3);
		price[i][0] = (int*)calloc(sizeof(int),2);
		price[i][1] = (int*)calloc(sizeof(int),2);
		price[i][2] = (int*)calloc(sizeof(int),2);
		scanf("%d %d %d", price[i][0],price[i][1],price[i][2]);
	}
	printf("%d\n", cheap(n,price));
	for(int i = 0; i < n; ++i) {
		free(price[i][0]);
		free(price[i][1]);
		free(price[i][2]);
		free(price[i]);
	}
	free(price);

	return 0;
}

int cheap(int house, int ***price)
{
	int answer = 1000000;
	cheap_i(house,price,-1,0,0,&answer);

	return answer;
}

int cheap_i(int house, int ***price, int lastcolor, int curhouse,int cost, int *answer)
{
	int temp, aftercost = 1000000;
	if(curhouse == house) {
		if(cost < *answer) *answer = cost;
		return cost;
	}
	for(int i = 0; i < 3; ++i) {
		if(lastcolor == i) continue;
		if(!price[curhouse][i][1]) {
			temp = cheap_i(house,price,i,curhouse+1,cost+price[curhouse][i][0],answer);
			price[curhouse][i][1] = temp - cost;
			if(temp<aftercost) aftercost = temp;
			continue;
		}
		if(price[curhouse][i][1]+cost<aftercost) aftercost = price[curhouse][i][1]+cost;
		if(price[curhouse][i][1]+cost<*answer) *answer = price[curhouse][i][1]+cost;
	}
	return aftercost;
}
