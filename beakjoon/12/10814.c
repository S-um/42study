#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct member
{
    int age;
    char *name;
}member;

void mergeSort(member *array, int low, int hight);
void mergeSort_i(member *array, int low, int hight, member *temp);
void merge(member *array, int low, int middle, int hight, member *temp);
char compare(member a, member b);

int main(void)
{
    int n;
    scanf("%d", &n);
    char name_t[100];
    member *mems = (member *)malloc(sizeof(member) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d %s", &((mems + i)->age), name_t);
        (mems + i)->name = malloc(sizeof(char) * (strlen(name_t) + 1));
        strcpy((mems + i)->name, name_t);
    }

    mergeSort(mems, 0, n-1);

    for(int i = 0; i < n; i++) {
        printf("%d %s\n", (mems + i)->age, (mems + i)->name);
        free((mems + i)->name);
    }
    free(mems);
}

void mergeSort(member *array, int low, int hight)
{
    member *temp = (member *)malloc(sizeof(member) * (hight - low + 1));
    mergeSort_i(array, low, hight, temp);
    free(temp);
}

void mergeSort_i(member *array, int low, int hight, member *temp)
{
    if(low < hight) {
        int middle = (low + hight) / 2;
        mergeSort_i(array, low, middle, temp);
        mergeSort_i(array, middle + 1, hight, temp);
        merge(array, low, middle, hight, temp);
    }
}

void merge(member *array, int low, int middle, int hight, member *temp)
{
    int leftP = low;
    int rightP = middle + 1;
    int tempP = low;

    while ((leftP <= middle) && (rightP <= hight)){
        if(compare(*(array+leftP), *(array+rightP))) *(temp + (tempP++)) = *(array + (leftP++));
        else *(temp + (tempP++)) = *(array + (rightP++));
    }
    
    while (leftP <= middle) *(temp + (tempP++)) = *(array + (leftP++));
    while (rightP <= hight) *(temp + (tempP++)) = *(array + (rightP++));

    tempP--;

    while (tempP >= low) {
        *(array + tempP) = *(temp + tempP);
        tempP--;
    }
}

char compare(member a, member b)
{
    if(a.age <= b.age) return 1;
    else return 0;
}