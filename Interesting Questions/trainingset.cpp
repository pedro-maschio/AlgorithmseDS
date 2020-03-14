#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int t, n, ans;
    string w1;
    bool boleano;

    cin >> t;

    while(t--) {
        cin >> n;

        ans = 0;
        unordered_map<string, pair<int, int>> mapa;
        for(int i = 0; i < n; i++) {
            cin >> w1 >> boleano;

            if(boleano)
                ++mapa[w1].second;
            else 
                ++mapa[w1].first;
        }

        for(auto i : mapa) {
            ans += max(i.second.first, i.second.second);
        }
        cout << ans << endl;
    }

    return 0;
}