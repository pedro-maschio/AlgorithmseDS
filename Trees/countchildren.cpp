#include <bits/stdc++.h>

using namespace std;

#define M (ll)(1e9+7)
#define EPS (double)(1e-12)
#define ll long long
#define N (ll)(2*1e5)

int conta[N];

class Tree {
    public:
        int V;
        vector<int> *adj;

        Tree(int V) {
            this->V = V;
            adj = new vector<int>[V];
        }
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void countChildren(int s, int e);
};

void Tree::countChildren(int s, int e) {
    conta[s] = 1;
    for(auto a : adj[s]) {
        if(a == e)
            continue;
        countChildren(a, s);
        conta[s] += conta[a];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Tree arvore(10);

    int u, v, V, raiz;
    cin >> V;
    for(int i = 0; i < V; i++) {
        cin >> u >> v;
        if(i == 0)
            raiz = u;
        arvore.addEdge(u, v);
    }

    arvore.countChildren(raiz, 0);

    for(int i = 0; i < V+1; i++)
        cout << conta[i] << " ";

    return 0;
}