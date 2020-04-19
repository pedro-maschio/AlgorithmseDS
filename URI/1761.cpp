// https://www.urionlinejudge.com.br/judge/pt/problems/view/1761
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

    double a, b, c;

    while(cin >> a >> b >> c) {
        cout << setprecision(2) << fixed << 5.0*(tan(a*3.141592654/180.0)*b + c) << endl;
    }

    return 0;
}