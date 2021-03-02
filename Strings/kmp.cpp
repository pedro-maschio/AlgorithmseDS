#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-10)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> prefixo(string pattern) {
    vector<int> p(pattern.size(), 0);

    for(int i = 1, j = 0; i < pattern.size(); i++) {
        while(j > 0 && pattern[i] != pattern[j])
            j = p[j-1];
        if(pattern[i] == pattern[j])
            j++;
        p[i] = j;
    }

    return p;
}

vector<int> matches(string t, string pattern) {
    vector<int> prefixos = prefixo(pattern+'$');

    for(auto a : prefixos)
        cout << a << " ";
    cout << endl;
    vector<int> ans;

    for(int i = 0, j = 0; i < t.size(); i++) {
        while(j > 0 && pattern[j] != t[i]) 
            j = prefixos[j-1];
        if(pattern[j] == t[i])
            j++;
        if(j == pattern.size())
            ans.push_back(i - j + 1);
    }


    return ans;
}


int main() {    
    fastio;

    string texto, pattern;

    getline(cin, texto);
    getline(cin, pattern);

    vector<int> res = matches(texto, pattern);

    cout << "Matches encontrados nos índices: ";
    for(auto pos : res) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}