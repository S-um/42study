
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
void finishqueue(q *queue);
void finishqueue_i(t_queue *t_queue);

int main(void)
{
	int commandLen, pushNum, i;
	char command[6];
	scanf("%d", &commandLen);

	q *que = startqueue();

	i = 0;
	while(i<commandLen) {
		scanf("%s", command);
		switch(command[0]) {
			case 's':
				printf("%d\n", size(que));
				break;
			case 'e':
				printf("%d\n",empty(que));
				break;
			case 'f':
				printf("%d\n",front(que));
				break;
			case 'b':
				printf("%d\n",back(que));
				break;
			case 'p':
				if('o' == command[1]) {
					printf("%d\n", pop(que));
					break;
				} else {
					scanf("%d", &pushNum);
					push(que,pushNum);
					break;
				}
		}
		++i;
	}

	finishqueue(que);

	return 0;
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
	if(NULL == queue->sp)
		return -1;

	int popNum = queue->sp->num;
	t_queue *temp = queue->sp;

	if(NULL == temp->next) {
		queue->sp = NULL;
		queue->ep = NULL;
		queue->size = 0;
	} else {
		queue->sp = queue->sp->next;
		queue->sp->previous = NULL;
		queue->size -= 1;
	}

	free(temp);
	return popNum;
}

int size(q *queue)
{
	return queue->size;
}

int empty(q *queue)
{
	if(NULL == queue->sp)
		return 1;
	else
		return 0;
}

int front(q *queue)
{
	if(NULL == queue->sp)
		return -1;
	return queue->sp->num;
}

int back(q *queue)
{
	if(NULL == queue->ep)
		return -1;
	return queue->ep->num;
}

void finishqueue(q *queue)
{
	finishqueue_i(queue->sp);
	free(queue);
}

void finishqueue_i(t_queue *t_queue)
{
	if(NULL != t_queue->next) {
		finishqueue_i(t_queue->next);
	}
	free(t_queue);
}
