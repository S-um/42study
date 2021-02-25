
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int num;
	struct s_q *next;
}q;

int **makeMap(int len);
void searchMap(int **map, int len);
void searchMap_i(int **map, int len, int x, int y, int *cnt);
void freeMap(int **map, int len);

void pushQ(q **que, int num);
void qtoa_i(q *que, int *array, int curIndex);
int *qtoa(q *que, int qLen);
void freeQ(q *que);

int compare(const void *a, const void *b);

int main(void)
{
	int len;
	int **map;
	scanf("%d", &len);

	map = makeMap(len);
	searchMap(map,len);
	freeMap(map,len);
}

int **makeMap(int len)
{
	int i, j;
	int **map;
	char *inputData;
	map = (int**)malloc(len*sizeof(int*));
	inputData = (char*)malloc((len+1)*sizeof(char));
	i = 0;
	while(i<len) {
		map[i] = (int*)malloc(len*sizeof(int));
		scanf("%s",inputData);
		j = 0;
		while(j<len) {
			map[i][j] = inputData[j]-'0';
			++j;
		}
		++i;
	}
	free(inputData);
	return map;
}

void searchMap(int **map, int len)
{
	int i, j;
	int cnt,bigCnt;
	int *qData;
	q *que;
	que = NULL;

	bigCnt = 0;
	i = 0;
	while(i<len) {
		j = 0;
		while(j<len) {
			if(map[i][j]) {
				cnt = 0;
				++bigCnt;
				searchMap_i(map,len,j,i,&cnt);
				pushQ(&que,cnt);
			}
			++j;
		}
		++i;
	}
	qData = qtoa(que, bigCnt);
	freeQ(que);
	qsort(qData,bigCnt,sizeof(int),&compare);

	printf("%d\n",bigCnt);
	i = 0;
	while(i<bigCnt)
		printf("%d\n",qData[i++]);

	free(qData);
}

void searchMap_i(int **map, int len, int x, int y, int *cnt)
{
	++(*cnt);
	map[y][x] = 0;
	if(x>0 && map[y][x-1])
		searchMap_i(map,len,x-1,y,cnt);
	if(x<len-1 && map[y][x+1])
		searchMap_i(map,len,x+1,y,cnt);
	if(y>0 && map[y-1][x])
		searchMap_i(map,len,x,y-1,cnt);
	if(y<len-1 && map[y+1][x])
		searchMap_i(map,len,x,y+1,cnt);
}

void freeMap(int **map, int len)
{
	int i = 0;
	while(i<len)
		free(map[i++]);
	free(map);
}

void pushQ(q **que, int num)
{
	q *new = (q*)malloc(sizeof(q));
	new->num = num;
	new->next = NULL;

	if(NULL == *que) {
		*que = new;
		return;
	}

	q *ptr = *que;
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void qtoa_i(q *que, int *array, int curIndex)
{
	if(que) {
		array[curIndex] = que->num;
		qtoa_i(que->next,array,curIndex+1);
	}
}

int *qtoa(q *que, int qLen)
{
	int *array = (int*)malloc(qLen*sizeof(int));
	qtoa_i(que,array,0);

	return array;
}

void freeQ(q *que)
{
	if(que) {
		freeQ(que->next);
		free(que);
	}
}


int compare(const void *a, const void *b)
{
	if(*(int*)a>*(int*)b)
		return 1;
	else
		return 0;
}
