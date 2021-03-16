
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int linked_vertex;
	struct s_q *next;
}q;

typedef struct s_link
{
	int root_vertex;
	q *sp;
	q *ep;
}link;

void push_link_data(link *link_data, int vertex1, int vertex2);
void link_data_to_tree(link *link_data, int cur_vertex);

void free_link_data(link *link_data, int vertex_cnt);

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
	free_link_data(link_data, vertex_cnt);
}

void push_link_data(link *link_data, int vertex1, int vertex2)
{
	q *new1;
	q *new2;

	new1 = (q*)malloc(sizeof(q));
	new1->linked_vertex = vertex2;
	new1->next = NULL;
	new2 = (q*)malloc(sizeof(q));
	new2->linked_vertex = vertex1;
	new2->next = NULL;

	if(link_data[vertex1].sp)
	{
		link_data[vertex1].ep->next = new1;
		link_data[vertex1].ep = new1;
	}
	else
	{
		link_data[vertex1].sp = new1;
		link_data[vertex1].ep = new1;
	}
	if(link_data[vertex2].sp)
	{
		link_data[vertex2].ep->next = new2;
		link_data[vertex2].ep = new2;
	}
	else
	{
		link_data[vertex2].sp = new2;
		link_data[vertex2].ep = new2;
	}
}

void link_data_to_tree(link *link_data, int cur_vertex)
{
	q *link_vertex;
	int next_vertex;
	link_vertex = link_data[cur_vertex].sp;
	while(link_vertex)
	{
		next_vertex = link_vertex->linked_vertex;
		if(link_data[cur_vertex].root_vertex != next_vertex && next_vertex) 
		{
			link_data[next_vertex].root_vertex = cur_vertex;
			link_data_to_tree(link_data,next_vertex);
		}
		link_vertex = link_vertex->next;
	}
}

void free_q(q *ptr)
{
	if(ptr)
	{
		free_q(ptr->next);
		free(ptr);
	}
}

void free_link_data(link *link_data, int vertex_cnt)
{
	int i;
	i = 0;
	while(i<=vertex_cnt)
	{
		free_q(link_data[i].sp);
		++i;
	}
	free(link_data);
}
