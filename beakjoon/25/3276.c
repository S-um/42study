
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if(*(int*)a>*(int*)b)
        return 1;
    return 0;
}

int main(void)
{
    int arr_len;
    int *arr;
    int target_num;
    int cnt;
    int sum;
    int l, r;
    int i;

    scanf("%d",&arr_len);
    l = 0;
    r = arr_len-1;
    cnt = 0;
    arr = (int*)malloc(arr_len*sizeof(int));
    i = 0;
    while(i<arr_len)
        scanf("%d",arr+(i++));
    scanf("%d",&target_num);
    qsort(arr,arr_len,sizeof(int),compare);
    while(l<r)
    {
        sum = arr[l]+arr[r];
        if(sum>target_num)
            --r;
        else if(sum<target_num)
            ++l;
        else
        {
            ++cnt;
            ++l;
            --r;
        }
    }
    printf("%d\n",cnt);
    free(arr);
    return 0;
}