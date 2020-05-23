// Name: Exponentiation II
// https://cses.fi/problemset/task/1712

#include <bits/stdc++.h>
 
// # DEFINES # //
#define ll long long
#define EPS 1e-9
const ll M = 1000000007;
using namespace std;
 
ll expo(ll a, ll b, ll M) {
    if(b == 0)
        return 1;
    else if(!(b & 1)) {
        ll y = expo(a, b/2, M)%M;
        return ((y%M) * (y%M))%M;
    } else {
        return (a%M * expo(a, b-1, M)%M)%M;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t, a, b, c;
 
    cin >> t;
 
    while(t--) {
        cin >> a >> b >> c;
        ll res = expo(b, c, M-1);
        cout << expo(a, res, M) << endl;
    }
    
 
    return 0;
}