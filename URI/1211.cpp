// https://www.urionlinejudge.com.br/judge/pt/problems/view/1211

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

    ll n;
    while(cin >> n) {
        vector<string> vetor(n);
        for(ll i = 0; i < n; i++) {
            
            string s;

            cin >> s;
            vetor[i] = s;
        }
        sort(vetor.begin(), vetor.end());
        int count = 0;
        int m = (int) vetor[0].size();

        if(n != 2) {
            for(int j = 1; j < n; j++) {
                int i = 0;
                while(i < m && vetor[j][i] == vetor[j-1][i]) {
                    count++;
                    i++;
                }
            }
        } else {
            int i = 0;
            while(i < m && vetor[1][i] == vetor[0][i]) {
                count++;
                i++;
            }
        }
        cout << count << endl;
    }
    return 0;
}