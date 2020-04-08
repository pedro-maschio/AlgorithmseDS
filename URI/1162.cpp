// https://www.urionlinejudge.com.br/judge/pt/problems/view/1162
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

    int t, n;

    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> vagoes(n);
        for(int i = 0; i < n; i++)
            cin >> vagoes[i];
        int trocas = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(vagoes[j] < vagoes[i])
                    trocas++;
            }
        }

        cout << "Optimal train swapping takes " << trocas << " swaps." << endl;

    }


    return 0;
}