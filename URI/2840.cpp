// https://www.urionlinejudge.com.br/judge/pt/problems/view/2840
#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

int main(){
    ll r, l;

    cin >> r >> l;

    ll volume = (4.0/3.0)*3.1415*r*r*r;

    cout << l/volume << endl;

    return 0;
}