
#include <stdio.h>
#include <stdlib.h>

char get_alp_input();

void preorder(char (*alp)[2], char index);
void inorder(char (*alp)[2], char index);
void postorder(char (*alp)[2], char index);

int main(void)
{
    char alp[26][2];
    char root,left,right;
    int node_cnt;
    int i;

    i = 0;
    while(i<26)
    {
        alp[i][0] = -1;
        alp[i][1] = -1;
        ++i;
    }

    scanf("%d",&node_cnt);
    i = 0;
    while(i<node_cnt)
    {
        root = get_alp_input();
        left = get_alp_input();
        right = get_alp_input();
        if('.' != left)
            alp[root-'A'][0] = left-'A';

        if('.' != right)
            alp[root-'A'][1] = right-'A';
        ++i;
    }

    preorder(alp,0);
    printf("\n");
    inorder(alp,0);
    printf("\n");
    postorder(alp,0);
    printf("\n");
}

void preorder(char (*alp)[2], char index)
{
    printf("%c",index+'A');
    if(-1 != alp[index][0])
        preorder(alp,alp[index][0]);
    if(-1 != alp[index][1])
        preorder(alp,alp[index][1]);
}

void inorder(char (*alp)[2], char index)
{
    if(-1 != alp[index][0])
        inorder(alp,alp[index][0]);
    printf("%c",index+'A');
    if(-1 != alp[index][1])
        inorder(alp,alp[index][1]);
}

void postorder(char (*alp)[2], char index)
{
    if(-1 != alp[index][0])
        postorder(alp,alp[index][0]);
    if(-1 != alp[index][1])
        postorder(alp,alp[index][1]);
    printf("%c",index+'A');
}

char get_alp_input()
{
    char temp;
    temp = 0;
    while((temp<'A' || 'Z'<temp) && '.' != temp)
        scanf("%c",&temp);
    return temp;
}