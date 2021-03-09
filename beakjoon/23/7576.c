
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int x;
	int y;
	int day;
}q;

int **makeMap(int rowLen, int colLen);
void freeMap(int **map, int rowLen);

int getMinDay(int **map, int rowLen, int colLen);

int main(void)
{
	int rowLen, colLen;
	int **map;

	scanf("%d %d",&colLen,&rowLen);
	
	map = makeMap(rowLen,colLen);
	printf("%d\n",getMinDay(map,rowLen,colLen));
	freeMap(map,rowLen);
}

int **makeMap(int rowLen, int colLen)
{
	int i, j;
	int **map;

	map = (int**)malloc(rowLen*sizeof(int*));
	i = 0;
	while(i<rowLen) {
		map[i] = (int*)malloc(colLen*sizeof(int));
		j = 0;
		while(j<colLen)
			scanf("%d",map[i]+(j++));
		++i;
	}
	return map;
}

void freeMap(int **map, int rowLen)
{
	int i;
	i = 0;
	while(i<rowLen)
		free(map[i++]);
	free(map);
}


int getMinDay(int **map, int rowLen, int colLen)
{
	int day, rawCnt, x, y;
	int sp,ep;
	int i, j;
	q *que;
	q curLoc;
	
	que = (q*)malloc((rowLen*colLen)*sizeof(q));

	i = 0;
	rawCnt = 0;
	sp = 0;
	ep = -1;
	while(i<rowLen) {
		j = 0;
		while(j<colLen) {
			if(1 == map[i][j]) {
				++ep;
				que[ep].y = i;
				que[ep].x = j;
				que[ep].day = 0;
			}else if(0 == map[i][j]) {
				++rawCnt;
			}
			++j;
		}
		++i;
	}

	while(sp <= ep) {
		curLoc = que[sp++];
		x = curLoc.x;
		y = curLoc.y;
		day = curLoc.day+1;

		if(y>0 && !map[y-1][x]) {
			map[y-1][x] = 1;
			++ep;
			que[ep].y = y-1;
			que[ep].x = x;
			que[ep].day = day;
			--rawCnt;
		}
		if(y<rowLen-1 && !map[y+1][x]) {
			map[y+1][x] = 1;
			++ep;
			que[ep].y = y+1;
			que[ep].x = x;
			que[ep].day = day;
			--rawCnt;
		}
		if(x>0 && !map[y][x-1]) {
			map[y][x-1] = 1;
			++ep;
			que[ep].y = y;
			que[ep].x = x-1;
			que[ep].day = day;
			--rawCnt;
		}
		if(x<colLen-1 && !map[y][x+1]) {
			map[y][x+1] = 1;
			++ep;
			que[ep].y = y;
			que[ep].x = x+1;
			que[ep].day = day;
			--rawCnt;
		}
	}

	free(que);

	if(!rawCnt)
		return day-1;
	else
		return -1;
}
