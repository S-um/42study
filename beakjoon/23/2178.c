
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int x;
	int y;
	int distance;
	struct s_q *next;
}q;

int **makeMap(int rowLen, int colLen);
void freeMap(int **map, int rowLen);

int searchMaze(int **map, int rowLen, int colLen);

void pushQ(q **que, int y, int x, int distance);
q popQ(q **que);
void freeQ(q *que);

int main(void)
{
	int rowLen,colLen;
	int **map;

	scanf("%d %d",&rowLen,&colLen);
	map = makeMap(rowLen,colLen);
	printf("%d\n",searchMaze(map,rowLen,colLen));

	freeMap(map,rowLen);
}

int **makeMap(int rowLen, int colLen)
{
	int i,j;
	int **map;
	char *input;

	map = (int**)malloc(rowLen*sizeof(int*));
	input = (char*)malloc((colLen+1)*sizeof(char));

	i = 0;
	while(i<rowLen) {
		map[i]= (int*)malloc(colLen*sizeof(int));
		scanf("%s",input);
		
		j = 0;
		while(j<colLen) {
			map[i][j] = input[j]-'0';
			++j;
		}
		++i;
	}
	
	free(input);

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


int searchMaze(int **map, int rowLen, int colLen)
{
	int x, y;
	int distance;
	q *que;
	q searchData;

	que = NULL;
	pushQ(&que,0,0,1);
	map[0][0] = 0;

	while(1) {
		searchData = popQ(&que);
		x = searchData.x;
		y = searchData.y;
		distance = searchData.distance + 1;

		if(rowLen-1 == y && colLen-1 == x)
			break;

		if(y>0 && map[y-1][x]) {
			map[y-1][x] = 0;
			pushQ(&que,y-1,x,distance);
		}
		if(y<rowLen-1 && map[y+1][x]) {
			map[y+1][x] = 0;
			pushQ(&que,y+1,x,distance);
		}
		if(x>0 && map[y][x-1]) {
			map[y][x-1] = 0;
			pushQ(&que,y,x-1,distance);
		}
		if(x<colLen-1 && map[y][x+1]) {
			map[y][x+1] = 0;
			pushQ(&que,y,x+1,distance);
		}
	}

	freeQ(que);

	return distance-1;
}

void pushQ(q **que, int y, int x, int distance)
{
	q *ptr;
	q *new;
	new = (q*)malloc(sizeof(q));
	new->x = x;
	new->y = y;
	new->distance = distance;
	new->next = NULL;

	if(*que) {
		ptr = *que;
		while(ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}else{
		*que = new;
	}
}

q popQ(q **que)
{
	q ret;
	q *temp;

	ret = **que;
	ret.next = NULL;

	temp = *que;
	*que = (*que)->next;
	free(temp);

	return ret;
}

void freeQ(q *que)
{
	if(que) {
		freeQ(que->next);
		free(que);
	}
}
