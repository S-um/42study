
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numLen, i, temp, numStackTopIndex, biggestPushedNum, stackDataTopIndex;
	scanf("%d", &numLen);

	int *num = (int*)malloc(numLen * sizeof(int));

	int *numStack = (int*)calloc(numLen, sizeof(int));
	char *stackData = (char*)malloc(numLen * 2 * sizeof(char));

	i = 0;
	while(i<numLen)
		scanf("%d", num+(i++));
	
	numStackTopIndex = 0;
	stackDataTopIndex = 0;
	biggestPushedNum = 0;
	i = 0;
	while(i<numLen) {
		if(biggestPushedNum<=num[i]) {
			temp = biggestPushedNum+1;
			while(temp<num[i]) {
				numStack[numStackTopIndex++] = temp;
				stackData[stackDataTopIndex++] = '+';
				++temp;
			}
			stackData[stackDataTopIndex++] = '+';
			stackData[stackDataTopIndex++] = '-';
			biggestPushedNum = num[i];
		} else {
			if(num[i] == numStack[numStackTopIndex-1]) {
				numStack[numStackTopIndex-1] = 0;
				--numStackTopIndex;
				stackData[stackDataTopIndex++] = '-';
			} else {
				printf("NO\n");
				return 0;
			}
		}
		++i;
	}

	i = 0;
	while(i<2*numLen) {
		printf("%c\n", stackData[i++]);
	}

	free(num);
	free(numStack);
	free(stackData);

	return 0;
}
