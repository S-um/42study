
#include <stdio.h>
#include <stdlib.h>

typedef struct s_binary_tree
{
	int vertex;
	struct s_binary_tree *left;
	struct s_binary_tree *right;
}binary_tree;

binary_tree *make_tree(int *post, int *in, int vertex_cnt, int last_in_index);
void print_tree_preorder(binary_tree *ptr);
void free_tree(binary_tree *ptr);

int main(void)
{
	int *post;
	int *in;
	int vertex_cnt;
	int in_input;
	int i;
	binary_tree *tree;

	scanf("%d",&vertex_cnt);
	post = (int*)malloc((vertex_cnt+1)*sizeof(int));
	in = (int*)malloc((vertex_cnt+1)*sizeof(int));
	i = 1;
	while(i<=vertex_cnt)
	{
		scanf("%d",&in_input);
		in[in_input] = i;
		++i;
	}
	i = 1;
	while(i<=vertex_cnt)
		scanf("%d",post+(i++));
	post[0] = vertex_cnt;

	tree = make_tree(post,in,vertex_cnt,0);
	print_tree_preorder(tree);
	free_tree(tree);
	free(post);
	free(in);
}

binary_tree *make_tree(int *post, int *in, int vertex_cnt, int last_in_index)
{
	binary_tree *new;
	if(post[0]<1)
		return NULL;
	if(in[post[0]]<in[last_in_index])
		return NULL;

	new = (binary_tree*)malloc(sizeof(binary_tree));
	new->vertex = post[post[0]];
	--post[0];
	new->right = make_tree(post,in,vertex_cnt,new->vertex);
	new->left = make_tree(post,in,vertex_cnt,last_in_index);
	return new;
}

void print_tree_preorder(binary_tree *ptr)
{
	if(ptr)
	{
		printf("%d ",ptr->vertex);
		print_tree_preorder(ptr->left);
		print_tree_preorder(ptr->right);
	}
}

void free_tree(binary_tree *ptr)
{
	if(ptr)
	{
		free_tree(ptr->left);
		free_tree(ptr->right);
		free(ptr);
	}
}
