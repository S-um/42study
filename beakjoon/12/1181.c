#include <stdio.h>
#include <malloc.h>
#include <string.h>

//정렬까지는 완성, 중복단어 삭제 기능 필요

char compare(char *a, char *b);
void mergeSort(char **array, int low, int hight);
void mergeSort_i(char **array, int low, int hight, char **temp);
void merge(char **array, int low, int middle, int hight, char **temp);

int main()
{
    int n;
    char temp[50];
    scanf("%d", &n);
    char **pp = malloc(sizeof(char *) * n);

    for(int i = 0; i < n; i++) {
        scanf("%s", temp);
        *(pp+i) = malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(*(pp+i), temp);
    }

    mergeSort(pp, 0, n-1);


    for(int i = 0; i < n; i++) {
        if(0 != i) {
            if(strcmp(*(pp+i), *(pp+i-1))) printf("%s\n", *(pp+i));
        } else printf("%s\n", *pp);
        
    }

    for(int i = 0; i < n; i++) {
        free(*(pp+i));
    }
    free(pp);
}

void mergeSort(char **array, int low, int hight)
{
    char **temp = (char **)malloc(sizeof(char *) * (hight - low + 1));
    mergeSort_i(array, low, hight, temp);
    free(temp);
}

void mergeSort_i(char **array, int low, int hight, char **temp)
{
    if(low < hight) {
        int middle = (hight + low) / 2;
        mergeSort_i(array, low, middle, temp);
        mergeSort_i(array, middle + 1, hight, temp);
        merge(array, low, middle, hight, temp);
    }
}

void merge(char **array, int low, int middle, int hight, char **temp)
{
    int leftP = low;
    int rightP = middle + 1;
    int tempP = low;

    while((leftP <= middle) && (rightP <= hight)) {
        if(compare(*(array + leftP), *(array + rightP))) *(temp + (tempP++)) = *(array + (leftP++));
        else *(temp + (tempP++)) = *(array + (rightP++));
    }

    while(leftP <= middle) *(temp + (tempP++)) = *(array + (leftP++));
    while(rightP <= middle) *(temp + (tempP++)) = *(array + (rightP++));

    tempP--;

    while(tempP >= low) {
        *(array + tempP) = *(temp + tempP);
        tempP--;
    }
}

char compare(char *a, char *b)
{
    if(strlen(a) < strlen(b)) return 1;
    else if(strlen(a) > strlen(b)) return 0;
    else {
        for (int i = 0; i < strlen(a); i++) {
            if(a[i] < b[i]) return 1;
            else if(a[i] > b[i]) return 0;
        }
    }
    return -1;
}