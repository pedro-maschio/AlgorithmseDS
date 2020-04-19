// https://www.urionlinejudge.com.br/judge/pt/problems/view/1240
#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

ll tam(ll n) {
    ll count = 0;
    while(n) {
        count++;
        n /= 10;
    }
    return count;
}

void encaixa(ll a, ll b) {
    ll count = 0;
    ll tb = tam(b);
    while(a && b && a % 10 == b % 10) {
        count++;
        a /= 10;
        b /= 10;
    }
    if(count == tb)
        cout << "encaixa" << endl;
    else 
        cout << "nao encaixa" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, n;

    cin >> n;

    while(n--) {
        cin >> a >> b;
        encaixa(a, b);
    }
    return 0;
}