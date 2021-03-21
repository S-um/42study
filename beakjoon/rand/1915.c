
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vector2d
{
	int row;
	int col;
}vector2d;

int **make_map(vector2d map_len);
int fill_map(int **map, vector2d map_len);
int get_bsq_len(int **map,vector2d map_len);
void free_map(int **map, int row_len);
int get_min_near_index(int **map, vector2d cur);

int main(void)
{
	vector2d map_len;
	int **map;
	int bsq_len;

	scanf("%d %d",&(map_len.row),&(map_len.col));
	map = make_map(map_len);
	if(fill_map(map,map_len))
	{
		printf("error\n");
		return -1;
	}
	if(0 == map)
	{
		printf("error\n");
		return -1;
	}
	bsq_len = get_bsq_len(map,map_len);
	printf("%d\n",bsq_len*bsq_len);
	free_map(map,map_len.row);
	return 0;
}

int **make_map(vector2d map_len)
{
	int row;
	int **map;

	map = (int**)malloc((map_len.row + 1) * sizeof(int*));
	if(0 == map)
		return NULL;
	row = 0;
	while(row<=map_len.row)
	{
		map[row] = (int*)calloc((map_len.col + 1), sizeof(int));
		if(0 == map[row])
		{
			free_map(map,row-1);
			return NULL;
		}
		++row;
	}
	return map;
}

int fill_map(int **map, vector2d map_len)
{
	char *input;
	int row;
	int col;

	input = (char*)malloc((map_len.col + 1) * sizeof(char));
	if(0 == input)
		return 1;
	row = 1;
	while (row <= map_len.row)
	{
		scanf("%s",input);
		map[row][0] = 0;
		col = 1;
		while(col <= map_len.col)
		{
			map[row][col] = input[col-1] - '0';
			++col;
		}
		++row;
	}
	free(input);
	return 0;
}

int get_bsq_len(int **map,vector2d map_len)
{
	vector2d cur;
	int max;

	max = 0;
	cur.row = 1;
	while(cur.row<=map_len.row)
	{
		cur.col = 1;
		while(cur.col<=map_len.col)
		{
			if(map[cur.row][cur.col])
			{
				map[cur.row][cur.col] = get_min_near_index(map,cur) + 1;
				if(max<map[cur.row][cur.col])
					max = map[cur.row][cur.col];
			}
			++(cur.col);
		}
		++(cur.row);
	}
	return max;
}

void free_map(int **map, int row_len)
{
	int row;

	row = 0;
	while (row<=row_len)
		free(map[row++]);
	free(map);
}

int get_min_near_index(int **map, vector2d cur)
{
	int min;

	min = map[cur.row-1][cur.col-1];
	if(min>map[cur.row-1][cur.col])
		min = map[cur.row-1][cur.col];
	if(min>map[cur.row][cur.col-1])
		min = map[cur.row][cur.col-1];
	return min;
}
