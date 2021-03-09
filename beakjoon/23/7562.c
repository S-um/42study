
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
	int x;
	int y;
	int cnt;
	struct s_q *next;
}q;

typedef struct s_q_controller
{
	q *sp;
	q *ep;
}q_controller;

int move_knight();
q_controller *make_q_controller();
int push_q(int x, int y, int cnt, q_controller *controller);
q *pop_q(q_controller *controller);
void free_q_controller(q_controller *controller);
void free_q(q *ptr);

int main(void)
{
	int i;
	int tc;

	scanf("%d",&tc);
	i = 0;
	while(i<tc) {
		printf("%d\n",move_knight());
		++i;
	}
	return 0;
}

int move_knight()
{
	int i;
	int len;
	int cnt;
	int s_x;
	int s_y;
	int e_x;
	int e_y;
	int cur_x;
	int cur_y;
	int cur_cnt;
	q *cur_q;
	q_controller *controller;

	int move[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
	int **plate;


	scanf("%d",&len);
	scanf("%d %d",&s_x,&s_y);
	scanf("%d %d",&e_x,&e_y);

	plate = (int**)malloc(len * sizeof(int*));
	i = 0;
	while(i<len)
		plate[i++] = (int*)calloc(len,sizeof(int));
	controller = make_q_controller();
	push_q(s_x,s_y,0,controller);

	while(controller->sp) {
		cur_q = pop_q(controller);
		cur_cnt = cur_q->cnt + 1;
		if(e_x == cur_q->x && e_y == cur_q->y) {
			cnt = cur_q->cnt;
			free(cur_q);
			break;
		}

		i = 0;
		while(i<8) {
			cur_x = cur_q->x + move[i][0];
			cur_y = cur_q->y + move[i][1];
			if(0<=cur_x && cur_x<len && 0<=cur_y && cur_y<len && !plate[cur_y][cur_x]) {
				plate[cur_y][cur_x] = 1;
				push_q(cur_x,cur_y,cur_cnt,controller);
			}
			++i;
		}

		free(cur_q);
	}

	free_q_controller(controller);
	i = 0;
	while(i<len)
		free(plate[i++]);
	free(plate);
	return cnt;
}

q_controller *make_q_controller()
{
	q_controller *controller;
	controller = (q_controller*)malloc(sizeof(q_controller));
	if(controller) {
		controller->sp = NULL;
		controller->ep = NULL;
	}
	return controller;
}

int push_q(int x, int y, int cnt, q_controller *controller)
{
	q *new;
	new = (q*)malloc(sizeof(q));
	if(NULL == new)
		return 0;
	new->x = x;
	new->y = y;
	new->cnt = cnt;
	new->next = NULL;
	if(controller->sp) {
		controller->ep->next = new;
		controller->ep = new;
	}else{
		controller->sp = new;
		controller->ep = new;
	}
	return 1;
}

q *pop_q(q_controller *controller)
{
	q *ret;
	ret = controller->sp;
	controller->sp = controller->sp->next;
	if(NULL == controller->sp)
		controller->ep = NULL;

	ret->next = NULL;
	return ret;
}

void free_q_controller(q_controller *controller)
{
	free_q(controller->sp);
	free(controller);
}

void free_q(q *ptr)
{
	if(ptr) {
		free_q(ptr->next);
		free(ptr);
	}
}
