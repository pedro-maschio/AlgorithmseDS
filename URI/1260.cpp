// https://www.urionlinejudge.com.br/judge/pt/problems/view/1260
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
    char c;
    string s;

    cin >> n;
    
    cin.ignore();
    cin.ignore();
    while(n--) {
        map<string, int> mapa;
        ll count = 0;
        
        while(getline(cin, s)) {
            if(s.size() == 0)   
                break;
            count++;
            mapa[s]++;
        }
        map<string, int>::iterator it;
        for(it = mapa.begin(); it != mapa.end(); it++) {
            double por = (double)(it->second/(double)count);
            
            cout << it->first << " ";
            cout << fixed << setprecision(4) << (double)por*100 << endl;;
        }
        if(n != 0)  
            cout << endl;
            
    }
    return 0;
}