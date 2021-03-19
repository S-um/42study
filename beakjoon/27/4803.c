
#include <stdio.h>
#include <stdlib.h>

void cnt_tree(int vertex_cnt, int line_cnt);

int main(void)
{
	int vertex_cnt;
	int line_cnt;
	int i;
	scanf("%d %d",&vertex_cnt,&line_cnt);
	i = 1;
	while(vertex_cnt && line_cnt)
	{
		printf("Case %d: ",i++);
		cnt_tree(vertex_cnt,line_cnt);
		scanf("%d %d",&vertex_cnt,&line_cnt);
		++i;
	}
}

int set_tree(int **link_data, int *vertex_tree_data, int vertex_cnt, int cur_vertex)
{
	int i = 1;
	int ret_val = 1;
	vertex_tree_data[cur_vertex] = 1;
	while(i<=vertex_cnt)
	{
		if(link_data[cur_vertex][i])
		{
			if(!vertex_tree_data[i])
			{
				link_data[cur_vertex][i] = 0;
				link_data[i][cur_vertex] = 0;
				if(!set_tree(link_data,vertex_tree_data,vertex_cnt,i))
					ret_val = 0;
			}
			else
			{
				ret_val = 0;
			}
		}
		++i;
	}
	return ret_val;
}

void cnt_tree(int vertex_cnt, int line_cnt)
{
	int **link_data;
	int *vertex_tree_data;
	int vertex1;
	int vertex2;
	int i;
	int tree_cnt;

	tree_cnt = 0;
	link_data = (int**)malloc((vertex_cnt+1)*sizeof(int*));
	vertex_tree_data = (int*)calloc((vertex_cnt+1),sizeof(int));
	i = 0;
	while(i<=vertex_cnt)
		link_data[i++] = (int*)calloc((vertex_cnt+1),sizeof(int));
	i = 0;
	while(i<line_cnt)
	{
		scanf("%d %d",&vertex1,&vertex2);
		link_data[vertex1][vertex2] = 1;
		link_data[vertex2][vertex1] = 1;
		++i;
	}
	i = 1;
	while(i<=vertex_cnt)
	{
		if(!vertex_tree_data[i])
		{
			if(set_tree(link_data,vertex_tree_data,vertex_cnt,i))
					++tree_cnt;
		}
		++i;
	}
	if(0 == tree_cnt)
		printf("No trees.\n");
	else if(1 == tree_cnt)
		printf("There is one tree.\n");
	else
		printf("A forest of %d trees.\n",tree_cnt);
	i = 0;
	while(i<=vertex_cnt)
		free(link_data[i++]);
	free(link_data);
	free(vertex_tree_data);
}
