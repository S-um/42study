
#include <stdio.h>
#include <stdlib.h>

int getMaxTreeHeight(int *tree, int treeCnt, int heighestLen, int targetLen);

int main(void)
{
	int treeCnt, targetLen, i, heighestLen = 0;
	scanf("%d %d",&treeCnt,&targetLen);

	int *tree = (int*)malloc(treeCnt*sizeof(int));

	i = 0;
	while(i<treeCnt) {
		scanf("%d",tree+i);
		if(tree[i]>heighestLen)
			heighestLen = tree[i];
		++i;
	}

	printf("%d\n",getMaxTreeHeight(tree,treeCnt,heighestLen,targetLen));
	free(tree);
}

int getMaxTreeHeight(int *tree, int treeCnt, int heighestLen, int targetLen)
{
	long long min = 0, max = heighestLen+1, mid = max/2, harvestLen;
	int i;
	
	while(min != mid) {
		i = 0;
		harvestLen = 0;
		while(i<treeCnt) {
			if(tree[i]>mid) {
				harvestLen += tree[i]-mid;
			}
			++i;
		}
		if(harvestLen<targetLen) {
			max = mid;
			mid = (min+max)/2;
		}else{
			min = mid;
			mid = (min+max)/2;
		}
	}
	return mid;
}
