#include <stdio.h>
#include <stdbool.h>
#define MAXNUM_VERTICES 100

/*Struktur data untuk merepresentasikan sebuah graf
dengan menggunakan adjacency matrix. Graph memiliki
n_vertices simpul dan n_edges sisi.
*/
typedef struct
{
    int n_vertices, n_edges, adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
} Graph;

/*
Fungsi ini untuk menginisialisasi adjacency matrix graph dengan cara
mengisi sub-matrix kiri atas dengan ukuran n_vertices x n_vertices dari adjancency matrix
dengan nilai 0, sedangkan sisanya (yang tidak relevan untuk tujuan representasi graph dengan 
jumlah vertex sebanyak n_vertices) akan diisi dengan nilai -1
*/

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

// prosedur yang mengimplementasikan DFS_visit
bool DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
    // printf("%d ", v);
    // tandai v dengan warna gray
    vertex_colors[v] = GRAY;
    // cari vertex yang adjaceng terhadap v, jika masih WHITE, panggil DFS_visit vertex itu
    for (int i = 0; i < g->n_vertices; i++)
    {
        // soal no 1
        // i adjacent terhadap v dan bukan berwarna white
        if (g->adjacency_matrix[v][i] == 1 && vertex_colors[i] == GRAY)
            return true;

        // lengkapi agar DFS_visit dipanggil pada vertex i yang adjacent terhadap v dan masih berwarna WHITE
        if (vertex_colors[i] == WHITE && g->adjacency_matrix[v][i] == 1 && DFS_visit(g, vertex_colors, i))
            return true;
    }
    vertex_colors[v] = BLACK;
    return false;
}

bool DFS(Graph *g)
{
    COLOR vertex_colors[MAXNUM_VERTICES];
    for (int i = 0; i < g->n_vertices; i++)
        vertex_colors[i] = WHITE;

    for (int i = 0; i < g->n_vertices; i++)
    {
        if (vertex_colors[i] == WHITE)
            if (DFS_visit(g, vertex_colors, i))
                return true;
    }
    return false;
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

    // print_adjancency_matrix(&g);

    if (DFS(&g))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}