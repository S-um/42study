
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int num;
	struct stack *next;
} stack;

void push(stack **starptr, char *s);
void pop(stack **starptr);
void top(stack **starptr);
void size(stack **starptr);
void empty(stack **starptr);
void endstack(stack *starptr);

int main(void)
{
	int n, i;
	char s[15] = {0,};
	scanf("%d\n", &n);
	stack *startp = NULL;
	
	i = 0;
	while(i<n) {
		fgets(s,15,stdin);
		switch(s[0]) {
			case 'p':
				if('u' == s[1])
					push(&startp,s);
				else
					pop(&startp);
				break;
			case 's':
				size(&startp);
				break;
			case 'e':
				empty(&startp);
				break;
			case 't':
				top(&startp);
				break;
		}
		++i;
	}
	endstack(startp);

	return 0;
}


void push(stack **starptr, char *s)
{
	int i = 5, num = 0;
	while(s[i] != '\n') {
		num *= 10;
		num += s[i] - '0';
		++i;
	}

	stack *new = (stack*)malloc(sizeof(stack));
	new->num = num;
	new->next = *starptr;
	(*starptr) = new;

	return;
}

void pop(stack **starptr)
{
	if((*starptr) == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d\n", (*starptr)->num);
	stack *temp = (*starptr);
	(*starptr) = (*starptr)->next;
	free(temp);

	return;
}

void top(stack **starptr)
{
	if((*starptr) == NULL)
		printf("-1\n");
	else
		printf("%d\n", (*starptr)->num);

	return;
}

void size(stack **starptr)
{
	int i = 0;
	stack *stackptr = (*starptr);
	while(stackptr != NULL) {
		stackptr = stackptr->next;
		++i;
	}
	printf("%d\n", i);

	return;
}

void empty(stack **starptr)
{
	if((*starptr) == NULL)
		printf("1\n");
	else
		printf("0\n");

	return;
}

void endstack(stack *starptr)
{
	stack *stptr = starptr;
	
	if(stptr == NULL)
		return;
	if(stptr->next != NULL)
		endstack(stptr->next);

	free(stptr);

	return;
}
