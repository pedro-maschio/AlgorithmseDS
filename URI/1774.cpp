#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
#define INF (ll)(1e8)

const int maxN = 1e3;

bool visited[maxN];
vector<vector<pair<int, int>>> adj(maxN);
 
int minimumSpanningTree(int s, int v) {
    int ans = 0, edgeCount = 0;

    priority_queue<pair<int, int>> fila;

    fila.push({0, s});

    while(!fila.empty() && edgeCount != v - 1) {
        int u = fila.top().second;
        int w = fila.top().first;
        fila.pop();

        if(visited[u])
            continue;
        ans += w;
        visited[u] = true;

        for(auto a : adj[u]) {
            int v = a.first;
            int peso = a.second;
            if(!visited[v])
                fila.push({-peso, v});
        }
    }
    return -1*ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e, u, v, w;

    cin >> n >> e;

    for(int i = 0; i < e; i++) {
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << minimumSpanningTree(1, n) << endl;
 
    return 0;
}