#include <bits/stdc++.h>

#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
#define M (ll)(347)

using namespace std;

const int maxN = 100;
vector<int> adj[maxN];
bool visited[maxN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void topSort(int s, stack<int>& pilha) {
    visited[s] = true;

    for(auto a : adj[s]) {
        if(!visited[a])
            topSort(a, pilha);
    }
    cout << s << endl;
    pilha.push(s);
}

void topologicalSorting(int n) {
    stack<int> pilha;

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            topSort(i, pilha);
    }

    while(!pilha.empty()) {
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int e, u, v;

    cin >> e;

    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }

    topologicalSorting(e);


    return 0;
}