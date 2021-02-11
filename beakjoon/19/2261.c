
#include <stdio.h>
#include <stdlib.h>

typedef struct vector2d {
	int x;
	int y;
}vector2d;

int getDistance(vector2d loc1, vector2d loc2);
int getMinDistance(vector2d *locData, int dataCnt);

int main(void)
{
	int dataCnt, i;
	scanf("%d",&dataCnt);

	vector2d *locData = (vector2d*)malloc(dataCnt*sizeof(vector2d));
	i = 0;
	while(i<dataCnt) {
		scanf("%d %d",&(locData[i].x),&(locData[i].y));
		++i;
	}

	printf("%d\n",getMinDistance(locData,dataCnt));
	free(locData);
	
	return 0;
}

int getDistance(vector2d loc1, vector2d loc2)
{
	return (loc1.x - loc2.x)*(loc1.x - loc2.x) + (loc1.y - loc2.y)*(loc1.y - loc2.y);
}

int getMinDistance(vector2d *locData, int dataCnt)
{
	int minDistance = 800000000, i, j, distance;
	i = 0;
	while(i<dataCnt-1) {
		j = i+1;
		while(j<dataCnt) {
			distance = getDistance(locData[i],locData[j]);
			if(minDistance>distance)
				minDistance = distance;
			++j;
		}
		++i;
	}
	return minDistance;
}
