
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int x;
	int y;
	int z;
	int day;
}q;

int getMinRipeDay(int ***map, int heightLen, int rowLen, int colLen);

int ***getMap(int heightLen, int rowLen, int colLen);
void freeMap(int ***map, int heightLen, int rowLen);
void pushQ(q *que, int ep, int z, int y, int x, int  day);

int main(void)
{
	int heightLen,rowLen,colLen;
	int ***map;
	scanf("%d %d %d",&colLen,&rowLen,&heightLen);

	map = getMap(heightLen,rowLen,colLen);
	printf("%d\n",getMinRipeDay(map,heightLen,rowLen,colLen));
	freeMap(map,heightLen,rowLen);
}

int getMinRipeDay(int ***map, int heightLen, int rowLen, int colLen)
{
	int day, sp, ep, x, y, z, rawCnt;
	int i, j, k;
	q *que;
	q curLoc;
	que = (q*)malloc((heightLen*rowLen*colLen)*sizeof(q));

	sp = 0;
	ep = -1;
	rawCnt = 0;
	i = 0;
	while(i<heightLen) {
		j = 0;
		while(j<rowLen) {
			k = 0;
			while(k<colLen) {
				if(1 == map[i][j][k]) {
					++ep;
					pushQ(que,ep,i,j,k,0);
				}else if(0 == map[i][j][k])
					++rawCnt;
				++k;
			}
			++j;
		}
		++i;
	}

	while(sp<=ep) {
		curLoc = que[sp++];
		z = curLoc.z;
		y = curLoc.y;
		x = curLoc.x;
		day = curLoc.day+1;

		if(z>0 && !map[z-1][y][x]) {
			map[z-1][y][x] = 1;
			++ep;
			pushQ(que,ep,z-1,y,x,day);
			--rawCnt;
		}
		if(z<heightLen-1 && !map[z+1][y][x]) {
			map[z+1][y][x] = 1;
			++ep;
			pushQ(que,ep,z+1,y,x,day);
			--rawCnt;
		}
		if(y>0 && !map[z][y-1][x]) {
			map[z][y-1][x] = 1;
			++ep;
			pushQ(que,ep,z,y-1,x,day);
			--rawCnt;
		}
		if(y<rowLen-1 && !map[z][y+1][x]) {
			map[z][y+1][x] = 1;
			++ep;
			pushQ(que,ep,z,y+1,x,day);
			--rawCnt;
		}
		if(x>0 && !map[z][y][x-1]) {
			map[z][y][x-1] = 1;
			++ep;
			pushQ(que,ep,z,y,x-1,day);
			--rawCnt;
		}
		if(x<colLen-1 && !map[z][y][x+1]) {
			map[z][y][x+1] = 1;
			++ep;
			pushQ(que,ep,z,y,x+1,day);
			--rawCnt;
		}
	}
	free(que);

	if(rawCnt)
		return -1;
	else
		return day-1;
}

int ***getMap(int heightLen, int rowLen, int colLen)
{
	int i, j, k;
	int ***map;
	map = (int***)malloc(heightLen*sizeof(int**));
	i = 0;
	while(i<heightLen) {
		map[i] = (int**)malloc(rowLen*sizeof(int*));
		j = 0;
		while(j<rowLen) {
			map[i][j]= (int*)malloc(colLen*sizeof(int));
			k = 0;
			while(k<colLen)
				scanf("%d",map[i][j]+(k++));
			++j;
		}
		++i;
	}
	return map;
}

void freeMap(int ***map, int heightLen, int rowLen)
{
	int i, j;

	i = 0;
	while(i<heightLen) {
		j = 0;
		while(j<rowLen)
			free(map[i][j++]);
		free(map[i++]);
	}
	free(map);
}

void pushQ(q *que, int ep, int z, int y, int x, int  day)
{
	que[ep].z = z;
	que[ep].y = y;
	que[ep].x = x;
	que[ep].day = day;
}
