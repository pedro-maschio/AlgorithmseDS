#include <bits/stdc++.h>
 
#define ll long long
#define vii vector<int>
#define pii pair<int, int>
#define endl '\n'
const ll INF = 10000000000;
const ll MOD = 1000000007;
const ll MAX = 10000;
using namespace std;


ll G[MAX][MAX], D[MAX][MAX];
int n;

void floyd_warshall() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                D[i][j] = 0;
            else {
                if(G[i][j])
                    D[i][j] = G[i][j];
                else 
                    D[i][j] = G[i][j];
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m, u, v, w;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        G[u][v] = w;
        G[v][u] = w;
    }

    floyd_warshall();

    // minimum cost from 1 to n
    cout << D[1][n] << endl;


}  