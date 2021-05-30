#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = (ll)(1e18);
const ll MOD = 1000000007;
const ll MAX = 100000;
using namespace std;


vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;

    for(auto neighbor: adj[v]) {
        if(!visited[neighbor])
            dfs(neighbor);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   

    int n, m; 
    cin >> n >> m;

    adj.resize(n+1);
    visited.assign(n+1, false);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}  