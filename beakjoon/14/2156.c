
#include <stdio.h>
#include <stdlib.h>

int drinkwine(int *exhibitwine, int winecount);

int main(void)
{
	int winecount, i;
	scanf("%d", &winecount);
	int *exhibitwine = (int*)malloc(sizeof(int) * winecount);
	i = 0;
	while(i<winecount) scanf("%d", exhibitwine + (i++));
	printf("%d\n", drinkwine(exhibitwine, winecount));
	free(exhibitwine);
	
	return 0;
}

int drinkwine(int *exhibitwine, int winecount)
{
	if(1 == winecount) return exhibitwine[0];
	else if(2 == winecount) return exhibitwine[0]+exhibitwine[1];
	int i, answer;
	int *drinkedwine = (int*)calloc(sizeof(int),winecount);
	drinkedwine[0] = exhibitwine[0];
	drinkedwine[1] = exhibitwine[0]+exhibitwine[1];
	if(exhibitwine[0]>exhibitwine[1]) drinkedwine[2] = exhibitwine[0] + exhibitwine[2];
	else drinkedwine[2] = exhibitwine[1]+exhibitwine[2];
	if(drinkedwine[1]>drinkedwine[2]) drinkedwine[2] = drinkedwine[1];
	i = 3;
	while(i<winecount) {
		if(drinkedwine[i-2] > drinkedwine[i-3] + exhibitwine[i-1]) drinkedwine[i] = drinkedwine[i-2] + exhibitwine[i];
		else drinkedwine[i] = drinkedwine[i-3] + exhibitwine[i-1] + exhibitwine[i];
		if(drinkedwine[i-1]>drinkedwine[i]) drinkedwine[i] = drinkedwine[i-1];
		++i;
	}

	answer = drinkedwine[winecount-1];
	free(drinkedwine);

	return answer;
}
