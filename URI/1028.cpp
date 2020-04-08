#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, f1, f2;

    cin >> n;

    while(n--) {
        cin >> f1 >> f2;

        cout << gcd(f1, f2) << endl;
    }

    return 0;
}