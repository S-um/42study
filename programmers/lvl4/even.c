
#include <stdio.h>
#include <stdlib.h>

void solution_i(int **a, int **temp, size_t a_rows, size_t a_cols, int cur_col, int *answer);
void solution_ii(int **a, int **temp, size_t a_rows, size_t a_cols, int cur_col, int*answer, int cur_row, int cur_cnt, int cnt);
int solution(int** a, size_t a_rows, size_t a_cols);

int main(void)
{
	int row, col;
	scanf("%d %d", &row, &col);
	int **arr = (int**)malloc(row * sizeof(int*));
	int i = 0, j;
	while(i<row) {
		arr[i] = (int*)malloc(col * sizeof(int));
		j = 0;
		while(j<col) {
			scanf("%d", arr[i]+j);
			++j;
		}
		++i;
	}
	printf("%d\n", solution(arr,row,col));
	i = 0;
	while(i<row)
		free(arr[i++]);
	free(arr);
	return 0;
}

void solution_ii(int **a, int **temp, size_t a_rows, size_t a_cols, int cur_col, int*answer, int cur_row, int cur_cnt, int cnt)
{
	if(cnt == cur_cnt) {
		solution_i(a,temp,a_rows,a_cols,cur_col+1,answer);
		return;
	}
	if(a_rows == cur_row)
		return;

	int i = cur_row;
	while(i<a_rows) {
		temp[i][cur_col] = 1;
		solution_ii(a,temp,a_rows,a_cols,cur_col,answer,i+1,cur_cnt+1,cnt);
		temp[i][cur_col] = 0;
		++i;
	}
}

void solution_i(int **a, int **temp, size_t a_rows, size_t a_cols, int cur_col, int *answer) {
	if(cur_col == a_cols) {
		int i = 0, j, oneCnt, isAnswer = 1;
		while(i<a_rows) {
			j = 0;
			oneCnt = 0;
			while(j<a_cols) {
				if(temp[i][j])
					++oneCnt;
				++j;
			}
			if(oneCnt%2) {
				isAnswer = 0;
				break;
			}
			++i;
		}
		if(isAnswer)
			*answer += 1;
		return;
	} else {
		int i = 0, cnt = 0;
		while(i<a_rows) {
			if(a[i][cur_col])
				++cnt;
			++i;
		}
		solution_ii(a,temp,a_rows,a_cols,cur_col,answer,0,0,cnt);
	}
}

int solution(int** a, size_t a_rows, size_t a_cols) {
	int answer = 0;
	int **temp = (int**)malloc(a_rows * sizeof(int*));
	int i = 0;
	while(i<a_rows)
		temp[i++] = (int*)calloc(a_cols,sizeof(int));
	solution_i(a,temp,a_rows,a_cols,0,&answer);
	return answer;
}
