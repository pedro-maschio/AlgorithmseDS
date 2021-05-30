#include <bits/stdc++.h>
 
#define ll long long
#define INF 1000000000
 
using namespace std;

class Cmp {
public:
    // para que seja uma fila de prioridade mínima
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) {
        if(a.first != b.first)
            return a.first > b.first;
        else 
            return a.second > b.second;
    }
};

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    
    ll n, m;

    cin >> n >> m;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Cmp> caixas;
    queue<ll> cliente;
    vector<ll> tempos(n);

    for(ll i = 0; i < n; i++) {
        ll num; cin >> num;

        caixas.push({0, i});
        tempos[i] = num;
    }
    for(ll i =  0; i < m; i++) {
        ll num; cin >> num;
        cliente.push(num);
    }

    ll ans = 0;
    while(!cliente.empty()) {
        ll c = cliente.front();
        cliente.pop();
        
        auto par = caixas.top();
        caixas.pop();
        
        caixas.push({par.first + tempos[par.second]*c, par.second});

        ans = max(ans, par.first + tempos[par.second]*c);
    }

    cout << ans << endl;
}