// https://www.urionlinejudge.com.br/judge/pt/problems/view/1429

#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;


ll fat(ll n) {
    if(n < 1)
        return 1;
    else 
        return n * fat(n-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll val;

    while(cin >> val, val > 0) {

        ll k = 1, res = 0;
        while(val) {
            res = res + (val % 10)*fat(k);
            k++;
            val /= 10;
        }
        cout << res << endl;
    }
    return 0;
}