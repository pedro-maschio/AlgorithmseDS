#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

class Graph {
    public:
        int u, v, V;
        vector<pair<int, int>> *adj;

        Graph(int V) {
            this->V = V;
            adj = new vector<pair<int, int>>[V];
        }
        void addElement(int u, int v, int w);
        void printGraph();
};

void Graph::addElement(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::printGraph() {
    for(int i = 0; i < V; i++) {
        cout << "Adjacency of " << i << ": ";

        for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << " -> " << "(" << it->first << ", " << it->second << ") ";
        }
        cout << endl;
    }
}

int main(){
    Graph grafo(10);
    int n, u, v, w;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        grafo.addElement(u, v, w);
    }
    grafo.printGraph();

    return 0;
}