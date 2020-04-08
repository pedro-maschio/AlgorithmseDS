// https://www.urionlinejudge.com.br/judge/pt/problems/view/1244
#include <bits/stdc++.h>

// # DEFINES # 
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n;
    cin >> n;
    cin.ignore();
    while(n--) {
        vector<string> vetor;
        string s;
        
        // to break the strings
        while(cin.peek() != '\n' && cin >> s) {
            vetor.push_back(s);
        }
        // stable sort keep the original order (when possible)
        stable_sort(vetor.begin(), vetor.end(), [](string a, string b) {
            return a.size() > b.size();
        });
        for(int i = 0; i < vetor.size(); i++) {
            cout << vetor[i];
            if(i < vetor.size()-1)
                cout << " ";
        }
        cout << "\n";
        
        cin.ignore();
    }

    return 0;
}