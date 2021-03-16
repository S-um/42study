
#include <stdio.h>
#include <stdlib.h>

typedef struct s_id
{
	int weight;
	int min_q_index;
}id;

typedef struct s_q
{
	int index;
	int weight;
	struct s_q *next;
}q;

typedef struct s_q_ctrl
{
	q *sp;
	q *ep;
}q_ctrl;

void push_link_data(q_ctrl *link_data, int index, int weight);

void push_min_q(int index, int weight, int *min_q, id *index_data);
int pop_min_q(int *min_q, id *index_data);
void update_min_q(int *min_q, id *index_data, int update_index);

int main(void)
{
	int vertex_cnt;
	int line_cnt;
	int start_index;
	int *min_q;
	int i;
	int cur_index;
	q *q_ptr;
	q_ctrl **link_data;

	int s_i, e_i, temp_weight;
	
	id *index_data;

	scanf("%d %d",&vertex_cnt,&line_cnt);
	scanf("%d",&start_index);

	min_q = (int*)malloc((vertex_cnt+1) * sizeof(int));
	min_q[0] = 1;

	index_data = (id*)malloc((vertex_cnt+1) * sizeof(id));
	i = 0;
	while(i<=vertex_cnt) {
		index_data[i].weight = -1;
		index_data[i].min_q_index = -1;
		++i;
	}

	link_data = (q_ctrl**)malloc((vertex_cnt+1) * sizeof(q_ctrl*));
	i = 0;
	while(i<=vertex_cnt)
		link_data[i++] = (q_ctrl*)calloc(1,sizeof(q_ctrl));

	i = 0;
	while(i<line_cnt)
	{
		scanf("%d %d %d",&s_i,&e_i,&temp_weight);
		push_link_data(link_data[s_i],e_i,temp_weight);
		++i;
	}



	index_data[start_index].weight = 0;
	index_data[start_index].min_q_index = 1;

	cur_index = start_index;
	while(cur_index)
	{
		q_ptr = link_data[cur_index]->sp;
		while(q_ptr)
		{
			if(-1 == index_data[q_ptr->index].weight)
			{
				push_min_q(q_ptr->index,q_ptr->weight + index_data[cur_index].weight,min_q,index_data);
			}
			else if(q_ptr->weight + index_data[cur_index].weight < index_data[q_ptr->index].weight)
			{
				index_data[q_ptr->index].weight = q_ptr->weight + index_data[cur_index].weight;
				update_min_q(min_q,index_data,q_ptr->index);
			}
			q_ptr = q_ptr->next;
		}
		
		cur_index = pop_min_q(min_q,index_data);
	}

	i = 1;
	while(i<=vertex_cnt)
	{
		if(-1 == index_data[i].weight)
			printf("INF\n");
		else
			printf("%d\n",index_data[i].weight);
		++i;
	}
}

void push_link_data(q_ctrl *link_data, int index, int weight)
{
	q *new;
	new = (q*)malloc(sizeof(q));
	new->index = index;
	new->weight = weight;
	new->next = NULL;
	
	if(link_data->sp)
	{
		link_data->ep->next = new;
		link_data->ep = new;
	}
	else
	{
		link_data->sp = new;
		link_data->ep = new;
	}
}

void push_min_q(int index, int weight, int *min_q, id *index_data)
{
	int q_index;
	int temp;
	q_index = min_q[0];
	++min_q[0];
	min_q[q_index] = index;
	index_data[index].min_q_index = q_index;
	index_data[index].weight = weight;
	while(q_index>1)
	{
		if(index_data[min_q[q_index]].weight < index_data[min_q[q_index/2]].weight)
		{
			index_data[min_q[q_index]].min_q_index = q_index/2;
			index_data[min_q[q_index/2]].min_q_index = q_index;
			temp = min_q[q_index];
			min_q[q_index] = min_q[q_index/2];
			min_q[q_index/2] = temp;
		}
		else
			return;
		q_index /= 2;
	}
}

int pop_min_q(int *min_q, id *index_data)
{
	int q_max;
	int q_index;
	int temp;
	int ret;

	if(min_q[0]>1)
	{
		ret = min_q[1];
		min_q[1] = min_q[min_q[0]-1];
		q_index = 1;
		while(q_index*2<min_q[0])
		{
			if(q_index*2 + 1 == min_q[0])
			{
				if(index_data[min_q[q_index*2]].weight<index_data[min_q[q_index]].weight)
				{
					index_data[min_q[q_index*2]].min_q_index = q_index;
					index_data[min_q[q_index]].min_q_index = q_index*2;
					temp = min_q[q_index];
					min_q[q_index] = min_q[q_index*2];
					min_q[q_index*2] = temp;
					q_index *= 2;
				}
				else
					break;
			}
			else
			{
				if(index_data[min_q[q_index*2]].weight <= index_data[min_q[q_index*2+1]].weight)
				{
					if(index_data[min_q[q_index*2]].weight<index_data[min_q[q_index]].weight)
					{
						index_data[min_q[q_index*2]].min_q_index = q_index;
						index_data[min_q[q_index]].min_q_index = q_index*2;
						temp = min_q[q_index];
						min_q[q_index] = min_q[q_index*2];
						min_q[q_index*2] = temp;
						q_index *= 2;
					}
					else
						break;
				}
				else
				{
					if(index_data[min_q[q_index*2+1]].weight<index_data[min_q[q_index]].weight)
					{
						index_data[min_q[q_index*2+1]].min_q_index = q_index;
						index_data[min_q[q_index]].min_q_index = q_index*2+1;
						temp = min_q[q_index];
						min_q[q_index] = min_q[q_index*2+1];
						min_q[q_index*2+1] = temp;
						q_index = q_index*2 + 1;
					}
					else
						break;
				}
			}
		}

		--min_q[0];

		return ret;
	}
	return 0;
}

void update_min_q(int *min_q, id *index_data, int update_index)
{
	int q_index;
	int temp;
	q_index = index_data[update_index].min_q_index;
	while(q_index>1)
	{
		if(index_data[min_q[q_index]].weight < index_data[min_q[q_index/2]].weight)
		{
			index_data[min_q[q_index]].min_q_index = q_index/2;
			index_data[min_q[q_index/2]].min_q_index = q_index;
			temp = min_q[q_index];
			min_q[q_index] = min_q[q_index/2];
			min_q[q_index/2] = temp;
		}
		else
			return;
		q_index /= 2;
	}
}
