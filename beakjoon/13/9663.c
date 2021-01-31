#include <stdio.h>
#include <stdlib.h>

char bput(char colnum, char *plate, char platesize);
int nqueen(char platesize);
int nqueen_i(char colnum, char *plate, char platesize);

int main(void)
{
    char size;
    scanf("%hhd", &size);
    printf("%d\n", nqueen(size));
    int zero = 0;

    return 0;
}

int nqueen(char platesize)
{
    char *plate = (char *)malloc(sizeof(char) * platesize);
    int anw = 0;

    for (int i = 0; i < platesize; i++) {
        *plate = i;
        anw += nqueen_i(0, plate, platesize);
    }
    free(plate);
    return anw;
}

int nqueen_i(char colnum, char *plate, char platesize)
{
    int cnt = 0;

    if (colnum == platesize-1) return 1;
    for (int i = 0; i < platesize; i++) {
        *(plate + colnum + 1) = i;
        if (bput(colnum+1, plate, platesize)) cnt += nqueen_i(colnum+1, plate, platesize);
    }
    
    return cnt;
}

char bput(char colnum, char *plate, char platesize)
{
    for (int i = 0; i < colnum; i++) {
        if ((*(plate + i) == *(plate + colnum)) || ((colnum - i) == abs(*(plate + colnum) - *(plate + i)))) return 0;
    }

    return 1;
}
