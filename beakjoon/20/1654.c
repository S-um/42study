
#include <stdio.h>
#include <stdlib.h>

long long getMaxLen(int *stringLen, int stringCnt, int maxLen, int targetCnt);

int main(void)
{
	int stringCnt, targetCnt, i, maxLen = 0, cnt;
	scanf("%d %d", &stringCnt, &targetCnt);
	int *stringLen = (int*)malloc(stringCnt*sizeof(int));

	i = 0;
	while(i<stringCnt) {
		scanf("%d",stringLen+i);
		if(maxLen<stringLen[i])
			maxLen = stringLen[i];
		++i;
	}

	printf("%lld\n", getMaxLen(stringLen,stringCnt,maxLen,targetCnt));
	free(stringLen);

}

long long getMaxLen(int *stringLen, int stringCnt, int maxLen, int targetCnt)
{
	long long min = 1, max = (long long)maxLen+1, mid = (max+1)/2, cnt, j;

	while(min != mid) {
		cnt = 0;
		j = 0;
		while(j<stringCnt)
			cnt += stringLen[j++]/mid;

		if(targetCnt>cnt) {
			max = mid;
			mid = (min+max)/2;
		}else{
			min = mid;
			mid = (min+max)/2;
		}
	}
	return mid;
}
