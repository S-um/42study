
#include <stdio.h>
#include <stdlib.h>

typedef struct s_link
{
	int root_vertex;
	int linked_vertex[3];
}link;

void push_link_data(link *link_data, int vertex1, int vertex2);
void link_data_to_tree(link *link_data, int cur_vertex);

int main(void)
{
	int vertex_cnt;
	int i;
	int vertex1;
	int vertex2;
	link *link_data;

	scanf("%d",&vertex_cnt);
	link_data = (link*)calloc((vertex_cnt + 1), sizeof(link));

	i = 1;
	while(i<vertex_cnt)
	{
		scanf("%d %d",&vertex1,&vertex2);
		push_link_data(link_data,vertex1,vertex2);
		++i;
	}

	link_data_to_tree(link_data,1);

	i = 2;
	while(i<=vertex_cnt)
	{
		printf("%d\n",link_data[i].root_vertex);
		++i;
	}
	free(link_data);
}

void push_link_data(link *link_data, int vertex1, int vertex2)
{
	int i;
	i = 0;
	while(i<3)
	{
		if(!link_data[vertex1].linked_vertex[i])
		{
			link_data[vertex1].linked_vertex[i] = vertex2;
			break;
		}
		++i;
	}
	i = 0;
	while(i<3)
	{
		if(!link_data[vertex2].linked_vertex[i])
		{
			link_data[vertex2].linked_vertex[i] = vertex1;
			break;
		}
		++i;
	}
}

void link_data_to_tree(link *link_data, int cur_vertex)
{
	int i;
	int next_vertex;
	i = 0;
	while(i<3)
	{
		next_vertex = link_data[cur_vertex].linked_vertex[i];
		if(link_data[cur_vertex].root_vertex != next_vertex && next_vertex) 
		{
			link_data[next_vertex].root_vertex = cur_vertex;
			link_data_to_tree(link_data,next_vertex);
		}
		++i;
	}
}
