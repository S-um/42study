
#include <stdio.h>
#include <stdlib.h>

int getbigroute(int **triangle, int floor);
int curbigroute(int **triangle, int **routedata, int sum, int *answer, int floor, int curfloor, int index);

int main(void)
{
	int floor;
	scanf("%d", &floor);
	int **triangle = (int **)malloc(sizeof(int*)*floor);
	for(int i = 0; i < floor; ++i) {
		triangle[i] = (int*)malloc(sizeof(int)*(i+1));
		for(int j = 0; j <= i; ++j) {
			scanf("%d", triangle[i]+j);
		}
	}
	printf("%d\n",getbigroute(triangle, floor));
	for(int i = 0; i < floor; ++i) {
		free(triangle[i]);
	}
	free(triangle);

	return 0;
}

int getbigroute(int **triangle, int floor)
{
	int **routedata = (int**)malloc(sizeof(int*)*floor);
	for(int i = 0; i < floor; ++i) {
		routedata[i] = (int*)calloc(sizeof(int),i+1);
	}
	int answer = 0;
	int temp = curbigroute(triangle, routedata, triangle[0][0], &answer, floor, 1, 0);
	for(int i = 0; i < floor; ++i)
		free(routedata[i]);
	free(routedata);
	return temp;
}

int curbigroute(int **triangle, int **routedata, int sum, int *answer, int floor, int curfloor, int index)
{
	int temp, aftersum;
	if(curfloor == floor) {
		if(sum>*answer) *answer = sum;
		return sum;
	}

	if(!routedata[curfloor][index]) {
		temp = curbigroute(triangle, routedata, sum+triangle[curfloor][index], answer, floor, curfloor+1, index);
		routedata[curfloor][index] = temp - sum;
	} else temp = routedata[curfloor][index] + sum;
	
	aftersum = temp;

	if(!routedata[curfloor][index+1]) { 
		temp = curbigroute(triangle, routedata, sum+triangle[curfloor][index+1],answer,floor,curfloor+1, index+1);
		routedata[curfloor][index+1] = temp - sum;
	} else temp = routedata[curfloor][index+1] + sum;

	if(temp>aftersum) aftersum = temp;

	return aftersum;
}
