#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    int n;
    char temp[50];
    scanf("%d", &n);
    char **pp = malloc(sizeof(char *) * n);

    for(int i = 0; i < n; i++) {
        scanf("%s", temp);
        *(pp+i) = malloc(sizeof(char) * strlen(temp));
        strcpy(*(pp+i), temp);
    }
}
