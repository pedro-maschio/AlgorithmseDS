#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-6)
#define M (ll)(1e9+7)
#define INF (ll)(1e18)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
using namespace std;

vector<int> procura(string texto, string pattern) {
    vector<int> ans;
    int n = texto.size();
    int m = pattern.size();

    int k;
    for(int i = 0; i < n; ) {
        k = 0;
        if(texto[i] == pattern[k] && (i == 0 || texto[i-1] == ' ')) {
            while(i < n && k < m && texto[i] == pattern[k])
                i++, k++;
            if(k == m && (texto[i] == ' ' || i == n))
                ans.push_back(i-m);
        } else 
            i++;
    }
    if(ans.size())
        return ans;
    ans.push_back(-1);
    return ans;
}

int main() {    
    fastio;

    int n;

    cin >> n;

    string texto, pattern;
    
    for(int i = 0; i < n; i++) {
        cin.ignore();
        getline(cin, texto);

        cin >> pattern;

        vector<int> res = procura(texto, pattern);

        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << (i != res.size()-1 ? " " : "");
        }
        cout << endl;
    }

    return 0;   
}