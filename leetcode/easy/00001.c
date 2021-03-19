#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(void)
{
	int arr[4] = {2,7,11,15};
	int returnSize;
	int *ret;
	ret = twoSum(arr,4,9,&returnSize);

	int i;
	i = 0;
	while(i<returnSize)
		printf("%d ",ret[i++]);
	printf("\n");
	free(ret);
	return 0;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int i;
    int j;
    int *ret = (int*)malloc(2*sizeof(int));
    i = 0;
    while(i<numsSize)
    {
        j = i+1;
        while(j<numsSize)
        {
            if(nums[i]+nums[j] == target)
	    {
	    	ret[0] = i;
		ret[1] = j;
		return ret;
	    }
            ++j;
        }
        ++i;
    }
}
