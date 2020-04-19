#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define EPS 1e-9
const ll M = 1000000007;
using namespace std;

// Check divisors in O(sqrt(N)) time
ll divisors(ll n) {
    ll cnt = 0;

    for(ll i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            if(n/i == i)
                cnt++;
            else 
                cnt += 2;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x;

    cin >> n;

    while(n--) {
        cin >> x;

        cout << divisors(x) << endl;
    }


    return 0;
}