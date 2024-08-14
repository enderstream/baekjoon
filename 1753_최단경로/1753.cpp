//fail

#include <iostream>
#include <vector>
#define INF 350000
using namespace std;

typedef vector<vector<int>> graph;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V = 0;
    int E = 0;
    int K = 0;
    cin >> V >> E >> K;
    graph G(V + 1, vector<int>(V + 1, INF));
    vector<int> D(V, INF); 
    vector<bool> visited(V, false); 
    for (int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (G[u][v] > w)
            G[u][v] = w;
    }

    for (int i = 1; i <= V; i++)
    {
        if(D[i] > D[K] + G[K][i])
            D[i] = D[K] + G[K][i];
    }
    // visited[i] = true;
    


    return 0;
}
