#include <bits/stdc++.h>

#define ll long long
#define M 10e9+7

using namespace std;

// Greatest number which divites both numbers
ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    else 
        gcd(b, a % b);
}

// Least common *multiple* of the two numbers
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll t, a, b;

    cin >> t;

    while(t--) {
        cin >> a >> b;

        cout << gcd(a, b) << " " << lcm(a, b) << endl;
    }

    return 0;
}