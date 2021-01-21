
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int cnt;
	scanf("%d", &cnt);
	if(cnt == 1) {
		int num;
		scanf("%d", &num);
		printf("%d\n", num*num);
		return 0;
	}
	int i = 0, min = 1000000, max = 0, num;
	while(i<cnt) {
		scanf("%d", &num);
		if(num<min)
			min = num;
		if(num>max)
			max = num;
		++i;
	}
	printf("%d\n", min*max);

	return 0;
}
