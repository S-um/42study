
#include <stdio.h>
#include <stdlib.h>

typedef struct s_q
{
    int y;
    int x;
    struct s_q *next;
}q;

typedef struct s_qCtrl
{
    q *sp;
    q *ep;
}qCtrl;

qCtrl *makeQCtrller();
void pushQ(qCtrl *controller, int y, int x);
q *popQ(qCtrl *controller);
void freeQ(qCtrl *controller);

int **makeMap(int mapSize);
void freeMap(int **map, int mapSize);

int moveToGaol(int **map, int mapSize, curX, curY, goalX, goalY);

int main(void)
{
    int tc, mapSize, curX, curY, goalX, goalY;
    int i;

    scanf("%d", &tc);

    i = 0;
    while(i<tc) {
        scanf("%d", &mapSize);
        scanf("%d %d", &curX, &curY);
        scanf("%d %d", &goalX, goalY);

    }
}

int moveToGaol(int **map, int mapSize, curX, curY, goalX, goalY);
{

}

qCtrl *makeQCtrller();
{
    qCtrl *controller;
    controller = (qCtrl*)malloc(sizeof(qCtrl));
    controller->sp = NULL;
    controller->ep = NULL;
    return controller;
}

void pushQ(qCtrl *controller, int y, int x)
{
    q *newQ;
    q *ptr;

    newQ = (q*)malloc(sizeof(q));
    newQ->y = y;
    newQ->x = x;
    newQ->next = NULL;

    if(controller->sp) {
        controller->ep->next = newQ;
        controller->ep = newQ;
    }else{
        controller->sp = newQ;
        controller->ep = newQ;
    }
}

q *popQ(qCtrl *controller)
{
    q *ret = controller->sp;
    if(controller->sp) {
        controller->sp = controller->sp->next;
        if(NULL == controller->sp)
            controller->ep = NULL;
    }
    return ret;
}

void freeQ_i(q *ptr)
{
    if(ptr) {
        freeQ_i(ptr->next);
        free(ptr);
    }
}

void freeQ(qCtrl *controller)
{
    freeQ_i(controller->sp);
    free(controller);
}


int **makeMap(int mapSize)
{
    int **map;
    int i, j;

    map = (int**)malloc(sizeof(int*));
    i = 0;
    while(i<mapSize) {
        map[i] = (int*)malloc(sizeof(int));
        j = 0;
        while(j<mapSize)
            map[i][j++] = 1;
        ++i;
    }

    return map;
}

void freeMap(int **map, int mapSize)
{
    int i;

    i = 0;
    while(i<mapSize)
        free(map[i++]);
    free(map);
}