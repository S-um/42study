
#include <stdio.h>
#include <stdlib.h>

int atm(int *time, int len);
int compare(const void*a,const void*b);

int main(void)
{
	int len;
	scanf("%d", &len);
	int i = 0;
	int *time = (int*)malloc(len*sizeof(int));
	while(i<len)
		scanf("%d", time+(i++));
	printf("%d\n", atm(time,len));
	free(time);

	return 0;
}

int atm(int *time, int len)
{
	qsort(time,len,sizeof(int),compare);
	int i = 0, temp = 0, answer = 0;
	while(i<len) {
		temp += time[i];
		answer += temp;
		++i;
	}
	return answer;
}

int compare(const void*a,const void*b)
{
	if(*(int*)a>=*(int*)b) return 1;
	else return -1;
}
