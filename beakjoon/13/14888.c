
#include <stdio.h>
#include <malloc.h>

int main(void)
{
	char N;
	scanf("%hhd", &N);
	char *num = (char *)malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++) {
		scanf("%hhd", num + i);
	}
	char opCnt[4] = {0,};

}
