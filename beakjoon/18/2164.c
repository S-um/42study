
#include <stdio.h>
#include <stdlib.h>

int count(int *num, int numLen, int countOddIndex);

int main(void)
{
	int numLen, i;
	scanf("%d", &numLen);
	int *arr = (int*)malloc((numLen+1) * sizeof(int));
	i = 0;
	while(i<=numLen) {
		arr[i] = i;
		++i;
	}

	printf("%d\n", count(arr,numLen,0));

	free(arr);

}

int count(int *num, int numLen, int countOddIndex)
{
	if(1 == numLen)
		return num[1];
	int i = 1, j;
	j = 2 - countOddIndex;
	while(j<=numLen) {
		num[i] = num[j];
		++i;
		j += 2;
	}
	if(numLen%2)
		return count(num,(numLen+countOddIndex)/2,!countOddIndex);
	else
		return count(num,numLen/2,countOddIndex);
}
