
#include <stdio.h>
#include <stdlib.h>

#define UNVISITED 0
#define VISITED 1
#define NEAR_VISITED 2

typedef struct s_q
{
    int index;
    int weight;
    struct s_q *next;
}q;

typedef struct s_q_controller
{
    q *sp;
    q *ep;
}q_controller;

void push_q(q_controller *controller, int index, int weight);
void free_q_controller(q_controller *controller);

int main(void)
{
    int vertex_cnt;
    int line_cnt;
    int start_index;
    int sp;
    int ep;
    int weight;
    int *weight_data;
    int i;
    int next_index;
    char *vertex_data;

    q *ptr;
    q_controller **link_data;

    scanf("%d %d",&vertex_cnt,&line_cnt);
    scanf("%d",&start_index);
    link_data = (q_controller**)malloc((vertex_cnt + 1) * sizeof(q_controller*));
    weight_data = (int*)malloc((vertex_cnt + 1) * sizeof(int));
    vertex_data = (char*)calloc(vertex_cnt + 1, sizeof(char));
    i = 0;
    while(i<=vertex_cnt)
        link_data[i++] = (q_controller*)calloc(1,sizeof(q_controller));
    i = 0;
    while(i<=vertex_cnt)
        weight_data[i++] = -1;
    weight_data[start_index] = 0;
    vertex_data[start_index] = VISITED;
    
    i = 0;
    while(i<line_cnt)
    {
        scanf("%d %d %d",&sp,&ep,&weight);
        push_q(link_data[sp],ep,weight);
        ++i;
    }
    
    ptr = link_data[start_index]->sp;
    while(ptr)
    {
        weight_data[ptr->index] = ptr->weight;
        vertex_data[ptr->index] = NEAR_VISITED;
        ptr = ptr->next;
    }
    next_index = start_index;
    while(1)
    {
        i = 1;
        next_index = -1;
        while(i<=vertex_cnt)
        {
            if(NEAR_VISITED == vertex_data[i] && (-1 == next_index || weight_data[i]<weight_data[next_index]))
                next_index = i;
            ++i;
        }
        if(-1 == next_index)
            break;
        vertex_data[next_index] = VISITED;
        ptr = link_data[next_index]->sp;
        while(ptr)
        {
            if(weight_data[next_index] + ptr->weight < weight_data[ptr->index] || -1 == weight_data[ptr->index])
                weight_data[ptr->index] = weight_data[next_index] + ptr->weight;
            if(UNVISITED == vertex_data[ptr->index])
                vertex_data[ptr->index] = NEAR_VISITED;
            ptr = ptr->next;
        }
    }
    i = 1;
    while(i<=vertex_cnt)
    {
        if(-1 == weight_data[i])
            printf("INF\n");
        else
            printf("%d\n",weight_data[i]);
        ++i;
    }
    free(weight_data);
    free(vertex_data);
    i = 0;
    while(i<=vertex_cnt)
        free_q_controller(link_data[i++]);
    free(link_data);
}

void push_q(q_controller *controller, int index, int weight)
{
    q *new;
    new = (q*)malloc(sizeof(q));
    new->index = index;
    new->weight = weight;
    new->next = NULL;
    if(controller->sp)
    {
        controller->ep->next = new;
        controller->ep = new;
    }
    else
    {
        controller->sp = new;
        controller->ep = new;
    }
}

void free_q(q *ptr)
{
    if(ptr)
    {
        free_q(ptr->next);
        free(ptr);
    }
}

void free_q_controller(q_controller *controller)
{
    free_q(controller->sp);
    free(controller);
}