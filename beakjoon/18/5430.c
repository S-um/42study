
#include <stdio.h>
#include <stdlib.h>

int *stoa(int numLen);

int main(void)
{
	int testCaseCnt, i, numLen, j, startPtr, endPtr, isReversed;
	int *num;
	char command[100001] = {0,};
	scanf("%d", &testCaseCnt);
	i = 0;
	while(i<testCaseCnt) {
		scanf("%s", command);
		scanf("%d", &numLen);
		num = stoa(numLen);

		startPtr = 0;
		endPtr = numLen-1;
		isReversed = 0;
		j = 0;
		while(command[j]) {
			switch(command[j]) {
				case 'R':
					isReversed = !isReversed;
					break;
				case 'D':
					if(isReversed) {
						--endPtr;
					} else {
						++startPtr;
					}
					break;
			}
			++j;
		}
		if(startPtr-1>endPtr) {
			printf("error\n");
		} else if(startPtr-1 == endPtr) {
			printf("[]\n");
		} else {
			if(isReversed) {
				j = endPtr - 1;
				printf("[%d",num[endPtr]);
				while(j>=startPtr) {
					printf(",%d",num[j]);
					--j;
				}
				printf("]\n");
			} else {
				j = startPtr + 1;
				printf("[%d",num[startPtr]);
				while(j<=endPtr) {
					printf(",%d",num[j]);
					++j;
				}
				printf("]\n");
			}
		}
		if(NULL != num)
			free(num);
		++i;
	}
}

int *stoa(int numLen)
{
	if(numLen == 0) {
		while(getchar()!=']');
		return NULL;
	}
	int *arr = (int*)calloc(numLen, sizeof(int));
	int arrIndex;
	arrIndex = 0;
	char c;
	getchar();
	getchar();
	c = getchar();
	while(c != EOF) {
		while(c>='0' && c<='9') {
			arr[arrIndex] *= 10;
			arr[arrIndex] += c-'0';
			c = getchar();
		}
		if(']' == c)
			break;
		c = getchar();
		++arrIndex;
	}

	return arr;
}
