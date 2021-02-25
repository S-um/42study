
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
	int num;
	struct s_tree *parent;
	struct s_tree *left;
	struct s_tree *right;
}tree;

int goUpstair(tree *q);
int goDownStair(tree *q);
void push(tree *q, int num);

int main(void)
{
	int n, i, num;
	tree *q = NULL;
	scanf("%d",&n);

	i = 0;
	while(i<n) {
		scanf("%d",&num);
		push(q,num);
		printf("%d\n",q->num);
		++i;
	}
}
