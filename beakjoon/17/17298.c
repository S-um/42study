
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int numLen, stackTopIndex, i, j;
	scanf("%d", &numLen);
	int **num = (int**)malloc(numLen * sizeof(int*));
	int **numStack = (int**)calloc(numLen, sizeof(int*));

	i = 0;
	stackTopIndex = 0;
	while(i<numLen) {
		num[i] = (int*)malloc(2 * sizeof(int));
		scanf("%d", num[i]);

		while(1) {
			if(0 == stackTopIndex) {
				numStack[stackTopIndex] = num[i];
				++stackTopIndex;
				break;
			}
			if(numStack[stackTopIndex-1][0] < num[i][0]) {
				numStack[stackTopIndex-1][1] = num[i][0];
				numStack[stackTopIndex-1] = NULL;
				--stackTopIndex;
				continue;
			}
			numStack[stackTopIndex] = num[i];
			++stackTopIndex;
			break;
		}

		++i;
	}

	i = 0;
	while(i<numLen) {
		if(num[i][1])
			printf("%d ", num[i][1]);
		else
			printf("-1 ");
		free(num[i]);
		++i;
	}
	printf("\n");

	free(num);
	free(numStack);

	return 0;
}
