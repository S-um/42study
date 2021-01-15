#include <stdio.h>
#include <malloc.h>

#define size 9

char **mkDokuPlt();
void getDoku(char **plate);
void printDoku(char **plate);
void solveDoku(char **plate);
void chkRow(char **plate, char *stdnum);
void chkCol(char **plate, char *stdnum);
void chkBox(char **plate, char *stdnum);
char bNeedLoop(char **plate);
void rmDokuPlt(char **plate);
void resStdnum(char *stdnum);

int main(void)
{
    char **doku = mkDokuPlt();

    getDoku(doku);
    solveDoku(doku);
    printDoku(doku);
    rmDokuPlt(doku);
}


char **mkDokuPlt()
{
    char **plate = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) *(plate + i) = (char *)malloc(sizeof(char) * size);

    return plate;
}

void getDoku(char **plate)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%hhd", *(plate+i)+j);
        }
    }
}


void printDoku(char **plate)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", *(*(plate+i)+j));
        }
        printf("\n");
    }
}

void rmDokuPlt(char **plate)
{
    for(int i = 0; i < size; i++) {
        free(*(plate + i));
    }
    free(plate);
}

void solveDoku(char **plate)
{
    char *stdnum = (char *)malloc(sizeof(char) * (size + 1));
    resStdnum(stdnum);

    do {
        chkRow(plate, stdnum);
        chkCol(plate, stdnum);
        chkBox(plate, stdnum);
    } while(bNeedLoop(plate));

    free(stdnum);
}

void chkRow(char **plate, char *stdnum)
{
    char zeroCnt = 0;
    char *CurRow;
    char zeroloc;
    for(int i = 0; i < size; i++) {
        CurRow = *(plate + i);
        for(int j = 0; j < size; j++) {
            if(*(CurRow + j)) stdnum[*(CurRow + j)] = 0;
            else if(!zeroCnt) {
                zeroCnt++;
                zeroloc = j;
            } else {
                zeroCnt++;
                break;
            }
        }
        if(1 == zeroCnt) {
            for(int j = 1; j <= size; j++) {
                if(stdnum[j]) *(CurRow + zeroloc) = j;
            }
        }
        resStdnum(stdnum);
        zeroCnt = 0;
    }
}

void chkCol(char **plate, char *stdnum)
{
    char zeroCnt = 0;
    char zeroloc;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(*(*(plate + j) + i)) stdnum[*(*(plate + j) + i)] = 0;
            else if(!zeroCnt) {
                zeroCnt++;
                zeroloc = j;
            } else {
                zeroCnt++;
                break;
            }
        }
        if(1 == zeroCnt) {
            for(int j = 1; j <=size; j++) {
                if(stdnum[j]) *(*(plate + zeroloc) + i) = j;
            }
        }
        resStdnum(stdnum);
        zeroCnt = 0;
    }
}

void chkBox(char **plate, char *stdnum)
{
    char curBoxRow;
    char curBoxCol;
    char zeroCnt = 0;
    char zeroloc[2];

    for(int i = 0; i < 3; i++) {
        curBoxCol = 3 * i;
        for(int j = 0; j < 3; j++) {
            curBoxRow = 3 * j;
            for(int m = 0; m < 3; m++) {
                for(int n = 0; n < 3; n++) {
                    if(*(*(plate + curBoxCol + m) + curBoxRow + n)) stdnum[*(*(plate + curBoxCol + m) + curBoxRow + n)] = 0;
                    else if(!zeroCnt) {
                        zeroCnt++;
                        zeroloc[0] = m;
                        zeroloc[1] = n;
                    } else {
                        zeroCnt++;
                        break;
                    }
                }
            }
            if(1 == zeroCnt) {
                for(int j = 1; j <=size; j++) {
                    if(stdnum[j]) *(*(plate + curBoxCol + zeroloc[0]) + curBoxRow + zeroloc[1]) = j;
                }
            }
            resStdnum(stdnum);
            zeroCnt = 0;
        }
    }
}

char bNeedLoop(char **plate)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(!*(*(plate + i) + j)) return 1;
        }
    }
    return 0;
}


void resStdnum(char *stdnum)
{
    for(int i = 0; i <= size; i++) {
        *(stdnum + i) = 1;
    }
}