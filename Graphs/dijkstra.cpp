#include <bits/stdc++.h>

#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
#define INF 1e8

using namespace std;

const int maxN = 1e3;


vector<pair<int, int>> adj[maxN];

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void dijkstra(int s, int n) {
    int distance[n+1];
    bool visited[n+1];

    for(int i = 0; i <= n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    priority_queue<pair<int, int>> fila_prioridades;

    // distancia / vertice
    fila_prioridades.push({0, s});
    distance[s] = 0;

    while(!fila_prioridades.empty()) {
        int no = fila_prioridades.top().second;
        fila_prioridades.pop();

        if(visited[no])
            continue;
        visited[no] = true;

        for(auto u : adj[no]) {
            int b = u.first, w = u.second;

            if(distance[no]+w < distance[b]) {
                distance[b] = distance[no]+w;
                fila_prioridades.push({-distance[b], b});
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e, a, b, w;

    cin >> n >> e;

    for(int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        addEdge(a, b, w);
    }
    
    dijkstra(1, n);

    return 0;
}