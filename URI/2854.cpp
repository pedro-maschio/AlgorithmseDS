#include <bits/stdc++.h>

#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
#define M (ll)(347)

using namespace std;
const int maxN = 301;
vector<int> adj[maxN];
bool visited[maxN];

void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs(int s) {
    if(visited[s])
        return;
    visited[s] = true;

    for(auto u : adj[s]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

int checkComponents() {

    int components = 0;
    
    for(int i = 0; i < maxN; i++) {
        if(!visited[i] && adj[i].size() > 0) {
            dfs(i);
            components++;
        }
    }

    return components;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e;

    cin >> n >> e;

    string s;
    map<string, int> mapa;
    int indice = 0;

    cin.ignore();
    for(int i = 0; i < e; i++) {
    
        getline(cin, s, '\n');

        istringstream is(s);
        
        string a;
        int j = 0;
        string temp;

        while(is >> temp) {
            
            if(j == 0) {
                if(mapa.find(temp) == mapa.end()) {
                   mapa[temp] = indice;
                   indice++;
                } 
                a = temp;
            } else if(j == 2) {
                if(mapa.find(temp) == mapa.end()) {
                    mapa[temp] = indice;
                    indice++;
                }
                addEdge(mapa[a], mapa[temp]);
            }
            j++;
        }
    }
    cout << checkComponents() << endl;

    return 0;
}