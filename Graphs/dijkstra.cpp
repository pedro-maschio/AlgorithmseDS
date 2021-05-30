#include <bits/stdc++.h>
 
#define ll long long
#define vii vector<int>
#define pii pair<int, int>
#define endl '\n'
const ll INF = 10000000000;
const ll MOD = 1000000007;
const ll MAX = 100000;
using namespace std;

vector<vector<pair<int, int>>> graph;

void dijkstra(int start) {
    vector<int> d(graph.size(), INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[start] = 0;
    pq.push({d[start], start});

    int dist, w, u, v;

    while(!pq.empty()) {
        tie(dist, u) = pq.top();
        pq.pop();

        if(dist > d[u])
            continue;
        
        for(auto neighbor: graph[u]) {
            tie(v, w) = neighbor;

            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // change all to ll, inf = 10^18 at least 

    int n, m, u, v, w;

    cin >> n >> m;

    graph.resize(n+1);
    
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    dijkstra(1);
    
}  