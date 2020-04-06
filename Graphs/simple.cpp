#include <bits/stdc++.h>

using namespace std;

class Graph {
    vector<int> *adj;
    int V;
    public:
        Graph(int V) {
            this->V = V;
            adj = new vector<int>[V];
        }
        void addEdge(int u, int v);
        void printGraph();
        bool isReachable(int u, int v); // check if there's a path from u to v;
        void DFSUtil(int v, bool visited[]);
        void DFS(int v);
        void BFS(int s);    
};

void Graph::BFS(int s) {
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        vector<int>::iterator it;
        for(it = adj[s].begin(); it != adj[s].end(); it++) {
            if(!visited[*it]) {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }

    }

}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    vector<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++) {
        if(!visited[*it])
            DFSUtil(*it, visited);
    }
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFSUtil(v, visited);
}

bool Graph::isReachable(int u, int v) {
    if(u == v)
        return true;
    
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    list<int> queue;
    visited[u] = true;

    queue.push_back(u);

    while(!queue.empty()) {
        u = queue.front();
        queue.pop_front();

        for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
            if(*it == v)
                return true;
            else if(!visited[*it]) {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
    return false;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::printGraph() {
    for(int i = 0; i < V; i++) {
        cout << "Adjacency list for " << i << ": ";

        for(auto a : adj[i]) {
            cout << " -> " << a;
        }
        cout << "\n";
    }
}

int main() {
    int V, E, Q, u, v;

    cin >> V >> E >> Q;

    Graph grafo(V+1);


    for(int i = 0;i < E; i++) {
        cin >> u >> v;
        grafo.addEdge(u, v);
    }
    grafo.printGraph();
    for(int i = 0; i < Q; i++) {
        cin >> u;
        grafo.DFS(u);
        cout << endl;
    }
   

    return 0;
}