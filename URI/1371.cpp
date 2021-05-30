#include <bits/stdc++.h>
 
#define ll long long
#define INF 10000000000
#define MOD (ll)(1000000007)
#define endl '\n'
 
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;

    while(cin >> n, n != 0) {
        ll i = 1;

        while(true) {
            cout << i*i;
            i++;

            if(i*i > n)
                break;
            else 
                cout << " ";
        }
        cout << endl;
    }
    
}