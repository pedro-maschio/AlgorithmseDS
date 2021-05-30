#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = (ll)(1e18);
const ll MOD = 1000000007;
const ll MAX = 100000;
using namespace std;

struct Matrix {

    vector<vector<ll>> matrix;
    ll r, c;
    Matrix(vector<vector<ll>> m) {
        matrix = m;
        r = m.size();
        c = m[0].size();
    }

    Matrix(ll n, ll m, bool ident=false) {
        r = n;
        c = m;
        matrix = vector<vector<ll>>(r, vector<ll>(c, 0));

        if(ident) {
            for(ll i = 0; i < min(r, c); i++) 
                matrix[i][i] = 1;
        }
    }

    Matrix operator*(Matrix& outra) {
        ll p = outra.c;

        vector<vector<ll>> ans(r, vector<ll>(p, 0));
        for(ll i = 0; i < r; i++) {
            for(ll j = 0; j < p; j++) {
                for(ll k = 0; k < c; k++) {
                    ans[i][j] = (ans[i][j] + matrix[i][k] * outra.matrix[k][j]) % MOD;
                }
            }
        }
        return Matrix(ans);
    }

};

Matrix fast_exp(Matrix b, ll e, ll n) {
    if(e == 0)
        return Matrix(n, n, true);

    Matrix res = fast_exp(b, e/2, n);
    res = res * res;

    if(e % 2)
        res = res * b;

    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Matrix a({{1LL, 1LL}, {1LL, 0LL}});

    ll n;

    cin >> n;

    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    Matrix ans = fast_exp(a, n-1, 2);


    cout << ans.matrix[0][0] << endl;

    return 0;
}  