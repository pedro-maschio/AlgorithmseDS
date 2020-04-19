// https://www.urionlinejudge.com.br/judge/pt/problems/view/2386

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

    ll a, n, val;

    cin >> a >> n;

    ll count = 0;
    while(n--) {
        cin >> val;
        if(a * val >= 40000000)
            count++;
    }
    cout << count << endl;

    return 0;
}