#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXNUM_VERTICES 100

typedef struct
{
    int n_vertices, n_edges, adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
} Graph;

void inisialisasi_graph(Graph *g, int n_v, int n_e)
{
    g->n_vertices = n_v;
    g->n_edges = n_e;
    for (int i = 0; i < MAXNUM_VERTICES; i++)
    {
        for (int j = 0; j < MAXNUM_VERTICES; j++)
        {
            if (i < n_v && j < n_v)
                g->adjacency_matrix[i][j] = 0;
            else
                g->adjacency_matrix[i][j] = -1;
        }
    }
}

void print_adjancency_matrix(Graph *g)
{
    for (int i = 0; i < g->n_vertices; i++)
        printf("\t%d", i);
    printf("\n");

    for (int i = 0; i < g->n_vertices; i++)
    {
        printf("%d", i);
        for (int j = 0; j < g->n_vertices; j++)
            printf("\t%d", g->adjacency_matrix[i][j]);
        printf("\n");
    }
}

typedef enum
{
    WHITE,
    GRAY,
    BLACK
} COLOR;

#define Inf 1000000000
int finish_time[MAXNUM_VERTICES], time = 0, vertex[MAXNUM_VERTICES];

bool DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
    vertex_colors[v] = GRAY;
    time++;
    for (int i = 0; i < g->n_vertices; i++)
    {
        if (g->adjacency_matrix[v][i] == 1 && vertex_colors[i] == GRAY)
            return true;
        if (vertex_colors[i] == WHITE && g->adjacency_matrix[v][i] == 1 && DFS_visit(g, vertex_colors, i))
            return true;
    }
    vertex_colors[v] = BLACK;

    time++;
    finish_time[v] = time;
    vertex[time] = v;
    return false;
}

bool DFS(Graph *g)
{
    COLOR vertex_colors[MAXNUM_VERTICES];
    for (int i = 0; i < g->n_vertices; i++)
        vertex_colors[i] = WHITE;
    for (int i = 0; i < g->n_vertices; i++)
        finish_time[i] = Inf;

    for (int i = 0; i < g->n_vertices; i++)
    {
        if (vertex_colors[i] == WHITE)
            if (DFS_visit(g, vertex_colors, i))
                return true;
    }
    return false;
}

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int n_v = 0, n_e = 0, i, j;
    scanf("%d %d", &n_v, &n_e);
    Graph g;
    inisialisasi_graph(&g, n_v, n_e);
    for (int i = 0; i < n_e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g.adjacency_matrix[a][b] = 1;
    }

    if (DFS(&g))
        printf("Cycle\n");
    else
    {
        qsort(finish_time, g.n_vertices, sizeof(int), compare);
        printf("\nTopological Sort\n");
        for (int i = 0; i < g.n_vertices; i++)
            printf("%d finished time: %d\n", vertex[finish_time[i]], finish_time[i]);
    }
    return 0;
}