
#include <stdio.h>
#include <stdlib.h>

char *get_prime_num(int num);
int next_prime_num(int num, char *prime_num, int max_num);

int main(void)
{
    int num;
    int sum;
    int l, r;
    int cnt;
    char *prime_num;

    scanf("%d",&num);
    prime_num = get_prime_num(num);
    sum = 2;
    l = 2;
    r = 2;
    cnt = 0;
    while(r<=num)
    {
        if(sum>num)
        {
            sum -= l;
            l = next_prime_num(l,prime_num,num);
        }
        else if(sum<num)
        {
            r = next_prime_num(r,prime_num,num);
            if(!r)
                break;
            sum += r;
        }
        else
        {
            ++cnt;
            r = next_prime_num(r,prime_num,num);
            if(!r)
                break;
            sum -= l;
            sum += r;
            l = next_prime_num(l,prime_num,num);
        }
    }
    printf("%d\n",cnt);
    free(prime_num);
    return 0;
}

char *get_prime_num(int num)
{
    char *arr;
    int temp;
    int i;
    arr = (char*)malloc((num+1) * sizeof(char));
    arr[0] = 0;
    arr[1] = 0;
    i = 2;
    while(i<=num)
        arr[i++] = 1;

    i = 2;
    while(i<=num)
    {
        if(arr[i])
        {
            temp = i * 2;
            while(temp<=num)
            {
                arr[temp] = 0;
                temp += i;
            }
        }
        ++i;
    }
    return arr;
}

int next_prime_num(int num, char *prime_num, int max_num)
{
    ++num;
    while(num<=max_num)
    {
        if(prime_num[num])
            return num;
        ++num;
    }
    return 0;
}