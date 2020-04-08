// https://www.urionlinejudge.com.br/judge/pt/problems/view/1256

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

    ll t, n, m, val;

    cin >> t;

    while(t--) {
        cin >> m >> n;

        vector<list<int>> res(m);
        for(int i = 0; i < n; i++) {
            cin >> val;
            ll pos = val % m;
            res[pos].push_back(val);
        }
        for(int i = 0; i < m; i++) {
            cout << i << " -> ";
            if(res[i].empty())
                cout << "\\" << endl;
            else {
                for(auto a : res[i]) {
                    cout << a << " -> ";
                }
                cout << "\\" << endl;
            }
        }
        if(t > 0)
            cout << endl;
    }

    return 0;
}