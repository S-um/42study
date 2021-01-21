
#include <stdio.h>
#include <stdlib.h>

int conference(int **confer, int confercnt);
int compare(const void *a, const void *b);

int main(void)
{
	int confercnt, i;
	scanf("%d", &confercnt);
	int **confer = (int**)malloc(confercnt*sizeof(int*));
	i = 0;
	while(i<confercnt) {
		confer[i] = (int*)malloc(3*sizeof(int));
		scanf("%d %d", confer[i], confer[i]+1);
		confer[i][2] = 1;
		++i;
	}
	i= 0;
	printf("%d\n", conference(confer, confercnt));

	return 0;
}

int conference(int **confer, int confercnt)
{
	int answer = 0, i, j, temp;
	qsort(confer,confercnt,sizeof(int*),compare);
	i = 0;
	temp = 0;
	while(i<confercnt) {
		if(confer[i][0]>=temp) {
			++answer;
			temp = confer[i][1];
		}
		++i;
	}
	return answer;
}

int compare(const void *a, const void *b)
{
	int *a1 = *(int**)a;
	int *b1 = *(int**)b;

	if(a1[1]>b1[1]) return 1;
	else if(a1[1]<b1[1]) return -1;
	else if(a1[0]>b1[0]) return 1;
	else if(a1[0]<b1[0]) return -1;

	return 0;
}
