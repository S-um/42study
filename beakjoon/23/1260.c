
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int index;
	struct s_q *next;
}q;

void inputNodeData(int **graph, int linkedVertex1, int linkedVertex2);
void freeNodeData(int **graph, int nodeCnt);

void DFSNode(int **graph, int startIndex, int vertexCnt);
void DFSNode_i(int **graph, int curIndex, int vertexCnt, int *unaccessedData);

void BFSNode(int **graph, int startIndex, int vertexCnt);
void BFSNode_i(int **graph, int curIndex, int vertexCnt, int *unaccessedData, q *que);

void pushQ(q **que, int num);
int popQ(q **que);

int main(void)
{
	int vertexCnt, nodeCnt, startIndex;
	int linkedVertex1, linkedVertex2;
	int i;
	int **graph;

	scanf("%d %d %d",&vertexCnt,&nodeCnt,&startIndex);
	graph = (int**)malloc((vertexCnt+1)*sizeof(int*));

	graph[0] = NULL;
	i = 1;
	while(i<=vertexCnt)
		graph[i++] = (int*)calloc((vertexCnt+1),sizeof(int));

	i = 1;
	while(i<=nodeCnt) {
		scanf("%d %d",&linkedVertex1,&linkedVertex2);
		inputNodeData(graph,linkedVertex1,linkedVertex2);
		++i;
	}

	DFSNode(graph,startIndex,vertexCnt);
	BFSNode(graph,startIndex,vertexCnt);

	freeNodeData(graph,vertexCnt);
}

void inputNodeData(int **graph, int linkedVertex1, int linkedVertex2)
{
	graph[linkedVertex1][linkedVertex2] = 1;
	graph[linkedVertex2][linkedVertex1] = 1;
}

void freeNodeData(int **graph, int vertexCnt)
{
	int i;
	i = 1;
	while(i<=vertexCnt)
		free(graph[i++]);
	free(graph);
}


void DFSNode(int **graph, int startIndex, int vertexCnt)
{
	int i;
	int *unaccessedData;

	unaccessedData = (int*)malloc((vertexCnt+1)*sizeof(int));
	i = 0;
	while(i<=vertexCnt)
		unaccessedData[i++] = 1;

	DFSNode_i(graph,startIndex,vertexCnt,unaccessedData);
	printf("\n");

	free(unaccessedData);
}

void DFSNode_i(int **graph, int curIndex, int vertexCnt, int *unaccessedData)
{
	int index;
	unaccessedData[curIndex] = 0;
	printf("%d ",curIndex);

	index = 1;
	while(index<=vertexCnt) {
		if(graph[curIndex][index] && unaccessedData[index]) {
			DFSNode_i(graph,index,vertexCnt,unaccessedData);
		}
		++index;
	}
}


void BFSNode(int **graph, int startIndex, int vertexCnt)
{
	int i;
	int *unaccessedData;

	unaccessedData = (int*)malloc((vertexCnt+1)*sizeof(int));
	i = 0;
	while(i<=vertexCnt)
		unaccessedData[i++] = 1;

	unaccessedData[startIndex] = 0;
	BFSNode_i(graph,startIndex,vertexCnt,unaccessedData,NULL);
	printf("\n");

	free(unaccessedData);
}

void BFSNode_i(int **graph, int curIndex, int vertexCnt, int *unaccessedData, q *que)
{
	int index, nextSearchIndex;
	printf("%d ",curIndex);

	index = 1;
	while(index<=vertexCnt) {
		if(graph[curIndex][index] && unaccessedData[index]) {
			pushQ(&que,index);
			unaccessedData[index] = 0;
		}
		++index;
	}

	nextSearchIndex = popQ(&que);
	if(nextSearchIndex) {
		BFSNode_i(graph,nextSearchIndex,vertexCnt,unaccessedData,que);
	}
}


void pushQ(q **que, int num)
{
	q *new = (q*)malloc(sizeof(q));
	new->index = num;
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

int popQ(q **que)
{
	if(NULL == *que)
		return 0;
	int ret = (*que)->index;
	q *temp = *que;
	*que = (*que)->next;
	free(temp);

	return ret;
}
