// https://www.urionlinejudge.com.br/judge/pt/problems/view/2402
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M (ll) (1e9+7)

bool isPrime(ll n) {
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;

    for(ll i = 3; i*i <= n; i++) {
        if(n % i == 0)
            return false; 
    }
    return true;
}

int main() {
    ll n, flag = 0;
    
    cin >> n;

    if(!isPrime(n))
        cout << "S" << endl;
    else 
        cout << "N"  << endl;
    
    return 0;
}