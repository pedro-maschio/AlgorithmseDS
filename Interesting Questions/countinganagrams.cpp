#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> m;
    for(string s : strs) {
        string copia = s;
        sort(copia.begin(), copia.end());
        m[copia].push_back(s);
    }
    vector<vector<string>> v;
    for(pair<string, vector<string>> a : m) {
        v.push_back(a.second);
    }
    return v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;

    cin >> n;
    
    vector<string> vetor(n);
    for(int i = 0; i <  n; i++) {
        cin >> s;
        vetor[i] = s;
    }

    vector<vector<string>> res = groupAnagrams(vetor);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}