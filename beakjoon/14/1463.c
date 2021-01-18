
#include <stdio.h>
#include <stdlib.h>

int makeone(int num);
int makeone_i(int num, int cnt, int *data, int *answer);

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", makeone(n));
	return 0;
}

int makeone(int num)
{
	int answer;
	int *data = (int*)calloc(sizeof(int),num+1);
	makeone_i(num,0,data,&answer);


	return makeone_i(num,0,data,&answer);
}

int makeone_i(int num, int cnt, int *data, int *answer)
{
	int temp, value = 1000000;
	if(1 == num) return cnt;
	if(!(num%3)) {
		if(!data[num/3]) {
			temp = makeone_i(num/3,cnt+1,data,answer);
			data[num/3] = temp - cnt -1;
		} else temp = data[num/3] + cnt + 1;
		value = temp;
	}
	if(!(num%2)) {
		if(!data[num/2]) {
			temp = makeone_i(num/2,cnt+1,data,answer);
			data[num/2] = temp - cnt -1;
		} else temp = data[num/2] + cnt +1;
		if(value>temp) value = temp;
	}

	if(!data[num-1]) {
		temp = makeone_i(num-1,cnt+1,data,answer);
		data[num-1] = temp - cnt -1;
	} else temp = data[num-1] + cnt + 1;
	if(value>temp) value = temp;

	return value;
}
