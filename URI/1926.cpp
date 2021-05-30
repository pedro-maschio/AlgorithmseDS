#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = 10000000000;
const ll MOD = 1000000007;
const ll MAX = 200010;
using namespace std;

vector<int> crivo(int n) {
    vector<bool> ehPrimo(n+2, 1);   
    vector<int> primos;
    vector<int> delta(n+2, 0);

    ehPrimo[0] = ehPrimo[1] = false;
    for(int i = 2; i <= n; i++) {
        if(ehPrimo[i] == 1) {
            primos.push_back(i);
            for(int j = i + i; j <= n; j += i) {
                ehPrimo[j] = 0;
            }
        }
    }   


    int k = 0;
    for(int i = 2; i <= n; i++) {
        if(ehPrimo[i]) {
            if(abs(primos[k]-primos[k+1]) == 2 || (k > 0 and abs(primos[k] - primos[k-1]) == 2)) 
                delta[i]++;
            k++;
        }
        delta[i] += delta[i-1];
    }

    return delta;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ehPrimo = crivo(1000010);

    ll t;

    cin >> t;

    while(t--) {
        ll l, r;
        cin >> l >> r;

        if(l > r)
            swap(l, r);
        cout << ehPrimo[r]-ehPrimo[l-1] << endl;
    }
    
}   