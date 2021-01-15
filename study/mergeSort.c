#include <stdio.h>
#include <malloc.h>

void mergeSort(int array[], int low, int hight);
void mergeSort_i(int array[], int low, int hight, int temp[]);
void merge(int array[], int low, int middle, int hight, int temp[]);

int main(void)
{
    int a;
    
    printf("enter the amount of number : ");
    scanf("%d", &a);

    int* b = malloc(sizeof(int)*a);
    for(int i = 0; i < a; i++) {
        scanf("%d", b + i);
    }

    mergeSort(b, 0, a-1);

    printf("MergeSorting.....\n.......\n......\nFinished!\n");

    for(int i = 0; i < a; i++) {
        printf("%d\n", *(b + i));
    }

    free(b);
}



void mergeSort(int array[], int low, int hight)
{
    int *temp = malloc(sizeof(int) * (hight - low + 1));
    mergeSort_i(array, low, hight, temp);
    free(temp);
}

void mergeSort_i(int array[], int low, int hight, int temp[])
{
    if(low<hight) {
        int middle = (low + hight) / 2;
        mergeSort_i(array, low, middle, temp);
        mergeSort_i(array, middle + 1, hight, temp);
        merge(array, low, middle, hight, temp);
    }
}

void merge(int array[], int low, int middle, int hight, int temp[])
{
    int leftP = low;
    int rightP = middle + 1;
    int tempP = low;

    while ((leftP<=middle) && (rightP<=hight))
    {
        if(array[leftP]<array[rightP]) temp[tempP++] = array[leftP++];
        else temp[tempP++] = array[rightP++];
    }

    while(leftP<=middle) temp[tempP++] = array[leftP++];
    while(rightP<=hight) temp[tempP++] = array[rightP++];

    tempP--;

    while(tempP >= low) {
        array[tempP] = temp[tempP];
        tempP--;
    }
}
