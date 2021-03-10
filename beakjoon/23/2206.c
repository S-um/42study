#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
    int y;
    int x;
    int cnt;
    char canDistroy;
    struct s_q *next;
}q;

typedef struct s_qControl
{
    q *sp;
    q *ep;
}qControl;

qControl *makeQController();

void pushQ(qControl *controller, int y, int x, int cnt, char canDistroy);
q *popQ(qControl *controller);
void freeQ(qControl *controller);
void freeQ_i(q *ptr);

int **makeMap(int rowLen, int colLen);
void freeMap(int **map, int rowLen, int colLen);
int escapeMaze(int **map, int rowLen, int colLen);

int main(void)
{
    int rowLen, colLen;
    int **map;
    scanf("%d %d", &rowLen, &colLen);
    map = makeMap(rowLen,colLen);

    printf("%d\n",escapeMaze(map,rowLen,colLen));

    freeMap(map,rowLen,colLen);

    return 0;
}

qControl *makeQController()
{
    qControl *controller = (qControl*)malloc(sizeof(qControl));
    controller->sp = NULL;
    controller->ep = NULL;
    return controller;
}

void pushQ(qControl *controller, int y, int x, int cnt, char canDistroy)
{
    q *new = (q*)malloc(sizeof(q));
    new->y = y;
    new->x = x;
    new->cnt = cnt;
    new->canDistroy = canDistroy;
    new->next = NULL;

    if(controller->sp) {
        controller->ep->next = new;
        controller->ep = new;
    }else{
        controller->sp = new;
        controller->ep = new;
    }
}

q *popQ(qControl *controller)
{
    q *pop = controller->sp;
    if(controller->sp) {
        controller->sp = controller->sp->next;
        if(NULL == controller->sp)
            controller->ep = NULL;
    }
    return pop;
}

void freeQ(qControl *controller)
{
    freeQ_i(controller->sp);
    free(controller);
}

void freeQ_i(q *ptr)
{
    if(ptr) {
        freeQ_i(ptr->next);
        free(ptr);
    }
}

int **makeMap(int rowLen, int colLen)
{
    int i, j;
    int **map;
    char *input;

    map = (int**)malloc(rowLen*sizeof(int*));
    input = (char*)malloc((colLen+1)*sizeof(char));

    i = 0;
    while(i<rowLen) {
        map[i] = (int*)malloc(colLen*sizeof(int));
        scanf("%s",input);

        j = 0;
        while(j<colLen) {
            map[i][j] = input[j]-'0';
            ++j;
        }
        ++i;
    }
    free(input);
    return map;
}

void freeMap(int **map, int rowLen, int colLen)
{
    int i;
    i = 0;
    while(i<rowLen)
        free(map[i++]);
    free(map);
}

int escapeMaze(int **map, int rowLen, int colLen)
{
    int y, x, cnt, canDistroy, arrived;
    int **visitedAfterDistroyed;
    qControl *qController;
    q *curLoc;
    qController = makeQController();

    visitedAfterDistroyed = (int**)malloc(rowLen*sizeof(int*));

    x = 0;
    while(x<rowLen)
        visitedAfterDistroyed[x++] = (int*)calloc(colLen,sizeof(int));

    pushQ(qController,0,0,1,1);

    arrived = 0;
    while(qController->sp) {
        curLoc = popQ(qController);
        y = curLoc->y;
        x = curLoc->x;
        cnt = curLoc->cnt+1;
        canDistroy = curLoc->canDistroy;

        if(y == rowLen-1 && x == colLen-1) {
            free(curLoc);
            arrived = 1;
            break;
        }

        if(y>0) {
            if(map[y-1][x]) {
                if(canDistroy) {
                    pushQ(qController,y-1,x,cnt,0);
                }
            }else{
                if(canDistroy) {
                    map[y-1][x] = 1;
                    pushQ(qController,y-1,x,cnt,1);
                }else{
                    if(!visitedAfterDistroyed[y-1][x]) {
                        visitedAfterDistroyed[y-1][x] = 1;
                        pushQ(qController,y-1,x,cnt,0);
                    }
                }
            }
        }
        if(y<rowLen-1) {
            if(map[y+1][x]) {
                if(canDistroy) {
                    pushQ(qController,y+1,x,cnt,0);
                }
            }else{
                if(canDistroy) {
                    map[y+1][x] = 1;
                    pushQ(qController,y+1,x,cnt,1);
                }else{
                    if(!visitedAfterDistroyed[y+1][x]) {
                        visitedAfterDistroyed[y+1][x] = 1;
                        pushQ(qController,y+1,x,cnt,0);
                    }
                }
            }
        }
        if(x>0) {
            if(map[y][x-1]) {
                if(canDistroy) {
                    pushQ(qController,y,x-1,cnt,0);
                }
            }else{
                if(canDistroy) {
                    map[y][x-1] = 1;
                    pushQ(qController,y,x-1,cnt,1);
                }else{
                    if(!visitedAfterDistroyed[y][x-1]) {
                        visitedAfterDistroyed[y][x-1] = 1;
                        pushQ(qController,y,x-1,cnt,0);
                    }
                }
            }
        }
        if(x<colLen-1) {
            if(map[y][x+1]) {
                if(canDistroy) {
                    pushQ(qController,y,x+1,cnt,0);
                }
            }else{
                if(canDistroy) {
                    map[y][x+1] = 1;
                    pushQ(qController,y,x+1,cnt,1);
                }else{
                    if(!visitedAfterDistroyed[y][x+1]) {
                        visitedAfterDistroyed[y][x+1] = 1;
                        pushQ(qController,y,x+1,cnt,0);
                    }
                }
            }
        }
        free(curLoc);
    }

    freeQ(qController);
    freeMap(visitedAfterDistroyed,rowLen,colLen);

    if(arrived)
        return cnt-1;
    else
        return -1;
}