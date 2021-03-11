
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
    int l;
    int r;
    int sum;
    int min;
    int min_l = 0;
    int min_r = 0;
    int i;

    scanf("%d",&arr_len);
    arr = (int*)malloc(arr_len*sizeof(int));
    i = 0;
    while(i<arr_len)
        scanf("%d",arr+(i++));
    qsort(arr,arr_len,sizeof(int),compare);
    l = 0;
    r = arr_len - 1;
    if(arr[r]<0)
        printf("%d %d\n",arr[r-1],arr[r]);
    else if(arr[l]>0)
        printf("%d %d\n",arr[l],arr[l+1]);
    else
    {
        min_l = l;
        min_r = r;
        min = arr[l] + arr[r];
        if(min<0)
            min *= -1;
        while(l<r)
        {
            sum = arr[l] + arr[r];
            if(sum<0){
                sum *= -1;
                if(sum<min) {
                    min = sum;
                    min_l = l;
                    min_r = r;
                }
                ++l;
            }else if(sum>0){
                if(sum<min) {
                    min = sum;
                    min_l = l;
                    min_r = r;
                }
                --r;
            }else{
                min = sum;
                min_l = l;
                min_r = r;
                break;
            }
        }
        printf("%d %d\n",arr[min_l],arr[min_r]);
    }
    free(arr);
    return 0;
}