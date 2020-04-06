// https://www.urionlinejudge.com.br/judge/pt/problems/view/2968
#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

int main(){
    ll v, n, total;

    cin >> v >> n;

    total = v*n;

    for(int i = 1; i <= 9; i++) {
        cout << (ll) ceil((total * i)/10.0);
        if(i < 9)
            cout << " ";
    }
    cout << '\n';

    return 0;
}