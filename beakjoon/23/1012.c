
#include <stdio.h>
#include <stdlib.h>

void play();
int cntGroup(int **map, int rowLen, int colLen);
void cntGroup_i(int **map, int rowLen, int colLen, int curX, int curY);

int main(void)
{
	int tc;
	int i;

	scanf("%d", &tc);

	i = 0;
	while(i<tc) {
		play();
		++i;
	}
}

void play()
{
	int rowLen, colLen, vertexCnt;
	int vertexX, vertexY;
	int i;
	int **map;

	scanf("%d %d %d", &colLen, &rowLen, &vertexCnt);

	map = (int**)malloc(rowLen*sizeof(int*));
	i = 0;
	while(i<rowLen)
		map[i++] = (int*)calloc(colLen,sizeof(int));

	i = 0;
	while(i<vertexCnt) {
		scanf("%d %d",&vertexX,&vertexY);
		map[vertexY][vertexX] = 1;
		++i;
	}

	printf("%d\n",cntGroup(map,rowLen,colLen));

	i = 0;
	while(i<rowLen)
		free(map[i++]);
	free(map);
}

int cntGroup(int **map, int rowLen, int colLen)
{
	int i, j;
	int cnt;

	cnt = 0;
	i = 0;
	while(i<rowLen) {
		j = 0;
		while(j<colLen) {
			if(map[i][j]) {
				++cnt;
				cntGroup_i(map,rowLen,colLen,j,i);
			}
			++j;
		}
		++i;
	}
	return cnt;
}

void cntGroup_i(int **map, int rowLen, int colLen, int curX, int curY)
{
	map[curY][curX] = 0;

	if(curX>0 && map[curY][curX-1])
		cntGroup_i(map,rowLen,colLen,curX-1,curY);
	if(curX<colLen-1 && map[curY][curX+1])
		cntGroup_i(map,rowLen,colLen,curX+1,curY);
	if(curY>0 && map[curY-1][curX])
		cntGroup_i(map,rowLen,colLen,curX,curY-1);
	if(curY<rowLen-1 && map[curY+1][curX])
		cntGroup_i(map,rowLen,colLen,curX,curY+1);
}
