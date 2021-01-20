
#include <stdio.h>
#include <stdlib.h>

int removecable(int **cable, int cable_cnt);
int compare(const void *a,const void *b);

int main(void)
{
	int cable_cnt;
	scanf("%d", &cable_cnt);
	int **cable = (int**)malloc(sizeof(int*)*cable_cnt);
	for(int i = 0; i < cable_cnt; ++i) {
		cable[i] = (int*)malloc(sizeof(int)*4);
		scanf("%d %d", cable[i], cable[i]+1);
	}
	printf("%d\n", removecable(cable, cable_cnt));
	
	for(int i = 0; i < cable_cnt; ++i)
		free(cable[i]);
	free(cable);

	return 0;
}

int removecable(int **cable, int cable_cnt)
{
	int answer = 0, i, temp, j;
	qsort(cable,cable_cnt,sizeof(int*),compare);

	int *smallcount = (int*)malloc(sizeof(int)*cable_cnt);
	i = 0;
	while(i<cable_cnt) smallcount[i++] = 1;

	i = 0;
	while(i<cable_cnt) {
		j = 0;
		temp = 0;
		while(j<i) {
			if(smallcount[j]>temp && cable[j][1] < cable[i][1]) {
				temp = smallcount[j];
			}
			++j;
		}
		smallcount[i] = temp + 1;
		if(temp+1>answer) answer = temp + 1;
		++i;
	}
	
	answer = cable_cnt - answer;

	return answer;
}

int compare(const void *a,const void *b)
{
	int *arr1 = *(int**)a;
	int *arr2 = *(int**)b;
	if(arr1[0]>arr2[0]) return 1;
	else if(arr1[0]<arr2[0]) return -1;
	return 0;
}
