
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
    int arr_len, huddle;
    int *arr;
    int i;
    int sum;
    int min_len;
    int l, r;

    scanf("%d %d", &arr_len,&huddle);
    arr = (int*)malloc(arr_len*sizeof(int));
    i = 0;
    while(i<arr_len)
        scanf("%d",arr+(i++));
    l = 0;
    r = 0;
    sum = arr[0];
    min_len = arr_len+1;
    while(r<arr_len)
    {
        if(sum>=huddle)
        {
            if(r-l+1<min_len)
                min_len = r-l+1;
            if(l<r){
                sum -= arr[l];
                ++l;
            } else if(l == r) {
                ++l;
                ++r;
                sum = arr[l];
            }
        }
        else
        {
            ++r;
            if(r<arr_len)
                sum += arr[r];
        }
    }
    if(min_len<=arr_len)
        printf("%d\n",min_len);
    else
        printf("0\n");
    free(arr);
    return 0;
}