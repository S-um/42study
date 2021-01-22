
#include <stdio.h>
#include <stdlib.h>

typedef struct s_queue {
	int num;
	struct s_queue *next;
	struct s_queue *previous;
}t_queue;

typedef struct s_q {
	t_queue *sp;
	t_queue *ep;
	int size;
}q;

q *startqueue();
void push(q *queue, int num);
int pop(q *queue);
int size(q *queue);
int empty(q *queue);
int front(q *queue);
int back(q *queue);

int main(void)
{
	
}

q *startqueue()
{
	q *new = (q*)malloc(sizeof(q));
	new->sp = NULL;
	new->ep = NULL;
	new->size = 0;

	return new;
}

void push(q *queue, int num)
{
	t_queue *newdata = (t_queue*)malloc(sizeof(t_queue));
	newdata->previous = NULL;
	newdata->next = NULL;
	newdata->num = num;
	if(queue->ep == NULL) {
		queue->ep = newdata;
		queue->sp = newdata;
		queue->size += 1;
	} else {
		newdata->previous = queue->ep;
		queue->ep->next = newdata;
		queue->ep = newdata;
		queue->size += 1;
	}

	return;
}

int pop(q *queue)
{
	
}

int size(q *queue)
{
	
}

int empty(q *queue)
{
	
}

int front(q *queue)
{
	
}

int back(q *queue)
{
	
}
