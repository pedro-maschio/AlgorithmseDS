#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-6)
#define M (ll)(1e9+7)
#define INF (ll)(1e18)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
using namespace std;


int main() {    
    fastio;

    while(1) {
        ll n, val;
        cin >> n;
        if(!n)
            break;

        unordered_map<ll, ll> mapa;
        for(ll i = 0; i < n; i++) {
            cin >> val;
            mapa[val]++;
        }
        for(auto a : mapa) {
            if(a.second % 2 != 0) {
                cout << a.first << endl;
                break;
            }
        }
    }

    return 0;   
}