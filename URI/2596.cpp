#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

ll numDivisores(ll n) {
    ll count = 0;
    for(int i = 1; i <= n; i++)  {
        if(n % i == 0)
            count++;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, t;

    cin >> t;

    while(t-- ) {
        ll count = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            if(numDivisores(i) % 2 == 0)    
                count++;
        cout << count << endl;
    }


    return 0;
}