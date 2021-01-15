#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int main()
{
    char *num = malloc(sizeof(char) * 10);
    scanf("%s", num);
    qsort(num, strlen(num), sizeof(char), compare);
    printf("%s\n", num);
    free(num);
}

int compare(const void *a, const void *b)
{
    char num1 = *(char *)a;
    char num2 = *(char *)b;

    if (num1 < num2)
        return 1;

    if (num1 > num2)
        return -1;

        return 0;
}