#include <stdio.h>
#include <malloc.h>

typedef struct vec
{
    int x;
    int y;
} vec;

void mergeSort(vec *array, int low, int hight);
void mergeSort_i(vec *array, int low, int hight, vec *temp);
void merge(vec *array, int low, int middle, int hight, vec *temp);
char compare(vec a, vec b);

int main()
{
    int n;
    scanf("%d", &n);
    vec *vecs = malloc(sizeof(vec) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(vecs[i].x), &(vecs[i].y));
    }

    mergeSort(vecs, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", vecs[i].x, vecs[i].y);
    }


    free(vecs);
}

void mergeSort(vec *array, int low, int hight)
{
    vec *temp = malloc(sizeof(vec) * (hight - low + 1));
    mergeSort_i(array, low, hight, temp);
    free(temp);
}

void mergeSort_i(vec *array, int low, int hight, vec *temp)
{
    if (low < hight) {
        int middle = (low + hight) / 2;

        mergeSort_i(array, low, middle, temp);
        mergeSort_i(array, middle + 1, hight, temp);
        merge(array, low, middle, hight, temp);
    }
}

void merge(vec *array, int low, int middle, int hight, vec *temp)
{
    int leftP = low;
    int rightP = middle + 1;
    int tempP = low;

    while ((leftP <= middle) && (rightP <= hight)) {
        if(compare(array[leftP], array[rightP])) temp[tempP++] = array[leftP++];
        else temp[tempP++] = array[rightP++];
    }

    while(leftP <= middle) temp[tempP++] = array[leftP++];
    while(rightP <= hight) temp[tempP++] = array[rightP++];

    tempP--;

    while(tempP >= low) {
        array[tempP] = temp[tempP];
        tempP--;
    }
}

char compare(vec a, vec b)
{
    if (a.y > b.y) return 0;
    else if (a.y < b.y) return 1;
    else if (a.x > b.x) return 0;
    else return 1;
}