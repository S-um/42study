#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%i", &n);

    int* numArr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%i", &numArr[i]);
    }

    qsort(numArr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%i\n", numArr[i]);
    }

    free(numArr);

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