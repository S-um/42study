#include <stdio.h>
#include <malloc.h>

void printSeq(char a, char b);
void printSeq_i(char a, char b, char *flag, char *print, char length);

int main(void)
{
    char m, n;
    scanf("%c %c", &m, &n);
    m -= '0';
    n -= '0';

    printSeq(m, n);
}

void printSeq(char a, char b)
{
    char *flag = (char *)malloc(sizeof(char) * a);
    for (int i = 0; i < a; i++) {
        *(flag + i) = 0;
    }
    char *print = (char *)malloc(sizeof(char) * b);
    printSeq_i(a, b, flag, print, 0);

    free(flag);
    free(print);
}

void printSeq_i(char a, char b, char *flag, char *print, char length)
{
    if(length < b) {
        for (int i = 0; i < a; i++) {
            if(!flag[i]) {
                if((length>0) && ((i+1) < print[length-1])) continue;
                flag[i] = 1;
                print[length] = i+1;
                printSeq_i(a, b, flag, print, length+1);
                flag[i] = 0;
            }
        }
    } else {
        for(int i = 0; i < length; i++) {
            printf("%d ", print[i]);
        }
        printf("\n");
    }
}