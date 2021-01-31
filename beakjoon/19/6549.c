
#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int index;
	struct list *next;
}list;

long long bigSquare(int *height, int len);
void push(list **stack, int index);
int pop(list **stack);

int main(void) {
	int len, i;
	int *height;
	while(1) {
		scanf("%d",&len);
		if(!len)
			break;

		height = (int*)malloc((len+2)*sizeof(int));
		*height = 0;
		i = 1;
		while(i<=len)
			scanf("%d", height+(i++));
		height[i] = 0;
		printf("%lld\n",bigSquare(height,len));
		free(height);
	}
	return 0;
}

long long bigSquare(int *height, int len)
{
	list *stack = (list*)malloc(sizeof(list));
	stack->index = 0;
	stack->next = NULL;

	int i = 1, curIndex;
	long long maxArea = 0, area;
	++len;
	while(i<=len) {
		if(height[i]>=height[stack->index]) {
			push(&stack,i);
		}else{
			while(height[stack->index]>height[i]) {
				area = (long long)height[stack->index] * (i - stack->next->index - 1);
				if(area>maxArea)
					maxArea = area;
				pop(&stack);
			}
			push(&stack,i);
		}
		++i;
	}
	free(stack->next);
	free(stack);
	return maxArea;
}

void push(list **stack, int index)
{
	list *temp = (list*)malloc(sizeof(list));
	temp->index = index;
	temp->next = *stack;
	(*stack) = temp;
}

int pop(list **stack)
{
	int popIndex = (*stack)->index;
	list *temp = (*stack);
	*stack = (*stack)->next;
	free(temp);
	return popIndex;
}
