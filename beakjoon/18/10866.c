
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
	int num;
	struct s_list *previous;
	struct s_list *next;
}list;

typedef struct s_listController {
	list *sp;
	list *ep;
	int size;
}listController;

listController *startList();
void endList(listController *controller);
void endList_i(list *listptr);
void push_front(listController *controller, int num);
void push_back(listController *controller, int num);
int pop_front(listController *controller);
int pop_back(listController *controller);
int size(listController *controller);
int empty(listController *controller);
int front(listController *controller);
int back(listController *controller);

int main(void)
{
	char command[11] = {0,};
	int commandCnt, pushNum, i;
	scanf("%d", &commandCnt);
	i = 0;
	listController *controller = startList();

	while(i<commandCnt) {
		scanf("%s", command);
		switch(command[0]) {
			case 's':
				printf("%d\n", size(controller));
				break;
			case 'e':
				printf("%d\n", empty(controller));
				break;
			case 'f':
				printf("%d\n", front(controller));
				break;
			case 'b':
				printf("%d\n", back(controller));
				break;
			case 'p':
				switch(command[5]) {
					case 'f':
						scanf("%d", &pushNum);
						push_front(controller,pushNum);
						break;
					case 'b':
						scanf("%d", &pushNum);
						push_back(controller,pushNum);
						break;
					case 'r':
						printf("%d\n", pop_front(controller));
						break;
					case 'a':
						printf("%d\n", pop_back(controller));
						break;
				}
				break;
		}
		++i;
	}

	endList(controller);

	return 0;
}

listController *startList()
{
	listController *new = (listController*)malloc(sizeof(listController));
	new->sp = NULL;
	new->ep = NULL;
	new->size = 0;
	return new;
}

void endList(listController *controller)
{
	if(NULL != controller->sp)
		endList_i(controller->sp);

	free(controller);
}

void endList_i(list *listptr)
{
	if(NULL != listptr->next)
		endList_i(listptr->next);
	free(listptr);
}

void push_front(listController *controller, int num)
{
	list *new = (list*)malloc(sizeof(list));
	new->num = num;
	new->previous = NULL;
	new->next = controller->sp;
	controller->sp = new;
	if(NULL != new->next)
		new->next->previous = new;
	else
		controller->ep = new;
	
	controller->size += 1;
}

void push_back(listController *controller, int num)
{
	list *new = (list*)malloc(sizeof(list));
	new->num = num;
	new->next = NULL;
	new->previous = controller->ep;
	controller->ep = new;
	if(NULL != new->previous)
		new->previous->next = new;
	else
		controller->sp = new;
	controller->size += 1;
}

int pop_front(listController *controller)
{
	if(NULL != controller->sp) {
		int popNum = controller->sp->num;
		list *temp = controller->sp;
		controller->sp = controller->sp->next;
		if(NULL != controller->sp)
			controller->sp->previous = NULL;
		else
			controller->ep = NULL;
		free(temp);
		controller->size -= 1;
		return popNum;
	} else
		return -1;
}

int pop_back(listController *controller)
{
	if(NULL != controller->ep) {
		int popNum = controller->ep->num;
		list *temp = controller->ep;
		controller->ep = controller->ep->previous;
		if(NULL != controller->ep)
			controller->ep->next = NULL;
		else
			controller->sp = NULL;
		free(temp);
		controller->size -= 1;
		return popNum;
	} else
		return -1;
}

int size(listController *controller)
{
	return controller->size;
}

int empty(listController *controller)
{
	if(NULL == controller->sp)
		return 1;
	else
		return 0;
}

int front(listController *controller)
{
	if(NULL != controller->sp)
		return controller->sp->num;
	else
		return -1;
}

int back(listController *controller)
{
	if(NULL != controller->ep)
		return controller->ep->num;
	else
		return -1;
}
