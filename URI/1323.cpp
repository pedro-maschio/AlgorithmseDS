// https://www.urionlinejudge.com.br/judge/pt/problems/view/1323

#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;

    while(cin >> n, n != 0) {
        cout << (n*(n+1)*(2*n+1))/6 << endl;
    }
    return 0;
}