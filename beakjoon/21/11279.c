
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int num;
	struct list *next;
}list;

void push(list **q, int num);
int pop(list **q);
void freeList(list *q);

int main(void)
{
	int n, i, num;
	scanf("%d", &n);

	list *q = NULL;
	i = 0;
	while(i<n) {
		scanf("%d", &num);
		if(num>0)
			push(&q,num);
		else
			printf("%d\n",pop(&q));
		++i;
	}
	freeList(q);
}

void push(list **q, int num)
{
	list *temp = (list*)malloc(sizeof(list));
	list *before = *q;
	list *cur = *q;
	temp->num = num;

	if(NULL == (*q)) {
		temp->next = NULL;
		(*q) = temp;
		return;
	}

	if(num>=(*q)->num) {
		temp->next = (*q);
		(*q) = temp;
	}else{
		while(cur != NULL) {
			if(cur->num<=num) {
				break;
			}
			before = cur;
			cur = cur->next;
		}
		temp->next = before->next;
		before->next = temp;
	}
}

int pop(list **q)
{
	if(NULL == (*q)) {
		return 0;
	}
	list *temp = (*q);
	int popNum = (*q)->num;
	(*q) = (*q)->next;
	free(temp);
	return popNum;
}

void freeList(list *q)
{
	if(q != NULL) {
		freeList(q->next);
		free(q);
	}
}
