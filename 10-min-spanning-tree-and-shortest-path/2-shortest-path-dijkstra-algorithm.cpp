#include <iostream>
#include <stdio.h>
#define MAXNUM_VERTICES 100
#define INF 1000000

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

int minimumDist(Graph *g, int dist[], bool Tset[])
{
    int min = INF, index;
    for (int i = 0; i < g->n_vertices; i++)
    {
        if (Tset[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int dijkstra(Graph *g, int source, int target)
{
    int dist[MAXNUM_VERTICES];  // arr utk jarak minimum setiap vertex
    bool Tset[MAXNUM_VERTICES]; // penanda vertex sudah dikunjungi/belom

    int n = g->n_vertices;
    for (int i = 0; i < g->n_vertices; i++)
    {
        dist[i] = INF;
        Tset[i] = false;
    }

    dist[source] = 0; // jarak vertex terhadap src = 0

    for (int i = 0; i < g->n_vertices; i++)
    {
        int m = minimumDist(g, dist, Tset);
        Tset[m] = true;
        for (int i = 0; i < g->n_vertices; i++)
        {
            // perbarui jarak minimun pada vertex tertentu
            if (!Tset[i] && g->adjacency_matrix[m][i] && dist[m] != INF && dist[m] + g->adjacency_matrix[m][i] < dist[i])
                dist[i] = dist[m] + g->adjacency_matrix[m][i];
        }
    }
    return dist[target];
}

int main()
{
    int n_v = 0, n_e = 0, i, j;
    scanf("%d %d", &n_v, &n_e);

    Graph g;
    inisialisasi_graph(&g, n_v, n_e);

    for (int i = 0; i < n_e; i++)
    {
        int a, b, weight;
        scanf("%d %d %d", &a, &b, &weight);
        g.adjacency_matrix[a][b] = weight; //jika elemen matriks tak nol, maka terdapat sebuah edge yang direpresentasikan oleh nilai bobotnya sendiri
    }

    printf("\nWeighted (directed) graph representation with adjacency matrix\n");
    print_adjancency_matrix(&g);

    int source, target, result;
    printf("\nDijkstra's algorithm\nVertex awal: ");
    scanf("%d", &source);
    printf("Vertex akhir: ");
    scanf("%d", &target);

    result = dijkstra(&g, source, target);
    printf("Shortest path => %d\n", result);
    return 0;
}