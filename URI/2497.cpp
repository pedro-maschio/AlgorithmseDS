// https://www.urionlinejudge.com.br/judge/pt/problems/view/2497

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
    ll i = 1;
    while(cin >> n, n != -1) {
        cout << "Experiment " << i << ": "  << n/2 << " full cycle(s)" << endl;
        i++;
    }


    return 0;
}