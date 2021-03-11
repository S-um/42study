
#include <stdio.h>
#include <stdlib.h>

#define BLUE 1
#define RED 2

void run();
int coloring_graph(char **graph_data, int *vertex_condition, int vertex_cnt, int cur_vertex);

int main(void)
{
    int tc;
    int i;
    scanf("%d",&tc);

    i = 0;
    while(i<tc)
    {
        run();
        ++i;
    }
}

void run()
{
    char **graph_data;
    int *vertex_condition;

    int vertex_cnt;
    int line_cnt;
    int ver1, ver2;
    int i, j;

    scanf("%d %d",&vertex_cnt,&line_cnt);
    graph_data = (char**)malloc((vertex_cnt+1) * sizeof(char*));
    vertex_condition = (int*)calloc((vertex_cnt+1), sizeof(int));
    graph_data[0] = NULL;
    i = 1;
    while(i<=vertex_cnt)
        graph_data[i++] = (char*)calloc((vertex_cnt+1), sizeof(char));
    i = 0;
    while(i<line_cnt)
    {
        scanf("%d %d",&ver1,&ver2);
        graph_data[ver1][ver2] = 1;
        graph_data[ver2][ver1] = 1;
        ++i;
    }

    i = 1;
    while(i<=vertex_cnt)
    {
        if(!vertex_condition[i])
        {
            if(!coloring_graph(graph_data,vertex_condition,vertex_cnt,i))
            {
                printf("NO\n");
                j = 1;
                while(j<=vertex_cnt)
                    free(graph_data[j++]);
                free(graph_data);
                free(vertex_condition);
                return;
            }
        }
        ++i;
    }

    printf("YES\n");
    i = 1;
    while(i<=vertex_cnt)
        free(graph_data[i++]);
    free(graph_data);
    free(vertex_condition);
    return;
}

int coloring_graph(char **graph_data, int *vertex_condition, int vertex_cnt, int cur_vertex)
{
    int i;
    int next_condition;
    if(BLUE == vertex_condition[cur_vertex])
        next_condition = RED;
    else
        next_condition = BLUE;

    i = 1;
    while(i<=vertex_cnt)
    {
        if(graph_data[cur_vertex][i])
        {
            if(vertex_condition[i])
            {
                if(next_condition != vertex_condition[i])
                    return 0;
            }else{
                vertex_condition[i] = next_condition;
                if(!coloring_graph(graph_data,vertex_condition,vertex_cnt,i))
                    return 0;
            }
        }
        ++i;
    }
    return 1;
}