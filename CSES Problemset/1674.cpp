// Name: Subordinates
// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
 
// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9
 
using namespace std;
 
 
vector<int> c;
vector<vector<int>> adj;
 
 
int dfs(int u) {
    c[u]++;
 
    for(int v : adj[u]) {
        if(!c[v])
            dfs(v);
        c[u] += c[v];
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, val;
 
    cin >> n;
 
    adj = vector<vector<int>>(n);
 
    for(int i = 1; i < n; i++) {
        cin >> val;
        val--;
        adj[val].push_back(i);
    }
 
    c = vector<int>(n);
    for(int i = 0; i < n; i++) {
        if(!c[i])
            dfs(i);
    }
 
    for(int i = 0; i < n; i++) {
        cout << c[i]-1 << " ";
    }
    cout << endl;
 
    return 0;
}