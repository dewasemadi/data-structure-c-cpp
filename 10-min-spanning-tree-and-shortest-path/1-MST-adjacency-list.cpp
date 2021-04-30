#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAXNUM_VERTICES = 1000;
typedef pair<unsigned int, int> PII; //weight, vertex adjecent
vector<PII> adj[MAXNUM_VERTICES];

bool selected[MAXNUM_VERTICES];
unsigned int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    int y;
    unsigned int minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while (!Q.empty())
    {
        /*
        soal no 3, pilih edge dengan bobot minimum saat ini, dan masukkan ke p
        lalu keluarkan dari priority queue Q
        gunakan fungsi top() dan pop() pada priority queue
        */
        p = Q.top();
        Q.pop();

        //ambil vertex tujuan p
        x = p.second;

        // soal no 4. lewati vertex yang sudah terpilih
        if (selected[x] == true)
            continue;

        minimumCost += p.first;
        selected[x] = true;

        for (int i = 0; i < adj[x].size(); i++)
        {
            y = adj[x][i].second;
            if (selected[y] == false)
            {
                // soal no 5. masukkan edge x-->y ke dalam Q,
                // gunakan fungsi push!
                Q.push(make_pair(adj[x][i].first, y));
            }
        }
    }
    return minimumCost;
}

int main()
{
    int n, k, x, y;
    unsigned int weight, minimumCost;
    // undirected graph!
    // soal no 1
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> x >> y >> weight;
        // masukkan edge x --> y dengan bobotnya ada adjacency list x
        adj[x].push_back(make_pair(weight, y));

        // soal no 2. masukkan edge yang sama pada adjacency list y
        adj[y].push_back(make_pair(weight, x));
    }
    cout << prim(1) << endl;
    return 0;
}