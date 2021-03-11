
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if(*(long long*)a>*(long long*)b)
        return 1;
    return 0;
}

void able_weight(long long *sum, long long *arr, long long limit, long long cur_index, long long last_index, long long *sum_index, long long cur_sum);

long long binary_search(long long *arr, long long target, long long s, long long m, long long e);

int main(void)
{
    long long arr_len;
    long long limit;
    long long *arr;
    long long *sum_l;
    long long *sum_r;
    long long sum_l_size;
    long long sum_r_size;
    long long l;
    long long i;
    long long sum;
    long long cnt;

    scanf("%lld %lld",&arr_len,&limit);
    arr = (long long*)malloc(arr_len * sizeof(long long));
    i = 0;
    while(i<arr_len)
        scanf("%lld",arr+(i++));

    sum_l_size = 0;
    sum_r_size = 0;
    sum_l = (long long*)malloc((1 << (arr_len/2 + 1)) * sizeof(long long));
    sum_r = (long long*)malloc((1 << (arr_len/2 + 2)) * sizeof(long long));
    able_weight(sum_l,arr,limit,0,arr_len/2,&sum_l_size,0);
    able_weight(sum_r,arr,limit,arr_len/2 + 1,arr_len-1,&sum_r_size,0);
    qsort(sum_r,sum_r_size,sizeof(long long),compare);
    l = 0;
    cnt = 0;
    while(l<sum_l_size)
    {
        i = binary_search(sum_r,limit-sum_l[l],0,sum_r_size/2,sum_r_size);
        if(sum_r[i]+sum_l[i] <= limit)
            cnt += i+1;
        ++l;
    }
    printf("%lld\n",cnt);
    free(arr);
    free(sum_l);
    free(sum_r);
}

void able_weight(long long *sum, long long *arr, long long limit, long long cur_index, long long last_index, long long *sum_index, long long cur_sum)
{
    if(cur_index>last_index)
    {
        sum[*sum_index] = cur_sum;
        ++(*sum_index);
        return;
    }
    able_weight(sum,arr,limit,cur_index+1,last_index,sum_index,cur_sum);
    cur_sum += arr[cur_index];
    if(cur_sum<=limit)
    {
        able_weight(sum,arr,limit,cur_index+1,last_index,sum_index,cur_sum);
    }
}

long long binary_search(long long *arr, long long target, long long s, long long m, long long e)
{
    while(s<m)
    {
        if(arr[m]<=target)
        {
            s = m;
            m = (s+e)/2;
        }
        else
        {
            e = m;
            m = (s+e)/2;
        }
    }
    return m;
}
