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

    ll n, m;

    while(cin >> n >> m, (n != 0 || m != 0)) {
        vector<ll> numeros(n);

        for(ll i = 0; i < n; i++) {
            cin >> numeros[i];
        }
        sort(numeros.begin(), numeros.end(), [&](int a, int b) {
            bool aimpar = a % 2;
            bool bimpar = b % 2;
            int resa = a % m;
            int resb = b % m;
            
            if(resa != resb) {
                return resa < resb;
            } else if(resa == resb && (aimpar && !bimpar || !aimpar && bimpar)) {
                if(aimpar)
                    return true;
                else 
                    return false;
            } else if(resa == resb && (aimpar && bimpar)) {
                return a > b;
            } else {
                return a < b;
            }
        });

        cout << n << " " << m << endl;
        for(int i = 0; i < n; i++)
            cout << numeros[i] << endl;
    }
    cout << "0 0" << endl;

    return 0;
}