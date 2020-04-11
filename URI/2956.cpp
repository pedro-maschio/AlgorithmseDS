// https://www.urionlinejudge.com.br/judge/pt/problems/view/2956
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

    double a, b;
    cin >> a >> b;
    cout << "Concluimos que, dado o limite da entrada, a resposta seria:  y = f(x) = ";
    cout << fixed << setprecision(5) << (a*b)/2.0 << "." << endl;


    return 0;
}