
#include <stdio.h>
#include <stdlib.h>

#define ADD 0
#define COMP 1

int main(void)
{
    int set_cnt;
    int cal_cnt;
    int command;
    int set1;
    int set2;
    int i;
    int **set;

    scanf("%d %d",&set_cnt,&cal_cnt);
    ++set_cnt;
    set = (int**)malloc(set_cnt * sizeof(int*));
    i = 0;
    while(i<set_cnt)
    {
        set[i] = (int*)malloc(sizeof(int));
        set[i][0] = i;
        ++i;
    }
    i = 0;
    while(i<cal_cnt)
    {
        scanf("%d %d %d",&command,&set1,&set2);
        if(ADD == command)
        {
            if(set[set1][0]>set[set2][0])
                set[set1] = set[set2];
            else if(set[set1][0]<set[set2][0])
                set[set2] = set[set1];
        }
        else if(COMP == command)
        {
            if(set[set1] == set[set2])
                printf("YES\n");
            else
                printf("NO\n");
        }
        ++i;
    }
    free(set);
}