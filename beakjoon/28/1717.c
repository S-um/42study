
#include <stdio.h>
#include <stdlib.h>

void union_set(int ver1, int ver2, int *union_data);
int find_top(int ver, int *union_data);

int *union_size;

int main(void)
{
	int vertex_cnt;
	int command_cnt;
	scanf("%d %d",&vertex_cnt,&command_cnt);
	int *union_data = (int*)malloc((vertex_cnt+1)*sizeof(int));
	union_size = (int*)malloc((vertex_cnt+1)*sizeof(int));
	int i = 0;
	int cmd;
	int ver1, ver2;
	i = 0;
	while(i<=vertex_cnt)
	{
		union_data[i] = i;
		union_size[i] = 1;
		++i;
	}
	i = 0;
	while(i<command_cnt)
	{
		scanf("%d %d %d",&cmd,&ver1,&ver2);
		if(cmd)
		{
			if(find_top(ver1,union_data) == find_top(ver2,union_data))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			union_set(ver1,ver2,union_data);
		}
		++i;
	}
	free(union_data);
}

void union_set(int ver1, int ver2, int *union_data)
{
	int ver1_top = find_top(ver1,union_data);
	int ver2_top = find_top(ver2,union_data);
	if(ver1_top == ver2_top)
		return;
	if(union_size[ver1]<=union_size[ver2])
	{
		union_data[ver1] = ver2;
		union_size[ver2] += union_size[ver1];
	}
	else
	{
		union_data[ver2] = ver1;
		union_size[ver1] += union_size[ver2];
	}
}

int find_top(int ver, int *union_data)
{
	if(union_data[ver] == ver)
		return ver;
	return find_top(union_data[ver],union_data);
}
