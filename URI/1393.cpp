// https://www.urionlinejudge.com.br/judge/pt/problems/view/1393

#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9
const ll INF = (1LL << 60)-1;

using namespace std;

ll fib[1000000];
ll n_fibonacci(ll n) {
    if(n <= 2) {
        fib[n] = n;
        return fib[n];
    } if(fib[n])
        return fib[n];
    else {
        fib[n] = n_fibonacci(n-1) + n_fibonacci(n-2);
        return fib[n];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;

    while(cin >> n && n) {
        cout << n_fibonacci(n) << endl;
    }
    return 0;
}