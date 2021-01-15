#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%i", &n);
    int sum = 0;
    int middle;
    int range;
    int freq = 1;
    int freqmax = 1;
    int freqmaxN;
    char bGetSec = 1;

    if (1 == n) {
        scanf("%d", &n);
        printf("%d\n%d\n%d\n0\n", n, n, n);

        return 0;
    }
    
    int* numArr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%i", &numArr[i]);
        sum += numArr[i];
    }

    qsort(numArr, n, sizeof(int), compare);
    
    
    middle = numArr[n/2];
    range = numArr[n-1] - numArr[0];

    for(int i = 0; i<(n-1); i++) {
        if(numArr[i]==numArr[i+1]) freq += 1;
        else
        {
            if (freq > freqmax) {
                freqmaxN = numArr[i];
                freqmax = freq;
                bGetSec = 1;
            } else if ((freq == freqmax) && bGetSec) {
                freqmaxN = numArr[i];
                if (0 != i) bGetSec = 0;
            }
            freq = 1;
        }
    }
    if (freq > freqmax) {
        freqmaxN = numArr[n-1];
        bGetSec = 1;
    } else if ((freq == freqmax) && bGetSec) {
        freqmaxN = numArr[n-1];
    }
    
    free(numArr);

    printf("%.0f\n%d\n%d\n%d\n", (double)sum/n, middle, freqmaxN, range);

    return 0;
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

        return 0;
}