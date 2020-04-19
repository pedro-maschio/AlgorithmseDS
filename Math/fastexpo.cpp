#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

ll expo(ll a, ll b) {
    if(b == 0)
        return 1;
    else if(b % 2 == 0) {
        ll rs = expo(a, b/2)%M; // better than doing two recursive calls
        return ((rs%M) * (rs%M))%M;
    } else 
        return (a%M * expo(a, b-1)%M)%M;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, a, b;

    cin >> t;

    while(t--) {
        cin >> a >> b;

        cout << expo(a, b) << endl;
    }

    return 0;
}