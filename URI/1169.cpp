// https://www.urionlinejudge.com.br/judge/pt/problems/view/1169

#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned ll n, casas;

    cin >> n;

    while(n--) {
        cin >> casas;
        
        unsigned ll res = 0;
        unsigned ll i = 1;
        while(casas) {
            res += i;
            i *= 2;
            casas--;
        }
        cout << res/12000 << " kg" << endl;
    }

    return 0;
}