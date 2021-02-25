
#include <stdio.h>
#include <stdlib.h>

void inputGraphData(int **graph, int linkedVertex1, int linkedVertex2);
int searchGraph(int **graph, int startIndex, int vertexCnt);
void searchGraph_i(int **graph, int curIndex, int vertexCnt, int *unaccessedData, int *accessedVertexCnt);
void freeGraph(int **graph, int vertexCnt);

int main(void)
{
	int vertexCnt, nodeCnt;
	int linkedVertex1, linkedVertex2;
	int i;
	int **nodeData;
	scanf("%d",&vertexCnt);
	scanf("%d",&nodeCnt);

	nodeData = (int**)malloc((vertexCnt+1)*sizeof(int*));
	nodeData[0] = NULL;
	i = 1;
	while(i<=vertexCnt)
		nodeData[i++] = (int*)calloc((vertexCnt+1),sizeof(int));

	i = 0;
	while(i<nodeCnt) {
		scanf("%d %d", &linkedVertex1, &linkedVertex2);
		inputGraphData(nodeData,linkedVertex1,linkedVertex2);
		++i;
	}

	printf("%d\n",searchGraph(nodeData,1,vertexCnt));

	freeGraph(nodeData,vertexCnt);
}

void inputGraphData(int **graph, int linkedVertex1, int linkedVertex2)
{
	graph[linkedVertex1][linkedVertex2] = 1;
	graph[linkedVertex2][linkedVertex1] = 1;
}

int searchGraph(int **graph, int startIndex, int vertexCnt)
{
	int accessedVertexCnt;
	int i;
	int *unaccessedData;
	unaccessedData = (int*)malloc((vertexCnt+1)*sizeof(int));

	i = 0;
	while(i<=vertexCnt)
		unaccessedData[i++] = 1;

	accessedVertexCnt = 0;
	unaccessedData[startIndex] = 0;
	searchGraph_i(graph,startIndex,vertexCnt,unaccessedData,&accessedVertexCnt);
	free(unaccessedData);

	return accessedVertexCnt;
}

void searchGraph_i(int **graph, int curIndex, int vertexCnt, int *unaccessedData, int *accessedVertexCnt)
{
	int i;
	i = 1;
	while(i<=vertexCnt) {
		if(graph[curIndex][i] && unaccessedData[i]) {
			unaccessedData[i] = 0;
			++(*accessedVertexCnt);
			searchGraph_i(graph,i,vertexCnt,unaccessedData,accessedVertexCnt);
		}
		++i;
	}
}

void freeGraph(int **graph, int vertexCnt)
{
	int i;
	i = 1;
	while(i<=vertexCnt)
		free(graph[i++]);
	free(graph);
}
