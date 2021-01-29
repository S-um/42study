
#include <stdio.h>
#include <stdlib.h>

typedef struct s_linkedList {
	int num;
	struct s_linkedList *next;
}t_linkedList;

int main(void)
{
	int maxNum, skip, i;
	scanf("%d %d", &maxNum, &skip);
	
	t_linkedList *start;
	t_linkedList *temp;
	t_linkedList *linkTemp;
	start = (t_linkedList*)malloc(sizeof(t_linkedList));
	temp  = start;
	temp->num = 1;
	i = 2;
	while(i<maxNum) {
		temp->next = (t_linkedList*)malloc(sizeof(t_linkedList));
		temp = temp->next;
		temp->num = i;
		++i;
	}
	if(1 != maxNum) {
		temp->next = (t_linkedList*)malloc(sizeof(t_linkedList));
		temp = temp->next;
		temp->num = maxNum;
		temp->next = start;
	} else {
		temp->next = temp;
	}

	linkTemp = temp;
	temp = start;
	printf("<");
	while(1) {
		if(temp == temp->next)
			break;

		i = 1;
		while(i<skip) {
			linkTemp = temp;
			temp = temp->next;
			++i;
		}
		printf("%d, ", temp->num);
		linkTemp->next = temp->next;
		free(temp);
		temp = linkTemp->next;
	}
	printf("%d>\n",temp->num);
	free(temp);
}
