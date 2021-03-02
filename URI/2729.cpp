#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-6)
#define M (ll)(1e9+7)
#define INF (ll)(1e18)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
using namespace std;


int main() {    
    fastio;
    
    int n;

    cin >> n;
    cin.ignore();
    string s;
    for(int i = 0; i < n; i++) {
        set<string> conjunto;
        getline(cin, s);

        istringstream is(s);
        string teste;
        while(is >> teste) {
            conjunto.insert(teste);
        
        }
        

        set<string>::iterator it;

        for(it = conjunto.begin(); it != conjunto.end(); it++) {
            cout << *it << ((++it) != conjunto.end() ? " " : "");
            --it;
        }
        is.clear();
   
        cout << endl;
    }

    return 0;   
}