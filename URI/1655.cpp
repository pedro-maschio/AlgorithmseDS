#include <bits/stdc++.h>
 
#define ll long long
#define vii vector<int>
#define pii pair<int, int>
#define endl '\n'
const ll INF = 1000000000000;
const ll MOD = 1000000007;
const ll MAX = 100000;
using namespace std;


double D[101][101];
ll n, m;

void floyd_warshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(D[i][k] >= 0 && D[k][j] >= 0) {
                    D[i][j] = max(D[i][j], D[i][k] * D[k][j]);
                }
            }
        }
    }
    printf("%.6lf percent\n", 100.0*D[1][n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(cin >> n) {
        if(!n)
            break;
        cin >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j)
                    D[i][j] = 0;
                else    
                    D[i][j] = -INF;
            }
        }

        for(ll i = 0; i < m; i++) {
            ll u, v;
            double p;
            cin >> u >> v >> p;

            D[u][v] = p*0.01;
            D[v][u] = p*0.01;
        }

        floyd_warshall();

    }

}  