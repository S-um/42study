
#include <stdio.h>
#include <stdlib.h>

typedef struct t_stack {
	int num;
	struct t_stack *next;
}t_stack;

void push(t_stack **start, int num);
void pop(t_stack **start);
void freestack(t_stack *stackptr);
void printfsum(t_stack *stackptr);

int main(void)
{
	int n, i, num;
	scanf("%d", &n);
	t_stack *str = NULL;

	i = 0;
	while(i<n) {
		scanf("%d", &num);
		if(num)
			push(&str,num);
		else
			pop(&str);
		++i;
	}

	printfsum(str);
	if(str != NULL)
		freestack(str);

	return 0;
}

void push(t_stack **start, int num)
{
	t_stack *new = (t_stack *)malloc(sizeof(t_stack));
	new->num = num;
	new->next = (*start);
	(*start) = new;

	return;
}

void pop(t_stack **start)
{
	t_stack *temp = (*start);
	(*start) = (*start)->next;
	free(temp);

	return;
}

void freestack(t_stack *stackptr)
{
	if(stackptr->next != NULL)
		freestack(stackptr->next);
	free(stackptr);

	return;
}

void printfsum(t_stack *stackptr)
{
	int sum = 0;
	while(stackptr != NULL) {
		sum += stackptr->num;
		stackptr = stackptr->next;
	}
	printf("%d\n",sum);

	return;
}
