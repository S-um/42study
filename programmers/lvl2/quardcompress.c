
#include <stdio.h>
#include <stdlib.h>

int* solution(int**arr,size_t arr_rows, size_t arr_cols);
void solution_i(int**arr,size_t arr_rows, size_t arr_cols, size_t scan_row, size_t scan_col, int*answer);
void countarr(int**arr, size_t arr_rows, size_t arr_cols, int*answer);

int main(void)
{
	int length;
	scanf("%d", &length);
	int**arr = (int**)malloc(sizeof(int*) * length);
	for(int i = 0; i < length; ++i) {
		*(arr+i) = (int*)malloc(sizeof(int)*length);
		for(int j = 0; j < length; ++j) {
			scanf("%d", *(arr+i)+j);
		}
	}
	int*answer = solution(arr, length, length);
	printf("0 : %d\n1 : %d\n", answer[0], answer[1]);
	
	for(int i = 0; i < length; ++i) {
		free(arr[i]);
	}
	free(arr);
	free(answer);
	return 0;
}


int* solution(int**arr,size_t arr_rows, size_t arr_cols)
{
	int *answer = (int*)malloc(sizeof(int)*2);
	countarr(arr, arr_rows, arr_cols, answer);
	solution_i(arr,arr_rows,arr_cols,2,2,answer);

	return answer;
}

void solution_i(int**arr,size_t arr_rows, size_t arr_cols, size_t scan_row, size_t scan_col, int*answer)
{
	if(arr_rows < scan_row) return;

	size_t rowcount = arr_rows/scan_row;
	size_t colcount = arr_cols/scan_col;

	int flag;
	int firstnum;

	for(int i = 0; i < rowcount; ++i) {
		for(int j = 0; j < colcount; ++j) {
			flag = 1;
			firstnum = arr[scan_row * i][scan_col * j];
			for(int m = 0; m < scan_row; ++m) {
				for(int n = 0; n < scan_col; ++n) {
					if(arr[scan_row * i + m][scan_row * j + n] != firstnum) {
						flag = 0;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag) {
				answer[firstnum] -= 3;
			}
		}
	}

	solution_i(arr, arr_rows, arr_cols, scan_row*2, scan_col*2, answer);
}

void countarr(int**arr, size_t arr_rows, size_t arr_cols, int*answer)
{
	answer[0] = 0;
	answer[1] = 0;
	for(int i = 0; i < arr_rows; ++i) {
		for(int j = 0; j < arr_cols; ++j) {
			answer[arr[i][j]]++;
		}
	}
}
