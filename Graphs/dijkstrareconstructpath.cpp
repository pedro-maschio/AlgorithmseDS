#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-10)
#define INF (ll)(1e18)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
using namespace std;
 
vector<vector<pair<int, int>>> adj((int)(2e5));
 
void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
 
void reconstructPath(int s, int e, vector<int>& ancestor) {
    vector<int> res;
    for(int i = e; i != -1; i = ancestor[i]) {
        res.push_back(i);
    }
    reverse(res.begin(), res.end());
    for(auto a : res) {
        cout << a << " ";
    }
}
void dijkstra(int s, int n) {
    vector<ll> distance(n+1, INF);
    vector<int> ancestor(n+1, -1);
    vector<bool> processed(n+1, false);
 
    // distancia / no
    priority_queue<pair<int, int>> fila;
    fila.push({0, s});
    distance[s] = 0;
 
    while(!fila.empty()) {
        auto no = fila.top().second;
        fila.pop();
 
        if(processed[no])
            continue;
        processed[no] = true;
 
        for(auto a : adj[no]) {
            int node = a.first, w = a.second;
 
            if(distance[no] + w < distance[node]) {
                distance[node] = distance[no] + w;
                fila.push({-distance[node], node});
                ancestor[node] = no;
            }
        }
    }
    if(distance[n] == INF)
        cout << -1;
    else {
        reconstructPath(s, n, ancestor);
    }
 
    cout << endl;
}
 
int main() {    
    fastio;
 
    int n, m, a, b, w;
 
    cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        addEdge(a, b, w);
    }
    dijkstra(1, n);
 
 
    return 0;   
}